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
#include <SeriousEngineCAPI/Entities/ShadingInfo.h>

class CShadingInfo
{
public:
  explicit CShadingInfo(CShadingInfo_* p, bool dummy = false);

  inline CShadingInfo_* C_Handle() { return mp_handle; }
  inline const CShadingInfo_* C_Handle() const { return mp_handle; }
  inline operator CShadingInfo_* () { return C_Handle(); }
  inline operator const CShadingInfo_* () const { return C_Handle(); }

private:
  CShadingInfo_* mp_handle = nullptr;

public:
  CBrushPolygon_*& si_pbpoPolygon; // the polygon that entity is above
  CTerrain_*& si_ptrTerrain; // terrain that entity is above
  FLOAT3D si_vNearPoint; // the relevant point in absolute space
  PIX& si_pixShadowU; // the relevant point in the polygon shadow map
  PIX& si_pixShadowV;
  FLOAT& si_fUDRatio; // fraction between pixels
  FLOAT& si_fLRRatio;
  CEntity_*& si_penEntity; // the entity which uses this shading info
};

#include "ShadingInfo.inl"
