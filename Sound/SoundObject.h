/* Copyright (c) 2026 SeriousAlexej.
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Sound/SoundObject.h>

// sound control values
#define SOF_NONE         SOF_NONE_
#define SOF_LOOP         SOF_LOOP_   // looping sound
#define SOF_3D           SOF_3D_   // has 3d effects
#define SOF_VOLUMETRIC   SOF_VOLUMETRIC_   // no 3d effects inside hot-spot
#define SOF_SURROUND     SOF_SURROUND_   // surround effect
#define SOF_LOCAL        SOF_LOCAL_   // local to listener with same entity
#define SOF_SMOOTHCHANGE SOF_SMOOTHCHANGE_   // for smooth transition from one sound to another on same channel
#define SOF_MUSIC        SOF_MUSIC_   // use music-volume master control instead of sound-volume
#define SOF_NONGAME      SOF_NONGAME_   // game sounds are not mixed while the game is paused
#define SOF_NOFILTER     SOF_NOFILTER_   // used to disable listener-specific filters - i.e. underwater

#define SOF_PAUSED       SOF_PAUSED_  // playing, but paused (internal)
#define SOF_LOADED       SOF_LOADED_  // sound just loaded (internal)
#define SOF_PREPARE      SOF_PREPARE_  // prepared for playing (internal)
#define SOF_PLAY         SOF_PLAY_  // currently playing

class CSoundObject
{
public:
  CSoundObject(CSoundObject_* p, bool owner = false);
  CSoundObject();
  ~CSoundObject();
  CSoundObject(const CSoundObject& o) = delete;
  CSoundObject& operator=(const CSoundObject& o) = delete;

  // copy from another object of same class
  void Copy(CSoundObject& soOther);

  // play sound
  void Play(CSoundData_* pCsdLink, SLONG slFlags);
  // stop playing sound
  void Stop();
  void Stop_internal();
  // Pause -> Stop playing sound but keep it linked to data
  void Pause();
  // Resume -> Resume playing stoped sound
  void Resume();
  // check if sound is playing
  BOOL IsPlaying();
  // check if sound is paused
  BOOL IsPaused();

  // Check if hooked
  BOOL IsHooked() const;

  // Set volume
  void SetVolume(FLOAT fLeftVolume, FLOAT fRightVolume);
  // Set filter
  void SetFilter(FLOAT fLeftFilter, FLOAT fRightFilter); // 1=no filter (>1=more bass)
  // Set pitch shifting
  void SetPitch(FLOAT fPitch); // 1.0 for normal (<1 = slower, >1 = faster playing)
  // Set phase shifting
  void SetPhase(FLOAT fPhase); // right channel delay in seconds (0 = no delay)
  // Set delay
  void SetDelay(FLOAT fDelay); // in seconds (0 = no delay)

  // Set Position in 3D
  void SetOwner(CEntity_* pen);
  // Set 3D parameters
  void Set3DParameters(FLOAT fMaxDistance, FLOAT fMinDistance, FLOAT fMaxVolume, FLOAT fPitch);

  // read/write functions
  void Read_t(CTStream* pistr);  // throw char *
  void Write_t(CTStream* postr); // throw char *

  // Obtain sound and play it for this object
  void Play_t(const CTFileName& fnmSound, SLONG slFlags); // throw char *
  // hard set sound offset in seconds
  void SetOffset(FLOAT fOffset);

  inline CSoundObject_* C_Handle() { return mp_handle; }
  inline const CSoundObject_* C_Handle() const { return mp_handle; }
  inline operator CSoundObject_* () { return C_Handle(); }
  inline operator const CSoundObject_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CSoundObject_* mp_handle = nullptr;
};

#include "SoundObject.inl"
