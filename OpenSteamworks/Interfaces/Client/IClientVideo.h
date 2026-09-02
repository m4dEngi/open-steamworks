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

#ifndef ICLIENTVIDEO_H
#define ICLIENTVIDEO_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Types/VideoCommon.h"

class CUtlString;

abstract_class UNSAFE_INTERFACE IClientVideo
{
public:
    virtual void UnlockH264() = 0;
    virtual int32 EGetBroadcastReady() = 0;
    virtual void BeginBroadcastSession() = 0;
    virtual void EndBroadcastSession() = 0;
    virtual bool IsBroadcasting(int32* pnNumViewers) = 0;
    virtual bool BIsUploadingThumbnails() = 0;
    virtual BroadcastSessionID_t GetBroadcastSessionID() = 0;
    virtual bool ReceiveBroadcastChat(CSteamID, BroadcastSessionID_t, bool) = 0;
    virtual bool PostBroadcastChat(BroadcastSessionID_t, const char*) = 0;
    virtual bool MuteBroadcastChatUser(BroadcastSessionID_t, CSteamID) = 0;
    virtual bool InitBroadcastVideo(int32, int32, int32 iWidth, int32 iHeight, const uint8*, int32, const uint8*, int32) = 0;
    virtual bool InitBroadcastAudio(int32, int32, int32, int32, int32, const uint8*, int32) = 0;
    virtual bool UploadBroadcastFrame(bool, bool, uint32, int64, int64, const uint8* pubFrame, int32 iFrameSize) = 0;
    virtual bool UploadBroadcastThumbnail(int32 iWidth, int32 iHeight, const uint8* pubRGBData, int32 iRGBDataSize) = 0;
    virtual void DroppedVideoFrames(int32) = 0;
    virtual void SetCurrentVideoEncodingRate(int32) = 0;
    virtual void SetMicrophoneState(bool, bool) = 0;
    virtual void SetVideoSource(bool) = 0;
    virtual void BroadcastRecorderError(EBroadcastRecorderResult) = 0;
    virtual void LoadBroadcastSettings() = 0;
    virtual void SetBroadcastPermissions(EBroadcastPermission) = 0;
    virtual EBroadcastPermission GetBroadcastPermissions() = 0;
    virtual int32 GetBroadcastMaxKbps() = 0;
    virtual int32 GetBroadcastDelaySeconds() = 0;
    virtual bool BGetBroadcastDimensions(int32* iWidth, int32* iHeight) = 0;
    virtual bool GetBroadcastIncludeDesktop() = 0;
    virtual bool GetBroadcastRecordSystemAudio() = 0;
    virtual bool GetBroadcastRecordMic() = 0;
    virtual EBroadcastChatCorner GetBroadcastShowChatCorner() = 0;
    virtual bool GetBroadcastShowDebugInfo() = 0;
    virtual bool GetBroadcastShowReminderBanner() = 0;
    virtual int32 GetBroadcastEncoderSetting() = 0;
    virtual void InviteToBroadcast(CSteamID steamID, bool bUnk, uint32 uUnk) = 0;
    virtual void IgnoreApprovalRequest(CSteamID, uint32 uUnk) = 0;
    virtual void BroadcastFirstTimeComplete() = 0;
    virtual void SetInHomeStreamState(bool) = 0;
    virtual void WatchBroadcast(CSteamID) = 0;
    virtual unknown_ret GetWatchBroadcastMPD(CSteamID) = 0;
    virtual int32 GetApprovalRequestCount() = 0;
    virtual int32 GetApprovalRequests(CSteamID*, uint32) = 0;
    virtual void GetVideoURL(AppId_t appId) = 0;
    virtual void GetOPFSettings(AppId_t appId) = 0;
    virtual bool GetOPFStringForApp(AppId_t appId, char* pchBuffer, int32 iUnk, int32* pnBufferSize) = 0;
    virtual unknown_ret WebRTCGetTURNAddress(CUtlString*) = 0;
    virtual unknown_ret WebRTCStartResult(uint64, bool, const char*) = 0;
    virtual unknown_ret WebRTCAddCandidate(uint64, const char*, int, const char*) = 0;
    virtual unknown_ret WebRTCGetAnswer(uint64, CUtlString*) = 0;
};

#endif // ICLIENTVIDEO_H
