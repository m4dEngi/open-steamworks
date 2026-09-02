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

#ifndef ICLIENTSHAREDCONNECTION_H
#define ICLIENTSHAREDCONNECTION_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SharedConnectionCommon.h"

abstract_class UNSAFE_INTERFACE IClientSharedConnection
{
public:
    virtual HSharedConnection AllocateSharedConnection() = 0;
    virtual void ReleaseSharedConnection(HSharedConnection hConn) = 0;
    virtual int32 SendMessage(HSharedConnection hConn, void* pBuf, size_t szBuf) = 0;
    virtual int32 SendMessageAndAwaitResponse(HSharedConnection hConn, void* pBuf, size_t szBuf) = 0;
    virtual void RegisterEMsgHandler(HSharedConnection hConn, uint32 eMsg) = 0;
    // some service methods used by client
    // "FriendsListClient.FavoritesChanged#1"
    // "FriendMessagesClient.IncomingMessage#1"
    // "FriendMessagesClient.NotifyAckMessageEcho#1"
    // "ChatRoomClient.NotifyIncomingChatMessage#1"
    // "ChatRoomClient.NotifyChatRoomHeaderStateChange#1"
    // "ChatRoomClient.NotifyMemberStateChange#1"
    // "ChatRoomClient.NotifyChatRoomGroupRoomsChange#1"
    // "ChatRoomClient.NotifyChatGroupUserStateChanged#1"
    // "ChatRoomClient.NotifyAckChatMessageEcho#1"
    // "ChatRoomClient.NotifyShouldRejoinChatRoomVoiceChat#1"
    // "ParentalClient.NotifyLock#1"
    // "ParentalClient.NotifyUnlock#1"
    // "ParentalClient.NotifySettingsChange#1"
    // "PlayerClient.NotifyCommunityPreferencesChanged#1"
    // "PlayerClient.NotifyFriendNicknameChanged#1"
    // "WebRTCClientNotifications.NotifyWebRTCUpdateRemoteDescription#1"
    // "WebRTCClientNotifications.NotifyWebRTCSessionConnected#1"
    // "VoiceChatClient.NotifyAllUsersVoiceStatus#1"
    // "VoiceChatClient.NotifyUserVoiceStatus#1"
    // "VoiceChatClient.NotifyOneOnOneChatResponse#1"
    // "VoiceChatClient.NotifyOneOnOneChatRequested#1"
    // "VoiceChatClient.NotifyVoiceChatEnded#1"
    // "VoiceChatClient.NotifyUserJoinedVoiceChat#1"
    // "VoiceChatClient.NotifyUserLeftVoiceChat#1"
    virtual void RegisterServiceMethodHandler(HSharedConnection hConn, const char* msgHandler) = 0;
    virtual bool BPopReceivedMessage(HSharedConnection hConn, CUtlBuffer* pBufOut, uint32* hCall) = 0;
    virtual unknown_ret InitiateConnection() = 0; //TODO: REVERSE ME
};

#endif // ICLIENTSHAREDCONNECTION_H
