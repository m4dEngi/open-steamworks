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

#ifndef ICLIENTSTREAMCLIENT_H
#define ICLIENTSTREAMCLIENT_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"

#define CLIENTSTREAMCLIENT_INTERFACE_VERSION "CLIENTSTREAMCLIENT_INTERFACE_VERSION001"

abstract_class UNSAFE_INTERFACE IClientStreamClient
{
public:
    virtual void Launched( CGameID gameID ) = 0;
    virtual unknown_ret VROverlayCreated() = 0; //TODO: REVERSE ME
    virtual void FocusGained( CGameID gameID, bool ) = 0;
    virtual void FocusLost( CGameID gameID ) = 0;
    virtual void Finished( CGameID gameID, EResult eResult ) = 0;
    virtual bool BGetStreamingClientConfig(CUtlBuffer*) = 0;
    virtual bool BSaveStreamingClientConfig(CUtlBuffer*) = 0;
    virtual unknown_ret SetQualityOverride(int32) = 0;
    virtual unknown_ret SetBitrateOverride(int32) = 0;
    virtual unknown_ret ShowOnScreenKeyboard() = 0; //TODO: REVERSE ME
    virtual unknown_ret BQueueControllerConfigMessageForLocal() = 0; //TODO: REVERSE ME
    virtual unknown_ret BGetControllerConfigMessageForRemote() = 0; //TODO: REVERSE ME
    virtual const char * GetSystemInfo() = 0;
    virtual void StartStreamingSession( CGameID gameID ) = 0;
    virtual void ReportStreamingSessionEvent( CGameID gameID, const char * ) = 0;
    virtual void FinishStreamingSession( CGameID gameID, const char *, const char * ) = 0;
};

#endif // ICLIENTSTREAMCLIENT_H
