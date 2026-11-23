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

inline ModelFrameVertex8::ModelFrameVertex8(ModelFrameVertex8_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mfv_SBPoint(ModelFrameVertex8_mfv_SBPoint(mp_handle), false)
  , mfv_NormIndex(*ModelFrameVertex8_mfv_NormIndex(mp_handle))
{
}

inline ModelFrameVertex8::ModelFrameVertex8()
  : ModelFrameVertex8(ModelFrameVertex8_new(), true)
{
}

inline ModelFrameVertex8::ModelFrameVertex8(const ModelFrameVertex8& o)
  : ModelFrameVertex8(ModelFrameVertex8_clone(o), true)
{
}

inline ModelFrameVertex8::~ModelFrameVertex8()
{
  if (m_owner)
    ModelFrameVertex8_delete(mp_handle);
}

inline ModelFrameVertex8& ModelFrameVertex8::operator=(const ModelFrameVertex8& o)
{
  ModelFrameVertex8_copy(mp_handle, o);
  return *this;
}

inline ModelFrameVertex16::ModelFrameVertex16(ModelFrameVertex16_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mfv_SWPoint(ModelFrameVertex16_mfv_SWPoint(mp_handle), false)
  , mfv_ubNormH(*ModelFrameVertex16_mfv_ubNormH(mp_handle))
  , mfv_ubNormP(*ModelFrameVertex16_mfv_ubNormP(mp_handle))
{
}

inline ModelFrameVertex16::ModelFrameVertex16()
  : ModelFrameVertex16(ModelFrameVertex16_new(), true)
{
}

inline ModelFrameVertex16::ModelFrameVertex16(const ModelFrameVertex16& o)
  : ModelFrameVertex16(ModelFrameVertex16_clone(o), true)
{
}

inline ModelFrameVertex16::~ModelFrameVertex16()
{
  if (m_owner)
    ModelFrameVertex16_delete(mp_handle);
}

inline ModelFrameVertex16& ModelFrameVertex16::operator=(const ModelFrameVertex16& o)
{
  ModelFrameVertex16_copy(mp_handle, o);
  return *this;
}

inline ModelFrameInfo::ModelFrameInfo(ModelFrameInfo_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mfi_Box(ModelFrameInfo_mfi_Box(mp_handle), false)
{
}

inline ModelFrameInfo::ModelFrameInfo()
  : ModelFrameInfo(ModelFrameInfo_new(), true)
{
}

inline ModelFrameInfo::ModelFrameInfo(const ModelFrameInfo& o)
  : ModelFrameInfo(ModelFrameInfo_clone(o), true)
{
}

inline ModelFrameInfo::~ModelFrameInfo()
{
  if (m_owner)
    ModelFrameInfo_delete(mp_handle);
}

inline ModelFrameInfo& ModelFrameInfo::operator=(const ModelFrameInfo& o)
{
  ModelFrameInfo_copy(mp_handle, o);
  return *this;
}

inline ModelTextureVertex::ModelTextureVertex(ModelTextureVertex_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mtv_UVW(ModelTextureVertex_mtv_UVW(mp_handle), false)
  , mtv_UV(ModelTextureVertex_mtv_UV(mp_handle), false)
{
}

inline ModelTextureVertex::ModelTextureVertex()
  : ModelTextureVertex(ModelTextureVertex_new(), true)
{
}

inline ModelTextureVertex::ModelTextureVertex(const ModelTextureVertex& o)
  : ModelTextureVertex(ModelTextureVertex_clone(o), true)
{
}

inline ModelTextureVertex::~ModelTextureVertex()
{
  if (m_owner)
    ModelTextureVertex_delete(mp_handle);
}

inline ModelTextureVertex& ModelTextureVertex::operator=(const ModelTextureVertex& o)
{
  ModelTextureVertex_copy(mp_handle, o);
  return *this;
}

inline TransformedVertexData::TransformedVertexData(TransformedVertexData_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , tvd_TransformedPoint(TransformedVertexData_tvd_TransformedPoint(mp_handle), false)
  , tvd_fX(*TransformedVertexData_tvd_fX(mp_handle))
  , tvd_fY(*TransformedVertexData_tvd_fY(mp_handle))
  , tvd_fZ(*TransformedVertexData_tvd_fZ(mp_handle))
  , tvd_fU(*TransformedVertexData_tvd_fU(mp_handle))
  , tvd_fV(*TransformedVertexData_tvd_fV(mp_handle))
  , tvd_bClipped(*TransformedVertexData_tvd_bClipped(mp_handle))
{
}

inline TransformedVertexData::TransformedVertexData()
  : TransformedVertexData(TransformedVertexData_new(), true)
{
}

inline TransformedVertexData::TransformedVertexData(const TransformedVertexData& o)
  : TransformedVertexData(TransformedVertexData_clone(o), true)
{
}

inline TransformedVertexData::~TransformedVertexData()
{
  if (m_owner)
    TransformedVertexData_delete(mp_handle);
}

inline TransformedVertexData& TransformedVertexData::operator=(const TransformedVertexData& o)
{
  TransformedVertexData_copy(mp_handle, o);
  return *this;
}

inline ModelPolygonVertex::ModelPolygonVertex(ModelPolygonVertex_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mpv_ptvTransformedVertex(*ModelPolygonVertex_mpv_ptvTransformedVertex(mp_handle))
  , mpv_ptvTextureVertex(*ModelPolygonVertex_mpv_ptvTextureVertex(mp_handle))
{
}

inline ModelPolygonVertex::ModelPolygonVertex()
  : ModelPolygonVertex(ModelPolygonVertex_new(), true)
{
}

inline ModelPolygonVertex::ModelPolygonVertex(const ModelPolygonVertex& o)
  : ModelPolygonVertex(ModelPolygonVertex_clone(o), true)
{
}

inline ModelPolygonVertex::~ModelPolygonVertex()
{
  if (m_owner)
    ModelPolygonVertex_delete(mp_handle);
}

inline ModelPolygonVertex& ModelPolygonVertex::operator=(const ModelPolygonVertex& o)
{
  ModelPolygonVertex_copy(mp_handle, o);
  return *this;
}

inline void ModelPolygonVertex::Read_t(CTStream* istrFile)
{
  ModelPolygonVertex_Read_t(mp_handle, *istrFile);
  SECppAPI_CheckException();
}

inline void ModelPolygonVertex::Write_t(CTStream* ostrFile)
{
  ModelPolygonVertex_Write_t(mp_handle, *ostrFile);
  SECppAPI_CheckException();
}



inline ModelPolygon::ModelPolygon(ModelPolygon_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mp_PolygonVertices(ModelPolygon_mp_PolygonVertices(mp_handle), false)
  , mp_RenderFlags(*ModelPolygon_mp_RenderFlags(mp_handle))
  , mp_ColorAndAlpha(*ModelPolygon_mp_ColorAndAlpha(mp_handle))
  , mp_Surface(*ModelPolygon_mp_Surface(mp_handle))
  , mp_slVisibility(*ModelPolygon_mp_slVisibility(mp_handle))
  , mp_bClipped(*ModelPolygon_mp_bClipped(mp_handle))
{
}

inline ModelPolygon::ModelPolygon()
  : ModelPolygon(ModelPolygon_new(), true)
{
}

inline ModelPolygon::~ModelPolygon()
{
  if (m_owner)
    ModelPolygon_delete(mp_handle);
}

inline ModelPolygon& ModelPolygon::operator=(const ModelPolygon& o)
{
  ModelPolygon_copy(mp_handle, o);
  return *this;
}

inline void ModelPolygon::Read_t(CTStream* istrFile)
{
  ModelPolygon_Read_t(mp_handle, *istrFile);
  SECppAPI_CheckException();
}

inline void ModelPolygon::Write_t(CTStream* ostrFile)
{
  ModelPolygon_Write_t(mp_handle, *ostrFile);
  SECppAPI_CheckException();
}


inline MappingSurface::MappingSurface(MappingSurface_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ms_Name(MappingSurface_ms_Name(mp_handle), false)
  , ms_colColor(*MappingSurface_ms_colColor(mp_handle))
  , ms_vSurfaceCenterOffset(MappingSurface_ms_vSurfaceCenterOffset(mp_handle), false)
  , ms_colDiffuse(*MappingSurface_ms_colDiffuse(mp_handle))
  , ms_colReflections(*MappingSurface_ms_colReflections(mp_handle))
  , ms_colSpecular(*MappingSurface_ms_colSpecular(mp_handle))
  , ms_colBump(*MappingSurface_ms_colBump(mp_handle))
  , ms_ulOnColor(*MappingSurface_ms_ulOnColor(mp_handle))
  , ms_ulOffColor(*MappingSurface_ms_ulOffColor(mp_handle))
  , ms_ulRenderingFlags(*MappingSurface_ms_ulRenderingFlags(mp_handle))
  , ms_sstShadingType(*((SurfaceShadingType*)MappingSurface_ms_sstShadingType(mp_handle)))
  , ms_sttTranslucencyType(*((SurfaceTranslucencyType*)MappingSurface_ms_sttTranslucencyType(mp_handle)))
  , ms_aiPolygons(MappingSurface_ms_aiPolygons(mp_handle), false)
  , ms_aiTextureVertices(MappingSurface_ms_aiTextureVertices(mp_handle), false)
  , ms_iSrfVx0(*MappingSurface_ms_iSrfVx0(mp_handle))
  , ms_ctSrfVx(*MappingSurface_ms_ctSrfVx(mp_handle))
  , ms_ctSrfEl(*MappingSurface_ms_ctSrfEl(mp_handle))
{
}

inline MappingSurface::MappingSurface()
  : MappingSurface(MappingSurface_new(), true)
{
}

inline MappingSurface::~MappingSurface()
{
  if (m_owner)
    MappingSurface_delete(mp_handle);
}

inline MappingSurface& MappingSurface::operator=(const MappingSurface& o)
{
  MappingSurface_copy(mp_handle, o);
  return *this;
}

inline BOOL MappingSurface::operator==(const MappingSurface& o) const
{
  return MappingSurface_equal(mp_handle, o);
}

inline void MappingSurface::Read_t(CTStream* istrFile, BOOL bReadPolygonsPerSurface, BOOL bReadSurfaceColors)
{
  MappingSurface_Read_t(mp_handle, *istrFile, bReadPolygonsPerSurface, bReadSurfaceColors);
  SECppAPI_CheckException();
}

inline void MappingSurface::Write_t(CTStream* ostrFile)
{
  MappingSurface_Write_t(mp_handle, *ostrFile);
  SECppAPI_CheckException();
}

inline void MappingSurface::ReadSettings_t(CTStream* istrFile)
{
  MappingSurface_ReadSettings_t(mp_handle, *istrFile);
  SECppAPI_CheckException();
}

inline void MappingSurface::WriteSettings_t(CTStream* ostrFile)
{
  MappingSurface_WriteSettings_t(mp_handle, *ostrFile);
  SECppAPI_CheckException();
}


inline PolygonsPerPatch::PolygonsPerPatch(PolygonsPerPatch_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ppp_iPolygons(PolygonsPerPatch_ppp_iPolygons(mp_handle), false)
  , ppp_auwElements(PolygonsPerPatch_ppp_auwElements(mp_handle), false)
{
}

inline PolygonsPerPatch::PolygonsPerPatch()
  : PolygonsPerPatch(PolygonsPerPatch_new(), true)
{
}

inline PolygonsPerPatch::~PolygonsPerPatch()
{
  if (m_owner)
    PolygonsPerPatch_delete(mp_handle);
}

inline PolygonsPerPatch& PolygonsPerPatch::operator=(const PolygonsPerPatch& o)
{
  PolygonsPerPatch_copy(mp_handle, o);
  return *this;
}

inline void PolygonsPerPatch::Clear()
{
  PolygonsPerPatch_Clear(mp_handle);
}


inline CModelCollisionBox::CModelCollisionBox(CModelCollisionBox_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mcb_vCollisionBoxMin(CModelCollisionBox_mcb_vCollisionBoxMin(mp_handle), false)
  , mcb_vCollisionBoxMax(CModelCollisionBox_mcb_vCollisionBoxMax(mp_handle), false)
  , mcb_iCollisionBoxDimensionEquality(*CModelCollisionBox_mcb_iCollisionBoxDimensionEquality(mp_handle))
  , mcb_strName(CModelCollisionBox_mcb_strName(mp_handle), false)
{
}

inline CModelCollisionBox::CModelCollisionBox()
  : CModelCollisionBox(CModelCollisionBox_new(), true)
{
}

inline CModelCollisionBox::CModelCollisionBox(const CModelCollisionBox& o)
  : CModelCollisionBox(CModelCollisionBox_clone(o), true)
{
}

inline CModelCollisionBox::~CModelCollisionBox()
{
  if (m_owner)
    CModelCollisionBox_delete(mp_handle);
}

inline CModelCollisionBox& CModelCollisionBox::operator=(const CModelCollisionBox& o)
{
  CModelCollisionBox_copy(mp_handle, o);
  return *this;
}

inline void CModelCollisionBox::Read_t(CTStream* istrFile)
{
  CModelCollisionBox_Read_t(mp_handle, *istrFile);
  SECppAPI_CheckException();
}

inline void CModelCollisionBox::ReadName_t(CTStream* istrFile)
{
  CModelCollisionBox_ReadName_t(mp_handle, *istrFile);
  SECppAPI_CheckException();
}

inline void CModelCollisionBox::Write_t(CTStream* ostrFile)
{
  CModelCollisionBox_Write_t(mp_handle, *ostrFile);
  SECppAPI_CheckException();
}


inline CAttachedModelPosition::CAttachedModelPosition(CAttachedModelPosition_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , amp_iCenterVertex(*CAttachedModelPosition_amp_iCenterVertex(mp_handle))
  , amp_iFrontVertex(*CAttachedModelPosition_amp_iFrontVertex(mp_handle))
  , amp_iUpVertex(*CAttachedModelPosition_amp_iUpVertex(mp_handle))
  , amp_plRelativePlacement(CAttachedModelPosition_amp_plRelativePlacement(mp_handle), false)
{
}

inline CAttachedModelPosition::CAttachedModelPosition()
  : CAttachedModelPosition(CAttachedModelPosition_new(), true)
{
}

inline CAttachedModelPosition::CAttachedModelPosition(const CAttachedModelPosition& o)
  : CAttachedModelPosition(CAttachedModelPosition_clone(o), true)
{
}

inline CAttachedModelPosition::~CAttachedModelPosition()
{
  if (m_owner)
    CAttachedModelPosition_delete(mp_handle);
}

inline CAttachedModelPosition& CAttachedModelPosition::operator=(const CAttachedModelPosition& o)
{
  CAttachedModelPosition_copy(mp_handle, o);
  return *this;
}

inline void CAttachedModelPosition::Read_t(CTStream* strFile)
{
  CAttachedModelPosition_Read_t(mp_handle, *strFile);
  SECppAPI_CheckException();
}

inline void CAttachedModelPosition::Write_t(CTStream* strFile)
{
  CAttachedModelPosition_Write_t(mp_handle, *strFile);
  SECppAPI_CheckException();
}

inline CMipInfo::CMipInfo(CMipInfo_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mi_TrianglesCt(*CMipInfo_mi_TrianglesCt(mp_handle))
  , mi_PolygonsCt(*CMipInfo_mi_PolygonsCt(mp_handle))
  , mi_VerticesCt(*CMipInfo_mi_VerticesCt(mp_handle))
{
}

inline CMipInfo::CMipInfo()
  : CMipInfo(CMipInfo_new(), true)
{
}

inline CMipInfo::CMipInfo(const CMipInfo& o)
  : CMipInfo(CMipInfo_clone(o), true)
{
}

inline CMipInfo::~CMipInfo()
{
  if (m_owner)
    CMipInfo_delete(mp_handle);
}

inline CMipInfo& CMipInfo::operator=(const CMipInfo& o)
{
  CMipInfo_copy(mp_handle, o);
  return *this;
}


inline CModelInfo::CModelInfo(CModelInfo_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mi_VerticesCt(*CModelInfo_mi_VerticesCt(mp_handle))
  , mi_FramesCt(*CModelInfo_mi_FramesCt(mp_handle))
  , mi_MipCt(*CModelInfo_mi_MipCt(mp_handle))
  , mi_MipInfos{
    {CModelInfo_mi_MipInfos(mp_handle, 0), false},
    {CModelInfo_mi_MipInfos(mp_handle, 1), false},
    {CModelInfo_mi_MipInfos(mp_handle, 2), false},
    {CModelInfo_mi_MipInfos(mp_handle, 3), false},
    {CModelInfo_mi_MipInfos(mp_handle, 4), false},
    {CModelInfo_mi_MipInfos(mp_handle, 5), false},
    {CModelInfo_mi_MipInfos(mp_handle, 6), false},
    {CModelInfo_mi_MipInfos(mp_handle, 7), false},
    {CModelInfo_mi_MipInfos(mp_handle, 8), false},
    {CModelInfo_mi_MipInfos(mp_handle, 9), false},
    {CModelInfo_mi_MipInfos(mp_handle, 10), false},
    {CModelInfo_mi_MipInfos(mp_handle, 11), false},
    {CModelInfo_mi_MipInfos(mp_handle, 12), false},
    {CModelInfo_mi_MipInfos(mp_handle, 13), false},
    {CModelInfo_mi_MipInfos(mp_handle, 14), false},
    {CModelInfo_mi_MipInfos(mp_handle, 15), false},
    {CModelInfo_mi_MipInfos(mp_handle, 16), false},
    {CModelInfo_mi_MipInfos(mp_handle, 17), false},
    {CModelInfo_mi_MipInfos(mp_handle, 18), false},
    {CModelInfo_mi_MipInfos(mp_handle, 19), false},
    {CModelInfo_mi_MipInfos(mp_handle, 20), false},
    {CModelInfo_mi_MipInfos(mp_handle, 21), false},
    {CModelInfo_mi_MipInfos(mp_handle, 22), false},
    {CModelInfo_mi_MipInfos(mp_handle, 23), false},
    {CModelInfo_mi_MipInfos(mp_handle, 24), false},
    {CModelInfo_mi_MipInfos(mp_handle, 25), false},
    {CModelInfo_mi_MipInfos(mp_handle, 26), false},
    {CModelInfo_mi_MipInfos(mp_handle, 27), false},
    {CModelInfo_mi_MipInfos(mp_handle, 28), false},
    {CModelInfo_mi_MipInfos(mp_handle, 29), false},
    {CModelInfo_mi_MipInfos(mp_handle, 30), false},
    {CModelInfo_mi_MipInfos(mp_handle, 31), false}
  }
  , mi_PatchFiles{
    {CModelInfo_mi_PatchFiles(mp_handle, 0), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 1), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 2), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 3), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 4), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 5), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 6), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 7), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 8), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 9), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 10), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 11), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 12), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 13), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 14), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 15), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 16), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 17), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 18), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 19), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 20), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 21), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 22), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 23), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 24), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 25), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 26), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 27), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 28), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 29), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 30), false},
    {CModelInfo_mi_PatchFiles(mp_handle, 31), false}
  }
  , mi_Width(*CModelInfo_mi_Width(mp_handle))
  , mi_Height(*CModelInfo_mi_Height(mp_handle))
  , mi_Flags(*CModelInfo_mi_Flags(mp_handle))
  , mi_ShadowQuality(*CModelInfo_mi_ShadowQuality(mp_handle))
  , mi_Stretch(CModelInfo_mi_Stretch(mp_handle), false)
{
}

inline CModelInfo::CModelInfo()
  : CModelInfo(CModelInfo_new(), true)
{
}

inline CModelInfo::CModelInfo(const CModelInfo& o)
  : CModelInfo(CModelInfo_clone(o), true)
{
}

inline CModelInfo::~CModelInfo()
{
  if (m_owner)
    CModelInfo_delete(mp_handle);
}

inline CModelInfo& CModelInfo::operator=(const CModelInfo& o)
{
  CModelInfo_copy(mp_handle, o);
  return *this;
}
