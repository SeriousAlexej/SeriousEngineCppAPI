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
#include <SeriousEngineCAPI/Base/Types.h>
#include "Pointer.h"

#define NONE 0
#define NOTHING ((void) 0)
#define FOREVER for(;;)
#define ARRAYCOUNT(array) (sizeof(array)/sizeof((array)[0]))

class FLOAT2D;
class FLOAT3D;
class FLOAT4D;
class DOUBLE2D;
class DOUBLE3D;
class DOUBLE4D;
class INDEX2D;
class INDEX3D;
class INDEX4D;
class SWORD3D;
class SBYTE3D;
using ANGLE3D = FLOAT3D;
using PIX2D = INDEX2D;
using MEX2D = INDEX2D;
using SWPOINT3D = SWORD3D;
using SBPOINT3D = SBYTE3D;
class INDEXaabbox2D;
class FLOATaabbox2D;
class FLOATaabbox3D;
class DOUBLEaabbox2D;
class DOUBLEaabbox3D;
using MEXaabbox2D = INDEXaabbox2D;
using PIXaabbox2D = INDEXaabbox2D;
class FLOATobbox3D;
class DOUBLEobbox3D;
class FLOATmatrix2D;
class FLOATmatrix3D;
class FLOATmatrix4D;
class DOUBLEmatrix2D;
class DOUBLEmatrix3D;
class DOUBLEmatrix4D;
class INDEXmatrix2D;
class INDEXmatrix3D;
class INDEXmatrix4D;
class FLOATquat3D;
class DOUBLEquat3D;
class CPlacement3D;
class FLOATplane3D;
class DOUBLEplane3D;
class CProjection3D;
class CSimpleProjection3D_DOUBLE;
class CPlanarGradients;
class CMappingDefinitionUI;
class CMappingVectors;
class CMappingDefinition;
class CTCriticalSection;
class CTSingleLock;
class CTimerValue;
class CTimerHandler;
class CChangeable;
class CUpdateable;
class CChangeableRT;
class CUpdateableRT;
class CSerial;
class CAnimInfo;
class COneAnim;
class CAnimData;
class CAnimObject;
class CImageInfo;
class CTextureData;
class CTextureObject;
class ModelPolygonVertex;
class PolygonsPerPatch;
class ModelPolygon;
class ModelTextureVertex;
class MappingSurface;
class ModelFrameVertex8;
class ModelFrameVertex16;
class ModelFrameInfo;
class TransformedVertexData;
class CModelCollisionBox;
class CAttachedModelPosition;
class CMipInfo;
class CModelInfo;
class CModelPatch;
class ModelMipInfo;
class CModelData;
class CTString;
class CTFileName;
class CChunkID;
class CTStream;
class CTranslationPair;
class CListHead;
class CListNode;
class GFXVertex3;
class GFXNormal3;
class GFXTexCoord;
class GFXTexCoord4;
class GFXColor;
class GFXVertex4;
class GFXNormal4;
class CDynamicArray_FLOAT;
class CDynamicArray_CTString;
class CDynamicArray_CTFileName;
class CDynamicArray_CTranslationPair;
class CDynamicArray_CModelCollisionBox;
class CDynamicArray_CAttachedModelPosition;
class CDynamicStackArray_FLOAT;
class CDynamicStackArray_CTString;
class CDynamicStackArray_CTFileName;
class CStaticArray_PolygonsPerPatch;
class CStaticArray_ModelPolygon;
class CStaticArray_ModelTextureVertex;
class CStaticArray_MappingSurface;
class CStaticArray_ModelFrameVertex8;
class CStaticArray_ModelFrameVertex16;
class CStaticArray_ModelFrameInfo;
class CStaticArray_TransformedVertexData;
class CStaticArray_ModelPolygonVertex;
class CStaticArray_PIX2D;
class CStaticArray_FLOAT2D;
class CStaticArray_FLOAT3D;
class CStaticArray_DOUBLE3D;
class CStaticArray_UWORD;
class CStaticArray_ULONG;
class CStaticArray_INDEX;
class CStaticArray_SLONG;
class CStaticArray_GFXColor;
class CStaticArray_GFXTexCoord;
class CStaticArray_GFXVertex4;
class CStaticArray_TileLayer;
class CStaticArray_TileArrays;
class CStaticArray_CTextureData;
class CStaticArray_QuadTreeNode;
class CStaticArray_QuadTreeLevel;
class CStaticArray_CTerrainTile;
class CStaticArray_CArrayHolder;
class CStaticArray_CTerrainLayer;
class CStaticArray_CBrushVertex;
class CStaticArray_CBrushPolygon;
class CStaticArray_CBrushSector;
class CStaticStackArray_INDEX;
class CStaticStackArray_SLONG;
class CStaticStackArray_FLOAT3D;
class CStaticStackArray_PIX2D;
class CStaticStackArray_GFXColor;
class CStaticStackArray_GFXTexCoord;
class CStaticStackArray_GFXVertex4;
class CStaticStackArray_TileLayer;
class CStaticStackArray_TileArrays;
class CStaticStackArray_CTextureData;
class CStaticStackArray_QuadTreeNode;
class CStaticStackArray_QuadTreeLevel;
class CStaticStackArray_CTerrainLayer;
class CStaticStackArray_CBrushVertex;
class CStaticStackArray_CBrushPolygon;
class CStaticStackArray_CBrushSector;
class CDynamicContainer_CTextureData;
class CDynamicContainer_CBrushVertex;
class CDynamicContainer_CBrushPolygon;
class CDynamicContainer_CBrushSector;
class CSelection_CBrushVertex;
class CSelection_CBrushPolygon;
class CSelection_CBrushSector;
class CModelRenderPrefs;
class CRenderModel;
class CModelObject;
class CAttachmentModelObject;
class CDrawPort;
class CViewPort;
class CRaster;
class CDisplayMode;
class CSoundData;
class CSoundObject;
class CSoundListener;
class CFontData;
class CFontCharData;
class CEntity;
class CShadingInfo;
class TileLayer;
class TileArrays;
class CArrayHolder;
class CTerrainTile;
class CTerrainLayer;
class CTerrain;
class QuadTreeNode;
class QuadTreeLevel;
class Rect;
class CObjectVertex;
class CObjectPlane;
class CObjectEdge;
class CObjectMaterial;
class CObjectPolygonEdge;
class CObjectPolygon;
class CObjectSector;
class CEdgeEx;
class CObject3D;
class CWorldRenderPrefs;
class CWorkingVertex;
class CWorkingPlane;
class CWorkingEdge;
class CBrushVertex;
class CBrushPlane;
class CBrushEdge;
class CBrushPolygonEdge;
class CBrushShadowLayer;
class CBrushShadowMap;
class CBrushPolygonTexture;
class CBrushPolygonProperties;
class CBrushPolygon;
class CBrushSector;
class CBrushMip;
class CBrush3D;
class CRelationLnk;
class CEntityPropertyEnumValue;
class CEntityPropertyEnumType;
class CEntityProperty;
class CDLLEntityClass;
class CEntityClass;
class CEntityPointer;
class CWorld;
class CLightSource;
class CTextureTransformation;
class CTextureBlending;
class CSurfaceType;
class CContentType;
class CEnvironmentType;
class CIlluminationType;

#define DECL_PTR(classname) using classname##Ptr = TPointer<classname, classname##_>;

DECL_PTR(CImageInfo)
DECL_PTR(CTextureData)
DECL_PTR(CTextureObject)
DECL_PTR(CModelData)
DECL_PTR(CModelObject)
DECL_PTR(ModelTextureVertex)
DECL_PTR(CDrawPort)
DECL_PTR(CViewPort)
DECL_PTR(CFontData)
DECL_PTR(CAnimData)
DECL_PTR(CTString)
DECL_PTR(CTFileName)
DECL_PTR(CTCriticalSection)
DECL_PTR(CProjection3D)
DECL_PTR(CFontCharData)
DECL_PTR(CAttachmentModelObject)
DECL_PTR(ModelPolygon)
DECL_PTR(CTranslationPair)
DECL_PTR(CModelCollisionBox)
DECL_PTR(CAttachedModelPosition)
DECL_PTR(CDisplayMode)
DECL_PTR(CSoundData)
DECL_PTR(CListHead)
DECL_PTR(CListNode)
DECL_PTR(MappingSurface)
DECL_PTR(PolygonsPerPatch)
DECL_PTR(ModelFrameVertex8)
DECL_PTR(ModelFrameVertex16)
DECL_PTR(ModelFrameInfo)
DECL_PTR(TransformedVertexData)
DECL_PTR(ModelPolygonVertex)
DECL_PTR(PIX2D)
DECL_PTR(FLOAT2D)
DECL_PTR(FLOAT3D)
DECL_PTR(DOUBLE3D)
DECL_PTR(ModelMipInfo)
DECL_PTR(CRenderModel)
DECL_PTR(COneAnim)
DECL_PTR(GFXColor)
DECL_PTR(GFXTexCoord)
DECL_PTR(GFXVertex4)
DECL_PTR(TileLayer)
DECL_PTR(TileArrays)
DECL_PTR(QuadTreeNode)
DECL_PTR(QuadTreeLevel)
DECL_PTR(CTerrainTile)
DECL_PTR(CArrayHolder)
DECL_PTR(CTerrainLayer)
DECL_PTR(CTerrain)
DECL_PTR(CEntity)
DECL_PTR(CObjectEdge)
DECL_PTR(CObjectPolygonEdge)
DECL_PTR(CObjectVertex)
DECL_PTR(CObjectPlane)
DECL_PTR(CObjectMaterial)
DECL_PTR(CObjectPolygon)
DECL_PTR(CObjectSector)
DECL_PTR(CWorkingVertex)
DECL_PTR(CWorkingPlane)
DECL_PTR(CWorkingEdge)
DECL_PTR(CBrushVertex)
DECL_PTR(CBrushPlane)
DECL_PTR(CBrushEdge)
DECL_PTR(CBrushPolygonEdge)
DECL_PTR(CBrushShadowLayer)
DECL_PTR(CBrushShadowMap)
DECL_PTR(CBrushPolygonTexture)
DECL_PTR(CBrushPolygonProperties)
DECL_PTR(CBrushPolygon)
DECL_PTR(CBrushSector)
DECL_PTR(CBrushMip)
DECL_PTR(CBrush3D)
DECL_PTR(CRelationLnk)
DECL_PTR(CEntityPropertyEnumValue)
DECL_PTR(CEntityPropertyEnumType)
DECL_PTR(CEntityProperty)
DECL_PTR(CDLLEntityClass)
DECL_PTR(CEntityClass)
DECL_PTR(CShadingInfo)
DECL_PTR(CWorld)
DECL_PTR(CLightSource)
DECL_PTR(CTextureTransformation)
DECL_PTR(CTextureBlending)
DECL_PTR(CSurfaceType)
DECL_PTR(CContentType)
DECL_PTR(CEnvironmentType)
DECL_PTR(CIlluminationType)

#undef DECL_PTR

inline void SECppAPI_CheckException()
{
  if (HasException())
    throw GrabException();
}
