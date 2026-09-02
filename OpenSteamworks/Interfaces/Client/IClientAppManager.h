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

#ifndef ICLIENTAPPMANAGER_H
#define ICLIENTAPPMANAGER_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Types/AppsCommon.h"

class StringView;

abstract_class UNSAFE_INTERFACE IClientAppManager
{
public:
    virtual EAppUpdateError InstallApp( AppId_t unAppID, int32 iBaseFolder, bool bLegacy ) = 0;
    virtual EAppUpdateError UninstallApp( AppId_t unAppID ) = 0;
    virtual EAppUpdateError LaunchApp( CGameID gameID, uint32 uLaunchOption, uint32 eLaunchSource, const char *pszUserArgs ) = 0;
    virtual bool ShutdownApp( AppId_t unAppID, bool bForce ) = 0;
    virtual EAppState GetAppInstallState( AppId_t unAppID ) = 0;
    virtual uint64 GetAppInstallDir( AppId_t unAppID, char *pchPath, uint32 cchPath ) = 0;
    virtual unknown_ret GetAppContentInfo( AppId_t unAppID, bool, uint32*, uint32*, uint64*, uint64* ) = 0;
    virtual unknown_ret GetAppStagingInfo() = 0; //TODO: REVERSE ME
    virtual unknown_ret BGetContentInfoForApps() = 0; //TODO: REVERSE ME
    virtual bool IsAppDlcInstalled( AppId_t unAppID, AppId_t unDLCAppID ) = 0;
    virtual bool GetDlcDownloadProgress( AppId_t unAppID, AppId_t unDLCAppID, uint64* lluUnk1, uint64* lluUnk2 ) = 0;
    virtual bool BIsDlcEnabled(AppId_t unAppID, uint32, bool*) = 0;
    virtual void SetDlcEnabled(AppId_t unAppID, uint32, bool) = 0;
    virtual unknown_ret SetDlcContext() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetDlcSizes() = 0; //TODO: REVERSE ME
    virtual uint32 GetNumInstalledApps() = 0;
    virtual uint32 GetInstalledApps( uint32 *punAppIDs, uint32 cAppIDsMax ) = 0;
    virtual unknown_ret BIsWaitingForInstalledApps() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetAppDependencies( AppId_t unAppID, AppId_t* unAppIDs, uint32 uUnk) = 0;
    virtual uint32 GetDependentApps( AppId_t unAppID, AppId_t *punAppIDs, int32 cAppIDsMax ) = 0;
    virtual uint32 GetUpdateInfo( AppId_t unAppID, AppUpdateInfo_s *pUpdateInfo ) = 0;
    virtual bool BIsAppUpToDate( AppId_t unAppID ) = 0;
    virtual uint32 GetAvailableLanguages( AppId_t unAppID, bool, char *pchLanguages, uint32 cchLanguagesMax ) = 0;
    virtual unknown_ret GetCurrentLanguage( AppId_t unAppID, char*, uint32 ) = 0;
    virtual unknown_ret GetCurrentLanguage( AppId_t unAppID ) = 0;
    virtual unknown_ret GetFallbackLanguage( AppId_t unAppID, ELanguage) = 0;
    virtual unknown_ret SetCurrentLanguage( AppId_t unAppID, ELanguage) = 0;
    virtual bool StartValidatingApp( AppId_t unAppID ) = 0;
    virtual bool CancelValidation( AppId_t unAppID ) = 0;
    virtual bool MarkContentCorrupt( AppId_t unAppID, bool bCorrupt ) = 0;
    virtual uint32 GetInstalledDepots( AppId_t unAppID, AppId_t puDepots[], uint32 cuDepotsMax ) = 0;
    virtual unknown_ret GetFileDetails(AppId_t unAppID, const char *pchUnk) = 0;
    virtual unknown_ret VerifySignedFiles(AppId_t unAppID) = 0;
    virtual unknown_ret GetNumBetas() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetBetaInfo() = 0; //TODO: REVERSE ME
    virtual bool CheckBetaPassword( AppId_t unAppID, char const*) = 0;
    virtual unknown_ret SetActiveBeta() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetActiveBeta( AppId_t unAppID, char*, int32) = 0;
    virtual bool BGetActiveBetaForApps( uint32* puUnk, int32 iUnk, char* pcUnk, int32 iUnk2) = 0;
    virtual bool SetDownloadingEnabled( bool ) = 0;
    virtual bool BIsDownloadingEnabled() = 0;
    virtual bool GetDownloadStats( DownloadStats_s *pDownloadStats ) = 0;
    virtual AppId_t GetDownloadingAppID() = 0;
    virtual bool GetAutoUpdateTimeRestrictionEnabled() = 0;
    virtual void SetAutoUpdateTimeRestrictionEnabled(bool) = 0;
    virtual bool GetAutoUpdateTimeRestrictionHours(int32 * piUnk1, int32 * piUnk2) = 0;
    virtual bool SetAutoUpdateTimeRestrictionStartHour(int32 iUnk) = 0;
    virtual bool SetAutoUpdateTimeRestrictionEndHour(int32 iUnk) = 0;
    virtual EAppAutoUpdateBehavior GetAppAutoUpdateBehavior( AppId_t unAppID ) = 0;
    virtual bool SetAppAutoUpdateBehavior( AppId_t unAppID, EAppAutoUpdateBehavior eAppAutoUpdateBehavior ) = 0;
    virtual unknown_ret SetGlobalAppUpdateBehavior() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetGlobalAppUpdateBehavior() = 0; //TODO: REVERSE ME
    virtual bool SetAppAllowDownloadsWhileRunningBehavior( AppId_t unAppID, EAppAllowDownloadsWhileRunningBehavior eAppAllowDownloadsWhileRunningBehavior ) =0;
    virtual EAppAllowDownloadsWhileRunningBehavior GetAppAllowDownloadsWhileRunningBehavior( AppId_t unAppID ) = 0;
    virtual void SetAllowDownloadsWhileAnyAppRunning( bool bAllowDownloadsWhileAnyAppRunning ) = 0;
    virtual bool BAllowDownloadsWhileAnyAppRunning() = 0;
    virtual bool ChangeAppDownloadQueuePlacement( AppId_t unAppID, EAppDownloadQueuePlacement eAppDownloadQueuePlacement ) = 0;
    virtual unknown_ret SetAppDownloadQueueIndex( AppId_t unAppID, int32 iUnk ) = 0;
    virtual int32 GetAppDownloadQueueIndex( AppId_t unAppID ) = 0;
    virtual int32 GetAppAutoUpdateDelayedUntilTime( AppId_t unAppID ) = 0;
    virtual int32 GetNumAppsInDownloadQueue() = 0;
    virtual bool BHasLocalContentServer() = 0;
    virtual bool BuildBackup( AppId_t unAppID, uint64 ullMaxFileSize, const char *cszBackupPath ) = 0;
    virtual bool BuildInstaller( const char *cszProjectFile, const char *cszBackupPath, const char *, const char * ) = 0;
    virtual bool CancelBackup() = 0;
    virtual EAppUpdateError RestoreAppFromBackup( AppId_t unAppID, const char *cszBackupPath ) = 0;
    virtual unknown_ret RecoverAppFromFolder( AppId_t unAppID, const char *cszUnk  ) = 0;
    virtual bool CanMoveApp( AppId_t unAppID ) = 0;
    virtual unknown_ret MoveApp( AppId_t unAppID, int32 unk ) = 0;
    virtual bool GetMoveAppProgress( AppId_t unAppID, uint64* unk_1, uint64* unk_2, uint32* unk_3) = 0;
    virtual bool CancelMoveApp( AppId_t unAppID ) = 0;
    virtual bool GetAppStateInfo( AppId_t unAppID, AppStateInfo_s* ) = 0;
    virtual unknown_ret BGetAppStateInfoForApps() = 0; //TODO: REVERSE ME
    virtual bool BCanRemotePlayTogether( AppId_t unAppID ) = 0;
    virtual bool BIsLocalMultiplayerApp( AppId_t unAppID ) = 0;
    virtual int32 GetNumLibraryFolders() = 0;
    virtual int32 GetLibraryFolderPath( int32 iBaseFolder, char *pchPath, int32 cbPath ) = 0;
    virtual int32 AddLibraryFolder( const char *szPath, const char* cUnk ) = 0;
    virtual unknown_ret SetLibraryFolderLabel() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetLibraryFolderLabel() = 0; //TODO: REVERSE ME
    virtual unknown_ret RemoveLibraryFolder() = 0; //TODO: REVERSE ME
    virtual bool BGetLibraryFolderInfo( int32 iBaseFolder, bool*, uint64*, uint64*) = 0;
    virtual int32 GetAppLibraryFolder( AppId_t unAppID ) = 0;
    virtual unknown_ret RefreshLibraryFolders() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetNumAppsInFolder() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetAppsInFolder() = 0; //TODO: REVERSE ME
    virtual void ForceInstallDirOverride( const char *cszPath ) = 0;
    virtual unknown_ret SetDebugInstallDir() = 0; //TODO: REVERSE ME
    virtual bool SetDownloadThrottleRateKbps( int32 iRate, bool ) = 0;
    virtual int32 GetDownloadThrottleRateKbps( bool ) = 0;
    virtual void SuspendDownloadThrottling( bool bSuspend ) = 0;
    virtual void SetThrottleDownloadsWhileStreaming( bool ) = 0;
    virtual bool BThrottleDownloadsWhileStreaming() = 0;
    virtual const char * GetLaunchQueryParam( AppId_t unAppID, const char * pchKey ) = 0;
    virtual void BeginLaunchQueryParams( AppId_t unAppId ) = 0;
    virtual void SetLaunchQueryParam( AppId_t unAppId, const char * pchKey, const char * pchValue ) = 0;
    virtual bool CommitLaunchQueryParams( AppId_t unAppId, const char * pchUnk) = 0;
    virtual unknown_ret GetLaunchCommandLine( AppId_t unAppId, char * pchUnk, int32 iUnk) = 0;
    virtual unknown_ret AllowExternalArguments() = 0; //TODO: REVERSE ME
    virtual void AddContentLogLine( StringView ) = 0;
    virtual unknown_ret SetUseHTTPSForDownloads(bool) = 0;
    virtual unknown_ret GetUseHTTPSForDownloads() = 0;
    virtual unknown_ret SetPeerContentServerMode() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetPeerContentClientMode() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetPeerContentServerMode() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetPeerContentClientMode() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetPeerContentServerStats() = 0; //TODO: REVERSE ME
    virtual unknown_ret SuspendPeerContentClient() = 0; //TODO: REVERSE ME
    virtual unknown_ret SuspendPeerContentServer() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetPeerContentServerForApp() = 0; //TODO: REVERSE ME
    virtual unknown_ret NotifyDriveAdded() = 0; //TODO: REVERSE ME
    virtual unknown_ret NotifyDriveRemoved() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetAudioDownloadQuality() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetGamePerformanceSetting() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetGameRenderResolution() = 0; //TODO: REVERSE ME
};

#endif // ICLIENTAPPMANAGER_H
