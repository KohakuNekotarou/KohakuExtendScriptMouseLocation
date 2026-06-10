#include "VCPlugInHeaders.h"

// Interface includes:
#include "IEventUtils.h"
#include "ILayoutUIUtils.h"
#include "IPanelControlData.h"
#include "IScript.h"
#include "IScriptRequestData.h"

// General includes:
#include "CAlert.h"
#include "CScriptProvider.h"
#include "LayoutUIID.h" // for kLayoutWidgetBoss
#include "Utils.h"

// Project includes:
#include "KESMLScriptingDefs.h"
#include "KESMLID.h"

#ifdef WINDOWS
#pragma comment(lib, "user32.lib")
#include <windows.h>
#elif MACINTOSH
#import <ApplicationServices/ApplicationServices.h>
#endif

class KESMLScriptProvider : public CScriptProvider
{
public:
	KESMLScriptProvider(IPMUnknown* boss) : CScriptProvider(boss) {};

	~KESMLScriptProvider() {}

	// AccessProperty
	ErrorCode AccessProperty(ScriptID scriptID_property, IScriptRequestData* iScriptRequestData, IScript* iScript);

private:

	// AccessGlobalMouseLocation
	ErrorCode AccessGlobalMouseLocation(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript, bool16 XYFlg);

	// AccessPasteboardMouseLocation
	ErrorCode AccessPasteboardMouseLocation(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript, bool16 XYFlg);
};

CREATE_PMINTERFACE(KESMLScriptProvider, kKESMLScriptProviderImpl)

// AccessProperty
ErrorCode KESMLScriptProvider::AccessProperty(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript)
{
	ErrorCode status = kFailure;

	bool16 x = 0, y = 1;
	switch (scriptID.Get())
	{
	case p_KESMLGlobalMouseLocationX:
		status = this->AccessGlobalMouseLocation(scriptID, iScriptRequestData, iScript, x);
		break;

	case p_KESMLGlobalMouseLocationY:
		status = this->AccessGlobalMouseLocation(scriptID, iScriptRequestData, iScript, y);
		break;

	case p_KESMLPasteboardMouseLocationX:
		status = this->AccessPasteboardMouseLocation(scriptID, iScriptRequestData, iScript, x);
		break;

	case p_KESMLPasteboardMouseLocationY:
		status = this->AccessPasteboardMouseLocation(scriptID, iScriptRequestData, iScript, y);
		break;

    default:
		status = CScriptProvider::AccessProperty(scriptID, iScriptRequestData, iScript);
    }

    return status;
}

// AccessGlobalMouseLocation
ErrorCode KESMLScriptProvider::AccessGlobalMouseLocation
	(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript, bool16 XYFlg)
{
	ErrorCode status = kFailure;

	do {
		// GetGlobalMouseLocation
		GSysPoint gSysPoint = Utils<IEventUtils>()->GetGlobalMouseLocation();

		// ---------------------------------------------------------------------------------------
		// Request
		ScriptData scriptData;
		bool16 x = 0, y = 1;
		if (iScriptRequestData->IsPropertyGet()) // Get
		{
			// ---------------------------------------------------------------------------------------
			// Append return data
			if (XYFlg == x) scriptData.SetInt32(gSysPoint.x);
			else if (XYFlg == y) scriptData.SetInt32(gSysPoint.y);

			iScriptRequestData->AppendReturnData(iScript, scriptID, scriptData);
		}
		else if (iScriptRequestData->IsPropertyPut()) // Set
		{
			status = iScriptRequestData->ExtractRequestData(scriptID.Get(), scriptData);
			if (status != kSuccess) break;

			// ---------------------------------------------------------------------------------------
			// Scroll
			int32 int32_point, int32_pointX = gSysPoint.x, int32_pointY = gSysPoint.y;
			status = scriptData.GetInt32(&int32_point);
			if (status != kSuccess) break;

			if (XYFlg == x) int32_pointX = int32_point;
			else if (XYFlg == y) int32_pointY = int32_point;

#ifdef WINDOWS
			::SetCursorPos(int32_pointX, int32_pointY);
#elif MACINTOSH
			::CGWarpMouseCursorPosition(CGPointMake(int32_pointX, int32_pointY));
#endif
		}
		status = kSuccess;

	} while (kFalse);

	return status;
}

// AccessPasteboardMouseLocation
ErrorCode KESMLScriptProvider::AccessPasteboardMouseLocation
(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript, bool16 XYFlg)
{
	ErrorCode status = kFailure;

	do {
		// GetGlobalMouseLocation
		GSysPoint gSysPoint = Utils<IEventUtils>()->GetGlobalMouseLocation();

		// ---------------------------------------------------------------------------------------
		// GetPasteboardMouseLocation
		InterfacePtr<IPanelControlData> iPanelControlData(iScript, ::UseDefaultIID());
		if (!iPanelControlData) break;

		IControlView* iControlView = iPanelControlData->FindWidget(kLayoutWidgetBoss); // kLayoutWidgetBoss is a BOSS representing a layout view.
		if (!iControlView) break;

		PMPoint pMPoint_pastboardPoint = Utils<ILayoutUIUtils>()->ComputePasteboardPoint(gSysPoint, iControlView);

		// ---------------------------------------------------------------------------------------
		// Request
		ScriptData scriptData;
		bool16 x = 0, y = 1;
		if (iScriptRequestData->IsPropertyGet()) // Get
		{

			// ---------------------------------------------------------------------------------------
			// Append return data
			if (XYFlg == x) scriptData.SetPMReal(pMPoint_pastboardPoint.X());
			else if (XYFlg == y) scriptData.SetPMReal(pMPoint_pastboardPoint.Y());

			iScriptRequestData->AppendReturnData(iScript, scriptID, scriptData);
		}
		else if (iScriptRequestData->IsPropertyPut()) // Set
		{
			status = iScriptRequestData->ExtractRequestData(scriptID.Get(), scriptData);
			if (status != kSuccess) break;

			// ---------------------------------------------------------------------------------------
			// Scroll
			PMReal pMReal_point;
			status = scriptData.GetPMReal(&pMReal_point);
			if (status != kSuccess) break;

			if (XYFlg == x) pMPoint_pastboardPoint.X(pMReal_point);
			else if (XYFlg == y) pMPoint_pastboardPoint.Y(pMReal_point);

			PMPoint pmPoint_WindowPoint = pMPoint_pastboardPoint;
			iControlView->ContentToWindowTransform(&pmPoint_WindowPoint);

			PMPoint pmPoint_GlobalPoint = iControlView->WindowToGlobal(pmPoint_WindowPoint);

#ifdef WINDOWS
			::SetCursorPos(::ToInt32(pmPoint_GlobalPoint.X()), ::ToInt32(pmPoint_GlobalPoint.Y()));
#elif MACINTOSH
			::CGWarpMouseCursorPosition(CGPointMake(::ToInt32(pmPoint_GlobalPoint.X()), ::ToInt32(pmPoint_GlobalPoint.Y()));
#endif
		}
		status = kSuccess;

	} while (kFalse);

	return status;
}
