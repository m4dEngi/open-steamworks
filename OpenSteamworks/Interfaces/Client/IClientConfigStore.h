//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code,  comments,  and all related files,  projects,  resources, 
// redistributables included with this project are Copyright Valve Corporation.
// Additionally,  Valve,  the Valve logo,  Half-Life,  the Half-Life logo,  the
// Lambda logo,  Steam,  the Steam logo,  Team Fortress,  the Team Fortress logo, 
// Opposing Force,  Day of Defeat,  the Day of Defeat logo,  Counter-Strike,  the
// Counter-Strike logo,  Source,  the Source logo,  and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTCONFIGSTORE_H
#define ICLIENTCONFIGSTORE_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Types/UtilsCommon.h"

#define CLIENTCONFIGSTORE_INTERFACE_VERSION "CLIENTCONFIGSTORE_INTERFACE_VERSION001"

abstract_class UNSAFE_INTERFACE IClientConfigStore
{
public:
    virtual bool IsSet( EConfigStore eConfigStore, StringView pszKeyNameIn ) = 0;
    virtual bool GetBool( EConfigStore eConfigStore, StringView pszKeyNameIn, bool defaultValue ) = 0;
    virtual int32 GetInt( EConfigStore eConfigStore, StringView pszKeyName, int32 defaultValue ) = 0;
    virtual uint64 GetUint64( EConfigStore eConfigStore, StringView pszKeyName, uint64 defaultValue ) = 0;
    virtual float GetFloat( EConfigStore eConfigStore, StringView pszKeyName, float defaultValue ) = 0;
    virtual const char* GetString( EConfigStore eConfigStore, StringView pszKeyName, StringView defaultValue ) = 0;
    virtual uint32 GetBinary( EConfigStore eConfigStore, StringView pszKeyName, uint8 *pubBuf, uint32 cubBuf ) = 0;
    virtual uint32 GetBinary( EConfigStore eConfigStore, StringView pszKeyName, CUtlBuffer *pUtlBuf) = 0;
    virtual uint32 GetBinaryWatermarked( EConfigStore eConfigStore, StringView pszKeyName, uint8 *pubBuf, uint32 cubBuf ) = 0;
    virtual bool SetBool( EConfigStore eConfigStore, StringView pszKeyNameIn, bool value ) = 0;
    virtual bool SetInt( EConfigStore eConfigStore, StringView pszKeyNameIn, int32 nValue ) = 0;
    virtual bool SetUint64( EConfigStore eConfigStore, StringView pszKeyNameIn, uint64 unValue ) = 0;
    virtual bool SetFloat( EConfigStore eConfigStore, StringView pszKeyNameIn, float flValue ) = 0;
    virtual bool SetString( EConfigStore eConfigStore, StringView pszKeyNameIn, StringView pszValue ) = 0;
    virtual bool SetBinary( EConfigStore eConfigStore, StringView pszKeyName, const uint8 *pubData, uint32 cubData ) = 0;
    virtual bool SetBinaryWatermarked( EConfigStore eConfigStore, StringView pszKeyName, const uint8 *pubData, uint32 cubData ) = 0;
    virtual bool RemoveKey( EConfigStore eConfigStore, StringView pszKeyName ) = 0;
    virtual int32 GetKeySerialized( EConfigStore eConfigStore, StringView pszKeyNameIn, uint8 *pchBuffer, int32 cbBufferMax ) = 0;
    virtual bool FlushToDisk( bool bIsShuttingDown ) = 0;
    virtual unknown_ret GetSubKeyCount() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetSubKeyName() = 0; //TODO: REVERSE ME
};

#endif // ICLIENTCONFIGSTORE_H
