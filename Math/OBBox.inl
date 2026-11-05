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

inline FLOATobbox3D::FLOATobbox3D(FLOATobbox3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , box_vO(FLOATobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(FLOATobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(FLOATobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(FLOATobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*FLOATobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*FLOATobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*FLOATobbox3D_box_atSize(mp_handle, 2))
{
}

inline FLOATobbox3D::FLOATobbox3D()
  : m_owner(true)
  , mp_handle(FLOATobbox3D_new())
  , box_vO(FLOATobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(FLOATobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(FLOATobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(FLOATobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*FLOATobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*FLOATobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*FLOATobbox3D_box_atSize(mp_handle, 2))
{
}
inline FLOATobbox3D::FLOATobbox3D(const FLOAT3D& vO,
          const FLOAT3D& vAxis0, const FLOAT3D& vAxis1, const FLOAT3D& vAxis2,
          FLOAT tSize0, FLOAT tSize1, FLOAT tSize2)
  : m_owner(true)
  , mp_handle(FLOATobbox3D_new_vaaa(vO, vAxis0, vAxis1, vAxis2, tSize0, tSize1, tSize2))
  , box_vO(FLOATobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(FLOATobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(FLOATobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(FLOATobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*FLOATobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*FLOATobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*FLOATobbox3D_box_atSize(mp_handle, 2))
{
}

inline FLOATobbox3D::FLOATobbox3D(const FLOATaabbox3D& aabbox,
          const FLOAT3D& vPos, const FLOATmatrix3D& mRot)
  : m_owner(true)
  , mp_handle(FLOATobbox3D_new_aapr(aabbox, vPos, mRot))
  , box_vO(FLOATobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(FLOATobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(FLOATobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(FLOATobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*FLOATobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*FLOATobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*FLOATobbox3D_box_atSize(mp_handle, 2))
{
}

inline FLOATobbox3D::FLOATobbox3D(const FLOATaabbox3D& aabbox)
  : m_owner(true)
  , mp_handle(FLOATobbox3D_new_aa(aabbox))
  , box_vO(FLOATobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(FLOATobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(FLOATobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(FLOATobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*FLOATobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*FLOATobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*FLOATobbox3D_box_atSize(mp_handle, 2))
{
}

inline FLOATobbox3D::FLOATobbox3D(const FLOATobbox3D& o)
  : m_owner(true)
  , mp_handle(FLOATobbox3D_clone(o))
  , box_vO(FLOATobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(FLOATobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(FLOATobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(FLOATobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*FLOATobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*FLOATobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*FLOATobbox3D_box_atSize(mp_handle, 2))
{
}

inline FLOATobbox3D::~FLOATobbox3D()
{
  if (m_owner)
    FLOATobbox3D_delete(mp_handle);
}

inline FLOATobbox3D& FLOATobbox3D::operator=(const FLOATobbox3D& o)
{
  FLOATobbox3D_copy(mp_handle, o);
  return *this;
}

inline void FLOATobbox3D::SetToNormalizedEmpty()
{
  FLOATobbox3D_SetToNormalizedEmpty(mp_handle);
}

inline FLOAT FLOATobbox3D::TestAgainstPlane(const FLOATplane3D& pl) const
{
  return FLOATobbox3D_TestAgainstPlane(mp_handle, pl);
}

inline BOOL FLOATobbox3D::HasContactWith(const FLOATobbox3D& boxB) const
{
  return FLOATobbox3D_HasContactWith(mp_handle, boxB);
}

inline BOOL FLOATobbox3D::IsEmpty() const
{
  return FLOATobbox3D_IsEmpty(mp_handle);
}

inline DOUBLEobbox3D::DOUBLEobbox3D(DOUBLEobbox3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , box_vO(DOUBLEobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(DOUBLEobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(DOUBLEobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(DOUBLEobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*DOUBLEobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*DOUBLEobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*DOUBLEobbox3D_box_atSize(mp_handle, 2))
{
}

inline DOUBLEobbox3D::DOUBLEobbox3D()
  : m_owner(true)
  , mp_handle(DOUBLEobbox3D_new())
  , box_vO(DOUBLEobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(DOUBLEobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(DOUBLEobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(DOUBLEobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*DOUBLEobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*DOUBLEobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*DOUBLEobbox3D_box_atSize(mp_handle, 2))
{
}
inline DOUBLEobbox3D::DOUBLEobbox3D(const DOUBLE3D& vO,
  const DOUBLE3D& vAxis0, const DOUBLE3D& vAxis1, const DOUBLE3D& vAxis2,
  DOUBLE tSize0, DOUBLE tSize1, DOUBLE tSize2)
  : m_owner(true)
  , mp_handle(DOUBLEobbox3D_new_vaaa(vO, vAxis0, vAxis1, vAxis2, tSize0, tSize1, tSize2))
  , box_vO(DOUBLEobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(DOUBLEobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(DOUBLEobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(DOUBLEobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*DOUBLEobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*DOUBLEobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*DOUBLEobbox3D_box_atSize(mp_handle, 2))
{
}

inline DOUBLEobbox3D::DOUBLEobbox3D(const DOUBLEaabbox3D& aabbox,
  const DOUBLE3D& vPos, const DOUBLEmatrix3D& mRot)
  : m_owner(true)
  , mp_handle(DOUBLEobbox3D_new_aapr(aabbox, vPos, mRot))
  , box_vO(DOUBLEobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(DOUBLEobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(DOUBLEobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(DOUBLEobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*DOUBLEobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*DOUBLEobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*DOUBLEobbox3D_box_atSize(mp_handle, 2))
{
}

inline DOUBLEobbox3D::DOUBLEobbox3D(const DOUBLEaabbox3D& aabbox)
  : m_owner(true)
  , mp_handle(DOUBLEobbox3D_new_aa(aabbox))
  , box_vO(DOUBLEobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(DOUBLEobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(DOUBLEobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(DOUBLEobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*DOUBLEobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*DOUBLEobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*DOUBLEobbox3D_box_atSize(mp_handle, 2))
{
}

inline DOUBLEobbox3D::DOUBLEobbox3D(const DOUBLEobbox3D& o)
  : m_owner(true)
  , mp_handle(DOUBLEobbox3D_clone(o))
  , box_vO(DOUBLEobbox3D_box_vO(mp_handle), false)
  , box_avAxis_0(DOUBLEobbox3D_box_avAxis(mp_handle, 0), false)
  , box_avAxis_1(DOUBLEobbox3D_box_avAxis(mp_handle, 1), false)
  , box_avAxis_2(DOUBLEobbox3D_box_avAxis(mp_handle, 2), false)
  , box_atSize_0(*DOUBLEobbox3D_box_atSize(mp_handle, 0))
  , box_atSize_1(*DOUBLEobbox3D_box_atSize(mp_handle, 1))
  , box_atSize_2(*DOUBLEobbox3D_box_atSize(mp_handle, 2))
{
}

inline DOUBLEobbox3D::~DOUBLEobbox3D()
{
  if (m_owner)
    DOUBLEobbox3D_delete(mp_handle);
}

inline DOUBLEobbox3D& DOUBLEobbox3D::operator=(const DOUBLEobbox3D& o)
{
  DOUBLEobbox3D_copy(mp_handle, o);
  return *this;
}

inline void DOUBLEobbox3D::SetToNormalizedEmpty()
{
  DOUBLEobbox3D_SetToNormalizedEmpty(mp_handle);
}

inline DOUBLE DOUBLEobbox3D::TestAgainstPlane(const DOUBLEplane3D& pl) const
{
  return DOUBLEobbox3D_TestAgainstPlane(mp_handle, pl);
}

inline BOOL DOUBLEobbox3D::HasContactWith(const DOUBLEobbox3D& boxB) const
{
  return DOUBLEobbox3D_HasContactWith(mp_handle, boxB);
}

inline BOOL DOUBLEobbox3D::IsEmpty() const
{
  return DOUBLEobbox3D_IsEmpty(mp_handle);
}

__forceinline DOUBLEobbox3D FLOATtoDOUBLE(const FLOATobbox3D& boxf)
{
  return DOUBLEobbox3D(FLOATtoDOUBLEobb(boxf), true);
}

__forceinline FLOATobbox3D DOUBLEtoFLOAT(const DOUBLEobbox3D& boxd)
{
  return FLOATobbox3D(DOUBLEtoFLOATobb(boxd), true);
}
