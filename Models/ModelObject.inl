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

inline CModelObject::CModelObject(CModelObject_* p, bool owner)
  : CAnimObject((CAnimObject_*)p, owner)
  , mo_toTexture(CModelObject_mo_toTexture(C_Handle()), false)
  , mo_toReflection(CModelObject_mo_toReflection(C_Handle()), false)
  , mo_toSpecular(CModelObject_mo_toSpecular(C_Handle()), false)
  , mo_toBump(CModelObject_mo_toBump(C_Handle()), false)
  , mo_Stretch(CModelObject_mo_Stretch(C_Handle()), false)
  , mo_ColorMask(*CModelObject_mo_ColorMask(C_Handle()))
  , mo_iLastRenderMipLevel(*CModelObject_mo_iLastRenderMipLevel(C_Handle()))
  , mo_colBlendColor(*CModelObject_mo_colBlendColor(C_Handle()))
  , mo_lhAttachments(CModelObject_mo_lhAttachments(C_Handle()), false)
{
}

inline CModelObject::CModelObject()
  : CModelObject(CModelObject_new(), true)
{
}

inline CModelObject::~CModelObject()
{
  if (m_owner)
    CModelObject_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline void CModelObject::Copy(CModelObject& moOther)
{
  CModelObject_Copy(C_Handle(), moOther);
}

inline MEX CModelObject::GetWidth()
{
  return CModelObject_GetWidth(C_Handle());
}

inline MEX CModelObject::GetHeight()
{
  return CModelObject_GetHeight(C_Handle());
}

inline void CModelObject::GetModelInfo(CModelInfo& miInfo)
{
  CModelObject_GetModelInfo(C_Handle(), miInfo);
}

inline BOOL CModelObject::IsModelVisible(FLOAT fMipFactor)
{
  return CModelObject_IsModelVisible(C_Handle(), fMipFactor);
}

inline INDEX CModelObject::GetMipModel(FLOAT fMipFactor)
{
  return CModelObject_GetMipModel(C_Handle(), fMipFactor);
}

inline BOOL CModelObject::HasShadow(INDEX iModelMip)
{
  return CModelObject_HasShadow(C_Handle(), iModelMip);
}

__forceinline FLOATaabbox3D CModelObject::GetFrameBBox(INDEX iFrameNo)
{
  return FLOATaabbox3D(CModelObject_GetFrameBBox(C_Handle(), iFrameNo), true);
}

inline BOOL CModelObject::IsAutoMipModeling()
{
  return CModelObject_IsAutoMipModeling(C_Handle());
}

inline void CModelObject::AutoMipModelingOn()
{
  CModelObject_AutoMipModelingOn(C_Handle());
}

inline void CModelObject::AutoMipModelingOff()
{
  CModelObject_AutoMipModelingOff(C_Handle());
}

inline INDEX CModelObject::GetManualMipLevel()
{
  return CModelObject_GetManualMipLevel(C_Handle());
}

inline void CModelObject::SetManualMipLevel(INDEX iNewMipLevel)
{
  CModelObject_SetManualMipLevel(C_Handle(), iNewMipLevel);
}

inline void CModelObject::PrevManualMipLevel()
{
  CModelObject_PrevManualMipLevel(C_Handle());
}

inline void CModelObject::NextManualMipLevel()
{
  CModelObject_NextManualMipLevel(C_Handle());
}

inline void CModelObject::SetMipSwitchFactor(INDEX iMipLevel, FLOAT fMipFactor)
{
  CModelObject_SetMipSwitchFactor(C_Handle(), iMipLevel, fMipFactor);
}

inline void CModelObject::GetCurrentFrameBBox(FLOATaabbox3D& MaxBB)
{
  CModelObject_GetCurrentFrameBBox(C_Handle(), MaxBB);
}

inline void CModelObject::GetAllFramesBBox(FLOATaabbox3D& MaxBB)
{
  CModelObject_GetAllFramesBBox(C_Handle(), MaxBB);
}

__forceinline FLOAT3D CModelObject::GetCollisionBoxMin(INDEX iCollisionBox)
{
  return FLOAT3D(CModelObject_GetCollisionBoxMin(C_Handle(), iCollisionBox), true);
}

__forceinline FLOAT3D CModelObject::GetCollisionBoxMax(INDEX iCollisionBox)
{
  return FLOAT3D(CModelObject_GetCollisionBoxMax(C_Handle(), iCollisionBox), true);
}

inline BOOL CModelObject::HasAlpha()
{
  return CModelObject_HasAlpha(C_Handle());
}

inline INDEX CModelObject::GetCollisionBoxDimensionEquality(INDEX iCollisionBox)
{
  return CModelObject_GetCollisionBoxDimensionEquality(C_Handle(), iCollisionBox);
}

inline INDEX CModelObject::SurfacesCt(INDEX iMipModel)
{
  return CModelObject_SurfacesCt(C_Handle(), iMipModel);
}

inline INDEX CModelObject::PolygonsInSurfaceCt(INDEX iMipModel, INDEX iSurface)
{
  return CModelObject_PolygonsInSurfaceCt(C_Handle(), iMipModel, iSurface);
}

inline COLOR CModelObject::GetSurfaceColor(INDEX iCurrentMip, INDEX iCurrentSurface)
{
  return CModelObject_GetSurfaceColor(C_Handle(), iCurrentMip, iCurrentSurface);
}

inline void CModelObject::SetSurfaceColor(INDEX iCurrentMip, INDEX iSurface, COLOR colNewColorAndAlpha)
{
  CModelObject_SetSurfaceColor(C_Handle(), iCurrentMip, iSurface, colNewColorAndAlpha);
}

inline void CModelObject::GetSurfaceRenderFlags(INDEX iCurrentMip, INDEX iCurrentSurface, SurfaceShadingType& sstShading, SurfaceTranslucencyType& sttTranslucency, ULONG& ulRenderingFlags)
{
  CModelObject_GetSurfaceRenderFlags(C_Handle(), iCurrentMip, iCurrentSurface, (SurfaceShadingType_*)&sstShading, (SurfaceTranslucencyType_*)&sttTranslucency, &ulRenderingFlags);
}

inline void CModelObject::SetSurfaceRenderFlags(INDEX iCurrentMip, INDEX iCurrentSurface, SurfaceShadingType sstShading, SurfaceTranslucencyType sttTranslucency, ULONG ulRenderingFlags)
{
  CModelObject_SetSurfaceRenderFlags(C_Handle(), iCurrentMip, iCurrentSurface, (SurfaceShadingType_)sstShading, (SurfaceTranslucencyType_)sttTranslucency, ulRenderingFlags);
}

__forceinline CTString CModelObject::GetColorName(INDEX iColor)
{
  return CTString(CModelObject_GetColorName(C_Handle(), iColor), true);
}

inline void CModelObject::SetColorName(INDEX iColor, CTString& strNewName)
{
  CModelObject_SetColorName(C_Handle(), iColor, strNewName);
}

inline ULONG CModelObject::GetPatchesMask()
{
  return CModelObject_GetPatchesMask(C_Handle());
}

inline void CModelObject::SetPatchesMask(ULONG new_patches_mask)
{
  CModelObject_SetPatchesMask(C_Handle(), new_patches_mask);
}

inline void CModelObject::UnpackVertex(CRenderModel& rm, const INDEX iVertex, FLOAT3D& vVertex)
{
  CModelObject_UnpackVertex_rm(C_Handle(), rm, iVertex, vVertex);
}

inline BOOL CModelObject::CreateAttachment(CRenderModel& rmMain, CAttachmentModelObject& amo)
{
  return CModelObject_CreateAttachment(C_Handle(), rmMain, amo);
}

inline void CModelObject::ResetAttachmentModelPosition(INDEX iAttachedPosition)
{
  CModelObject_ResetAttachmentModelPosition(C_Handle(), iAttachedPosition);
}

inline CAttachmentModelObjectPtr CModelObject::GetAttachmentModelList(INDEX iAttachedPosition, ...)
{
  va_list marker;
  va_start(marker, iAttachedPosition);

  CAttachmentModelObject_* pamo = nullptr;
  CModelObject_* pmo = *this;

  // while not end of list
  while (iAttachedPosition >= 0) {
    // get attachment
    pamo = CModelObject_GetAttachmentModel(pmo, iAttachedPosition);
    // if not found
    if (pamo == nullptr) {
      // return failure
      va_end(marker);
      return static_cast<CAttachmentModelObject_*>(nullptr);
    }
    // get next attachment in list
    pmo = CAttachmentModelObject_amo_moModelObject(pamo);
    iAttachedPosition = va_arg(marker, INDEX);
  }
  va_end(marker);

  // return current attachment
  return pamo;
}

__forceinline CAttachmentModelObjectPtr CModelObject::GetAttachmentModel(INDEX iAttachedPosition)
{
  return CModelObject_GetAttachmentModel(C_Handle(), iAttachedPosition);
}

__forceinline CAttachmentModelObjectPtr CModelObject::AddAttachmentModel(INDEX iAttachedPosition)
{
  return CModelObject_AddAttachmentModel(C_Handle(), iAttachedPosition);
}

inline void CModelObject::RemoveAttachmentModel(INDEX iAttachedPosition)
{
  CModelObject_RemoveAttachmentModel(C_Handle(), iAttachedPosition);
}

inline void CModelObject::RemoveAllAttachmentModels()
{
  CModelObject_RemoveAllAttachmentModels(C_Handle());
}

inline void CModelObject::StretchModel(const FLOAT3D& vStretch)
{
  CModelObject_StretchModel(C_Handle(), vStretch);
}

inline void CModelObject::StretchModelRelative(const FLOAT3D& vStretch)
{
  CModelObject_StretchModelRelative(C_Handle(), vStretch);
}

inline void CModelObject::StretchSingleModel(const FLOAT3D& vStretch)
{
  CModelObject_StretchSingleModel(C_Handle(), vStretch);
}

inline void CModelObject::SetupModelRendering(CRenderModel& rm)
{
  CModelObject_SetupModelRendering(C_Handle(), rm);
}

inline void CModelObject::RenderModel(CRenderModel& rm)
{
  CModelObject_RenderModel(C_Handle(), rm);
}

inline void CModelObject::AddSimpleShadow(CRenderModel& rm, const FLOAT fIntensity, const FLOATplane3D& plShadowPlane)
{
  CModelObject_AddSimpleShadow(C_Handle(), rm, fIntensity, plShadowPlane);
}

inline void CModelObject::RenderShadow(CRenderModel& rm, const CPlacement3D& plLight, const FLOAT fFallOff, const FLOAT fHotSpot, const FLOAT fIntensity, const FLOATplane3D& plShadowPlane)
{
  CModelObject_RenderShadow(C_Handle(), rm, plLight, fFallOff, fHotSpot, fIntensity, plShadowPlane);
}

inline void CModelObject::GetModelVertices(CStaticStackArray_FLOAT3D& avVertices, FLOATmatrix3D& mRotation, FLOAT3D& vPosition, FLOAT fNormalOffset, FLOAT fMipFactor)
{
  CModelObject_GetModelVertices(C_Handle(), avVertices, mRotation, vPosition, fNormalOffset, fMipFactor);
}

inline void CModelObject::GetAttachmentMatrices(CAttachmentModelObject_* pamo, FLOATmatrix3D& mRotation, FLOAT3D& vPosition)
{
  CModelObject_GetAttachmentMatrices(C_Handle(), pamo, mRotation, vPosition);
}

inline void CModelObject::GetAttachmentTransformations(INDEX iAttachment, FLOATmatrix3D& mRotation, FLOAT3D& vPosition, BOOL bDummyAttachment)
{
  CModelObject_GetAttachmentTransformations(C_Handle(), iAttachment, mRotation, vPosition, bDummyAttachment);
}

inline void CModelObject::ProjectFrameVertices(CProjection3D_* pProjection, INDEX iMipModel)
{
  CModelObject_ProjectFrameVertices(C_Handle(), pProjection, iMipModel);
}

inline void CModelObject::ColorizeRegion(CDrawPort_* pDP, CProjection3D_* projection, PIXaabbox2D box, INDEX iChoosedColor, BOOL bOnColorMode)
{
  CModelObject_ColorizeRegion(C_Handle(), pDP, projection, box, iChoosedColor, bOnColorMode);
}

inline void CModelObject::ColorizePolygon(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX iChoosedColor, BOOL bOnColorMode)
{
  CModelObject_ColorizePolygon(C_Handle(), pDP, projection, x1, y1, iChoosedColor, bOnColorMode);
}

inline void CModelObject::ApplySurfaceToPolygon(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX iSurface, COLOR colSurfaceColor)
{
  CModelObject_ApplySurfaceToPolygon(C_Handle(), pDP, projection, x1, y1, iSurface, colSurfaceColor);
}

inline void CModelObject::ApplySurfaceToPolygonsInRegion(CDrawPort_* pDP, CProjection3D_* projection, PIXaabbox2D box, INDEX iSurface, COLOR colSurfaceColor)
{
  CModelObject_ApplySurfaceToPolygonsInRegion(C_Handle(), pDP, projection, box, iSurface, colSurfaceColor);
}

inline void CModelObject::UnpackVertex(INDEX iFrame, INDEX iVertex, FLOAT3D& vVertex)
{
  CModelObject_UnpackVertex(C_Handle(), iFrame, iVertex, vVertex);
}

__forceinline CPlacement3D CModelObject::GetAttachmentPlacement(CAttachmentModelObject& amo)
{
  return CPlacement3D(CModelObject_GetAttachmentPlacement(C_Handle(), amo), true);
}

__forceinline ModelPolygonPtr CModelObject::PolygonHit(CPlacement3D plRay, CPlacement3D plObject, INDEX iCurrentMip, FLOAT& fHitDistance)
{
  return CModelObject_PolygonHit(C_Handle(), plRay, plObject, iCurrentMip, &fHitDistance);
}

__forceinline ModelPolygonPtr CModelObject::PolygonHitModelData(CModelData_* pMD, CPlacement3D plRay, CPlacement3D plObject, INDEX iCurrentMip, FLOAT& fHitDistance)
{
  return CModelObject_PolygonHitModelData(C_Handle(), pMD, plRay, plObject, iCurrentMip, &fHitDistance);
}

inline void CModelObject::PickPolyColor(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX& iPickedColorNo, BOOL bOnColorMode)
{
  CModelObject_PickPolyColor(C_Handle(), pDP, projection, x1, y1, &iPickedColorNo, bOnColorMode);
}

inline INDEX CModelObject::PickPolySurface(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1)
{
  return CModelObject_PickPolySurface(C_Handle(), pDP, projection, x1, y1);
}

inline INDEX CModelObject::PickVertexIndex(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, FLOAT3D& vClosestVertex)
{
  return CModelObject_PickVertexIndex(C_Handle(), pDP, projection, x1, y1, vClosestVertex);
}

inline void CModelObject::ShowPatch(INDEX iMaskBit)
{
  CModelObject_ShowPatch(C_Handle(), iMaskBit);
}

inline void CModelObject::HidePatch(INDEX iMaskBit)
{
  CModelObject_HidePatch(C_Handle(), iMaskBit);
}

inline void CModelObject::Read_t(CTStream* istrFile)
{
  CModelObject_Read_t(C_Handle(), *istrFile);
  SECppAPI_CheckException();
}

inline void CModelObject::Write_t(CTStream* ostrFile)
{
  CModelObject_Write_t(C_Handle(), *ostrFile);
  SECppAPI_CheckException();
}

inline void CModelObject::SetTextureData(CTextureData_* ptdNewMainTexture)
{
  CModelObject_SetTextureData(C_Handle(), ptdNewMainTexture);
}

__forceinline CTFileName CModelObject::GetName()
{
  return CTFileName(CModelObject_GetName(C_Handle()), true);
}

inline void CModelObject::AutoSetTextures()
{
  CModelObject_AutoSetTextures(C_Handle());
}

inline void CModelObject::AutoSetAttachments()
{
  CModelObject_AutoSetAttachments(C_Handle());
}

inline void CModelObject::SetData_t(const CTFileName& fnmModel)
{
  CModelObject_SetData_t(C_Handle(), fnmModel);
  SECppAPI_CheckException();
}

inline void CModelObject::SetData(CModelData_* pmd)
{
  CModelObject_SetData(C_Handle(), pmd);
}

__forceinline CModelDataPtr CModelObject::GetData()
{
  return CModelDataPtr(CModelObject_GetData(C_Handle()));
}

inline void CModelObject::Synchronize(CModelObject& moOther)
{
  CModelObject_Synchronize(C_Handle(), moOther);
}

inline SLONG CModelObject::GetUsedMemory()
{
  return CModelObject_GetUsedMemory(C_Handle());
}


inline CAttachmentModelObject::CAttachmentModelObject(CAttachmentModelObject_* p, bool)
  : mp_handle(p)
  , amo_lnInMain(CAttachmentModelObject_amo_lnInMain(mp_handle), false)
  , amo_iAttachedPosition(*CAttachmentModelObject_amo_iAttachedPosition(mp_handle))
  , amo_plRelative(CAttachmentModelObject_amo_plRelative(mp_handle), false)
  , amo_moModelObject(CAttachmentModelObject_amo_moModelObject(mp_handle), false)
  , amo_prm(*CAttachmentModelObject_amo_prm(mp_handle))
{
}
