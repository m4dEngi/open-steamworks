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

#ifndef ICLIENTNETWORKDEVICEMANAGER_H
#define ICLIENTNETWORKDEVICEMANAGER_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Types/AppsCommon.h"

enum ENetworkDeviceState
{
    // TODO : Reverse this enum
};

enum EWirelessSecurityFlags
{
    // TODO : Reverse this enum
};

struct WirelessAccessPoint_t
{
    // TODO : Reverse this struct
};

struct WirelessCredentials_t
{
    // TODO : Reverse this struct
};

struct NetworkDevicesData_t
{
    // TODO : Reverse this struct
};

enum ENetworkDeviceManagerError
{
    // TODO: Reverse this enum
};

#define CLIENTNETWORKDEVICEMANAGER_INTERFACE_VERSION "CLIENTNETWORKDEVICEMANAGER_INTERFACE_VERSION001"

abstract_class UNSAFE_INTERFACE IClientNetworkDeviceManager
{
public:
    virtual bool IsInterfaceValid() = 0;
    virtual void RefreshDevices() = 0;
    virtual unknown_ret GetNetworkDevicesData(NetworkDevicesData_t*) = 0;
    virtual unknown_ret ConnectToDevice(uint32, uint32, const char*, const char*, uint32, bool, bool) = 0;
    virtual unknown_ret DisconnectFromDevice(uint32) = 0;
    virtual unknown_ret SetDeviceOptions() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetWifiEnabled(bool) = 0;
    virtual unknown_ret SetWifiScanningEnabled(bool) = 0;
    virtual unknown_ret ForgetWirelessEndpoint(uint32, uint32) = 0;
    virtual unknown_ret SetCustomIPSettings(uint32, uint32, uint32, uint32, uint32, uint32) = 0;
    virtual unknown_ret GetCustomIPSettings(uint32, uint32*, uint32*, uint32*, uint32*, uint32*) = 0;
    virtual unknown_ret SetProxyInfo() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetProxyInfo() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetObviousConnectivityProblem() = 0; //TODO: REVERSE ME
    virtual unknown_ret TEST_SetFakeLocalSystemStateSetting() = 0; //TODO: REVERSE ME
    virtual unknown_ret TEST_GetFakeLocalSystemStateSetting() = 0; //TODO: REVERSE ME
    virtual unknown_ret TEST_GetFakeLocalSystemEffectiveState() = 0; //TODO: REVERSE ME
    virtual unknown_ret TEST_SetEmulateSingleWirelessDevice() = 0; //TODO: REVERSE ME
    virtual unknown_ret TEST_GetEmulateSingleWirelessDevice() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_EnumerateNetworkDevices() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDeviceType() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_IsCurrentDevice() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_IsCurrentlyConnected() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDeviceIP4() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDeviceBroadcastIP4() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDeviceIPV6InterfaceIndex() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDeviceVendor() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDeviceProduct() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetMacAddress() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetSubnetMaskBitCount() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetRouterAddressIP4() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDNSResolversIP4() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDeviceState() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetDevicePluggedState() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_EnumerateWirelessEndpoints() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetConnectedWirelessEndpointSSID() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetWirelessSecurityCapabilities() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetWirelessEndpointSSIDUserDisplayString() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetWirelessEndpointStrength() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_IsSecurityRequired() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_GetCachedWirelessCredentials() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_IsWirelessEndpointForgettable() = 0; //TODO: REVERSE ME
    virtual unknown_ret LEGACY_IsUsingDHCP() = 0; //TODO: REVERSE ME
};

#endif // ICLIENTNETWORKDEVICEMANAGER_H
