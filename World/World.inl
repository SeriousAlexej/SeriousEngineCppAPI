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

inline void CCastRay::Cast(CWorld* pwoWorld)
{
  CCastRay_Cast(C_Handle(), pwoWorld ? pwoWorld->C_Handle() : nullptr);
}

inline void CCastRay::ContinueCast(CWorld* pwoWorld)
{
  CCastRay_ContinueCast(C_Handle(), pwoWorld ? pwoWorld->C_Handle() : nullptr);
}

inline CWorld::CWorld(CWorld_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , wo_attTextureTransformations(CWorld_wo_attTextureTransformations(p), false)
  , wo_atbTextureBlendings(CWorld_wo_atbTextureBlendings(p), false)
  , wo_astSurfaceTypes(CWorld_wo_astSurfaceTypes(p), false)
  , wo_actContentTypes(CWorld_wo_actContentTypes(p), false)
  , wo_aetEnvironmentTypes(CWorld_wo_aetEnvironmentTypes(p), false)
  , wo_aitIlluminationTypes(CWorld_wo_aitIlluminationTypes(p), false)
  , wo_colBackground(*CWorld_wo_colBackground(p))
  , wo_strBackdropUp(CWorld_wo_strBackdropUp(p), false)
  , wo_strBackdropFt(CWorld_wo_strBackdropFt(p), false)
  , wo_strBackdropRt(CWorld_wo_strBackdropRt(p), false)
  , wo_strBackdropObject(CWorld_wo_strBackdropObject(p), false)
  , wo_fUpW(*CWorld_wo_fUpW(p))
  , wo_fUpL(*CWorld_wo_fUpL(p))
  , wo_fUpCX(*CWorld_wo_fUpCX(p))
  , wo_fUpCZ(*CWorld_wo_fUpCZ(p))
  , wo_fFtW(*CWorld_wo_fFtW(p))
  , wo_fFtH(*CWorld_wo_fFtH(p))
  , wo_fFtCX(*CWorld_wo_fFtCX(p))
  , wo_fFtCY(*CWorld_wo_fFtCY(p))
  , wo_fRtL(*CWorld_wo_fRtL(p))
  , wo_fRtH(*CWorld_wo_fRtH(p))
  , wo_fRtCZ(*CWorld_wo_fRtCZ(p))
  , wo_fRtCY(*CWorld_wo_fRtCY(p))
  , wo_plFocus(CWorld_wo_plFocus(p), false)
  , wo_fTargetDistance(*CWorld_wo_fTargetDistance(p))
  , wo_plThumbnailFocus(CWorld_wo_plThumbnailFocus(p), false)
  , wo_fThumbnailTargetDistance(*CWorld_wo_fThumbnailTargetDistance(p))
  , wo_fnmFileName(CWorld_wo_fnmFileName(p), false)
  , wo_cenEntities(CWorld_wo_cenEntities(p), false)
{
}

inline CWorld::CWorld()
  : CWorld(CWorld_new(), true)
{
}

inline CWorld::~CWorld()
{
  if (m_owner)
  {
    CWorld_delete(C_Handle());
    SECppAPI_CheckException();
  }
}

inline void CWorld::UntargetEntity(CEntity_* penToUntarget)
{
  CWorld_UntargetEntity(C_Handle(), penToUntarget);
  SECppAPI_CheckException();
}

inline void CWorld::TriangularizePolygons(CDynamicContainer_CBrushPolygon& dcPolygons)
{
  CWorld_TriangularizePolygons(C_Handle(), dcPolygons);
  SECppAPI_CheckException();
}

inline void CWorld::Clear()
{
  CWorld_Clear(C_Handle());
  SECppAPI_CheckException();
}

__forceinline CEntityPtr CWorld::CreateEntity_t(const CPlacement3D& plPlacement, const CTFileName& fnmClass)
{
  auto* res = CWorld_CreateEntity_t(C_Handle(), plPlacement, fnmClass);
  SECppAPI_CheckException();
  return res;
}

__forceinline CEntityPtr CWorld::CopyOneEntity(CEntity& enToCopy, const CPlacement3D& plOtherSystem)
{
  auto* res = CWorld_CopyOneEntity(C_Handle(), enToCopy, plOtherSystem);
  SECppAPI_CheckException();
  return res;
}

inline void CWorld::CopyEntities(CWorld& woOther, CDynamicContainer_CEntity& cenToCopy, CEntitySelection& senCopied, const CPlacement3D& plOtherSystem)
{
  CWorld_CopyEntities(C_Handle(), woOther, cenToCopy, senCopied, plOtherSystem);
  SECppAPI_CheckException();
}

__forceinline CEntityPtr CWorld::CopyEntityInWorld(CEntity& enOriginal, const CPlacement3D& plOtherEntity, BOOL bWithDescendants)
{
  auto* res = CWorld_CopyEntityInWorld(C_Handle(), enOriginal, plOtherEntity, bWithDescendants);
  SECppAPI_CheckException();
  return res;
}

inline void CWorld::DestroyEntities(CEntitySelection& senToDestroy)
{
  CWorld_DestroyEntities(C_Handle(), senToDestroy);
  SECppAPI_CheckException();
}

inline void CWorld::DestroyOneEntity(CEntity_* penToDestroy)
{
  CWorld_DestroyOneEntity(C_Handle(), penToDestroy);
  SECppAPI_CheckException();
}

inline void CWorld::CastRay(CCastRay& crRay)
{
  CWorld_CastRay(C_Handle(), crRay);
}

inline void CWorld::ContinueCast(CCastRay& crRay)
{
  CWorld_ContinueCast(C_Handle(), crRay);
}

inline void CWorld::SetBackgroundColor(COLOR colBackground)
{
  CWorld_SetBackgroundColor(C_Handle(), colBackground);
}

inline COLOR CWorld::GetBackgroundColor()
{
  return CWorld_GetBackgroundColor(C_Handle());
}

__forceinline CEntityPtr CWorld::GetBackgroundViewer()
{
  return CWorld_GetBackgroundViewer(C_Handle());
}

inline void CWorld::SetDescription(const CTString& strDescription)
{
  CWorld_SetDescription(C_Handle(), strDescription);
}

__forceinline CTString CWorld::GetDescription()
{
  return CTString(CWorld_GetDescription(C_Handle()), true);
}

inline void CWorld::SetName(const CTString& strName)
{
  CWorld_SetName(C_Handle(), strName);
}

__forceinline CTString CWorld::GetName()
{
  return CTString(CWorld_GetName(C_Handle()), true);
}

inline void CWorld::SetSpawnFlags(ULONG ulFlags)
{
  CWorld_SetSpawnFlags(C_Handle(), ulFlags);
}

inline ULONG CWorld::GetSpawnFlags()
{
  return CWorld_GetSpawnFlags(C_Handle());
}

inline void CWorld::Save_t(const CTFileName& fnmWorld)
{
  CWorld_Save_t(C_Handle(), fnmWorld);
  SECppAPI_CheckException();
}

inline void CWorld::Load_t(const CTFileName& fnmWorld)
{
  CWorld_Load_t(C_Handle(), fnmWorld);
  SECppAPI_CheckException();
}

inline void CWorld::ReinitializeEntities()
{
  CWorld_ReinitializeEntities(C_Handle());
  SECppAPI_CheckException();
}

inline void CWorld::Read_t(CTStream* pistrm)
{
  CWorld_Read_t(C_Handle(), *pistrm);
  SECppAPI_CheckException();
}

inline void CWorld::Write_t(CTStream* postrm)
{
  CWorld_Write_t(C_Handle(), *postrm);
  SECppAPI_CheckException();
}

inline void CWorld::UpdateSectorsAfterVertexChange(CBrushVertexSelection& selVertex)
{
  CWorld_UpdateSectorsAfterVertexChange(C_Handle(), selVertex);
}

inline void CWorld::UpdateSectorsDuringVertexChange(CBrushVertexSelection& selVertex)
{
  CWorld_UpdateSectorsDuringVertexChange(C_Handle(), selVertex);
}

inline void CWorld::TriangularizeForVertices(CBrushVertexSelection& selVertex)
{
  CWorld_TriangularizeForVertices(C_Handle(), selVertex);
  SECppAPI_CheckException();
}

inline void CWorld::CSGAdd(CEntity& enThis, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther)
{
  CWorld_CSGAdd(C_Handle(), enThis, woOther, enOther, plOther);
  SECppAPI_CheckException();
}

inline void CWorld::CSGAddReverse(CEntity& enThis, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther)
{
  CWorld_CSGAddReverse(C_Handle(), enThis, woOther, enOther, plOther);
  SECppAPI_CheckException();
}

inline void CWorld::CSGRemove(CEntity& enThis, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther)
{
  CWorld_CSGRemove(C_Handle(), enThis, woOther, enOther, plOther);
  SECppAPI_CheckException();
}

inline void CWorld::SplitSectors(CEntity& enThis, CBrushSectorSelection& selbscSectorsToSplit, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther)
{
  CWorld_SplitSectors(C_Handle(), enThis, selbscSectorsToSplit, woOther, enOther, plOther);
  SECppAPI_CheckException();
}

inline BOOL CWorld::CanJoinSectors(CBrushSectorSelection& selbscSectorsToJoin)
{
  return CWorld_CanJoinSectors(C_Handle(), selbscSectorsToJoin);
}

inline void CWorld::JoinSectors(CBrushSectorSelection& selbscSectorsToJoin)
{
  CWorld_JoinSectors(C_Handle(), selbscSectorsToJoin);
  SECppAPI_CheckException();
}

inline void CWorld::SplitPolygons(CEntity& enThis, CBrushPolygonSelection& selbpoPolygonsToSplit, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther)
{
  CWorld_SplitPolygons(C_Handle(), enThis, selbpoPolygonsToSplit, woOther, enOther, plOther);
  SECppAPI_CheckException();
}

inline void CWorld::JoinPolygons(CBrushPolygonSelection& selbpoPolygonsToJoin)
{
  CWorld_JoinPolygons(C_Handle(), selbpoPolygonsToJoin);
  SECppAPI_CheckException();
}

inline BOOL CWorld::CanJoinPolygons(CBrushPolygonSelection& selbpoPolygonsToJoin)
{
  return CWorld_CanJoinPolygons(C_Handle(), selbpoPolygonsToJoin);
}

inline void CWorld::JoinAllPossiblePolygons(CBrushPolygonSelection& selbpoPolygonsToJoin, BOOL bPreserveTextures, INDEX iTexture)
{
  CWorld_JoinAllPossiblePolygons(C_Handle(), selbpoPolygonsToJoin, bPreserveTextures, iTexture);
  SECppAPI_CheckException();
}

inline BOOL CWorld::CanJoinAllPossiblePolygons(CBrushPolygonSelection& selbpoPolygonsToJoin)
{
  return CWorld_CanJoinAllPossiblePolygons(C_Handle(), selbpoPolygonsToJoin);
}

inline BOOL CWorld::CanCopySectors(CBrushSectorSelection& selbscSectorsToCopy)
{
  return CWorld_CanCopySectors(C_Handle(), selbscSectorsToCopy);
}

inline void CWorld::CopySectors(CBrushSectorSelection& selbscSectorsToCopy, CEntity_* penTarget, BOOL bWithEntities)
{
  CWorld_CopySectors(C_Handle(), selbscSectorsToCopy, penTarget, bWithEntities);
  SECppAPI_CheckException();
}

inline void CWorld::DeleteSectors(CBrushSectorSelection& selbscSectorsToDelete, BOOL bClearPortalFlags)
{
  CWorld_DeleteSectors(C_Handle(), selbscSectorsToDelete, bClearPortalFlags);
  SECppAPI_CheckException();
}

inline void CWorld::CopyPolygonInWorld(CBrushPolygon& bpoSrc, CBrushSector& bsc, INDEX iPol, INDEX& iEdg, INDEX& iVtx)
{
  CWorld_CopyPolygonInWorld(C_Handle(), bpoSrc, bsc, iPol, &iEdg, &iVtx);
  SECppAPI_CheckException();
}

inline void CWorld::CopyPolygonsToBrush(CBrushPolygonSelection& selPolygons, CEntity_* penbr)
{
  CWorld_CopyPolygonsToBrush(C_Handle(), selPolygons, penbr);
  SECppAPI_CheckException();
}

inline void CWorld::DeletePolygons(CDynamicContainer_CBrushPolygon& dcPolygons)
{
  CWorld_DeletePolygons(C_Handle(), dcPolygons);
  SECppAPI_CheckException();
}

inline void CWorld::CreatePolygon(CBrushVertexSelection& selVtx)
{
  CWorld_CreatePolygon(C_Handle(), selVtx);
  SECppAPI_CheckException();
}

inline void CWorld::FlipPolygon(CBrushPolygon& bpo)
{
  CWorld_FlipPolygon(C_Handle(), bpo);
  SECppAPI_CheckException();
}

inline void CWorld::MirrorAndStretch(CWorld& woOriginal, FLOAT fStretch, WorldMirrorType wmt)
{
  CWorld_MirrorAndStretch(C_Handle(), woOriginal, fStretch, (WorldMirrorType_)wmt);
  SECppAPI_CheckException();
}

inline void CWorld::HideSelectedEntities(CDynamicContainer_CEntity& selenEntitiesToHide)
{
  CWorld_HideSelectedEntities(C_Handle(), selenEntitiesToHide);
}

inline void CWorld::HideUnselectedEntities()
{
  CWorld_HideUnselectedEntities(C_Handle());
}

inline void CWorld::ShowAllEntities()
{
  CWorld_ShowAllEntities(C_Handle());
}

inline void CWorld::HideSelectedSectors(CBrushSectorSelection& selbscSectorsToHide)
{
  CWorld_HideSelectedSectors(C_Handle(), selbscSectorsToHide);
}

inline void CWorld::HideUnselectedSectors()
{
  CWorld_HideUnselectedSectors(C_Handle());
}

inline void CWorld::ShowAllSectors()
{
  CWorld_ShowAllSectors(C_Handle());
}

inline void CWorld::CalculateDirectionalShadows()
{
  CWorld_CalculateDirectionalShadows(C_Handle());
  SECppAPI_CheckException();
}

inline void CWorld::CalculateNonDirectionalShadows()
{
  CWorld_CalculateNonDirectionalShadows(C_Handle());
  SECppAPI_CheckException();
}

inline void CWorld::FindShadowLayers(const FLOATaabbox3D& boxNear, BOOL bSelectedOnly, BOOL bDirectional)
{
  CWorld_FindShadowLayers(C_Handle(), boxNear, bSelectedOnly, bDirectional);
  SECppAPI_CheckException();
}

inline void CWorld::DiscardAllShadows()
{
  CWorld_DiscardAllShadows(C_Handle());
  SECppAPI_CheckException();
}

inline void CWorld::RebuildLinks()
{
  CWorld_RebuildLinks(C_Handle());
  SECppAPI_CheckException();
}
