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

#ifndef ICLIENTSYSTEMMANAGER_H
#define ICLIENTSYSTEMMANAGER_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"

abstract_class UNSAFE_INTERFACE IClientSystemManager
{
public:
    virtual unknown_ret GetSettings() = 0; //TODO: REVERSE ME
    virtual unknown_ret UpdateSettings() = 0; //TODO: REVERSE ME
    virtual unknown_ret ShutdownSystem() = 0;
    virtual unknown_ret SuspendSystem() = 0;
    virtual unknown_ret RestartSystem() = 0;
    virtual unknown_ret GetDisplayBrightness() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetDisplayBrightness() = 0; //TODO: REVERSE ME
    virtual unknown_ret FormatRemovableStorage() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetOSBranchList() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetCurrentOSBranch() = 0; //TODO: REVERSE ME
    virtual unknown_ret SelectOSBranch() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetUpdateState() = 0; //TODO: REVERSE ME
    virtual unknown_ret CheckForUpdate() = 0; //TODO: REVERSE ME
    virtual unknown_ret ApplyUpdate() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetBackgroundUpdateCheckInterval() = 0; //TODO: REVERSE ME
    virtual unknown_ret ClearAudioDefaults() = 0; //TODO: REVERSE ME
    virtual unknown_ret RunDeckMicEnableHack() = 0; //TODO: REVERSE ME
    virtual unknown_ret RunDeckEchoCancellationHack() = 0; //TODO: REVERSE ME
};

#endif // ICLIENTSYSTEMMANAGER_H
