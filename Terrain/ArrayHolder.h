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
#include "../Graphics/Vertex.h"
#include "../Templates/StaticArray.h"
#include "../Templates/StaticStackArray.h"
#include <SeriousEngineCAPI/Terrain/ArrayHolder.h>

DECLARE_CStaticArray(GFXColor)
DECLARE_CStaticArray(GFXTexCoord)
DECLARE_CStaticArray(GFXVertex4)

DECLARE_CStaticStackArray(GFXColor)
DECLARE_CStaticStackArray(GFXTexCoord)
DECLARE_CStaticStackArray(GFXVertex4)

class TileLayer
{
public:
  TileLayer(TileLayer_* p, bool owner = false);
  TileLayer();
  TileLayer(const TileLayer& o) = delete;
  ~TileLayer();
  TileLayer& operator=(const TileLayer& o);

  inline TileLayer_* C_Handle() { return mp_handle; }
  inline const TileLayer_* C_Handle() const { return mp_handle; }
  inline operator TileLayer_* () { return C_Handle(); }
  inline operator const TileLayer_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  TileLayer_* mp_handle = nullptr;

public:
  CStaticStackArray_INDEX       tl_auiIndices;   // Array of indices for one layer
  CStaticStackArray_GFXColor    tl_acColors;     // Array of colors for one layer
  CStaticStackArray_GFXTexCoord tl_atcTexCoords; // Array of texcoords for one layer
  CStaticStackArray_GFXVertex4  tl_avVertices;   // Array of vertices  for one layer (used only if tile layer)
};

DECLARE_CStaticArray(TileLayer)
DECLARE_CStaticStackArray(TileLayer)

class TileArrays
{
public:
  TileArrays(TileArrays_* p, bool owner = false);
  TileArrays();
  TileArrays(const TileArrays& o) = delete;
  ~TileArrays();
  TileArrays& operator=(const TileArrays& o);

  inline TileArrays_* C_Handle() { return mp_handle; }
  inline const TileArrays_* C_Handle() const { return mp_handle; }
  inline operator TileArrays_* () { return C_Handle(); }
  inline operator const TileArrays_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  TileArrays_* mp_handle = nullptr;

public:
  CStaticStackArray_GFXVertex4  ta_avVertices;   // Array of vertices for one tile
  CStaticStackArray_GFXTexCoord ta_auvTexCoords; // Array of texcoords for one tile (not used in highest lod)
  CStaticStackArray_GFXTexCoord ta_auvShadowMap; // Array of texcoords for shadow map
  CStaticStackArray_GFXTexCoord ta_auvDetailMap; // Array of texcoords for detail map
  CStaticStackArray_INDEX       ta_auiIndices;   // Array of indices for one tile
  CStaticStackArray_TileLayer   ta_atlLayers;    // Array if layers per tile (used only in highest lod)
  CTextureData_*&               ta_ptdTopMap;    // Pointer to tile top map
};

DECLARE_CStaticArray(TileArrays)
DECLARE_CStaticStackArray(TileArrays)

class CArrayHolder
{
public:
  CArrayHolder(CArrayHolder_* p, bool owner = false);
  CArrayHolder();
  ~CArrayHolder();
  CArrayHolder(const CArrayHolder& o) = delete;
  CArrayHolder& operator=(const CArrayHolder& o) = delete;

  // Returns index of new tile arrays
  INDEX GetNewArrays();
  // Mark tile arrays as unused
  void FreeArrays(INDEX iOldArraysIndex);
  // Just do popall on all arrays
  void EmptyArrays(INDEX iArrayIndex);
  // Release array holder
  void Clear();
  // Count used memory
  SLONG GetUsedMemory();

  inline CArrayHolder_* C_Handle() { return mp_handle; }
  inline const CArrayHolder_* C_Handle() const { return mp_handle; }
  inline operator CArrayHolder_* () { return C_Handle(); }
  inline operator const CArrayHolder_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CArrayHolder_* mp_handle = nullptr;

public:
  CTerrain_*& ah_ptrTerrain; // Terrain that owns this array holder
  CStaticStackArray_TileArrays ah_ataTileArrays; // array of tile arrays
  CStaticStackArray_INDEX      ah_aiFreeArrays;  // array of indices of free arrays
  INDEX& ah_iLod; // this array holder works in this lod
};

#include "ArrayHolder.inl"
