//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTHTMLSURFACE_H
#define ICLIENTHTMLSURFACE_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Types/HTMLSurfaceCommon.h"

class CValidator
#ifdef _S4N_
{
	int m_iPadding;
}
#endif
;

abstract_class UNSAFE_INTERFACE IClientHTMLSurface
{
public:
	virtual void __virtualDestructorForCSteamHTMLSurface() = 0;

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual SteamAPICall_t CreateBrowser(const char *pchUserAgent, const char *pchUserCSS) = 0;
	virtual void RemoveBrowser(HHTMLBrowser hBrowser) = 0;

	virtual void AllowStartRequest(HHTMLBrowser hBrowser, bool allowed) = 0;
	virtual void LoadURL(HHTMLBrowser hBrowser, const char *pchURL, const char *pchPostData) = 0;
	virtual void SetSize(HHTMLBrowser hBrowser, uint32 width, uint32 height) = 0;
	virtual void StopLoad(HHTMLBrowser hBrowser) = 0;
	virtual void Reload(HHTMLBrowser hBrowser) = 0;
	virtual void GoBack(HHTMLBrowser hBrowser) = 0;
	virtual void GoForward(HHTMLBrowser hBrowser) = 0;

	virtual void AddHeader(HHTMLBrowser hBrowser, const char *pchKey, const char *pchValue) = 0;
	virtual void ExecuteJavascript(HHTMLBrowser hBrowser, const char *pchJs) = 0;

	virtual void MouseUp(HHTMLBrowser hBrowser, EHTMLMouseButton eMButton) = 0;
	virtual void MouseDown(HHTMLBrowser hBrowser, EHTMLMouseButton eMButton) = 0;
	virtual void MouseDoubleClick(HHTMLBrowser hBrowser, EHTMLMouseButton eMButton) = 0;
	virtual void MouseMove(HHTMLBrowser hBrowser, int32 x, int32 y) = 0;
	virtual void MouseWheel(HHTMLBrowser hBrowser, int32 delta) = 0;
	virtual void KeyDown(HHTMLBrowser hBrowser, uint32 key, EHTMLKeyModifiers eKeyMod, bool bUnk) = 0;
	virtual void KeyUp(HHTMLBrowser hBrowser, uint32 key, EHTMLKeyModifiers eKeyMod) = 0;
	virtual void KeyChar(HHTMLBrowser hBrowser, uint32 key, EHTMLKeyModifiers eKeyMod) = 0;

	virtual void SetHorizontalScroll(HHTMLBrowser hBrowser, uint32 nAbsScrollPx) = 0;
	virtual void SetVerticalScroll(HHTMLBrowser hBrowser, uint32 nAbsScrollPx) = 0;
	virtual void SetKeyFocus(HHTMLBrowser hBrowser, bool hasFocus) = 0;

	virtual void ViewSource(HHTMLBrowser hBrowser) = 0;
	virtual void CopyToClipboard(HHTMLBrowser hBrowser) = 0;
	virtual void PasteFromClipboard(HHTMLBrowser hBrowser) = 0;
	virtual void Find(HHTMLBrowser hBrowser, const char *search, bool currentlyInFind, bool reverse) = 0;
	virtual void StopFind(HHTMLBrowser hBrowser) = 0;
	virtual void GetLinkAtPosition(HHTMLBrowser hBrowser, int32 x, int32 y) = 0;
	virtual void JSDialogResponse(HHTMLBrowser hBrowser, bool result) = 0;
	virtual void FileLoadDialogResponse(HHTMLBrowser hBrowser, const char **selectedFiles) = 0;

	virtual void SetCookie(const char *pchHost, const char *pchKey, const char *pchValue, const char *pchPath = "/", uint32 expires = 0, bool secure = false, bool HTTPOnly = false) = 0;

	virtual void SetPageScaleFactor(HHTMLBrowser hBrowser, float, int, int) = 0;
	virtual void SetBackgroundMode(HHTMLBrowser hBrowser, bool backgroundMode) = 0;
	virtual void SetDPIScalingFactor(HHTMLBrowser hBrowser, float) = 0;

	virtual void OpenDeveloperTools(HHTMLBrowser hBrowser) = 0;
	virtual void Validate(CValidator&, const char*) = 0;
};


#endif // ICLIENTHTMLSURFACE_H
