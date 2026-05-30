//========================================================================================
//  
//  $File: $
//  
//  Owner: 
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================


#ifndef __KESMLID_h__
#define __KESMLID_h__

#include "SDKDef.h"

// Company:
#define kKESMLCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kKESMLCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kKESMLPluginName	"KohakuExtendScriptMouseLocation"			// Name of this plug-in.
#define kKESMLPrefixNumber	0xcba9f1ba 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kKESMLVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kKESMLAuthor		""					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kKESMLPrefixNumber above to modify the prefix.)
#define kKESMLPrefix		RezLong(kKESMLPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kKESMLStringPrefix	SDK_DEF_STRINGIZE(kKESMLPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kKESMLMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kKESMLMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kKESMLPluginID, kKESMLPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kKESMLScriptProviderBoss, kKESMLPrefix + 0)

// InterfaceIDs:
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESMLINTERFACE, kKESMLPrefix + 0)

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kKESMLScriptProviderImpl, kKESMLPrefix + 0 )

// ActionIDs:
DECLARE_PMID(kActionIDSpace, kKESMLAboutActionID, kKESMLPrefix + 0)

// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kKESMLWidgetID, kKESMLPrefix + 2)

//Script Element IDs
DECLARE_PMID(kScriptInfoIDSpace, kKESMLGlobalMouseLocationXPropertyScriptElement, kKESMLPrefix + 0)
DECLARE_PMID(kScriptInfoIDSpace, kKESMLGlobalMouseLocationYPropertyScriptElement, kKESMLPrefix + 1)
DECLARE_PMID(kScriptInfoIDSpace, kKESMLPasteboardMouseLocationXPropertyScriptElement, kKESMLPrefix + 2)
DECLARE_PMID(kScriptInfoIDSpace, kKESMLPasteboardMouseLocationYPropertyScriptElement, kKESMLPrefix + 3)

// "About Plug-ins" sub-menu:
#define kKESMLAboutMenuKey			kKESMLStringPrefix "kKESMLAboutMenuKey"
#define kKESMLAboutMenuPath		kSDKDefStandardAboutMenuPath kKESMLCompanyKey

// "Plug-ins" sub-menu:
#define kKESMLPluginsMenuKey 		kKESMLStringPrefix "kKESMLPluginsMenuKey"
#define kKESMLPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kKESMLCompanyKey kSDKDefDelimitMenuPath kKESMLPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kKESMLAboutBoxStringKey	kKESMLStringPrefix "kKESMLAboutBoxStringKey"
#define kKESMLTargetMenuPath kKESMLPluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kKESMLFirstMajorFormatNumber  RezLong(1)
#define kKESMLFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kKESMLCurrentMajorFormatNumber kKESMLFirstMajorFormatNumber
#define kKESMLCurrentMinorFormatNumber kKESMLFirstMinorFormatNumber

#endif // __KESMLID_h__
