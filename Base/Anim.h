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
#include "Serial.h"
#include <SeriousEngineCAPI/Base/Anim.h>

/*
 * An object used for obtaining animation's information
 */
class CAnimInfo
{
public:
  CAnimInfo(CAnimInfo_* p, bool owner = false);
  CAnimInfo();
  CAnimInfo(const CAnimInfo& o);
  ~CAnimInfo();
  CAnimInfo& operator=(const CAnimInfo& o);

  inline CAnimInfo_* C_Handle() { return mp_handle; }
  inline const CAnimInfo_* C_Handle() const { return mp_handle; }
  inline operator CAnimInfo_* () { return C_Handle(); }
  inline operator const CAnimInfo_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  CAnimInfo_* mp_handle = nullptr;

public:
  char* ai_AnimName;
  TIME& ai_SecsPerFrame;      // speed of this animation
  INDEX& ai_NumberOfFrames;
};

/*
 * One animation of an animateable object
 */
class COneAnim
{
public:
  explicit COneAnim(COneAnim_* p, bool dummy = false);

  inline COneAnim_* C_Handle() { return mp_handle; }
  inline const COneAnim_* C_Handle() const { return mp_handle; }
  inline operator COneAnim_* () { return C_Handle(); }
  inline operator const COneAnim_* () const { return C_Handle(); }

private:
  COneAnim_* mp_handle = nullptr;

public:
  char* oa_Name;
  TIME& oa_SecsPerFrame;      // speed of this animation
  INDEX& oa_NumberOfFrames;
  INDEX*& oa_FrameIndices;   // array of frame indices
};

/*
 * Animation data for a class of animateable objects
 */
class CAnimData : public CSerial
{
public:
  CAnimData(CAnimData_* p, bool owner = false);
  CAnimData();
  ~CAnimData();
  CAnimData(const CAnimData& oaAnim) = delete;
  CAnimData& operator=(const CAnimData& oaAnim) = delete;

  COneAnimPtr ad_Anims(INDEX i);
  COneAnimPtr ad_Anims(INDEX i) const;

  // creates given number of default animations (1 frame, given name and apeed)
  void CreateAnimations(INDEX ctAnimations, CTString strName = "None",
    INDEX iDefaultFrame = 0, TIME tmSpeed = 0.02f);
  // replaces frames array with given one
  void SetFrames(INDEX iAnimation, INDEX ctFrames, INDEX* pNewFrames);
  // replaces requested animation's name with given one
  void SetName(INDEX iAnimation, CTString strNewName);
  // replaces requested animation's speed with given one
  void SetSpeed(INDEX iAnimation, TIME tmSpeed);
  // obtains frame index for given place in array representing given animation
  INDEX GetFrame(INDEX iAnimation, INDEX iFramePlace);
  // sets frame index for given place in array representing given animation
  void SetFrame(INDEX iAnimation, INDEX iFramePlace, INDEX iNewFrame);
  // fill animation data object vith valid data containing one animation, one frame
  void DefaultAnimation();
  /* Get animation's info. */
  void GetAnimInfo(INDEX iAnimNo, CAnimInfo& aiInfo) const;
  /* Add animation */
  void AddAnimation();
  /* Delete animation */
  void DeleteAnimation(INDEX iAnim);
  /* Get number of animations. */
  INDEX GetAnimsCt() const;

  inline CAnimData_* C_Handle() { return (CAnimData_*)CSerial::C_Handle(); }
  inline const CAnimData_* C_Handle() const { return (CAnimData_*)CSerial::C_Handle(); }
  inline operator CAnimData_* () { return C_Handle(); }
  inline operator const CAnimData_* () const { return C_Handle(); }

public:
  INDEX& ad_NumberOfAnims;
};

class CAnimObject : public CChangeable
{
public:
  CAnimObject(CAnimObject_* p, bool owner = false);
  CAnimObject();
  ~CAnimObject();

  // copy from another object of same class
  void Copy(CAnimObject& aoOther);
  // synchronize with another animation object (set same anim and frames)
  void Synchronize(CAnimObject& aoOther);

  CAnimObject(const CAnimObject& aoOther) = delete;
  CAnimObject& operator=(const CAnimObject& aoOther) = delete;

  /* Loop anims forward */
  void NextAnim();
  /* Loop anims backward */
  void PrevAnim();
  /* Loop frames forward */
  void NextFrame();
  /* Loop frames backward */
  void PrevFrame();
  /* Select frame in given time offset */
  void SelectFrameInTime(TIME tmOffset);
  /* Select first frame */
  void FirstFrame();
  /* Select last frame */
  void LastFrame();
  /* Test if some updateable object is up to date with this anim object. */
  BOOL IsUpToDate(const CUpdateable& ud) const;

  /* Get animation's info. */
  void GetAnimInfo(INDEX iAnimNo, CAnimInfo& aiInfo) const;

  /* Attach data to this object. */
  void SetData(CAnimData_* pAD);
  // obtain animation and set it for this object
  void SetData_t(const CTFileName& fnmAnim); // throw char *

  /* Get current anim data ptr. */
  CAnimDataPtr GetData();

  /* Get animation's length. */
  FLOAT GetCurrentAnimLength() const;
  FLOAT GetAnimLength(INDEX iAnim) const;
  /* Get number of animations in current anim data */
  INDEX GetAnimsCt() const;
  /* If animation has finished */
  BOOL IsAnimFinished() const;
  /* Get passed time from start of animation */
  TIME GetPassedTime() const;

  /* Start new animation -- obsolete. */
  void StartAnim(INDEX iNew);
  /* Start playing an animation. */
  void PlayAnim(INDEX iNew, ULONG ulFlags);
  /* Seamlessly continue playing another animation from same point. */
  void SwitchToAnim(INDEX iNew);
  /* Set new animation but doesn't starts it. */
  void SetAnim(INDEX iNew);
  /* Reset anim (restart) */
  void ResetAnim();
  /* Pauses current animation. */
  void PauseAnim();
  /* Continues paused animation. */
  void ContinueAnim();
  /* Offsets the animation phase */
  void OffsetPhase(TIME tm);
  /* Retrieves paused flag */
  BOOL IsPaused();
  /* Gets the number of current animation */
  INDEX GetAnim() const;
  /* Gets the number of current frame. */
  INDEX GetFrame() const;
  /* Gets number of frames in current anim. */
  INDEX GetFramesInCurrentAnim() const;
  /* Get  information for linear interpolation beetween frames. */
  void GetFrame(INDEX& iFrame0, INDEX& iFrame1, FLOAT& fRatio) const;

  inline CAnimObject_* C_Handle() { return (CAnimObject_*)mp_handle; }
  inline const CAnimObject_* C_Handle() const { return (const CAnimObject_*)mp_handle; }
  inline operator CAnimObject_* () { return C_Handle(); }
  inline operator const CAnimObject_* () const { return C_Handle(); }

public:
  TIME& ao_tmAnimStart;      // time when current anim was started
  INDEX& ao_iCurrentAnim;    // index of active animation
  ULONG& ao_ulFlags;         // flags
  INDEX& ao_iLastAnim;       // index of last animation (for smooth transition)
};

#include "Anim.inl"
