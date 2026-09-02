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

#ifndef ICLIENTSHORTCUTS_H
#define ICLIENTSHORTCUTS_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"

#define CLIENTSHORTCUTS_INTERFACE_VERSION "CLIENTSHORTCUTS_INTERFACE_VERSION001"

#pragma pack( push, 8 )

struct ShortcutChanged_t
{
    enum { k_iCallback = k_iClientShortcutsCallbacks + 1 };

    AppId_t m_nAppID;
    bool m_bRemote;
};

struct ShortcutRemoved_t
{
    enum { k_iCallback = k_iClientShortcutsCallbacks + 2 };

    AppId_t m_nAppID;
    bool m_bRemote;
};

#pragma pack( pop )

abstract_class UNSAFE_INTERFACE IClientShortcuts
{
public:
    virtual uint32 GetUniqueLocalAppId() = 0;
    virtual CGameID GetGameIDForAppID( AppId_t unAppID ) = 0;
    virtual unknown_ret GetDevkitAppIDByDevkitGameID( const char * pchUnk) = 0;
    virtual unknown_ret GetShortcutAppIds() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetShortcutInfos() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetShortcutInfoByAppID() = 0; //TODO: REVERSE ME
    virtual AppId_t AddShortcut( const char *szShortcutName, const char *szShortcutExe, const char *szUnk1, const char *szUnk2, const char *szhUnk3) = 0;
    virtual uint32 AddTemporaryShortcut( const char *, const char *, const char * ) = 0;
    virtual uint32 AddOpenVRShortcut( const char *, const char *, const char * ) = 0;
    virtual void SetShortcutFromFullpath( AppId_t unAppID, const char * szPath ) = 0;
    virtual void SetShortcutAppName( AppId_t unAppID, const char * szAppName ) = 0;
    virtual void SetShortcutExe( AppId_t unAppID, const char * szExePath ) = 0;
    virtual void SetShortcutStartDir( AppId_t unAppID, const char * szPath ) = 0;
    virtual void SetShortcutIcon( AppId_t unAppID, const char * szIconPath ) = 0;
    virtual void SetShortcutCommandLine( AppId_t unAppID, const char * szCommandLine ) = 0;
    virtual void SetShortcutHidden( AppId_t unAppID, bool ) = 0;
    virtual void SetAllowDesktopConfig( uint32, bool ) = 0;
    virtual void SetAllowOverlay( AppId_t unAppID, bool ) = 0;
    virtual void SetOpenVRShortcut( uint32, bool ) = 0;
    virtual unknown_ret SetShortcutSortAs() = 0; //TODO: REVERSE ME
    virtual void SetDevkitShortcut( uint32 uUnk, const char * pchUnk ) = 0;
    virtual unknown_ret SetFlatpakAppID() = 0; //TODO: REVERSE ME
    virtual void RemoveShortcut( AppId_t unAppID ) = 0;
    virtual void RemoveAllTemporaryShortcuts() = 0;
    virtual bool LaunchShortcut( AppId_t unAppID, uint32 uUnk ) = 0;
    virtual unknown_ret GetAppIDByExeName() = 0; //TODO: REVERSE ME
};

#endif // ICLIENTSHORTCUTS_H
