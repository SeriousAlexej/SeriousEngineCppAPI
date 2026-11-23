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
#include "../Base/Types.h"
#include "../Math/Vector.h"
#include "../Math/AABBox.h"
#include "../Math/Placement.h"
#include "../Templates/StaticArray.h"
#include <SeriousEngineCAPI/Models/Model_internal.h>

// surface shading types
enum SurfaceShadingType : SurfaceShadingType_
{
  SST_INVALID = SST_INVALID_,
  SST_FULLBRIGHT = SST_FULLBRIGHT_,
  SST_MATTE = SST_MATTE_,
  SST_FLAT = SST_FLAT_,
};

// surface translucency types
enum SurfaceTranslucencyType : SurfaceTranslucencyType_
{
  STT_INVALID = STT_INVALID_,
  STT_OPAQUE = STT_OPAQUE_,
  STT_TRANSLUCENT = STT_TRANSLUCENT_,
  STT_ALPHAGOURAUD = STT_ALPHAGOURAUD_,  // obsolete!
  STT_ADD = STT_ADD_,
  STT_TRANSPARENT = STT_TRANSPARENT_,
  STT_MULTIPLY = STT_MULTIPLY_,
};

// colors used to represent on and off bits
#define PaletteColorValues\
  PaletteColorValues_()

class ModelFrameVertex8
{
public:
  ModelFrameVertex8(ModelFrameVertex8_* p, bool owner = false);
  ModelFrameVertex8();
  ModelFrameVertex8(const ModelFrameVertex8& o);
  ~ModelFrameVertex8();
  ModelFrameVertex8& operator=(const ModelFrameVertex8& o);

  inline ModelFrameVertex8_* C_Handle() { return mp_handle; }
  inline const ModelFrameVertex8_* C_Handle() const { return mp_handle; }
  inline operator ModelFrameVertex8_* () { return C_Handle(); }
  inline operator const ModelFrameVertex8_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  ModelFrameVertex8_* mp_handle = nullptr;

public:
  SBPOINT3D mfv_SBPoint; // 8-bit compressed vertex
  UBYTE& mfv_NormIndex;
};

class ModelFrameVertex16
{
public:
  ModelFrameVertex16(ModelFrameVertex16_* p, bool owner = false);
  ModelFrameVertex16();
  ModelFrameVertex16(const ModelFrameVertex16& o);
  ~ModelFrameVertex16();
  ModelFrameVertex16& operator=(const ModelFrameVertex16& o);

  inline ModelFrameVertex16_* C_Handle() { return mp_handle; }
  inline const ModelFrameVertex16_* C_Handle() const { return mp_handle; }
  inline operator ModelFrameVertex16_* () { return C_Handle(); }
  inline operator const ModelFrameVertex16_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  ModelFrameVertex16_* mp_handle = nullptr;

public:
  SWPOINT3D mfv_SWPoint; // 16-bit compressed vertex
  UBYTE& mfv_ubNormH;
  UBYTE& mfv_ubNormP;
};

class ModelFrameInfo
{
public:
  ModelFrameInfo(ModelFrameInfo_* p, bool owner = false);
  ModelFrameInfo();
  ModelFrameInfo(const ModelFrameInfo& o);
  ~ModelFrameInfo();
  ModelFrameInfo& operator=(const ModelFrameInfo& o);

  inline ModelFrameInfo_* C_Handle() { return mp_handle; }
  inline const ModelFrameInfo_* C_Handle() const { return mp_handle; }
  inline operator ModelFrameInfo_* () { return C_Handle(); }
  inline operator const ModelFrameInfo_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  ModelFrameInfo_* mp_handle = nullptr;

public:
  FLOATaabbox3D mfi_Box; // bounding box info for each frame
};

class ModelTextureVertex
{
public:
  ModelTextureVertex(ModelTextureVertex_* p, bool owner = false);
  ModelTextureVertex();
  ModelTextureVertex(const ModelTextureVertex& o);
  ~ModelTextureVertex();
  ModelTextureVertex& operator=(const ModelTextureVertex& o);

  inline ModelTextureVertex_* C_Handle() { return mp_handle; }
  inline const ModelTextureVertex_* C_Handle() const { return mp_handle; }
  inline operator ModelTextureVertex_* () { return C_Handle(); }
  inline operator const ModelTextureVertex_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  ModelTextureVertex_* mp_handle = nullptr;

public:
  FLOAT3D mtv_UVW; // 3D coordinate of one texture vertex
  MEX2D mtv_UV; // U,V mapping coordinates
};

class TransformedVertexData
{
public:
  TransformedVertexData(TransformedVertexData_* p, bool owner = false);
  TransformedVertexData();
  TransformedVertexData(const TransformedVertexData& o);
  ~TransformedVertexData();
  TransformedVertexData& operator=(const TransformedVertexData& o);

  inline TransformedVertexData_* C_Handle() { return mp_handle; }
  inline const TransformedVertexData_* C_Handle() const { return mp_handle; }
  inline operator TransformedVertexData_* () { return C_Handle(); }
  inline operator const TransformedVertexData_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  TransformedVertexData_* mp_handle = nullptr;

public:
  FLOAT3D tvd_TransformedPoint; // for transformed point vector
  FLOAT& tvd_fX; // view space original coords
  FLOAT& tvd_fY;
  FLOAT& tvd_fZ;
  FLOAT& tvd_fU; // texture mapping temp vars for clipping purposes
  FLOAT& tvd_fV;
  BOOL& tvd_bClipped; // is clipped to near clip plane or screen boundaries?
};

class ModelPolygonVertex
{
public:
  ModelPolygonVertex(ModelPolygonVertex_* p, bool owner = false);
  ModelPolygonVertex();
  ModelPolygonVertex(const ModelPolygonVertex& o);
  ~ModelPolygonVertex();
  ModelPolygonVertex& operator=(const ModelPolygonVertex& o);

  void Read_t(CTStream* istrFile);   // throw char *
  void Write_t(CTStream* ostrFile);  // throw char *

  inline ModelPolygonVertex_* C_Handle() { return mp_handle; }
  inline const ModelPolygonVertex_* C_Handle() const { return mp_handle; }
  inline operator ModelPolygonVertex_* () { return C_Handle(); }
  inline operator const ModelPolygonVertex_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  ModelPolygonVertex_* mp_handle = nullptr;

public:
  TransformedVertexData_*& mpv_ptvTransformedVertex; // buffer where vertices really rotate
  ModelTextureVertex_*& mpv_ptvTextureVertex;    // needed by modeler to calculate U,V
};

DECLARE_CStaticArray(ModelPolygonVertex)
IMPL_CStaticArray(ModelPolygonVertex)

class ModelPolygon
{
public:
  ModelPolygon(ModelPolygon_* p, bool owner = false);
  ModelPolygon();
  ModelPolygon(const ModelPolygon& o) = delete;
  ~ModelPolygon();
  ModelPolygon& operator=(const ModelPolygon& o);

  void Read_t(CTStream* istrFile);       // throw char *
  void Write_t(CTStream* ostrFile);      // throw char *

  inline ModelPolygon_* C_Handle() { return mp_handle; }
  inline const ModelPolygon_* C_Handle() const { return mp_handle; }
  inline operator ModelPolygon_* () { return C_Handle(); }
  inline operator const ModelPolygon_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  ModelPolygon_* mp_handle = nullptr;

public:
  CStaticArray_ModelPolygonVertex mp_PolygonVertices;  // this polygon's vertices
  ULONG& mp_RenderFlags; // flags which define rendering of this polygon
  ULONG& mp_ColorAndAlpha; // color and global alpha for this polygon
  INDEX& mp_Surface; // in which surface this polygon belongs
  SLONG& mp_slVisibility; // how this poligon is visible
  BOOL&  mp_bClipped; // is polygon clipped
};

class MappingSurface
{
public:
  MappingSurface(MappingSurface_* p, bool owner = false);
  MappingSurface();
  MappingSurface(const MappingSurface& o) = delete;
  ~MappingSurface();
  MappingSurface& operator=(const MappingSurface& o);
  BOOL operator==(const MappingSurface& o) const;

  void Read_t(CTStream* istrFile, BOOL bReadPolygonsPerSurface, BOOL bReadSurfaceColors); // throw char *
  void Write_t(CTStream* ostrFile);      // throw char *
  void ReadSettings_t(CTStream* istrFile);       // throw char *
  void WriteSettings_t(CTStream* ostrFile);      // throw char *

  inline MappingSurface_* C_Handle() { return mp_handle; }
  inline const MappingSurface_* C_Handle() const { return mp_handle; }
  inline operator MappingSurface_* () { return C_Handle(); }
  inline operator const MappingSurface_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  MappingSurface_* mp_handle = nullptr;

public:
  CTString ms_Name;                               // name of this surface
  COLOR&  ms_colColor;                            // color of this surface
  FLOAT3D ms_vSurfaceCenterOffset;                // vector of surface center offseting

  COLOR& ms_colDiffuse;                            // difuse color of this surface
  COLOR& ms_colReflections;                        // reflections color of this surface
  COLOR& ms_colSpecular;                            // specular color of this surface
  COLOR& ms_colBump;                                // bump color of this surface

  ULONG& ms_ulOnColor;                             // on and off colors for surface
  ULONG& ms_ulOffColor;

  ULONG& ms_ulRenderingFlags;                           // surface rendering flags
  SurfaceShadingType& ms_sstShadingType;      // surface shading types
  SurfaceTranslucencyType& ms_sttTranslucencyType; // surface translucency types
  CStaticArray_INDEX ms_aiPolygons;              // indices of all polygons in surface
  CStaticArray_INDEX ms_aiTextureVertices;        // indices of all texture vertices in surface

  // rendering data
  INDEX& ms_iSrfVx0;  // first surface vertex
  INDEX& ms_ctSrfVx;  // number of surface vertices
  INDEX& ms_ctSrfEl;  // number of surface elemtns
};

// struct containing list of polygons that are touched by current patch
class PolygonsPerPatch
{
public:
  PolygonsPerPatch(PolygonsPerPatch_* p, bool owner = false);
  PolygonsPerPatch();
  PolygonsPerPatch(const PolygonsPerPatch& o) = delete;
  ~PolygonsPerPatch();
  PolygonsPerPatch& operator=(const PolygonsPerPatch& o);

  void Clear();

  inline PolygonsPerPatch_* C_Handle() { return mp_handle; }
  inline const PolygonsPerPatch_* C_Handle() const { return mp_handle; }
  inline operator PolygonsPerPatch_* () { return C_Handle(); }
  inline operator const PolygonsPerPatch_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  PolygonsPerPatch_* mp_handle = nullptr;

public:
  CStaticArray_INDEX ppp_iPolygons;  // indices of polygons occupied by this patch
  // rendering info
  CStaticArray_UWORD ppp_auwElements; // elements for drawing
};

class CModelCollisionBox
{
public:
  CModelCollisionBox(CModelCollisionBox_* p, bool owner = false);
  CModelCollisionBox();
  CModelCollisionBox(const CModelCollisionBox& o);
  ~CModelCollisionBox();
  CModelCollisionBox& operator=(const CModelCollisionBox& o);

  void Read_t(CTStream* istrFile);
  void ReadName_t(CTStream* istrFile);
  void Write_t(CTStream* ostrFile);

  inline CModelCollisionBox_* C_Handle() { return mp_handle; }
  inline const CModelCollisionBox_* C_Handle() const { return mp_handle; }
  inline operator CModelCollisionBox_* () { return C_Handle(); }
  inline operator const CModelCollisionBox_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CModelCollisionBox_* mp_handle = nullptr;

public:
  FLOAT3D mcb_vCollisionBoxMin;                   // min vector of collision box
  FLOAT3D mcb_vCollisionBoxMax;                   // max vector of collision box
  ULONG& mcb_iCollisionBoxDimensionEquality;       // HEIGHT_EQ_WIDTH or LENGTH_EQ_WIDTH or LENGTH_EQ_HEIGHT
  CTString mcb_strName;                           // name of collision box (exported as define)
};

class CAttachedModelPosition
{
public:
  CAttachedModelPosition(CAttachedModelPosition_* p, bool owner = false);
  CAttachedModelPosition();
  CAttachedModelPosition(const CAttachedModelPosition& o);
  ~CAttachedModelPosition();
  CAttachedModelPosition& operator=(const CAttachedModelPosition& o);

  void Read_t(CTStream* strFile); // throw char *
  void Write_t(CTStream* strFile); // throw char *

  inline CAttachedModelPosition_* C_Handle() { return mp_handle; }
  inline const CAttachedModelPosition_* C_Handle() const { return mp_handle; }
  inline operator CAttachedModelPosition_* () { return C_Handle(); }
  inline operator const CAttachedModelPosition_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CAttachedModelPosition_* mp_handle = nullptr;

public:
  INDEX& amp_iCenterVertex;
  INDEX& amp_iFrontVertex;
  INDEX& amp_iUpVertex;
  CPlacement3D amp_plRelativePlacement;
};

class CMipInfo
{
public:
  CMipInfo(CMipInfo_* p, bool owner = false);
  CMipInfo();
  CMipInfo(const CMipInfo& o);
  ~CMipInfo();
  CMipInfo& operator=(const CMipInfo& o);

  inline CMipInfo_* C_Handle() { return mp_handle; }
  inline const CMipInfo_* C_Handle() const { return mp_handle; }
  inline operator CMipInfo_* () { return C_Handle(); }
  inline operator const CMipInfo_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CMipInfo_* mp_handle = nullptr;

public:
  INDEX& mi_TrianglesCt; // how many triangles in this mip-model
  INDEX& mi_PolygonsCt; // how many polygons in this mip-model
  INDEX& mi_VerticesCt; // how many vertices in this mip-model
};

class CModelInfo
{
public:
  CModelInfo(CModelInfo_* p, bool owner = false);
  CModelInfo();
  CModelInfo(const CModelInfo& o);
  ~CModelInfo();
  CModelInfo& operator=(const CModelInfo& o);

  inline CModelInfo_* C_Handle() { return mp_handle; }
  inline const CModelInfo_* C_Handle() const { return mp_handle; }
  inline operator CModelInfo_* () { return C_Handle(); }
  inline operator const CModelInfo_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CModelInfo_* mp_handle = nullptr;

public:
  INDEX& mi_VerticesCt;                            // number of vertices in model
  INDEX& mi_FramesCt;                              // number of all frames used by this model
  INDEX& mi_MipCt;                                  // number of mip-models
  CMipInfo mi_MipInfos[MAX_MODELMIPS];            // contains count of polygons and vertices
  CTFileName mi_PatchFiles[MAX_TEXTUREPATCHES];      // and their names
  MEX& mi_Width;                                    // size of mapping texture
  MEX& mi_Height;
  BOOL& mi_Flags;                                  // model flags (MF_...)
  SLONG& mi_ShadowQuality;                          // how models will be shaded
  FLOAT3D mi_Stretch;                              // stretch vector (static one, dynamic one is in model object)
};

#include "Model_internal.inl"
