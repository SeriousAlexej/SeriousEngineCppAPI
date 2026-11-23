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
#include "../Math/VectorDecl.h"
#include "../Math/Plane.h"
#include "../Math/TextureMapping.h"
#include "../Math/AABBox.h"
#include "../Math/Object3D.h"
#include "../Graphics/Texture.h"
#include "../Templates/Selection.h"

// a vertex in brush
class CBrushVertex
{
public:
  CBrushVertex(CBrushVertex_* p, bool owner = false);
  CBrushVertex();
  CBrushVertex(const CBrushVertex& o);
  ~CBrushVertex();
  CBrushVertex& operator=(const CBrushVertex& o);

  BOOL IsSelected() const;
  // set new absolute position for the vertex
  void SetAbsolutePosition(const DOUBLE3D& vAbsolute);

  inline CBrushVertex_* C_Handle() { return mp_handle; }
  inline const CBrushVertex_* C_Handle() const { return mp_handle; }
  inline operator CBrushVertex_* () { return C_Handle(); }
  inline operator const CBrushVertex_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CBrushVertex_* mp_handle = nullptr;

public:
  CWorkingVertex_*& bvx_pwvxWorking;  // used for rendering and ray casting
  FLOAT3D  bvx_vAbsolute;
  FLOAT3D  bvx_vRelative;             // relative coordinates used for collision
  DOUBLE3D bvx_vdPreciseRelative;     // precise relative coordinates used for editing
  CBrushSector_*& bvx_pbscSector;     // back-pointer to sector
};

DECLARE_CStaticArray(CBrushVertex)
IMPL_CStaticArray(CBrushVertex)
DECLARE_CDynamicContainer(CBrushVertex)
IMPL_CDynamicContainer(CBrushVertex)
DECLARE_CSelection(CBrushVertex)
IMPL_CSelection(CBrushVertex)

using CBrushVertexSelection = CSelection_CBrushVertex;

DECLARE_CStaticArray_simple(CBrushVertexPtr_)
IMPL_CStaticArray_simple(CBrushVertexPtr_)

// a plane in brush
class CBrushPlane
{
public:
  CBrushPlane(CBrushPlane_* p, bool owner = false);
  CBrushPlane();
  CBrushPlane(const CBrushPlane& o);
  ~CBrushPlane();
  CBrushPlane& operator=(const CBrushPlane& o);

  inline CBrushPlane_* C_Handle() { return mp_handle; }
  inline const CBrushPlane_* C_Handle() const { return mp_handle; }
  inline operator CBrushPlane_* () { return C_Handle(); }
  inline operator const CBrushPlane_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CBrushPlane_* mp_handle = nullptr;

public:
  CWorkingPlane_*& bpl_pwplWorking;  // use for rendering and ray casting
  FLOATplane3D bpl_plAbsolute;
  FLOATplane3D bpl_plRelative;    // relative coordinates used for collision
  DOUBLEplane3D_*& bpl_ppldPreciseAbsolute; // precise relative plane coordinates in absolute space
  DOUBLEplane3D bpl_pldPreciseRelative;           // precise coordinates used for editing
  INDEX& bpl_iPlaneMajorAxis1;  // major axes of the plane in apsolute space
  INDEX& bpl_iPlaneMajorAxis2;
};

DECLARE_CStaticArray(CBrushPlane)
IMPL_CStaticArray(CBrushPlane)

// an edge in brush
class CBrushEdge
{
public:
  CBrushEdge(CBrushEdge_* p, bool owner = false);
  CBrushEdge();
  CBrushEdge(CBrushVertex_* v0, CBrushVertex_* v1);
  CBrushEdge(const CBrushEdge& o);
  ~CBrushEdge();
  CBrushEdge& operator=(const CBrushEdge& o);

  inline CBrushEdge_* C_Handle() { return mp_handle; }
  inline const CBrushEdge_* C_Handle() const { return mp_handle; }
  inline operator CBrushEdge_* () { return C_Handle(); }
  inline operator const CBrushEdge_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CBrushEdge_* mp_handle = nullptr;

public:
  CBrushVertex_*& bed_pbvxVertex0;   // start vertex
  CBrushVertex_*& bed_pbvxVertex1;   // end vertex
};

DECLARE_CStaticArray(CBrushEdge)
IMPL_CStaticArray(CBrushEdge)

// a reference to edge used in brush polygon
class CBrushPolygonEdge
{
public:
  CBrushPolygonEdge(CBrushPolygonEdge_* p, bool owner = false);
  CBrushPolygonEdge();
  CBrushPolygonEdge(const CBrushPolygonEdge& o);
  ~CBrushPolygonEdge();
  CBrushPolygonEdge& operator=(const CBrushPolygonEdge& o);

  void GetVertexCoordinatesAbsolute(FLOAT3D& v0, FLOAT3D& v1);
  void GetVertexCoordinatesRelative(FLOAT3D& v0, FLOAT3D& v1);
  void GetVertexCoordinatesPreciseRelative(DOUBLE3D& v0, DOUBLE3D& v1);
  void GetVertexCoordinatesPreciseAbsolute(DOUBLE3D& v0, DOUBLE3D& v1);

  inline CBrushPolygonEdge_* C_Handle() { return mp_handle; }
  inline const CBrushPolygonEdge_* C_Handle() const { return mp_handle; }
  inline operator CBrushPolygonEdge_* () { return C_Handle(); }
  inline operator const CBrushPolygonEdge_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CBrushPolygonEdge_* mp_handle = nullptr;

public:
  CBrushEdge_*& bpe_pbedEdge;         // pointer to the edge
};

DECLARE_CStaticArray(CBrushPolygonEdge)
IMPL_CStaticArray(CBrushPolygonEdge)

// one layer on brush shadow map (cross link between brush shadow map and light source)
class CBrushShadowLayer
{
public:
  CBrushShadowLayer(CBrushShadowLayer_* p, bool dummy = false);
  ~CBrushShadowLayer();
  CBrushShadowLayer(const CBrushShadowLayer& o) = delete;
  CBrushShadowLayer& operator=(const CBrushShadowLayer& o) = delete;

  inline CBrushShadowLayer_* C_Handle() { return mp_handle; }
  inline const CBrushShadowLayer_* C_Handle() const { return mp_handle; }
  inline operator CBrushShadowLayer_* () { return C_Handle(); }
  inline operator const CBrushShadowLayer_* () const { return C_Handle(); }
private:
  CBrushShadowLayer_* mp_handle = nullptr;

public:
  CListNode bsl_lnInShadowMap;    // node in list of all layers of a shadow map
  CLightSource_*& bsl_plsLightSource;   // the light source
};

class CBrushShadowMap
{
public:
  CBrushShadowMap(CBrushShadowMap_* p, bool dummy = false);
  ~CBrushShadowMap();
  CBrushShadowMap(const CBrushShadowMap& o) = delete;
  CBrushShadowMap& operator=(const CBrushShadowMap& o) = delete;

  // discard all layers on this shadow map
  void DiscardAllLayers();
  // get shadowmap memory usage (in bytes)
  ULONG GetShadowSize();
  // uncache the shadow map (returns total ammount of memory that has been freed)
  SLONG Uncache();

  inline CBrushShadowMap_* C_Handle() { return mp_handle; }
  inline const CBrushShadowMap_* C_Handle() const { return mp_handle; }
  inline operator CBrushShadowMap_* () { return C_Handle(); }
  inline operator const CBrushShadowMap_* () const { return C_Handle(); }
private:
  CBrushShadowMap_* mp_handle = nullptr;

public:
  CListHead bsm_lhLayers;     // list of all layers of this shadow map
};

class CBrushPolygonTexture
{
public:
  CBrushPolygonTexture(CBrushPolygonTexture_* p, bool owner = false);
  CBrushPolygonTexture();
  ~CBrushPolygonTexture();
  CBrushPolygonTexture(const CBrushPolygonTexture& o) = delete;
  CBrushPolygonTexture& operator=(const CBrushPolygonTexture& o) = delete;

  CBrushPolygonTexture& CopyTextureProperties(CBrushPolygonTexture& bptOther, BOOL bCopyMapping);
  void Clear();

  inline CBrushPolygonTexture_* C_Handle() { return mp_handle; }
  inline const CBrushPolygonTexture_* C_Handle() const { return mp_handle; }
  inline operator CBrushPolygonTexture_* () { return C_Handle(); }
  inline operator const CBrushPolygonTexture_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CBrushPolygonTexture_* mp_handle = nullptr;

public:
  CTextureObject bpt_toTexture;     // texture object
  CMappingDefinition bpt_mdMapping; // mapping of texture on polygon
  UBYTE& bpt_ubScroll;              // texture scroll
  UBYTE& bpt_ubBlend;               // type of texture blending used
  UBYTE& bpt_ubFlags;               // additional flags
  UBYTE& bpt_ubDummy;               // unused (alignment)
  COLOR& bpt_colColor;              // defines constant color and alpha of polygon
};

// properties that are retained in conversions to/from CObjectPolygon
class CBrushPolygonProperties
{
public:
  CBrushPolygonProperties(CBrushPolygonProperties_* p, bool owner = false);
  CBrushPolygonProperties();
  CBrushPolygonProperties(const CBrushPolygonProperties& o);
  ~CBrushPolygonProperties();
  CBrushPolygonProperties& operator=(const CBrushPolygonProperties& o);

  inline CBrushPolygonProperties_* C_Handle() { return mp_handle; }
  inline const CBrushPolygonProperties_* C_Handle() const { return mp_handle; }
  inline operator CBrushPolygonProperties_* () { return C_Handle(); }
  inline operator const CBrushPolygonProperties_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CBrushPolygonProperties_* mp_handle = nullptr;

public:
  UBYTE& bpp_ubSurfaceType;        // surface type on this polygon
  UBYTE& bpp_ubIlluminationType;   // type of illuminating polygon, 0 if not illuminating
  UBYTE& bpp_ubShadowBlend;        // type of texture blending used for shadow map
  UBYTE& bpp_ubMirrorType;         // mirror or warp
  UBYTE& bpp_ubGradientType;       // for gradiental shadows
  SBYTE& bpp_sbShadowClusterSize;  // size of shadow clusters (size=(1<<ub)*0.5m)
  UWORD& bpp_uwPretenderDistance;  // distance for pretender switching [m]
};

class CBrushPolygon
{
public:
  CBrushPolygon(CBrushPolygon_* p, bool owner = false);
  CBrushPolygon();
  ~CBrushPolygon();
  CBrushPolygon(const CBrushPolygon& o) = delete;
  CBrushPolygon& operator=(const CBrushPolygon& o) = delete;

  /* Initialize shadow map for the polygon. */
  void InitializeShadowMap();
  /* Copy polygon properties */
  CBrushPolygon& CopyProperties(CBrushPolygon& bpoOther, BOOL bCopyMapping = TRUE);
  /* Copy polygon properties without texture */
  CBrushPolygon& CopyPropertiesWithoutTexture(CBrushPolygon& bpoOther);
  /* Copy polygon's textures */
  CBrushPolygon& CopyTextures(CBrushPolygon& bpoOther);
  BOOL IsSelected() const;
  /* Select group of adjacent polygons with same color. */
  void SelectSimilarByColor(CSelection_CBrushPolygon& selbpoSimilar);
  /* Select group of adjacent polygons with same texture. */
  void SelectSimilarByTexture(CSelection_CBrushPolygon& selbpoSimilar, INDEX iTexture);
  /* Select all polygons in sector with same texture. */
  void SelectByTextureInSector(CSelection_CBrushPolygon& selbpoSimilar, INDEX iTexture);
  /* Select all polygons in sector with same color. */
  void SelectByColorInSector(CSelection_CBrushPolygon& selbpoSimilar);
  /* Discard shadows on the polygon. */
  void DiscardShadows();

  inline CBrushPolygon_* C_Handle() { return mp_handle; }
  inline const CBrushPolygon_* C_Handle() const { return mp_handle; }
  inline operator CBrushPolygon_* () { return C_Handle(); }
  inline operator const CBrushPolygon_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CBrushPolygon_* mp_handle = nullptr;

public:
  CBrushPlane_*& bpo_pbplPlane;                 // plane of this polygon
  CStaticArray_CBrushPolygonEdge bpo_abpePolygonEdges;     // edges in this polygon
  CStaticArray_CBrushVertexPtr_ bpo_apbvxTriangleVertices; // triangle vertices
  CStaticArray_INDEX bpo_aiTriangleElements;  // element indices inside vertex arrays
  CBrushPolygonTexture bpo_abptTextures[3];   // texture on this polygon
  COLOR& bpo_colColor;                        // color of this polygon
  ULONG& bpo_ulFlags;                         // flags
  COLOR& bpo_colShadow;                       // color of shadow on this polygon
  CBrushShadowMap bpo_smShadowMap;            // shadow map of this polygon
  CMappingDefinition bpo_mdShadow;            // mapping of shadow on polygon
  CBrushPolygonProperties bpo_bppProperties;  // additional properties
  FLOATaabbox3D bpo_boxBoundingBox;           // bounding box
  CBrushSector_*& bpo_pbscSector;             // sector of this polygon
  CListHead bpo_rsOtherSideSectors;           // relation to sectors on other side of portal
};

DECLARE_CStaticArray(CBrushPolygon)
IMPL_CStaticArray(CBrushPolygon)
DECLARE_CDynamicContainer(CBrushPolygon)
IMPL_CDynamicContainer(CBrushPolygon)
DECLARE_CSelection(CBrushPolygon)
IMPL_CSelection(CBrushPolygon)

using CBrushPolygonSelection = CSelection_CBrushPolygon;

// a sector in brush
class CBrushSector
{
public:
  CBrushSector(CBrushSector_* p, bool owner = false);
  CBrushSector();
  ~CBrushSector();
  CBrushSector(const CBrushSector& o) = delete;
  CBrushSector& operator=(const CBrushSector& o) = delete;

  // update changed sector's data after dragging vertices or importing
  void UpdateSector();
  /* Clear the object. */
  void Clear();
  // triangularize given polygon
  void TriangularizePolygon(CBrushPolygon_* pbpo);
  /* Triangularize polygons contining vertices from selection */
  void TriangularizeForVertices(CBrushVertexSelection& selVertex);
  // Insert given vertex into triangle
  void InsertVertexIntoTriangle(CBrushPolygonSelection& selPolygon, FLOAT3D vVertex);
  // Retriple two triangles given trough selection
  BOOL IsReTripleAvailable(CBrushPolygonSelection& selPolygon);
  void ReTriple(CBrushPolygonSelection& selPolygon);
  BOOL IsSelected() const;
  /* Read from stream. */
  void Read_t(CTStream* istrFile); // throw char *
  /* Write to stream. */
  void Write_t(CTStream* ostrFile); // throw char *
  /* Uncache lightmaps on all shadows on the sector. */
  void UncacheLightMaps();
  /* Get/set properties. */
  INDEX GetContentType();
  void SetContentType(INDEX iNewContent);
  INDEX GetForceType();
  void SetForceType(INDEX iNewForce);
  INDEX GetFogType();
  void SetFogType(INDEX iNewForce);
  INDEX GetHazeType();
  void SetHazeType(INDEX iNewForce);
  INDEX GetEnvironmentType();
  void SetEnvironmentType(INDEX iNewEnvironment);

  inline CBrushSector_* C_Handle() { return mp_handle; }
  inline const CBrushSector_* C_Handle() const { return mp_handle; }
  inline operator CBrushSector_* () { return C_Handle(); }
  inline operator const CBrushSector_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  CBrushSector_* mp_handle = nullptr;

public:
  CStaticArray_CBrushVertex bsc_abvxVertices;  // vertices
  CStaticArray_CBrushEdge bsc_abedEdges;       // edges
  CStaticArray_CBrushPlane bsc_abplPlanes;     // planes
  CStaticArray_CBrushPolygon bsc_abpoPolygons; // polygons
  CBrushMip_*& bsc_pbmBrushMip;                // pointer to brush mip of this sector
  COLOR& bsc_colColor;                         // color of this sector
  COLOR& bsc_colAmbient;                       // ambient light for that sector
  ULONG& bsc_ulFlags;                          // flags
  ULONG& bsc_ulFlags2;                         // second set of flags
  ULONG& bsc_ulVisFlags;                       // special visibility flags
  FLOATaabbox3D bsc_boxBoundingBox;            // bounding box in absolute space
  CListHead bsc_rdOtherSidePortals;            // relation to portals pointing to this sector
  CListHead bsc_rsEntities;                    // relation to all entities in this sector
  CTString bsc_strName;                        // sector name
};

DECLARE_CDynamicContainer(CBrushSector)
IMPL_CDynamicContainer(CBrushSector)
DECLARE_CSelection(CBrushSector)
IMPL_CSelection(CBrushSector)

using CBrushSectorSelection = CSelection_CBrushSector;

DECLARE_CDynamicArray(CBrushSector)
IMPL_CDynamicArray(CBrushSector)

/*
 * One detail level of a brush.
 */
class CBrushMip
{
public:
  CBrushMip(CBrushMip_* p, bool owner = false);
  CBrushMip();
  ~CBrushMip();
  CBrushMip(const CBrushMip& o) = delete;
  CBrushMip& operator=(const CBrushMip& o) = delete;

  /* Reoptimize all sectors in the brush mip. */
  void Reoptimize();
  /* Free all memory and leave empty brush mip. */
  void Clear();
  /* Copy brush mip from another brush mip. */
  void Copy(CBrushMip& bmOther, FLOAT fStretch, BOOL bMirrorX);
  /* Set mip distance of this mip, spread all that are further. */
  void SetMipDistance(FLOAT fMipDistance);
  /* Get mip factor of this mip. */
  FLOAT GetMipDistance();
  /* Get mip index of this mip. */
  INDEX GetMipIndex();
  // get next brush mip
  CBrushMipPtr GetNext();
  // get previous brush mip
  CBrushMipPtr GetPrev();

  inline CBrushMip_* C_Handle() { return mp_handle; }
  inline const CBrushMip_* C_Handle() const { return mp_handle; }
  inline operator CBrushMip_* () { return C_Handle(); }
  inline operator const CBrushMip_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  CBrushMip_* mp_handle = nullptr;

public:
  CDynamicArray_CBrushSector bm_abscSectors; // sectors
  CBrush3D_*& bm_pbrBrush;                   // pointer to brush
  CListNode bm_lnInBrush;                    // for linking in list of mip-brushes for a brush
  FLOATaabbox3D bm_boxBoundingBox;           // bounding box of entire mip-brush in absolute space
};

/*
 * Brush class -- a piece of level that can be moved independently
 */
class CBrush3D
{
public:
  CBrush3D(CBrush3D_* p, bool owner = false);
  CBrush3D();
  ~CBrush3D();
  CBrush3D(const CBrush3D& o) = delete;
  CBrush3D& operator=(const CBrush3D& o) = delete;

  /* Calculate bounding boxes in all brush mips. */
  void CalculateBoundingBoxes();
  /* Free all memory and leave empty brush. */
  void Clear();
  /* Fill a brush from 3d object. */
  void FromObject3D_t(CObject3D& ob); // throw char *
  void AddMipBrushFromObject3D_t(CObject3D& ob, FLOAT fSwitchDistance); // throw char *
  /* Copy brush from another brush with possible mirror and stretch. */
  void Copy(CBrush3D& brOther, FLOAT fStretch, BOOL bMirrorX);

  /* Delete a brush mip with given factor. */
  void DeleteBrushMip(CBrushMip_* pbmToDelete);
  /* Create a new brush mip. */
  CBrushMipPtr NewBrushMipAfter(CBrushMip_* pbm, BOOL bCopy);
  CBrushMipPtr NewBrushMipBefore(CBrushMip_* pbm, BOOL bCopy);
  /* Get a brush mip for given mip-factor. */
  CBrushMipPtr GetBrushMipByDistance(FLOAT fDistance);
  // get first brush mip
  CBrushMipPtr GetFirstMip();
  // get last brush mip
  CBrushMipPtr GetLastMip();

  // switch from zoning to non-zoning
  void SwitchToNonZoning();
  // switch from non-zoning to zoning
  void SwitchToZoning();

  void Read_t(CTStream* istrFile); // throw char *
  void Write_t(CTStream* ostrFile);  // throw char *

  inline CBrush3D_* C_Handle() { return mp_handle; }
  inline const CBrush3D_* C_Handle() const { return mp_handle; }
  inline operator CBrush3D_* () { return C_Handle(); }
  inline operator const CBrush3D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  CBrush3D_* mp_handle = nullptr;

public:
  CEntity_*& br_penEntity;  // back pointer from brush to its entity
  CListHead br_lhBrushMips; // mip brushes in this brush
};

#include "Brush.inl"
