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

inline CShadingInfo::CShadingInfo(CShadingInfo_* p, bool)
  : mp_handle(p)
  , si_pbpoPolygon(*CShadingInfo_si_pbpoPolygon(mp_handle))
  , si_ptrTerrain(*CShadingInfo_si_ptrTerrain(mp_handle))
  , si_vNearPoint(CShadingInfo_si_vNearPoint(mp_handle), false)
  , si_pixShadowU(*CShadingInfo_si_pixShadowU(mp_handle))
  , si_pixShadowV(*CShadingInfo_si_pixShadowV(mp_handle))
  , si_fUDRatio(*CShadingInfo_si_fUDRatio(mp_handle))
  , si_fLRRatio(*CShadingInfo_si_fLRRatio(mp_handle))
  , si_penEntity(*CShadingInfo_si_penEntity(mp_handle))
{
}
