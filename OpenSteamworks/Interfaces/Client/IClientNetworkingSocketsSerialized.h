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

#ifndef ICLIENTNETWORKINGSOCKETSSERIALIZED_H
#define ICLIENTNETWORKINGSOCKETSSERIALIZED_H
#ifdef _WIN32
#pragma once
#endif

class IClientNetworkingSocketsSerialized
{
public:
    virtual unknown_ret SendP2PRendezvous( CSteamID, uint32, const void*, uint32 ) = 0;
    virtual unknown_ret SendP2PConnectionFailureLegacy() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetCertAsync() = 0;
    virtual unknown_ret CacheRelayTicket( const void*, uint32 ) = 0;
    virtual unknown_ret GetCachedRelayTicketCount() = 0;
    virtual unknown_ret GetCachedRelayTicket( uint32, void*, uint32 ) = 0;
    virtual unknown_ret GetSTUNServer() = 0; //TODO: REVERSE ME
    virtual unknown_ret AllowDirectConnectToPeerString() = 0; //TODO: REVERSE ME
    virtual unknown_ret BeginAsyncRequestFakeIP() = 0; //TODO: REVERSE ME
    virtual unknown_ret AllowDirectConnectToPeerString_2() = 0; // TODO: REVERSE ME
    virtual unknown_ret SetAllowShareIPUserSetting() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetAllowShareIPUserSetting() = 0; //TODO: REVERSE ME
    virtual unknown_ret TEST_ClearInMemoryCachedCredentials() = 0;
};

#endif // ICLIENTNETWORKINGSOCKETSSERIALIZED_H
