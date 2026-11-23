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
#include "../Templates/StaticStackArray.h"
#include "../Templates/DynamicArray.h"
#include "../Graphics/Texture.h"
#include "Model_internal.h"
#include <SeriousEngineCAPI/Models/ModelData.h>

class CModelPatch
{
public:
  CModelPatch(CModelPatch_* p, bool owner = false);
  CModelPatch();
  ~CModelPatch();
  CModelPatch(const CModelPatch& o) = delete;
  CModelPatch& operator=(const CModelPatch& o) = delete;

  void Read_t(CTStream* strFile); // throw char *
  void Write_t(CTStream* strFile); // throw char *

  inline CModelPatch_* C_Handle() { return mp_handle; }
  inline const CModelPatch_* C_Handle() const { return mp_handle; }
  inline operator CModelPatch_* () { return C_Handle(); }
  inline operator const CModelPatch_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CModelPatch_* mp_handle = nullptr;

public:
  CTString mp_strName;
  CTextureObject mp_toTexture;
  MEX2D mp_mexPosition;
  FLOAT& mp_fStretch;
};

DECLARE_CStaticArray(PolygonsPerPatch)
IMPL_CStaticArray(PolygonsPerPatch)
DECLARE_CStaticArray(ModelPolygon)
IMPL_CStaticArray(ModelPolygon)
DECLARE_CStaticArray(ModelTextureVertex)
IMPL_CStaticArray(ModelTextureVertex)
DECLARE_CStaticArray(MappingSurface)
IMPL_CStaticArray(MappingSurface)

class ModelMipInfo
{
public:
  ModelMipInfo(ModelMipInfo_* p, bool owner = false);
  ModelMipInfo();
  ModelMipInfo(const ModelMipInfo& o) = delete;
  ~ModelMipInfo();
  ModelMipInfo& operator=(const ModelMipInfo& o);

  void Clear();                 // clears this mip model's arays and their sub-arrays, dealocates memory
  void Read_t(CTStream* istrFile, BOOL bReadPolygonalPatches, BOOL bReadPolygonsPerSurface,
    BOOL bReadSurfaceColors);  // throw char *
  void Write_t(CTStream* ostrFile); // throw char *

  inline ModelMipInfo_* C_Handle() { return mp_handle; }
  inline const ModelMipInfo_* C_Handle() const { return mp_handle; }
  inline operator ModelMipInfo_* () { return C_Handle(); }
  inline operator const ModelMipInfo_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  ModelMipInfo_* mp_handle = nullptr;

public:
  INDEX& mmpi_PolygonsCt;                          // how many polygons in this mip-model
  ULONG& mmpi_ulFlags;                             // flags for this mip model
  CStaticArray_PolygonsPerPatch   mmpi_aPolygonsPerPatch; // for each patch info telling which polygons are occupied by that patch
  CStaticArray_ModelPolygon       mmpi_Polygons;          // array of polygons
  CStaticArray_ModelTextureVertex mmpi_TextureVertices;    // with U,V and data for calculating U,V (for modeler) [???]
  CStaticArray_MappingSurface     mmpi_MappingSurfaces;    // with HPB, zoom, name of all surfaces

  // rendering info
  INDEX& mmpi_ctMipVx;
  INDEX& mmpi_ctSrfVx;                    // total number of surface vertices in this mip
  CStaticArray_UWORD   mmpi_auwMipToMdl;   // model vertices used in this mip
  CStaticArray_UWORD   mmpi_auwSrfToMip;     // surface vertices to mip vertices lookup
  CStaticArray_FLOAT2D mmpi_avmexTexCoord;   // texture coordinates for each surface vertex
  CStaticArray_FLOAT3D mmpi_avBumpU;   // bump directions for each surface vertex
  CStaticArray_FLOAT3D mmpi_avBumpV;   // bump directions for each surface vertex
  ULONG& mmpi_ulLayerFlags;              // all texture layers needed in this mip
  INDEX& mmpi_ctTriangles;               // total triangles in this mip
  CStaticStackArray_INDEX mmpi_aiElements;
};

DECLARE_CStaticArray(ModelFrameVertex8)
IMPL_CStaticArray(ModelFrameVertex8)
DECLARE_CStaticArray(ModelFrameVertex16)
IMPL_CStaticArray(ModelFrameVertex16)
DECLARE_CStaticArray(ModelFrameInfo)
IMPL_CStaticArray(ModelFrameInfo)
DECLARE_CStaticArray(TransformedVertexData)
IMPL_CStaticArray(TransformedVertexData)
DECLARE_CDynamicArray(CModelCollisionBox)
IMPL_CDynamicArray(CModelCollisionBox)
DECLARE_CDynamicArray(CAttachedModelPosition)
IMPL_CDynamicArray(CAttachedModelPosition)

class CModelData : public CAnimData
{
public:
  CModelData(CModelData_* p, bool owner = false);
  CModelData();
  ~CModelData();
  CModelData(const CModelData& o) = delete;
  CModelData& operator=(const CModelData& o) = delete;

  void SpreadMipSwitchFactors(INDEX iFirst, FLOAT fStartingFactor); // spreads mip switch factors
  void GetTextureDimensions(MEX& mexWidth, MEX& mexHeight); // riches texture dimensions
  void GetAllFramesBBox(FLOATaabbox3D& MaxBB);   // calculates all frame's bounding box
  FLOAT3D GetCollisionBoxMin(INDEX iCollisionBox);
  FLOAT3D GetCollisionBoxMax(INDEX iCollisionBox);
  // returns HEIGHT_EQ_WIDTH, LENGTH_EQ_WIDTH or LENGTH_EQ_HEIGHT
  INDEX GetCollisionBoxDimensionEquality(INDEX iCollisionBox);
  ULONG GetFlags();
  void Clear();
  void ClearAnimations();
  void LinkDataForSurfaces(BOOL bFirstMip);// calculate polygons and vertices for surface
  // array of mip factors determing where mip-models switch
  FLOAT& md_MipSwitchFactors(INDEX i);
  FLOAT md_MipSwitchFactors(INDEX i) const;
  void CreateAnimationsRaw(INDEX ct);

  inline CModelData_* C_Handle() { return (CModelData_*)CAnimData::C_Handle(); }
  inline const CModelData_* C_Handle() const { return (const CModelData_*)CAnimData::C_Handle(); }
  inline operator CModelData_* () { return C_Handle(); }
  inline operator const CModelData_* () const { return C_Handle(); }

public:
  INDEX& md_VerticesCt;                            // number of vertices in model
  INDEX& md_FramesCt;                              // number of all frames used by this model
  CStaticArray_ModelFrameVertex8 md_FrameVertices8;    // all frames and all their vertices [FramesCt*VerticesCt] (8-bit)
  CStaticArray_ModelFrameVertex16 md_FrameVertices16;  // same but 16-bit
  CStaticArray_ModelFrameInfo md_FrameInfos;          // bounding box info [FramesCt]
  CStaticArray_FLOAT3D md_MainMipVertices;        // global array with coordinates of all vertices of main mip-model, used for creating mip-models [VerticesCt]
  CStaticArray_TransformedVertexData md_TransformedVertices;    // buffer with i,j,k, rotated and stretched gouraud normal [VerticesCt]
  CStaticArray_ULONG md_VertexMipMask;            // array of vertice masks telling in which mip model some vertex exists [VerticesCt]
  INDEX& md_MipCt;                                  // number of mip-models
  ModelMipInfo md_MipInfos[MAX_MODELMIPS];  // contains how many polygons and which contains which vertices (different for each mip-model)
  MEX& md_Width;                             // size of texture, used for checking validiti of surfaces
  MEX& md_Height;
  CModelPatch md_mpPatches[MAX_TEXTUREPATCHES];    // patches themselfs
  CTString md_ColorNames[MAX_COLOR_NAMES];        // strings containing edited color names
  ULONG& md_Flags;                                  // model flags (face froward, reflesction mapping)
  SLONG& md_ShadowQuality;                          // determines maximum shadow quality
  FLOAT3D md_Stretch;                              // stretch vector (static one, dynamic one is in model object)
  FLOAT3D md_vCenter;                              // center of object
  FLOAT3D md_vCompressedCenter;                   // compressed (0-255) center of object (handle)
  BOOL& md_bHasAlpha;                              // set if any surface has alpha blending
  // array of collision boxes for this model
  CDynamicArray_CModelCollisionBox md_acbCollisionBox;
  BOOL& md_bCollideAsCube;                         // if model colide as stretched cube
  CDynamicArray_CAttachedModelPosition md_aampAttachedPosition;
  BOOL& md_bIsEdited;  // set if model is part of CEditModel object
  COLOR& md_colDiffuse;
  COLOR& md_colReflections;
  COLOR& md_colSpecular;
  COLOR& md_colBump;

  BOOL& md_bPreparedForRendering;  // set if model is prepared for rendering
};

#include "ModelData.inl"
