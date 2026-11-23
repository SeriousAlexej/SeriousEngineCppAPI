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
#include "../Base/Lists.h"
#include "RenderModel.h"
#include "Model_internal.h"
#include "ModelData.h"
#include <SeriousEngineCAPI/Models/ModelObject.h>

class CModelObject : public CAnimObject
{
public:
  CModelObject(CModelObject_* p, bool owner = false);
  CModelObject();
  ~CModelObject();
  CModelObject(const CModelObject& o) = delete;
  CModelObject& operator=(const CModelObject& o) = delete;

  // copy from another object of same class
  void Copy(CModelObject& moOther);

  MEX GetWidth(); // retrieves model's texture width
  MEX GetHeight();// retrieves model's texture height
  void GetModelInfo(CModelInfo& miInfo);          // retrieves full model info
  BOOL IsModelVisible(FLOAT fMipFactor);          // is model visible for given mip factor
  INDEX GetMipModel(FLOAT fMipFactor);            // retrieves current mip model index
  BOOL HasShadow(INDEX iModelMip);                // test if model has shadow at given mip level
  FLOATaabbox3D GetFrameBBox(INDEX iFrameNo);    // retrieves bounding box of given frame
  BOOL IsAutoMipModeling();                       // TRUE if auto mip modeling is on
  void AutoMipModelingOn();                       // function starts auto mip modeling
  void AutoMipModelingOff();                       // function stops auto mip modeling
  INDEX GetManualMipLevel();                   // retrieves current mip level
  void SetManualMipLevel(INDEX iNewMipLevel);     // sets given mip-level as current (auto mip modeling off)
  void PrevManualMipLevel();                       // sets previous mip-level (more precize)
  void NextManualMipLevel();                       // sets next mip-level (more rough)
  void SetMipSwitchFactor(INDEX iMipLevel, FLOAT fMipFactor); // sets given mip-level's new switch factor
  /* retrieves current frame's bounding box */
  void GetCurrentFrameBBox(FLOATaabbox3D& MaxBB);
  /* retrieves bounding box of all frames */
  void GetAllFramesBBox(FLOATaabbox3D& MaxBB);
  FLOAT3D GetCollisionBoxMin(INDEX iCollisionBox);
  FLOAT3D GetCollisionBoxMax(INDEX iCollisionBox);
  // test it the model has alpha blending
  BOOL HasAlpha();
  // returns HEIGHT_EQ_WIDTH, LENGTH_EQ_WIDTH or LENGTH_EQ_HEIGHT
  INDEX GetCollisionBoxDimensionEquality(INDEX iCollisionBox);
  // retrieves number of surfaces used in given mip model
  INDEX SurfacesCt(INDEX iMipModel);
  // retrieves number of polygons in given surface in given mip model
  INDEX PolygonsInSurfaceCt(INDEX iMipModel, INDEX iSurface);
  COLOR GetSurfaceColor(INDEX iCurrentMip, INDEX iCurrentSurface); // retrieves color of given surface
  void SetSurfaceColor(INDEX iCurrentMip, INDEX iSurface, COLOR colNewColorAndAlpha); // changes color of given surface
  void GetSurfaceRenderFlags(INDEX iCurrentMip, INDEX iCurrentSurface,
    SurfaceShadingType& sstShading, SurfaceTranslucencyType& sttTranslucency,
    ULONG& ulRenderingFlags);
  void SetSurfaceRenderFlags(INDEX iCurrentMip, INDEX iCurrentSurface,
    SurfaceShadingType sstShading, SurfaceTranslucencyType sttTranslucency,
    ULONG ulRenderingFlags);
  CTString GetColorName(INDEX iColor);           // retrieves name of color with given index
  void SetColorName(INDEX iColor, CTString& strNewName); // sets new color name

  ULONG GetPatchesMask(); // this function returns current value of patches mask
  void  SetPatchesMask(ULONG new_patches_mask);      // use this function to set new patches combination

  void UnpackVertex(CRenderModel& rm, const INDEX iVertex, FLOAT3D& vVertex);
  BOOL CreateAttachment(CRenderModel& rmMain, CAttachmentModelObject& amo);
  void ResetAttachmentModelPosition(INDEX iAttachedPosition);
  CAttachmentModelObjectPtr GetAttachmentModelList(INDEX iAttachedPosition, ...);
  CAttachmentModelObjectPtr GetAttachmentModel(INDEX iAttachedPosition);
  CAttachmentModelObjectPtr AddAttachmentModel(INDEX iAttachedPosition);
  void RemoveAttachmentModel(INDEX iAttachedPosition);
  void RemoveAllAttachmentModels();
  void StretchModel(const FLOAT3D& vStretch);
  // stretches model relative to current size
  void StretchModelRelative(const FLOAT3D& vStretch);
  // stretches the model without stretching its children
  void StretchSingleModel(const FLOAT3D& vStretch);

  // model rendering
  void SetupModelRendering(CRenderModel& rm);
  void RenderModel(CRenderModel& rm);
  void AddSimpleShadow(CRenderModel& rm, const FLOAT fIntensity, const FLOATplane3D& plShadowPlane);
  void RenderShadow(CRenderModel& rm, const CPlacement3D& plLight,
    const FLOAT fFallOff, const FLOAT fHotSpot, const FLOAT fIntensity,
    const FLOATplane3D& plShadowPlane);

  // Get model vertices in absoulte space
  void GetModelVertices(CStaticStackArray_FLOAT3D& avVertices, FLOATmatrix3D& mRotation,
    FLOAT3D& vPosition, FLOAT fNormalOffset, FLOAT fMipFactor);
  void GetAttachmentMatrices(CAttachmentModelObject_* pamo, FLOATmatrix3D& mRotation, FLOAT3D& vPosition);
  void GetAttachmentTransformations(INDEX iAttachment, FLOATmatrix3D& mRotation, FLOAT3D& vPosition, BOOL bDummyAttachment);

  void ProjectFrameVertices(CProjection3D_* pProjection, INDEX iMipModel);
  void ColorizeRegion(CDrawPort_* pDP, CProjection3D_* projection, PIXaabbox2D box,
    INDEX iChoosedColor, BOOL bOnColorMode); // colorizes polygons touching given box
  void ColorizePolygon(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1,
    INDEX iChoosedColor, BOOL bOnColorMode); // colorizes hitted polygon
  void ApplySurfaceToPolygon(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1,
    INDEX iSurface, COLOR colSurfaceColor);
  void ApplySurfaceToPolygonsInRegion(CDrawPort_* pDP, CProjection3D_* projection,
    PIXaabbox2D box, INDEX iSurface, COLOR colSurfaceColor);
  void UnpackVertex(INDEX iFrame, INDEX iVertex, FLOAT3D& vVertex);
  CPlacement3D GetAttachmentPlacement(CAttachmentModelObject& amo);
  ModelPolygonPtr PolygonHit(CPlacement3D plRay, CPlacement3D plObject,
    INDEX iCurrentMip, FLOAT& fHitDistance); // returns ptr to hitted polygon (NULL if none)
  ModelPolygonPtr PolygonHitModelData(CModelData_* pMD, CPlacement3D plRay,
    CPlacement3D plObject, INDEX iCurrentMip, FLOAT& fHitDistance);
  void PickPolyColor(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1,
    INDEX& iPickedColorNo, BOOL bOnColorMode); // picks color from hitted polygon
  INDEX PickPolySurface(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1); // picks surface from hitted polygon
  INDEX PickVertexIndex(CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, FLOAT3D& vClosestVertex); // obtains index of closest vertex

  void ShowPatch(INDEX iMaskBit);
  void HidePatch(INDEX iMaskBit);
  void Read_t(CTStream* istrFile); // throw char *
  void Write_t(CTStream* ostrFile);// throw char *

  // set texture data for main texture in surface of this model
  void SetTextureData(CTextureData_* ptdNewMainTexture);
  CTFileName GetName();
  void AutoSetTextures();
  void AutoSetAttachments();
  // obtain model and set it for this object
  void SetData_t(const CTFileName& fnmModel); // throw char *
  void SetData(CModelData_* pmd);
  CModelDataPtr GetData();

  // synchronize with another model (copy animations/attachments positions etc from there)
  void Synchronize(CModelObject& moOther);

  // get amount of memory used by this object
  SLONG GetUsedMemory();

  inline CModelObject_* C_Handle() { return (CModelObject_*)CAnimObject::C_Handle(); }
  inline const CModelObject_* C_Handle() const { return (const CModelObject_*)CAnimObject::C_Handle(); }
  inline operator CModelObject_* () { return C_Handle(); }
  inline operator const CModelObject_* () const { return C_Handle(); }

public:
  CTextureObject mo_toTexture;                     // texture used for model rendering
  CTextureObject mo_toReflection;                   // texture used for reflection
  CTextureObject mo_toSpecular;                     // texture used for specularity
  CTextureObject mo_toBump;                        // texture used for bump
  FLOAT3D mo_Stretch;                              // dynamic stretching vector, (usually 1,1,1)
  ULONG& mo_ColorMask;                              // mask telling what parts (colors) are visible
  INDEX& mo_iLastRenderMipLevel;                   // last rendered mip model index remembered
  COLOR& mo_colBlendColor;                          // dynamic blend color (alpha is applied)
  CListHead mo_lhAttachments;                     // list of currently active attachment models
};


class CAttachmentModelObject
{
public:
  explicit CAttachmentModelObject(CAttachmentModelObject_* p, bool dummy = false);

  inline CAttachmentModelObject_* C_Handle() { return mp_handle; }
  inline const CAttachmentModelObject_* C_Handle() const { return mp_handle; }
  inline operator CAttachmentModelObject_* () { return C_Handle(); }
  inline operator const CAttachmentModelObject_* () const { return C_Handle(); }

private:
  CAttachmentModelObject_* mp_handle = nullptr;

public:
  CListNode amo_lnInMain;
  INDEX& amo_iAttachedPosition;        // indentifier of positions saved in model data
  CPlacement3D amo_plRelative;        // relative placement used for rendering
  CModelObject amo_moModelObject;     // model and texture
  CRenderModel_*& amo_prm;   // render model structure used in rendering
};

#include "ModelObject.inl"
