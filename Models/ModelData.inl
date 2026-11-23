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

inline CModelPatch::CModelPatch(CModelPatch_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mp_strName(CModelPatch_mp_strName(mp_handle), false)
  , mp_toTexture(CModelPatch_mp_toTexture(mp_handle), false)
  , mp_mexPosition(CModelPatch_mp_mexPosition(mp_handle), false)
  , mp_fStretch(*CModelPatch_mp_fStretch(mp_handle))
{
}

inline CModelPatch::CModelPatch()
  : CModelPatch(CModelPatch_new(), true)
{
}

inline CModelPatch::~CModelPatch()
{
  if (m_owner)
    CModelPatch_delete(mp_handle);
}

inline void CModelPatch::Read_t(CTStream* strFile)
{
  CModelPatch_Read_t(mp_handle, *strFile);
  SECppAPI_CheckException();
}

inline void CModelPatch::Write_t(CTStream* strFile)
{
  CModelPatch_Write_t(mp_handle, *strFile);
  SECppAPI_CheckException();
}

inline ModelMipInfo::ModelMipInfo(ModelMipInfo_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mmpi_PolygonsCt(*ModelMipInfo_mmpi_PolygonsCt(mp_handle))
  , mmpi_ulFlags(*ModelMipInfo_mmpi_ulFlags(mp_handle))
  , mmpi_aPolygonsPerPatch(ModelMipInfo_mmpi_aPolygonsPerPatch(mp_handle), false)
  , mmpi_Polygons(ModelMipInfo_mmpi_Polygons(mp_handle), false)
  , mmpi_TextureVertices(ModelMipInfo_mmpi_TextureVertices(mp_handle), false)
  , mmpi_MappingSurfaces(ModelMipInfo_mmpi_MappingSurfaces(mp_handle), false)
  , mmpi_ctMipVx(*ModelMipInfo_mmpi_ctMipVx(mp_handle))
  , mmpi_ctSrfVx(*ModelMipInfo_mmpi_ctSrfVx(mp_handle))
  , mmpi_auwMipToMdl(ModelMipInfo_mmpi_auwMipToMdl(mp_handle), false)
  , mmpi_auwSrfToMip(ModelMipInfo_mmpi_auwSrfToMip(mp_handle), false)
  , mmpi_avmexTexCoord(ModelMipInfo_mmpi_avmexTexCoord(mp_handle), false)
  , mmpi_avBumpU(ModelMipInfo_mmpi_avBumpU(mp_handle), false)
  , mmpi_avBumpV(ModelMipInfo_mmpi_avBumpV(mp_handle), false)
  , mmpi_ulLayerFlags(*ModelMipInfo_mmpi_ulLayerFlags(mp_handle))
  , mmpi_ctTriangles(*ModelMipInfo_mmpi_ctTriangles(mp_handle))
  , mmpi_aiElements(ModelMipInfo_mmpi_aiElements(mp_handle), false)
{
}

inline ModelMipInfo::ModelMipInfo()
  : ModelMipInfo(ModelMipInfo_new(), true)
{
}

inline ModelMipInfo::~ModelMipInfo()
{
  if (m_owner)
    ModelMipInfo_delete(mp_handle);
}

inline ModelMipInfo& ModelMipInfo::operator=(const ModelMipInfo& o)
{
  ModelMipInfo_copy(mp_handle, o);
  return *this;
}

inline void ModelMipInfo::Clear()
{
  ModelMipInfo_Clear(mp_handle);
}

inline void ModelMipInfo::Read_t(CTStream* istrFile, BOOL bReadPolygonalPatches, BOOL bReadPolygonsPerSurface, BOOL bReadSurfaceColors)
{
  ModelMipInfo_Read_t(mp_handle, *istrFile, bReadPolygonalPatches, bReadPolygonsPerSurface, bReadSurfaceColors);
  SECppAPI_CheckException();
}

inline void ModelMipInfo::Write_t(CTStream* ostrFile)
{
  ModelMipInfo_Write_t(mp_handle, *ostrFile);
  SECppAPI_CheckException();
}

inline CModelData::CModelData(CModelData_* p, bool owner)
  : CAnimData((CAnimData_*)p, owner)
  , md_VerticesCt(*CModelData_md_VerticesCt(C_Handle()))
  , md_FramesCt(*CModelData_md_FramesCt(C_Handle()))
  , md_FrameVertices8(CModelData_md_FrameVertices8(C_Handle()), false)
  , md_FrameVertices16(CModelData_md_FrameVertices16(C_Handle()), false)
  , md_FrameInfos(CModelData_md_FrameInfos(C_Handle()), false)
  , md_MainMipVertices(CModelData_md_MainMipVertices(C_Handle()), false)
  , md_TransformedVertices(CModelData_md_TransformedVertices(C_Handle()), false)
  , md_VertexMipMask(CModelData_md_VertexMipMask(C_Handle()), false)
  , md_MipCt(*CModelData_md_MipCt(C_Handle()))
  , md_MipInfos{
    {CModelData_md_MipInfos(C_Handle(), 0), false},
    {CModelData_md_MipInfos(C_Handle(), 1), false},
    {CModelData_md_MipInfos(C_Handle(), 2), false},
    {CModelData_md_MipInfos(C_Handle(), 3), false},
    {CModelData_md_MipInfos(C_Handle(), 4), false},
    {CModelData_md_MipInfos(C_Handle(), 5), false},
    {CModelData_md_MipInfos(C_Handle(), 6), false},
    {CModelData_md_MipInfos(C_Handle(), 7), false},
    {CModelData_md_MipInfos(C_Handle(), 8), false},
    {CModelData_md_MipInfos(C_Handle(), 9), false},
    {CModelData_md_MipInfos(C_Handle(), 10), false},
    {CModelData_md_MipInfos(C_Handle(), 11), false},
    {CModelData_md_MipInfos(C_Handle(), 12), false},
    {CModelData_md_MipInfos(C_Handle(), 13), false},
    {CModelData_md_MipInfos(C_Handle(), 14), false},
    {CModelData_md_MipInfos(C_Handle(), 15), false},
    {CModelData_md_MipInfos(C_Handle(), 16), false},
    {CModelData_md_MipInfos(C_Handle(), 17), false},
    {CModelData_md_MipInfos(C_Handle(), 18), false},
    {CModelData_md_MipInfos(C_Handle(), 19), false},
    {CModelData_md_MipInfos(C_Handle(), 20), false},
    {CModelData_md_MipInfos(C_Handle(), 21), false},
    {CModelData_md_MipInfos(C_Handle(), 22), false},
    {CModelData_md_MipInfos(C_Handle(), 23), false},
    {CModelData_md_MipInfos(C_Handle(), 24), false},
    {CModelData_md_MipInfos(C_Handle(), 25), false},
    {CModelData_md_MipInfos(C_Handle(), 26), false},
    {CModelData_md_MipInfos(C_Handle(), 27), false},
    {CModelData_md_MipInfos(C_Handle(), 28), false},
    {CModelData_md_MipInfos(C_Handle(), 29), false},
    {CModelData_md_MipInfos(C_Handle(), 30), false},
    {CModelData_md_MipInfos(C_Handle(), 31), false}
  }
  , md_Width(*CModelData_md_Width(C_Handle()))
  , md_Height(*CModelData_md_Height(C_Handle()))
  , md_mpPatches{
    {CModelData_md_mpPatches(C_Handle(), 0), false},
    {CModelData_md_mpPatches(C_Handle(), 1), false},
    {CModelData_md_mpPatches(C_Handle(), 2), false},
    {CModelData_md_mpPatches(C_Handle(), 3), false},
    {CModelData_md_mpPatches(C_Handle(), 4), false},
    {CModelData_md_mpPatches(C_Handle(), 5), false},
    {CModelData_md_mpPatches(C_Handle(), 6), false},
    {CModelData_md_mpPatches(C_Handle(), 7), false},
    {CModelData_md_mpPatches(C_Handle(), 8), false},
    {CModelData_md_mpPatches(C_Handle(), 9), false},
    {CModelData_md_mpPatches(C_Handle(), 10), false},
    {CModelData_md_mpPatches(C_Handle(), 11), false},
    {CModelData_md_mpPatches(C_Handle(), 12), false},
    {CModelData_md_mpPatches(C_Handle(), 13), false},
    {CModelData_md_mpPatches(C_Handle(), 14), false},
    {CModelData_md_mpPatches(C_Handle(), 15), false},
    {CModelData_md_mpPatches(C_Handle(), 16), false},
    {CModelData_md_mpPatches(C_Handle(), 17), false},
    {CModelData_md_mpPatches(C_Handle(), 18), false},
    {CModelData_md_mpPatches(C_Handle(), 19), false},
    {CModelData_md_mpPatches(C_Handle(), 20), false},
    {CModelData_md_mpPatches(C_Handle(), 21), false},
    {CModelData_md_mpPatches(C_Handle(), 22), false},
    {CModelData_md_mpPatches(C_Handle(), 23), false},
    {CModelData_md_mpPatches(C_Handle(), 24), false},
    {CModelData_md_mpPatches(C_Handle(), 25), false},
    {CModelData_md_mpPatches(C_Handle(), 26), false},
    {CModelData_md_mpPatches(C_Handle(), 27), false},
    {CModelData_md_mpPatches(C_Handle(), 28), false},
    {CModelData_md_mpPatches(C_Handle(), 29), false},
    {CModelData_md_mpPatches(C_Handle(), 30), false},
    {CModelData_md_mpPatches(C_Handle(), 31), false}
  }
  , md_ColorNames{
    {CModelData_md_ColorNames(C_Handle(), 0), false},
    {CModelData_md_ColorNames(C_Handle(), 1), false},
    {CModelData_md_ColorNames(C_Handle(), 2), false},
    {CModelData_md_ColorNames(C_Handle(), 3), false},
    {CModelData_md_ColorNames(C_Handle(), 4), false},
    {CModelData_md_ColorNames(C_Handle(), 5), false},
    {CModelData_md_ColorNames(C_Handle(), 6), false},
    {CModelData_md_ColorNames(C_Handle(), 7), false},
    {CModelData_md_ColorNames(C_Handle(), 8), false},
    {CModelData_md_ColorNames(C_Handle(), 9), false},
    {CModelData_md_ColorNames(C_Handle(), 10), false},
    {CModelData_md_ColorNames(C_Handle(), 11), false},
    {CModelData_md_ColorNames(C_Handle(), 12), false},
    {CModelData_md_ColorNames(C_Handle(), 13), false},
    {CModelData_md_ColorNames(C_Handle(), 14), false},
    {CModelData_md_ColorNames(C_Handle(), 15), false},
    {CModelData_md_ColorNames(C_Handle(), 16), false},
    {CModelData_md_ColorNames(C_Handle(), 17), false},
    {CModelData_md_ColorNames(C_Handle(), 18), false},
    {CModelData_md_ColorNames(C_Handle(), 19), false},
    {CModelData_md_ColorNames(C_Handle(), 20), false},
    {CModelData_md_ColorNames(C_Handle(), 21), false},
    {CModelData_md_ColorNames(C_Handle(), 22), false},
    {CModelData_md_ColorNames(C_Handle(), 23), false},
    {CModelData_md_ColorNames(C_Handle(), 24), false},
    {CModelData_md_ColorNames(C_Handle(), 25), false},
    {CModelData_md_ColorNames(C_Handle(), 26), false},
    {CModelData_md_ColorNames(C_Handle(), 27), false},
    {CModelData_md_ColorNames(C_Handle(), 28), false},
    {CModelData_md_ColorNames(C_Handle(), 29), false},
    {CModelData_md_ColorNames(C_Handle(), 30), false},
    {CModelData_md_ColorNames(C_Handle(), 31), false}
  }
  , md_Flags(*CModelData_md_Flags(C_Handle()))
  , md_ShadowQuality(*CModelData_md_ShadowQuality(C_Handle()))
  , md_Stretch(CModelData_md_Stretch(C_Handle()), false)
  , md_vCenter(CModelData_md_vCenter(C_Handle()), false)
  , md_vCompressedCenter(CModelData_md_vCompressedCenter(C_Handle()), false)
  , md_bHasAlpha(*CModelData_md_bHasAlpha(C_Handle()))
  , md_acbCollisionBox(CModelData_md_acbCollisionBox(C_Handle()), false)
  , md_bCollideAsCube(*CModelData_md_bCollideAsCube(C_Handle()))
  , md_aampAttachedPosition(CModelData_md_aampAttachedPosition(C_Handle()), false)
  , md_bIsEdited(*CModelData_md_bIsEdited(C_Handle()))
  , md_colDiffuse(*CModelData_md_colDiffuse(C_Handle()))
  , md_colReflections(*CModelData_md_colReflections(C_Handle()))
  , md_colSpecular(*CModelData_md_colSpecular(C_Handle()))
  , md_colBump(*CModelData_md_colBump(C_Handle()))
  , md_bPreparedForRendering(*CModelData_md_bPreparedForRendering(C_Handle()))
{
}

inline CModelData::CModelData()
  : CModelData(CModelData_new(), true)
{
}

inline CModelData::~CModelData()
{
  if (m_owner)
    CModelData_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline void CModelData::SpreadMipSwitchFactors(INDEX iFirst, FLOAT fStartingFactor)
{
  CModelData_SpreadMipSwitchFactors(C_Handle(), iFirst, fStartingFactor);
}

inline void CModelData::GetTextureDimensions(MEX& mexWidth, MEX& mexHeight)
{
  CModelData_GetTextureDimensions(C_Handle(), &mexWidth, &mexHeight);
}

inline void CModelData::GetAllFramesBBox(FLOATaabbox3D& MaxBB)
{
  CModelData_GetAllFramesBBox(C_Handle(), MaxBB);
}

__forceinline FLOAT3D CModelData::GetCollisionBoxMin(INDEX iCollisionBox)
{
  return FLOAT3D(CModelData_GetCollisionBoxMin(C_Handle(), iCollisionBox), true);
}

__forceinline FLOAT3D CModelData::GetCollisionBoxMax(INDEX iCollisionBox)
{
  return FLOAT3D(CModelData_GetCollisionBoxMax(C_Handle(), iCollisionBox), true);
}

inline INDEX CModelData::GetCollisionBoxDimensionEquality(INDEX iCollisionBox)
{
  return CModelData_GetCollisionBoxDimensionEquality(C_Handle(), iCollisionBox);
}

inline ULONG CModelData::GetFlags()
{
  return CModelData_GetFlags(C_Handle());
}

inline void CModelData::Clear()
{
  CModelData_Clear(C_Handle());
}

inline void CModelData::ClearAnimations()
{
  CModelData_ClearAnimations(C_Handle());
}

inline void CModelData::LinkDataForSurfaces(BOOL bFirstMip)
{
  CModelData_LinkDataForSurfaces(C_Handle(), bFirstMip);
}

inline FLOAT& CModelData::md_MipSwitchFactors(INDEX i)
{
  return *CModelData_md_MipSwitchFactors(C_Handle(), i);
}

inline FLOAT CModelData::md_MipSwitchFactors(INDEX i) const
{
  return *CModelData_md_MipSwitchFactors((CModelData_*)C_Handle(), i);
}

inline void CModelData::CreateAnimationsRaw(INDEX ct)
{
  CModelData_CreateAnimationsRaw(C_Handle(), ct);
}
