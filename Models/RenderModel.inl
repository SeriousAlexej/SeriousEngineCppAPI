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

inline CModelRenderPrefs::CModelRenderPrefs(CModelRenderPrefs_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CModelRenderPrefs::CModelRenderPrefs()
  : CModelRenderPrefs(CModelRenderPrefs_new(), true)
{
}

inline CModelRenderPrefs::CModelRenderPrefs(const CModelRenderPrefs& o)
  : CModelRenderPrefs(CModelRenderPrefs_clone(o), true)
{
}

inline CModelRenderPrefs::~CModelRenderPrefs()
{
  if (m_owner)
    CModelRenderPrefs_delete(mp_handle);
}

inline CModelRenderPrefs& CModelRenderPrefs::operator=(const CModelRenderPrefs& o)
{
  CModelRenderPrefs_copy(mp_handle, o);
  return *this;
}

inline void CModelRenderPrefs::SetRenderType(ULONG rtNew)
{
  CModelRenderPrefs_SetRenderType(mp_handle, rtNew);
}

inline void CModelRenderPrefs::SetTextureType(ULONG rtNew)
{
  CModelRenderPrefs_SetTextureType(mp_handle, rtNew);
}

inline void CModelRenderPrefs::SetShadingType(ULONG rtNew)
{
  CModelRenderPrefs_SetShadingType(mp_handle, rtNew);
}

inline void CModelRenderPrefs::SetShadowQuality(INDEX iNew)
{
  CModelRenderPrefs_SetShadowQuality(mp_handle, iNew);
}

inline void CModelRenderPrefs::DesreaseShadowQuality()
{
  CModelRenderPrefs_DesreaseShadowQuality(mp_handle);
}

inline void CModelRenderPrefs::IncreaseShadowQuality()
{
  CModelRenderPrefs_IncreaseShadowQuality(mp_handle);
}

inline void CModelRenderPrefs::SetWire(BOOL bWireOn)
{
  CModelRenderPrefs_SetWire(mp_handle, bWireOn);
}

inline void CModelRenderPrefs::SetHiddenLines(BOOL bHiddenLinesOn)
{
  CModelRenderPrefs_SetHiddenLines(mp_handle, bHiddenLinesOn);
}

inline BOOL CModelRenderPrefs::BBoxFrameVisible()
{
  return CModelRenderPrefs_BBoxFrameVisible(mp_handle);
}

inline BOOL CModelRenderPrefs::BBoxAllVisible()
{
  return CModelRenderPrefs_BBoxAllVisible(mp_handle);
}

inline BOOL CModelRenderPrefs::WireOn()
{
  return CModelRenderPrefs_WireOn(mp_handle);
}

inline BOOL CModelRenderPrefs::HiddenLines()
{
  return CModelRenderPrefs_HiddenLines(mp_handle);
}

inline void CModelRenderPrefs::SetInkColor(COLOR clrNew)
{
  CModelRenderPrefs_SetInkColor(mp_handle, clrNew);
}

inline COLOR CModelRenderPrefs::GetInkColor()
{
  return CModelRenderPrefs_GetInkColor(mp_handle);
}

inline void CModelRenderPrefs::SetPaperColor(COLOR clrNew)
{
  CModelRenderPrefs_SetPaperColor(mp_handle, clrNew);
}

inline COLOR CModelRenderPrefs::GetPaperColor()
{
  return CModelRenderPrefs_GetPaperColor(mp_handle);
}

inline void CModelRenderPrefs::BBoxFrameShow(BOOL bShow)
{
  CModelRenderPrefs_BBoxFrameShow(mp_handle, bShow);
}

inline void CModelRenderPrefs::BBoxAllShow(BOOL bShow)
{
  CModelRenderPrefs_BBoxAllShow(mp_handle, bShow);
}

inline ULONG CModelRenderPrefs::GetRenderType()
{
  return CModelRenderPrefs_GetRenderType(mp_handle);
}

inline INDEX CModelRenderPrefs::GetShadowQuality()
{
  return CModelRenderPrefs_GetShadowQuality(mp_handle);
}

inline void CModelRenderPrefs::Read_t(CTStream* inFile)
{
  CModelRenderPrefs_Read_t(mp_handle, *inFile);
  SECppAPI_CheckException();
}

inline void CModelRenderPrefs::Write_t(CTStream* outFile)
{
  CModelRenderPrefs_Write_t(mp_handle, *outFile);
  SECppAPI_CheckException();
}

inline void BeginModelRenderingView(CAnyProjection3D& prProjection, CDrawPort_* pdp)
{
  BeginModelRenderingView_(prProjection, pdp);
}

inline void EndModelRenderingView(BOOL bRestoreOrtho)
{
  EndModelRenderingView_(bRestoreOrtho);
}

inline void BeginModelRenderingMask(CAnyProjection3D& prProjection, UBYTE* pubMask, SLONG slMaskWidth, SLONG slMaskHeight)
{
  BeginModelRenderingMask_(prProjection, pubMask, slMaskWidth, slMaskHeight);
}

inline void EndModelRenderingMask()
{
  EndModelRenderingMask_();
}

inline CRenderModel::CRenderModel(CRenderModel_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , rm_vObjectPosition(CRenderModel_rm_vObjectPosition(mp_handle), false)
  , rm_mObjectRotation(CRenderModel_rm_mObjectRotation(mp_handle), false)
  , rm_ulFlags(*CRenderModel_rm_ulFlags(mp_handle))
  , rm_colBlend(*CRenderModel_rm_colBlend(mp_handle))
  , rm_fDistanceFactor(*CRenderModel_rm_fDistanceFactor(mp_handle))
  , rm_fMipFactor(*CRenderModel_rm_fMipFactor(mp_handle))
  , rm_vLightDirection(CRenderModel_rm_vLightDirection(mp_handle), false)
  , rm_colLight(*CRenderModel_rm_colLight(mp_handle))
  , rm_colAmbient(*CRenderModel_rm_colAmbient(mp_handle))
{
}

inline CRenderModel::CRenderModel()
  : CRenderModel(CRenderModel_new(), true)
{
}

inline CRenderModel::~CRenderModel()
{
  if (m_owner)
    CRenderModel_delete(mp_handle);
}

inline CRenderModel& CRenderModel::operator=(const CRenderModel& o)
{
  CRenderModel_copy(mp_handle, o);
  return *this;
}

inline void CRenderModel::SetObjectPlacement(const CPlacement3D& pl)
{
  CRenderModel_SetObjectPlacement_pl(mp_handle, pl);
}

inline void CRenderModel::SetObjectPlacement(const FLOAT3D& v, const FLOATmatrix3D& m)
{
  CRenderModel_SetObjectPlacement(mp_handle, v, m);
}
