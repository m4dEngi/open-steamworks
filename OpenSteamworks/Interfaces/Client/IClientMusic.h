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

#ifndef ICLIENTMUSIC_H
#define ICLIENTMUSIC_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Types/MusicCommon.h"

abstract_class UNSAFE_INTERFACE IClientMusic
{
public:
    virtual bool BIsEnabled() = 0;
    virtual void Enable( bool bUnk ) = 0;
    virtual bool BIsPlaying() = 0;
    virtual int32 GetQueueCount() = 0;
    virtual int32 GetCurrentQueueEntry() = 0;
    virtual AudioPlayback_Status GetPlaybackStatus() = 0;
    virtual void SetPlayingRepeatStatus(PlayingRepeat_Status) = 0;
    virtual PlayingRepeat_Status GetPlayingRepeatStatus() = 0;
    virtual PlayingRepeat_Status TogglePlayingRepeatStatus() = 0;
    virtual void SetPlayingShuffled( bool bPlayingShuffled ) = 0;
    virtual bool IsPlayingShuffled() = 0;
    virtual void Play() = 0;
    virtual void Pause() = 0;
    virtual void PlayPrevious() = 0;
    virtual void PlayNext() = 0;
    virtual void PlayEntry( int32 ) = 0;
    virtual void TogglePlayPause() = 0;
    virtual void SetVolume( float flVolume ) = 0;
    virtual float GetVolume() = 0;
    virtual void ToggleMuteVolume() = 0;
    virtual void IncreaseVolume() = 0;
    virtual void DecreaseVolume() = 0;
    virtual void SetPlaybackPosition(int32) = 0;
    virtual int32 GetPlaybackPosition() = 0;
    virtual int32 GetPlaybackDuration() = 0;
    virtual unknown_ret ReplacePlaylistWithSoundtrackAlbum(uint32 uUnk) = 0;
    virtual unknown_ret GetQueueSoundtrackAppID() = 0; //TODO: REVERSE ME
};

#endif // ICLIENTMUSIC_H
