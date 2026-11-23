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

inline CAnimInfo::CAnimInfo(CAnimInfo_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ai_AnimName(CAnimInfo_ai_AnimName(mp_handle))
  , ai_SecsPerFrame(*CAnimInfo_ai_SecsPerFrame(mp_handle))
  , ai_NumberOfFrames(*CAnimInfo_ai_NumberOfFrames(mp_handle))
{
}

inline CAnimInfo::CAnimInfo()
  : CAnimInfo(CAnimInfo_new(), true)
{
}

inline CAnimInfo::CAnimInfo(const CAnimInfo& o)
  : CAnimInfo(CAnimInfo_clone(o), true)
{
}

inline CAnimInfo::~CAnimInfo()
{
  if (m_owner)
    CAnimInfo_delete(mp_handle);
}

inline CAnimInfo& CAnimInfo::operator=(const CAnimInfo& o)
{
  CAnimInfo_copy(mp_handle, o);
  return *this;
}

inline COneAnim::COneAnim(COneAnim_* p, bool)
  : mp_handle(p)
  , oa_Name(COneAnim_oa_Name(mp_handle))
  , oa_SecsPerFrame(*COneAnim_oa_SecsPerFrame(mp_handle))
  , oa_NumberOfFrames(*COneAnim_oa_NumberOfFrames(mp_handle))
  , oa_FrameIndices(*COneAnim_oa_FrameIndices(mp_handle))
{
}

inline CAnimData::CAnimData(CAnimData_* p, bool owner)
  : CSerial((CSerial_*)p, owner)
  , ad_NumberOfAnims(*CAnimData_ad_NumberOfAnims(C_Handle()))
{
}

inline CAnimData::CAnimData()
  : CAnimData(CAnimData_new(), true)
{
}

inline CAnimData::~CAnimData()
{
  if (m_owner)
    CAnimData_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

__forceinline COneAnimPtr CAnimData::ad_Anims(INDEX i)
{
  return CAnimData_ad_Anims(C_Handle(), i);
}

__forceinline COneAnimPtr CAnimData::ad_Anims(INDEX i) const
{
  return CAnimData_ad_Anims((CAnimData_*)C_Handle(), i);
}

inline void CAnimData::CreateAnimations(INDEX ctAnimations, CTString strName, INDEX iDefaultFrame, TIME tmSpeed)
{
  CAnimData_CreateAnimations(C_Handle(), ctAnimations, strName, iDefaultFrame, tmSpeed);
}

inline void CAnimData::SetFrames(INDEX iAnimation, INDEX ctFrames, INDEX* pNewFrames)
{
  CAnimData_SetFrames(C_Handle(), iAnimation, ctFrames, pNewFrames);
}

inline void CAnimData::SetName(INDEX iAnimation, CTString strNewName)
{
  CAnimData_SetName(C_Handle(), iAnimation, strNewName);
}

inline void CAnimData::SetSpeed(INDEX iAnimation, TIME tmSpeed)
{
  CAnimData_SetSpeed(C_Handle(), iAnimation, tmSpeed);
}

inline INDEX CAnimData::GetFrame(INDEX iAnimation, INDEX iFramePlace)
{
  return CAnimData_GetFrame(C_Handle(), iAnimation, iFramePlace);
}

inline void CAnimData::SetFrame(INDEX iAnimation, INDEX iFramePlace, INDEX iNewFrame)
{
  CAnimData_SetFrame(C_Handle(), iAnimation, iFramePlace, iNewFrame);
}

inline void CAnimData::DefaultAnimation()
{
  CAnimData_DefaultAnimation(C_Handle());
}

inline void CAnimData::GetAnimInfo(INDEX iAnimNo, CAnimInfo& aiInfo) const
{
  CAnimData_GetAnimInfo(C_Handle(), iAnimNo, aiInfo);
}

inline void CAnimData::AddAnimation()
{
  CAnimData_AddAnimation(C_Handle());
}

inline void CAnimData::DeleteAnimation(INDEX iAnim)
{
  CAnimData_DeleteAnimation(C_Handle(), iAnim);
}

inline INDEX CAnimData::GetAnimsCt() const
{
  return CAnimData_GetAnimsCt(C_Handle());
}

inline CAnimObject::CAnimObject(CAnimObject_* p, bool owner)
  : CChangeable((CChangeable_*)p, owner)
  , ao_tmAnimStart(*CAnimObject_ao_tmAnimStart(C_Handle()))
  , ao_iCurrentAnim(*CAnimObject_ao_iCurrentAnim(C_Handle()))
  , ao_ulFlags(*CAnimObject_ao_ulFlags(C_Handle()))
  , ao_iLastAnim(*CAnimObject_ao_iLastAnim(C_Handle()))
{
}

inline CAnimObject::CAnimObject()
  : CAnimObject(CAnimObject_new(), true)
{
}

inline CAnimObject::~CAnimObject()
{
  if (m_owner)
    CAnimObject_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline void CAnimObject::Copy(CAnimObject& aoOther)
{
  CAnimObject_Copy(C_Handle(), aoOther);
}

inline void CAnimObject::Synchronize(CAnimObject& aoOther)
{
  CAnimObject_Synchronize(C_Handle(), aoOther);
}

inline void CAnimObject::NextAnim()
{
  CAnimObject_NextAnim(C_Handle());
}

inline void CAnimObject::PrevAnim()
{
  CAnimObject_PrevAnim(C_Handle());
}

inline void CAnimObject::NextFrame()
{
  CAnimObject_NextFrame(C_Handle());
}

inline void CAnimObject::PrevFrame()
{
  CAnimObject_PrevFrame(C_Handle());
}

inline void CAnimObject::SelectFrameInTime(TIME tmOffset)
{
  CAnimObject_SelectFrameInTime(C_Handle(), tmOffset);
}

inline void CAnimObject::FirstFrame()
{
  CAnimObject_FirstFrame(C_Handle());
}

inline void CAnimObject::LastFrame()
{
  CAnimObject_LastFrame(C_Handle());
}

inline BOOL CAnimObject::IsUpToDate(const CUpdateable& ud) const
{
  return CAnimObject_IsUpToDate(C_Handle(), ud);
}

inline void CAnimObject::GetAnimInfo(INDEX iAnimNo, CAnimInfo& aiInfo) const
{
  CAnimObject_GetAnimInfo(C_Handle(), iAnimNo, aiInfo);
}

inline void CAnimObject::SetData(CAnimData_* pAD)
{
  CAnimObject_SetData(C_Handle(), pAD);
}

inline void CAnimObject::SetData_t(const CTFileName& fnmAnim)
{
  CAnimObject_SetData_t(C_Handle(), fnmAnim);
  SECppAPI_CheckException();
}

__forceinline CAnimDataPtr CAnimObject::GetData()
{
  return CAnimDataPtr(CAnimObject_ao_AnimData(C_Handle()));
}

inline FLOAT CAnimObject::GetCurrentAnimLength() const
{
  return CAnimObject_GetCurrentAnimLength(C_Handle());
}

inline FLOAT CAnimObject::GetAnimLength(INDEX iAnim) const
{
  return CAnimObject_GetAnimLength(C_Handle(), iAnim);
}

inline INDEX CAnimObject::GetAnimsCt() const
{
  return CAnimObject_GetAnimsCt(C_Handle());
}

inline BOOL CAnimObject::IsAnimFinished() const
{
  return CAnimObject_IsAnimFinished(C_Handle());
}

inline TIME CAnimObject::GetPassedTime() const
{
  return CAnimObject_GetPassedTime(C_Handle());
}

inline void CAnimObject::StartAnim(INDEX iNew)
{
  CAnimObject_StartAnim(C_Handle(), iNew);
}

inline void CAnimObject::PlayAnim(INDEX iNew, ULONG ulFlags)
{
  CAnimObject_PlayAnim(C_Handle(), iNew, ulFlags);
}

inline void CAnimObject::SwitchToAnim(INDEX iNew)
{
  CAnimObject_SwitchToAnim(C_Handle(), iNew);
}

inline void CAnimObject::SetAnim(INDEX iNew)
{
  CAnimObject_SetAnim(C_Handle(), iNew);
}

inline void CAnimObject::ResetAnim()
{
  CAnimObject_ResetAnim(C_Handle());
}

inline void CAnimObject::PauseAnim()
{
  CAnimObject_PauseAnim(C_Handle());
}

inline void CAnimObject::ContinueAnim()
{
  CAnimObject_ContinueAnim(C_Handle());
}

inline void CAnimObject::OffsetPhase(TIME tm)
{
  CAnimObject_OffsetPhase(C_Handle(), tm);
}

inline BOOL CAnimObject::IsPaused()
{
  return CAnimObject_IsPaused(C_Handle());
}

inline INDEX CAnimObject::GetAnim() const
{
  return CAnimObject_GetAnim(C_Handle());
}

inline INDEX CAnimObject::GetFrame() const
{
  return CAnimObject_GetFrame(C_Handle());
}

inline INDEX CAnimObject::GetFramesInCurrentAnim() const
{
  return CAnimObject_GetFramesInCurrentAnim(C_Handle());
}

inline void CAnimObject::GetFrame(INDEX& iFrame0, INDEX& iFrame1, FLOAT& fRatio) const
{
  CAnimObject_GetFrameIndices(C_Handle(), &iFrame0, &iFrame1, &fRatio);
}

