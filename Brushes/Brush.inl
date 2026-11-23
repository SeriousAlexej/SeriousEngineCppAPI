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
#include <SeriousEngineCAPI/Brushes/Brush.h>

inline CBrushVertex::CBrushVertex(CBrushVertex_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bvx_pwvxWorking(*CBrushVertex_bvx_pwvxWorking(p))
  , bvx_vAbsolute(CBrushVertex_bvx_vAbsolute(p), false)
  , bvx_vRelative(CBrushVertex_bvx_vRelative(p), false)
  , bvx_vdPreciseRelative(CBrushVertex_bvx_vdPreciseRelative(p), false)
  , bvx_pbscSector(*CBrushVertex_bvx_pbscSector(p))
{
}

inline CBrushVertex::CBrushVertex()
  : CBrushVertex(CBrushVertex_new(), true)
{
}

inline CBrushVertex::CBrushVertex(const CBrushVertex& o)
  : CBrushVertex(CBrushVertex_clone(o), true)
{
}

inline CBrushVertex::~CBrushVertex()
{
  if (m_owner)
    CBrushVertex_delete(mp_handle);
}

inline CBrushVertex& CBrushVertex::operator=(const CBrushVertex& o)
{
  CBrushVertex_copy(mp_handle, o);
  return *this;
}

inline BOOL CBrushVertex::IsSelected() const
{
  return CBrushVertex_IsSelected(C_Handle());
}

inline void CBrushVertex::SetAbsolutePosition(const DOUBLE3D& vAbsolute)
{
  CBrushVertex_SetAbsolutePosition(C_Handle(), vAbsolute);
}

inline CBrushPlane::CBrushPlane(CBrushPlane_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bpl_pwplWorking(*CBrushPlane_bpl_pwplWorking(p))
  , bpl_plAbsolute(CBrushPlane_bpl_plAbsolute(p), false)
  , bpl_plRelative(CBrushPlane_bpl_plRelative(p), false)
  , bpl_ppldPreciseAbsolute(*CBrushPlane_bpl_ppldPreciseAbsolute(p))
  , bpl_pldPreciseRelative(CBrushPlane_bpl_pldPreciseRelative(p), false)
  , bpl_iPlaneMajorAxis1(*CBrushPlane_bpl_iPlaneMajorAxis1(p))
  , bpl_iPlaneMajorAxis2(*CBrushPlane_bpl_iPlaneMajorAxis2(p))
{
}

inline CBrushPlane::CBrushPlane()
  : CBrushPlane(CBrushPlane_new(), true)
{
}

inline CBrushPlane::CBrushPlane(const CBrushPlane& o)
  : CBrushPlane(CBrushPlane_clone(o), true)
{
}

inline CBrushPlane::~CBrushPlane()
{
  if (m_owner)
    CBrushPlane_delete(mp_handle);
}

inline CBrushPlane& CBrushPlane::operator=(const CBrushPlane& o)
{
  CBrushPlane_copy(mp_handle, o);
  return *this;
}

inline CBrushEdge::CBrushEdge(CBrushEdge_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bed_pbvxVertex0(*CBrushEdge_bed_pbvxVertex0(p))
  , bed_pbvxVertex1(*CBrushEdge_bed_pbvxVertex1(p))
{
}

inline CBrushEdge::CBrushEdge()
  : CBrushEdge(CBrushEdge_new(), true)
{
}

inline CBrushEdge::CBrushEdge(CBrushVertex_* v0, CBrushVertex_* v1)
  : CBrushEdge(CBrushEdge_new_v(v0, v1), true)
{
}

inline CBrushEdge::CBrushEdge(const CBrushEdge& o)
  : CBrushEdge(CBrushEdge_clone(o), true)
{
}

inline CBrushEdge::~CBrushEdge()
{
  if (m_owner)
    CBrushEdge_delete(mp_handle);
}

inline CBrushEdge& CBrushEdge::operator=(const CBrushEdge& o)
{
  CBrushEdge_copy(mp_handle, o);
  return *this;
}

inline CBrushPolygonEdge::CBrushPolygonEdge(CBrushPolygonEdge_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bpe_pbedEdge(*CBrushPolygonEdge_bpe_pbedEdge(p))
{
}

inline CBrushPolygonEdge::CBrushPolygonEdge()
  : CBrushPolygonEdge(CBrushPolygonEdge_new(), true)
{
}

inline CBrushPolygonEdge::CBrushPolygonEdge(const CBrushPolygonEdge& o)
  : CBrushPolygonEdge(CBrushPolygonEdge_clone(o), true)
{
}

inline CBrushPolygonEdge::~CBrushPolygonEdge()
{
  if (m_owner)
    CBrushPolygonEdge_delete(mp_handle);
}

inline CBrushPolygonEdge& CBrushPolygonEdge::operator=(const CBrushPolygonEdge& o)
{
  CBrushPolygonEdge_copy(mp_handle, o);
  return *this;
}

inline void CBrushPolygonEdge::GetVertexCoordinatesAbsolute(FLOAT3D& v0, FLOAT3D& v1)
{
  CBrushPolygonEdge_GetVertexCoordinatesAbsolute(C_Handle(), v0, v1);
}

inline void CBrushPolygonEdge::GetVertexCoordinatesRelative(FLOAT3D& v0, FLOAT3D& v1)
{
  CBrushPolygonEdge_GetVertexCoordinatesRelative(C_Handle(), v0, v1);
}

inline void CBrushPolygonEdge::GetVertexCoordinatesPreciseRelative(DOUBLE3D& v0, DOUBLE3D& v1)
{
  CBrushPolygonEdge_GetVertexCoordinatesPreciseRelative(C_Handle(), v0, v1);
}

inline void CBrushPolygonEdge::GetVertexCoordinatesPreciseAbsolute(DOUBLE3D& v0, DOUBLE3D& v1)
{
  CBrushPolygonEdge_GetVertexCoordinatesPreciseAbsolute(C_Handle(), v0, v1);
}

inline CBrushShadowLayer::CBrushShadowLayer(CBrushShadowLayer_* p, bool)
  : mp_handle(p)
  , bsl_lnInShadowMap(CBrushShadowLayer_bsl_lnInShadowMap(p), false)
  , bsl_plsLightSource(*CBrushShadowLayer_bsl_plsLightSource(p))
{
}

inline CBrushShadowLayer::~CBrushShadowLayer()
{
}

inline CBrushShadowMap::CBrushShadowMap(CBrushShadowMap_* p, bool)
  : mp_handle(p)
  , bsm_lhLayers(CBrushShadowMap_bsm_lhLayers(p), false)
{
}

inline CBrushShadowMap::~CBrushShadowMap()
{
}

inline void CBrushShadowMap::DiscardAllLayers()
{
  CBrushShadowMap_DiscardAllLayers(C_Handle());
}

inline ULONG CBrushShadowMap::GetShadowSize()
{
  return CBrushShadowMap_GetShadowSize(C_Handle());
}

inline SLONG CBrushShadowMap::Uncache()
{
  return CBrushShadowMap_Uncache(C_Handle());
}

inline CBrushPolygonTexture::CBrushPolygonTexture(CBrushPolygonTexture_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bpt_toTexture(CBrushPolygonTexture_bpt_toTexture(p), false)
  , bpt_mdMapping(CBrushPolygonTexture_bpt_mdMapping(p), false)
  , bpt_ubScroll(*CBrushPolygonTexture_bpt_ubScroll(p))
  , bpt_ubBlend(*CBrushPolygonTexture_bpt_ubBlend(p))
  , bpt_ubFlags(*CBrushPolygonTexture_bpt_ubFlags(p))
  , bpt_ubDummy(*CBrushPolygonTexture_bpt_ubDummy(p))
  , bpt_colColor(*CBrushPolygonTexture_bpt_colColor(p))
{
}

inline CBrushPolygonTexture::CBrushPolygonTexture()
  : CBrushPolygonTexture(CBrushPolygonTexture_new(), true)
{
}

inline CBrushPolygonTexture::~CBrushPolygonTexture()
{
  if (m_owner)
    CBrushPolygonTexture_delete(mp_handle);
}

inline CBrushPolygonTexture& CBrushPolygonTexture::CopyTextureProperties(CBrushPolygonTexture& bptOther, BOOL bCopyMapping)
{
  CBrushPolygonTexture_CopyTextureProperties(C_Handle(), bptOther, bCopyMapping);
  return *this;
}

inline void CBrushPolygonTexture::Clear()
{
  CBrushPolygonTexture_Clear(C_Handle());
}

inline CBrushPolygonProperties::CBrushPolygonProperties(CBrushPolygonProperties_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bpp_ubSurfaceType(*CBrushPolygonProperties_bpp_ubSurfaceType(p))
  , bpp_ubIlluminationType(*CBrushPolygonProperties_bpp_ubIlluminationType(p))
  , bpp_ubShadowBlend(*CBrushPolygonProperties_bpp_ubShadowBlend(p))
  , bpp_ubMirrorType(*CBrushPolygonProperties_bpp_ubMirrorType(p))
  , bpp_ubGradientType(*CBrushPolygonProperties_bpp_ubGradientType(p))
  , bpp_sbShadowClusterSize(*CBrushPolygonProperties_bpp_sbShadowClusterSize(p))
  , bpp_uwPretenderDistance(*CBrushPolygonProperties_bpp_uwPretenderDistance(p))
{
}

inline CBrushPolygonProperties::CBrushPolygonProperties()
  : CBrushPolygonProperties(CBrushPolygonProperties_new(), true)
{
}

inline CBrushPolygonProperties::CBrushPolygonProperties(const CBrushPolygonProperties& o)
  : CBrushPolygonProperties(CBrushPolygonProperties_clone(o), true)
{
}

inline CBrushPolygonProperties::~CBrushPolygonProperties()
{
  if (m_owner)
    CBrushPolygonProperties_delete(mp_handle);
}

inline CBrushPolygonProperties& CBrushPolygonProperties::operator=(const CBrushPolygonProperties& o)
{
  CBrushPolygonProperties_copy(mp_handle, o);
  return *this;
}

inline CBrushPolygon::CBrushPolygon(CBrushPolygon_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bpo_pbplPlane(*CBrushPolygon_bpo_pbplPlane(p))
  , bpo_abpePolygonEdges(CBrushPolygon_bpo_abpePolygonEdges(p), false)
  , bpo_apbvxTriangleVertices(CBrushPolygon_bpo_apbvxTriangleVertices(p), false)
  , bpo_aiTriangleElements(CBrushPolygon_bpo_aiTriangleElements(p), false)
  , bpo_abptTextures {
    {CBrushPolygon_bpo_abptTextures(p, 0), false},
    {CBrushPolygon_bpo_abptTextures(p, 1), false},
    {CBrushPolygon_bpo_abptTextures(p, 2), false}
  }
  , bpo_colColor(*CBrushPolygon_bpo_colColor(p))
  , bpo_ulFlags(*CBrushPolygon_bpo_ulFlags(p))
  , bpo_colShadow(*CBrushPolygon_bpo_colShadow(p))
  , bpo_smShadowMap(CBrushPolygon_bpo_smShadowMap(p), false)
  , bpo_mdShadow(CBrushPolygon_bpo_mdShadow(p), false)
  , bpo_bppProperties(CBrushPolygon_bpo_bppProperties(p), false)
  , bpo_boxBoundingBox(CBrushPolygon_bpo_boxBoundingBox(p), false)
  , bpo_pbscSector(*CBrushPolygon_bpo_pbscSector(p))
  , bpo_rsOtherSideSectors(CBrushPolygon_bpo_rsOtherSideSectors(p), false)
{
}

inline CBrushPolygon::CBrushPolygon()
  : CBrushPolygon(CBrushPolygon_new(), true)
{
}

inline CBrushPolygon::~CBrushPolygon()
{
  if (m_owner)
    CBrushPolygon_delete(mp_handle);
}

inline void CBrushPolygon::InitializeShadowMap()
{
  CBrushPolygon_InitializeShadowMap(C_Handle());
}

inline CBrushPolygon& CBrushPolygon::CopyProperties(CBrushPolygon& bpoOther, BOOL bCopyMapping)
{
  CBrushPolygon_CopyProperties(C_Handle(), bpoOther, bCopyMapping);
  return *this;
}

inline CBrushPolygon& CBrushPolygon::CopyPropertiesWithoutTexture(CBrushPolygon& bpoOther)
{
  CBrushPolygon_CopyPropertiesWithoutTexture(C_Handle(), bpoOther);
  return *this;
}

inline CBrushPolygon& CBrushPolygon::CopyTextures(CBrushPolygon& bpoOther)
{
  CBrushPolygon_CopyTextures(C_Handle(), bpoOther);
  return *this;
}

inline BOOL CBrushPolygon::IsSelected() const
{
  return CBrushPolygon_IsSelected(C_Handle());
}

inline void CBrushPolygon::SelectSimilarByColor(CSelection_CBrushPolygon& selbpoSimilar)
{
  CBrushPolygon_SelectSimilarByColor(C_Handle(), selbpoSimilar);
}

inline void CBrushPolygon::SelectSimilarByTexture(CSelection_CBrushPolygon& selbpoSimilar, INDEX iTexture)
{
  CBrushPolygon_SelectSimilarByTexture(C_Handle(), selbpoSimilar, iTexture);
}

inline void CBrushPolygon::SelectByTextureInSector(CSelection_CBrushPolygon& selbpoSimilar, INDEX iTexture)
{
  CBrushPolygon_SelectByTextureInSector(C_Handle(), selbpoSimilar, iTexture);
}

inline void CBrushPolygon::SelectByColorInSector(CSelection_CBrushPolygon& selbpoSimilar)
{
  CBrushPolygon_SelectByColorInSector(C_Handle(), selbpoSimilar);
}

inline void CBrushPolygon::DiscardShadows()
{
  CBrushPolygon_DiscardShadows(C_Handle());
}

inline CBrushSector::CBrushSector(CBrushSector_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bsc_abvxVertices(CBrushSector_bsc_abvxVertices(p), false)
  , bsc_abedEdges(CBrushSector_bsc_abedEdges(p), false)
  , bsc_abplPlanes(CBrushSector_bsc_abplPlanes(p), false)
  , bsc_abpoPolygons(CBrushSector_bsc_abpoPolygons(p), false)
  , bsc_pbmBrushMip(*CBrushSector_bsc_pbmBrushMip(p))
  , bsc_colColor(*CBrushSector_bsc_colColor(p))
  , bsc_colAmbient(*CBrushSector_bsc_colAmbient(p))
  , bsc_ulFlags(*CBrushSector_bsc_ulFlags(p))
  , bsc_ulFlags2(*CBrushSector_bsc_ulFlags2(p))
  , bsc_ulVisFlags(*CBrushSector_bsc_ulVisFlags(p))
  , bsc_boxBoundingBox(CBrushSector_bsc_boxBoundingBox(p), false)
  , bsc_rdOtherSidePortals(CBrushSector_bsc_rdOtherSidePortals(p), false)
  , bsc_rsEntities(CBrushSector_bsc_rsEntities(p), false)
  , bsc_strName(CBrushSector_bsc_strName(p), false)
{
}

inline CBrushSector::CBrushSector()
  : CBrushSector(CBrushSector_new(), true)
{
}

inline CBrushSector::~CBrushSector()
{
  if (m_owner)
    CBrushSector_delete(mp_handle);
}

inline void CBrushSector::UpdateSector()
{
  CBrushSector_UpdateSector(C_Handle());
}

inline void CBrushSector::Clear()
{
  CBrushSector_Clear(C_Handle());
}

inline void CBrushSector::TriangularizePolygon(CBrushPolygon_* pbpo)
{
  CBrushSector_TriangularizePolygon(C_Handle(), pbpo);
}

inline void CBrushSector::TriangularizeForVertices(CBrushVertexSelection& selVertex)
{
  CBrushSector_TriangularizeForVertices(C_Handle(), selVertex);
}

inline void CBrushSector::InsertVertexIntoTriangle(CBrushPolygonSelection& selPolygon, FLOAT3D vVertex)
{
  CBrushSector_InsertVertexIntoTriangle(C_Handle(), selPolygon, vVertex);
}

inline BOOL CBrushSector::IsReTripleAvailable(CBrushPolygonSelection& selPolygon)
{
  return CBrushSector_IsReTripleAvailable(C_Handle(), selPolygon);
}

inline void CBrushSector::ReTriple(CBrushPolygonSelection& selPolygon)
{
  CBrushSector_ReTriple(C_Handle(), selPolygon);
}

inline BOOL CBrushSector::IsSelected() const
{
  return CBrushSector_IsSelected(C_Handle());
}

inline void CBrushSector::Read_t(CTStream* istrFile)
{
  CBrushSector_Read_t(C_Handle(), *istrFile);
  SECppAPI_CheckException();
}

inline void CBrushSector::Write_t(CTStream* ostrFile)
{
  CBrushSector_Write_t(C_Handle(), *ostrFile);
  SECppAPI_CheckException();
}

inline void CBrushSector::UncacheLightMaps()
{
  CBrushSector_UncacheLightMaps(C_Handle());
}

inline INDEX CBrushSector::GetContentType()
{
  return CBrushSector_GetContentType(C_Handle());
}

inline void CBrushSector::SetContentType(INDEX iNewContent)
{
  CBrushSector_SetContentType(C_Handle(), iNewContent);
}

inline INDEX CBrushSector::GetForceType()
{
  return CBrushSector_GetForceType(C_Handle());
}

inline void CBrushSector::SetForceType(INDEX iNewForce)
{
  CBrushSector_SetForceType(C_Handle(), iNewForce);
}

inline INDEX CBrushSector::GetFogType()
{
  return CBrushSector_GetFogType(C_Handle());
}

inline void CBrushSector::SetFogType(INDEX iNewForce)
{
  CBrushSector_SetFogType(C_Handle(), iNewForce);
}

inline INDEX CBrushSector::GetHazeType()
{
  return CBrushSector_GetHazeType(C_Handle());
}

inline void CBrushSector::SetHazeType(INDEX iNewForce)
{
  CBrushSector_SetHazeType(C_Handle(), iNewForce);
}

inline INDEX CBrushSector::GetEnvironmentType()
{
  return CBrushSector_GetEnvironmentType(C_Handle());
}

inline void CBrushSector::SetEnvironmentType(INDEX iNewEnvironment)
{
  CBrushSector_SetEnvironmentType(C_Handle(), iNewEnvironment);
}

inline CBrushMip::CBrushMip(CBrushMip_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , bm_abscSectors(CBrushMip_bm_abscSectors(p), false)
  , bm_pbrBrush(*CBrushMip_bm_pbrBrush(p))
  , bm_lnInBrush(CBrushMip_bm_lnInBrush(p), false)
  , bm_boxBoundingBox(CBrushMip_bm_boxBoundingBox(p), false)
{
}

inline CBrushMip::CBrushMip()
  : CBrushMip(CBrushMip_new(), true)
{
}

inline CBrushMip::~CBrushMip()
{
  if (m_owner)
    CBrushMip_delete(mp_handle);
}

inline void CBrushMip::Reoptimize()
{
  CBrushMip_Reoptimize(C_Handle());
}

inline void CBrushMip::Clear()
{
  CBrushMip_Clear(C_Handle());
}

inline void CBrushMip::Copy(CBrushMip& bmOther, FLOAT fStretch, BOOL bMirrorX)
{
  CBrushMip_Copy(C_Handle(), bmOther, fStretch, bMirrorX);
}

inline void CBrushMip::SetMipDistance(FLOAT fMipDistance)
{
  CBrushMip_SetMipDistance(C_Handle(), fMipDistance);
}

inline FLOAT CBrushMip::GetMipDistance()
{
  return CBrushMip_GetMipDistance(C_Handle());
}

inline INDEX CBrushMip::GetMipIndex()
{
  return CBrushMip_GetMipIndex(C_Handle());
}

__forceinline CBrushMipPtr CBrushMip::GetNext()
{
  return CBrushMip_GetNext(C_Handle());
}

__forceinline CBrushMipPtr CBrushMip::GetPrev()
{
  return CBrushMip_GetPrev(C_Handle());
}

inline CBrush3D::CBrush3D(CBrush3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , br_penEntity(*CBrush3D_br_penEntity(p))
  , br_lhBrushMips(CBrush3D_br_lhBrushMips(p), false)
{
}

inline CBrush3D::CBrush3D()
  : CBrush3D(CBrush3D_new(), true)
{
}

inline CBrush3D::~CBrush3D()
{
  if (m_owner)
    CBrush3D_delete(mp_handle);
}

inline void CBrush3D::CalculateBoundingBoxes()
{
  CBrush3D_CalculateBoundingBoxes(C_Handle());
}

inline void CBrush3D::Clear()
{
  CBrush3D_Clear(C_Handle());
}

inline void CBrush3D::FromObject3D_t(CObject3D& ob)
{
  CBrush3D_FromObject3D_t(C_Handle(), ob);
  SECppAPI_CheckException();
}

inline void CBrush3D::AddMipBrushFromObject3D_t(CObject3D& ob, FLOAT fSwitchDistance)
{
  CBrush3D_AddMipBrushFromObject3D_t(C_Handle(), ob, fSwitchDistance);
  SECppAPI_CheckException();
}

inline void CBrush3D::Copy(CBrush3D& brOther, FLOAT fStretch, BOOL bMirrorX)
{
  CBrush3D_Copy(C_Handle(), brOther, fStretch, bMirrorX);
}

inline void CBrush3D::DeleteBrushMip(CBrushMip_* pbmToDelete)
{
  CBrush3D_DeleteBrushMip(C_Handle(), pbmToDelete);
}

__forceinline CBrushMipPtr CBrush3D::NewBrushMipAfter(CBrushMip_* pbm, BOOL bCopy)
{
  return CBrush3D_NewBrushMipAfter(C_Handle(), pbm, bCopy);
}

__forceinline CBrushMipPtr CBrush3D::NewBrushMipBefore(CBrushMip_* pbm, BOOL bCopy)
{
  return CBrush3D_NewBrushMipBefore(C_Handle(), pbm, bCopy);
}

__forceinline CBrushMipPtr CBrush3D::GetBrushMipByDistance(FLOAT fDistance)
{
  return CBrush3D_GetBrushMipByDistance(C_Handle(), fDistance);
}

__forceinline CBrushMipPtr CBrush3D::GetFirstMip()
{
  return CBrush3D_GetFirstMip(C_Handle());
}

__forceinline CBrushMipPtr CBrush3D::GetLastMip()
{
  return CBrush3D_GetLastMip(C_Handle());
}

inline void CBrush3D::SwitchToNonZoning()
{
  CBrush3D_SwitchToNonZoning(C_Handle());
}

inline void CBrush3D::SwitchToZoning()
{
  CBrush3D_SwitchToZoning(C_Handle());
}

inline void CBrush3D::Read_t(CTStream* istrFile)
{
  CBrush3D_Read_t(C_Handle(), *istrFile);
  SECppAPI_CheckException();
}

inline void CBrush3D::Write_t(CTStream* ostrFile)
{
  CBrush3D_Write_t(C_Handle(), *ostrFile);
  SECppAPI_CheckException();
}
