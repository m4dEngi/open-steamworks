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

#ifndef ICLIENTUTILS_H
#define ICLIENTUTILS_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Types/UtilsCommon.h"

abstract_class UNSAFE_INTERFACE IClientUtils
{
public:
    virtual const char* GetInstallPath() = 0;
    virtual const char* GetUserBaseFolderInstallImage() = 0;
    virtual unknown_ret GetUserBaseFolderPersistentStorage() = 0;
    virtual const char* GetManagedContentRoot() = 0;

    // return the number of seconds since the user
    virtual uint32 GetSecondsSinceAppActive() = 0;
    virtual uint32 GetSecondsSinceComputerActive() = 0;
    virtual void SetComputerActive() = 0;

    // the universe this client is connecting to
    virtual EUniverse GetConnectedUniverse() = 0;
    virtual unknown_ret GetSteamRealm() = 0;

    // server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
    virtual uint32 GetServerRealTime() = 0;

    // returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
    // e.g "US" or "UK".
    virtual const char* GetIPCountry() = 0;

    // returns true if the image exists, and valid sizes were filled out
    virtual bool GetImageSize( int32 iImage, uint32 *pnWidth, uint32 *pnHeight ) = 0;

    // returns true if the image exists, and the buffer was successfully filled out
    // results are returned in RGBA format
    // the destination buffer size should be 4 * height * width * sizeof(char)
    virtual bool GetImageRGBA( int32 iImage, uint8 *pubDest, int32 nDestBufferSize ) = 0;

    virtual uint32 GetNumRunningApps() = 0;

    // return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
    virtual uint8 GetCurrentBatteryPower() = 0;
    virtual unknown_ret GetBatteryInformation(int32*, bool*) = 0;


    virtual void SetOfflineMode( bool bOffline ) = 0;
    virtual bool GetOfflineMode() = 0;
    virtual AppId_t SetAppIDForCurrentPipe( AppId_t nAppID, bool bTrackProcess ) = 0;
    virtual AppId_t GetAppID() = 0;
    virtual void SetAPIDebuggingActive( bool bActive, bool bVerbose ) = 0;
    virtual unknown_ret AllocPendingAPICallHandle() = 0;

    // API asynchronous call results
    // can be used directly, but more commonly used via the callback dispatch API (see steam_api.h)
    virtual bool IsAPICallCompleted( SteamAPICall_t hSteamAPICall, bool *pbFailed ) = 0;
    virtual ESteamAPICallFailure GetAPICallFailureReason( SteamAPICall_t hSteamAPICall ) = 0;
    virtual bool GetAPICallResult( SteamAPICall_t hSteamAPICall, void *pCallback, int32 cubCallback, int32 iCallbackExpected, bool *pbFailed ) = 0;
    virtual void SetAPICallResultWithoutPostingCallback(uint64, void const*, int32, int32) = 0;
    virtual bool SignalAppsToShutDown() = 0;
    virtual bool SignalServiceAppsToDisconnect() = 0;
    virtual bool TerminateAllApps(bool bUnk) = 0;
    virtual CellID_t GetCellID() = 0;
    virtual bool BIsGlobalInstance() = 0;

    // Asynchronous call to check if file is signed, result is returned in CheckFileSignature_t
    virtual SteamAPICall_t CheckFileSignature( const char *szFileName ) = 0;
    virtual bool IsSteamClientBeta() = 0;
    virtual uint64 GetBuildID() = 0;
    virtual void SetCurrentUIMode( EUIMode eUIMode ) = 0;
    virtual EUIMode GetCurrentUIMode() = 0;
    virtual bool BIsWebBasedUIMode() = 0;
    virtual void SetDisableOverlayScaling(bool) = 0;
    virtual void ShutdownLauncher( bool, bool ) = 0;
    virtual void SetLauncherType( ELauncherType eLauncherType ) = 0;
    virtual ELauncherType GetLauncherType() = 0;
    virtual bool ShowGamepadTextInput( EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eInputLineMode, const char *szText, uint32 uMaxLength, const char * szUnk ) = 0;
    virtual uint32 GetEnteredGamepadTextLength() = 0;
    virtual bool GetEnteredGamepadTextInput( char *pchValue, uint32 cchValueMax ) = 0;
    virtual void GamepadTextInputClosed( HSteamPipe hSteamPipe, bool, const char * ) = 0;
    virtual void ShowControllerLayoutPreview(int32, uint64) = 0;
    virtual void SetSpew( ESpewGroup eSpewGroup, int32 iSpewLevel, int32 iLogLevel ) = 0;
    virtual bool BDownloadsDisabled() = 0;
    virtual void SetFocusedWindow( CGameID gameID, bool bUnk ) = 0;
    virtual const char* GetSteamUILanguage() = 0;
    virtual void SetLastGameLaunchMethod( EGameLaunchMethod eGameLaunchMethod ) = 0;
    virtual void SetVideoAdapterInfo( int32, int32, int32, int32, int32, int32, const char * ) = 0;
    virtual void SetOverlayWindowFocusForPipe( bool, bool, CGameID gameID ) = 0;
    virtual CGameID GetGameOverlayUIInstanceFocusGameID( bool * pbUnk ) = 0;
    virtual unknown_ret GetFocusedGameWindow() = 0;
    virtual bool SetControllerConfigFileForAppID( AppId_t unAppID, const char * pszControllerConfigFile ) = 0;
    virtual bool GetControllerConfigFileForAppID( AppId_t unAppID, const char * pszControllerConfigFile, uint32 cubControllerConfigFile ) = 0;
    virtual bool IsSteamRunningInVR() = 0;
    virtual void StartVRDashboard() = 0;
    virtual bool IsVRHeadsetStreamingEnabled(uint32 unk) = 0;
    virtual void SetVRHeadsetStreamingEnabled(uint32 unk, bool) = 0;
    virtual unknown_ret GenerateSupportSystemReport() = 0;
    virtual bool GetSupportSystemReport(char*, uint32 unk, uint8* unk_2, uint32 unk_3) = 0;
    virtual AppId_t GetAppIdForPid(uint32 unk, bool bUnk) = 0;
    virtual void SetClientUIProcess() = 0;
    virtual bool BIsClientUIInForeground() = 0;
    virtual void AllowSetForegroundThroughWebhelper(int32) = 0;
    virtual void SetOverlayBrowserInfo(int32, int32, int64, int32, int32, int32, int32, int32) = 0;
    virtual void ClearOverlayBrowserInfo(int32) = 0;

    // function expects buf to be the size of 36 * szStructs
    //
    // first value is Game Overlay PID for current game
    virtual bool GetOverlayBrowserInfo(char* buf, int32 szStructs, int32* success) = 0;

    virtual void SetOverlayNotificationPosition(int32, int32) = 0;
    virtual void SetOverlayNotificationInset(int32, int32, int32) = 0;
    virtual unknown_ret DispatchClientUINotification(EClientUINotificationType eUnk, const char* pcUnk, uint32 uUnk) = 0;
    virtual unknown_ret RespondToClientUINotification(uint32 uUnk, bool bUnk, uint32 uUnk1) = 0;
    virtual unknown_ret DispatchClientUICommand(const char* pcUnk, uint32 uUnk) = 0;
    virtual unknown_ret DispatchComputerActiveStateChange() = 0;
    virtual unknown_ret DispatchOpenURLInClient(const char* pcUnk, uint32 uUnk, bool bUnk) = 0;
    virtual unknown_ret DispatchClearAllBrowsingData() = 0;
    virtual unknown_ret DispatchClientSettingsChanged() = 0;
    virtual unknown_ret DispatchClientPostMessage(const char*, const char*, const char*) = 0;
    virtual unknown_ret IsSteamChina() = 0;
    virtual unknown_ret NeedsSteamChinaWorkshop(uint32) = 0;
    virtual unknown_ret InitFilterText(uint32, uint32) = 0;
    virtual unknown_ret FilterText(uint32, ETextFilteringContext, CSteamID, const char*, char*, uint32) = 0;
    virtual unknown_ret GetIPv6ConnectivityState( ESteamIPv6ConnectivityProtocol ) = 0;
    virtual void ScheduleConnectivityTest(int32, int32, int32) = 0;
    virtual unknown_ret GetConnectivityTestState() = 0;
    virtual const char* GetCaptivePortalURL() = 0;
    virtual unknown_ret RecordSteamInterfaceCreation( const char*, const char* ) = 0;
    virtual unknown_ret GetCloudGamingPlatform() = 0;
    virtual unknown_ret BGetMacAddresses(uint64*, uint32, uint32*) = 0;
    virtual unknown_ret BGetDiskSerialNumber(char*, int32) = 0;
    virtual unknown_ret GetSteamEnvironmentForApp(uint32, char*, uint32) = 0;
    virtual unknown_ret TestHTTP(const char*) = 0;
    virtual unknown_ret DumpJobs(const char*) = 0;
    virtual bool ShowFloatingGamepadTextInput(int32, int32, int32, int32, int32, int32) = 0;
    virtual bool DismissFloatingGamepadTextInput(int32) = 0;
    virtual bool DismissGamepadTextInput(int32) = 0;
    virtual void FloatingGamepadTextInputDismissed() = 0;
    virtual void SetGameLauncherMode(int32, bool) = 0;
    virtual void ClearAllHTTPCaches() = 0;
    virtual unknown_ret GetFocusedGameID() = 0;
    virtual uint32 GetFocusedWindowPID() = 0;

    // int32 is probably a pointer to buffer or int passed by value
    virtual void SetWebUITransportWebhelperPID(int32) = 0;
    virtual void GetWebUITransportInfo(int32 iUnk) = 0;
    virtual void RecordFakeReactRouteMetric(int32 iUnk) = 0;
    virtual unknown_ret SteamRuntimeSystemInfo(int32 iUnk) = 0;
    virtual void DumpHTTPClients(int32 iUnk) = 0;
    virtual bool BGetMachineID(int32 iUnk) = 0;
    virtual void NotifyMissingInterface(int32 iUnk) = 0;

    virtual bool IsSteamInTournamentMode() = 0;
    virtual void DesktopLockedStateChanged(bool) = 0;
    virtual void ScheduleBootReserveJob() = 0;
    virtual unknown_ret GetGameFrameRateReportFrequency() = 0;
    virtual void ReportGameFrameRate(int32, int32, int32, int32) = 0;
};

#endif // ICLIENTUTILS_H
