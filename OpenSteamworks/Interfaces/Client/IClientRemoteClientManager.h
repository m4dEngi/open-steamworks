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

#ifndef ICLIENTREMOTECLIENTMANAGER_H
#define ICLIENTREMOTECLIENTMANAGER_H

#include "Types/RemoteClientCommon.h"

class IClientRemoteClientManager
{
public:
	virtual unknown_ret SetUIReadyForStream(bool) = 0;
	virtual unknown_ret StreamingAudioPreparationComplete(bool) = 0;
	virtual unknown_ret StreamingAudioFinished() = 0;
	virtual unknown_ret ProcessStreamAvailable(uint32, uint32) = 0;
	virtual unknown_ret ProcessStreamShutdown(uint32) = 0;
	virtual unknown_ret UpdateStreamClientResolution(uint32, int32, int32) = 0;
	virtual unknown_ret ProcessStreamClientConnected(uint32, RemotePlayPlayer_t, ESteamDeviceFormFactor) = 0;
	virtual unknown_ret GetStreamClientPlayer(uint32) = 0;
	virtual unknown_ret GetStreamClientFormFactor(uint32) = 0;
	virtual unknown_ret UpdateStreamClientNetworkUtilization(uint32, float, float) = 0;
	virtual unknown_ret ProcessStreamClientDisconnected(uint32) = 0;
	virtual bool BGetStreamTransportSignal(uint32, CUtlBuffer*) = 0;
	virtual unknown_ret SendStreamTransportSignal(uint32, CUtlBuffer const*) = 0;
	virtual unknown_ret ConnectToRemote(uint64) = 0;
	virtual unknown_ret ConnectToRemoteAddress(const char*) = 0;
	virtual unknown_ret RefreshRemoteClients(bool) = 0;
	virtual unknown_ret GetClientPlatformTypes() = 0;
	virtual unknown_ret GetRemoteClientCount() = 0;
	virtual unknown_ret GetRemoteClientIDByIndex(uint32) = 0;
	virtual unknown_ret GetRemoteClientNameByIndex(uint32) = 0;
	virtual unknown_ret GetRemoteClientConnectStateByIndex(uint32) = 0;
	virtual bool BRemoteClientHasStreamingSupportedByIndex(uint32) = 0;
	virtual bool BRemoteClientHasStreamingEnabledByIndex(uint32) = 0;
	virtual unknown_ret GetRemoteClientAppStateByIndex(uint32, uint32) = 0;
	virtual unknown_ret GetRemoteClientConnectedCount() = 0;
	virtual unknown_ret GetRemoteClientStreamingEnabledCount() = 0;
	virtual unknown_ret GetRemoteClientName(uint64) = 0;
	virtual bool BRemoteClientStreaming(uint64) = 0;
	virtual unknown_ret GetRemoteClientStreamingSession(uint64) = 0;
	virtual unknown_ret GetRemoteClientFormFactor(uint64) = 0;
	virtual bool BRemoteClientCanSteamVR(uint64) = 0;
	virtual unknown_ret GetRemoteClientConnectState(uint64) = 0;
	virtual bool BRemoteClientHasStreamingSupported(uint64) = 0;
	virtual bool BRemoteClientHasStreamingEnabled(uint64) = 0;
	virtual unknown_ret GetRemoteClientAppAvailability(uint64, uint32) = 0;
	virtual unknown_ret GetRemoteClientAppState(uint64, uint32) = 0;
	virtual unknown_ret GetRemoteDeviceCount() = 0;
	virtual unknown_ret GetRemoteDeviceIDByIndex(uint32) = 0;
	virtual unknown_ret GetRemoteDeviceNameByIndex(uint32) = 0;
	virtual unknown_ret GetRemoteDeviceName(uint64) = 0;
	virtual bool BRemoteDeviceStreaming(uint64) = 0;
	virtual unknown_ret GetRemoteDeviceStreamingSession(uint64) = 0;
	virtual unknown_ret GetRemoteDeviceFormFactor(uint64) = 0;
	virtual unknown_ret UnpairRemoteDevices() = 0;
	virtual bool BIsStreamingSupported() = 0;
	virtual bool BIsStreamingDisabledBySystemPolicy() = 0;
	virtual bool BIsStreamingEnabled() = 0;
	virtual unknown_ret SetStreamingEnabled(bool) = 0;
	virtual unknown_ret StartStream(uint64, uint32, int32, ERemoteClientStreamEnv, RemoteClientReservedGamepad_t const*, int32) = 0;
	virtual bool BIsRemoteLaunch(CGameID) = 0;
	virtual bool BIsBigPictureActiveForStreaming() = 0;
	virtual bool BIsStreamingSessionActive() = 0;
	virtual bool BIsStreamingSessionActiveForGame(CGameID) = 0;
	virtual bool BIsStreamingClientConnected() = 0;
	virtual bool BStreamingClientWantsRecentGames() = 0;
	virtual unknown_ret StopStreamingSession(uint32) = 0;
	virtual unknown_ret LaunchAppProgress(uint32, const char*, const char*, int32, int32) = 0;
	virtual unknown_ret LaunchAppResult(uint32, ERemoteClientLaunchResult) = 0;
	virtual bool BIsStreamStartInProgress(uint64, uint32) = 0;
	virtual unknown_ret LaunchAppResultRequestLaunchOption(uint32, int32 const*, int32) = 0;
	virtual unknown_ret AcceptEULA(uint64, uint32, char const*, uint32) = 0;
	virtual unknown_ret GetRemoteClientPlatformName(uint64, bool*) = 0;
	virtual bool BIsStreamClientRunning() = 0;
	virtual bool BIsStreamClientRunning(CGameID) = 0;
	virtual bool BIsStreamClientRunningConnectedToClient(CGameID, uint64) = 0;
	virtual bool BIsStreamClientRemotePlayTogether() = 0;
	virtual bool BGetStreamingClientConfig(CUtlBuffer*) = 0;
	virtual bool BSetStreamingClientConfig(CUtlBuffer*) = 0;
	virtual bool BQueueControllerConfigMessageForRemote(void* unk) = 0;
	virtual bool BGetControllerConfigMessageForLocal(void* unk) = 0;
	virtual unknown_ret RequestControllerConfig(uint64, uint32, uint32) = 0;
	virtual unknown_ret PostControllerConfig(uint64, const uint8*, uint32) = 0;
	virtual unknown_ret GetControllerConfig(uint64, uint8*, uint32) = 0;
	virtual unknown_ret SetRemoteDeviceAuthorized(bool, const char*) = 0;
	virtual unknown_ret SetStreamingDriversInstalled(bool) = 0;
	virtual unknown_ret SetStreamingPIN(const char*) = 0;
	virtual unknown_ret GetStreamingPINSize(int32*) = 0;
    virtual unknown_ret CancelRemoteClientPairing(uint64) = 0;
	virtual unknown_ret UsedVideoX264() = 0;
	virtual unknown_ret UsedVideoH264() = 0;
	virtual unknown_ret UsedVideoHEVC() = 0;
	virtual unknown_ret SetRemotePlayTogetherQualityOverride(int32) = 0;
	virtual unknown_ret SetRemotePlayTogetherBitrateOverride(int32) = 0;
	virtual bool BHasRemotePlayInviteAndSession(RemotePlayPlayer_t) = 0;
	virtual bool BCreateRemotePlayGroup(void* unk) = 0;
    virtual bool BCreateRemotePlayInviteAndSession(RemotePlayPlayer_t friendID, AppId_t appID) = 0;
	virtual unknown_ret CancelRemotePlayInviteAndSession(RemotePlayPlayer_t) = 0;
	virtual unknown_ret JoinRemotePlaySession(CSteamID, const char*) = 0;
	virtual bool BStreamingDesktopToRemotePlayTogetherEnabled() = 0;
	virtual unknown_ret SetStreamingDesktopToRemotePlayTogetherEnabled(bool) = 0;
	virtual unknown_ret GetStreamingSessionForRemotePlayer(RemotePlayPlayer_t) = 0;
	virtual unknown_ret SetPerUserKeyboardInputEnabled(RemotePlayPlayer_t, bool) = 0;
	virtual unknown_ret SetPerUserMouseInputEnabled(RemotePlayPlayer_t, bool) = 0;
	virtual unknown_ret SetPerUserControllerInputEnabled(RemotePlayPlayer_t, bool) = 0;
	virtual unknown_ret GetPerUserInputSettings(RemotePlayPlayer_t, RemoteClientInputSettings_t*) = 0;
	virtual unknown_ret GetClientInputSettings(RemotePlayPlayer_t, RemoteClientInputSettings_t*) = 0;
	virtual unknown_ret OnClientUsedInput(RemotePlayPlayer_t, EClientUsedInputType) = 0;
	virtual unknown_ret OnPlaceholderStateChanged(bool) = 0;
	virtual unknown_ret OnRemoteClientRemotePlayClearControllers() = 0;
	virtual unknown_ret OnRemoteClientRemotePlayControllerIndexSet(RemotePlayPlayer_t, uint32) = 0;
	virtual unknown_ret UpdateRemotePlayTogetherGroup() = 0;
	virtual unknown_ret DisbandRemotePlayTogetherGroup() = 0;
	virtual unknown_ret OnRemotePlayUIMovedController() = 0;
	virtual unknown_ret OnSendRemotePlayTogetherInvite(CSteamID, uint32) = 0;
	virtual void ShowRemotePlayTogetherUI(AppId_t) = 0;
	virtual unknown_ret GetCloudGameTimeRemaining(CGameID, uint64) = 0;
	virtual unknown_ret ShutdownStreamClients(bool) = 0;
};

#endif // ICLIENTREMOTECLIENTMANAGER_H
