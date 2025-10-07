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

#ifndef REMOTECLIENTCOMMON_H
#define REMOTECLIENTCOMMON_H

#define STEAMREMOTEPLAY_INTERFACE_VERSION "STEAMREMOTEPLAY_INTERFACE_VERSION001"

enum ESteamDeviceFormFactor
{
    k_ESteamDeviceFormFactorUnknown,    // The device form factor isn't available.
    k_ESteamDeviceFormFactorPhone,      // The device is a phone or other small handheld device with touchscreen.
    k_ESteamDeviceFormFactorTablet,     // The device is a tablet or other large handheld device with a touchscreen.
    k_ESteamDeviceFormFactorComputer,   // The device is a desktop computer or laptop.
    k_ESteamDeviceFormFactorTV          // The device is a TV.
};

enum ERemoteClientStreamEnv
{

};

enum ERemoteClientLaunchResult
{
    k_ERemoteClientLaunchResultOK = 1,
    k_ERemoteClientLaunchResultFail = 2,
    k_ERemoteClientLaunchResultRequiresUI = 3,
    k_ERemoteClientLaunchResultRequiresLaunchOption = 4,
    k_ERemoteClientLaunchResultRequiresEULA = 5,
    k_ERemoteClientLaunchResultTimeout = 6,
    k_ERemoteClientLaunchResultStreamTimeout = 7,
    k_ERemoteClientLaunchResultStreamClientFail = 8,
    k_ERemoteClientLaunchResultOtherGameRunning = 9,
    k_ERemoteClientLaunchResultDownloadStarted = 10,
    k_ERemoteClientLaunchResultDownloadNoSpace = 11,
    k_ERemoteClientLaunchResultDownloadFiltered = 12,
    k_ERemoteClientLaunchResultDownloadRequiresUI = 13,
    k_ERemoteClientLaunchResultAccessDenied = 14,
    k_ERemoteClientLaunchResultNetworkError = 15,
    k_ERemoteClientLaunchResultProgress = 16,
    k_ERemoteClientLaunchResultParentalUnlockFailed = 17,
    k_ERemoteClientLaunchResultScreenLocked = 18,
    k_ERemoteClientLaunchResultUnsupported = 19,
    k_ERemoteClientLaunchResultDisabledLocal = 20,
    k_ERemoteClientLaunchResultDisabledRemote = 21,
    k_ERemoteClientLaunchResultBroadcasting = 22,
    k_ERemoteClientLaunchResultBusy = 23,
    k_ERemoteClientLaunchResultDriversNotInstalled = 24,
    k_ERemoteClientLaunchResultTransportUnavailable = 25,
    k_ERemoteClientLaunchResultCanceled = 26,
    k_ERemoteClientLaunchResultInvisible = 27,
    k_ERemoteClientLaunchResultRestrictedCountry = 28
};

enum EClientUsedInputType
{
    k_EClientUsedInputTypeKeyboard,
    k_EClientUsedInputTypeMouse,
    k_EClientUsedInputTypeController,
    k_EClientUsedInputTypeMax
};

#pragma pack( push, 1 )

struct RemotePlayPlayer_t
{
    CSteamID m_playerID;
    uint32   m_unGuestID;
    uint32   m_unOverlayPIDGroupID;
    uint64   m_ullUnk2;
    uint64   m_ullUnk3;
    uint32   m_uUnk1;
};

#pragma pack( pop )

#pragma pack( push, 8 )

struct RemoteClientReservedGamepad_t
{

};

struct RemoteClientInputSettings_t
{

};

// k_iClientRemoteClientManager Callbacks

struct RemoteClientStartStreamSession_t
{
    enum { k_iCallback = k_iClientRemoteClientManagerCallbacks + 11 };

    uint32 m_unStreamingSessionID;
    RemotePlayPlayer_t m_player;
    CGameID m_GameID;

    bool m_bRemotePlayTogether;
    bool m_bEnableVideoStreaming;
    bool m_bEnableAudioStreaming;
    bool m_bEnableInputStreaming;
    bool m_bRestrictedSession;

    char m_szRemoteIP[64];
    uint8 m_rgubAuthToken[32];
    uint32 m_cubAuthToken;

    char m_szDeviceName[128];
    char m_szDeviceVersion[128];
    ESteamDeviceFormFactor m_eDeviceFormFactor;
    int32 m_nAudioChannels;
    int32 m_nGamepads;
    int32 m_nMaximumResolutionX;
    int32 m_nMaximumResolutionY;
    int32 m_eTransport;
    char m_szRelayServer[128];
};

struct RemoteClientStopStreamSession_t
{
    enum { k_iCallback = k_iClientRemoteClientManagerCallbacks + 12 };

    uint32 m_unStreamingSessionID;
    RemotePlayPlayer_t m_player;
};

struct RemotePlayInviteResult_t
{
    enum { k_iCallback = k_iClientRemoteClientManagerCallbacks + 28 };

    RemotePlayPlayer_t m_player;
    ERemoteClientLaunchResult m_eResult;
    CGameID m_nGameID;
    char m_szConnectURL[1024];
};

#pragma pack( pop )

#endif // REMOTECLIENTCOMMON_H
