#ifndef __KESMLScriptingDefs_h__
#define __KESMLScriptingDefs_h__

#define kCPrefs_CLSID { 0x8d448fe0, 0x8194, 0x11d3, { 0xa6, 0x53, 0x0, 0xe0, 0x98, 0x71, 0xa, 0x6f } }
DECLARE_GUID(CPrefs_CLSID, kCPrefs_CLSID);

// Note: 4-char IDs below must be unique.
// See ScriptingDefs.h for further information.

// Property IDs
enum KESMLScriptProperties
{
	p_KESMLGlobalMouseLocationX = 'KGLX',
	p_KESMLGlobalMouseLocationY = 'KGLY',
	p_KESMLPasteboardMouseLocationX = 'KPLX',
	p_KESMLPasteboardMouseLocationY = 'KPLY',
};

#endif // __KESMLScriptingDefs_h__
