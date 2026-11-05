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

inline FLOATquat3D::FLOATquat3D(FLOATquat3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline FLOATquat3D::FLOATquat3D()
  : m_owner(true)
  , mp_handle(FLOATquat3D_new())
{
}

inline FLOATquat3D::FLOATquat3D(const FLOATquat3D& o)
  : m_owner(true)
  , mp_handle(FLOATquat3D_clone(o))
{
}

inline FLOATquat3D::FLOATquat3D(FLOAT w, FLOAT x, FLOAT y, FLOAT z)
  : m_owner(true)
  , mp_handle(FLOATquat3D_new_args(w, x, y, z))
{
}

inline FLOATquat3D::~FLOATquat3D()
{
  if (m_owner)
    FLOATquat3D_delete(mp_handle);
}

inline FLOATquat3D& FLOATquat3D::operator=(const FLOATquat3D& o)
{
  FLOATquat3D_copy(mp_handle, o);
  return *this;
}

inline FLOAT FLOATquat3D::x() const
{
  return FLOATquat3D_x(mp_handle);
}

inline FLOAT FLOATquat3D::y() const
{
  return FLOATquat3D_y(mp_handle);
}

inline FLOAT FLOATquat3D::z() const
{
  return FLOATquat3D_z(mp_handle);
}

inline FLOAT FLOATquat3D::w() const
{
  return FLOATquat3D_w(mp_handle);
}

inline void FLOATquat3D::setx(FLOAT x)
{
  FLOATquat3D_setx(mp_handle, x);
}

inline void FLOATquat3D::sety(FLOAT y)
{
  FLOATquat3D_sety(mp_handle, y);
}

inline void FLOATquat3D::setz(FLOAT z)
{
  FLOATquat3D_setz(mp_handle, z);
}

inline void FLOATquat3D::setw(FLOAT w)
{
  FLOATquat3D_setw(mp_handle, w);
}

inline void FLOATquat3D::FromEuler(const FLOAT3D& a)
{
  FLOATquat3D_FromEuler(mp_handle, a);
}

inline void FLOATquat3D::ToMatrix(FLOATmatrix3D& m) const
{
  FLOATquat3D_ToMatrix(mp_handle, m);
}

inline void FLOATquat3D::FromMatrix(FLOATmatrix3D& m)
{
  FLOATquat3D_FromMatrix(mp_handle, m);
}

inline void FLOATquat3D::FromAxisAngle(const FLOAT3D& n, FLOAT a)
{
  FLOATquat3D_FromAxisAngle(mp_handle, n, a);
}

inline void FLOATquat3D::ToAxisAngle(FLOAT3D& n, FLOAT& a)
{
  FLOATquat3D_ToAxisAngle(mp_handle, n, &a);
}

__forceinline FLOATquat3D FLOATquat3D::operator-() const
{
  return FLOATquat3D(FLOATquat3D_Flip(mp_handle), true);
}

__forceinline FLOATquat3D FLOATquat3D::operator~() const
{
  return FLOATquat3D(FLOATquat3D_Conjugate(mp_handle), true);
}

__forceinline FLOATquat3D FLOATquat3D::Inv() const
{
  return FLOATquat3D(FLOATquat3D_Inv(mp_handle), true);
}

__forceinline FLOATquat3D FLOATquat3D::operator*(FLOAT t) const
{
  return FLOATquat3D(FLOATquat3D_Multiply_scalar(mp_handle, t), true);
}

inline FLOATquat3D& FLOATquat3D::operator*=(FLOAT t)
{
  FLOATquat3D_MultiplyInplace_scalar(mp_handle, t);
  return *this;
}

__forceinline FLOATquat3D FLOATquat3D::operator/(FLOAT t) const
{
  return FLOATquat3D(FLOATquat3D_Divide_scalar(mp_handle, t), true);
}

inline FLOATquat3D& FLOATquat3D::operator/=(FLOAT t)
{
  FLOATquat3D_DivideInplace_scalar(mp_handle, t);
  return *this;
}

__forceinline FLOATquat3D FLOATquat3D::operator+(const FLOATquat3D& q2) const
{
  return FLOATquat3D(FLOATquat3D_Plus(mp_handle, q2), true);
}

inline FLOATquat3D& FLOATquat3D::operator+=(const FLOATquat3D& q2)
{
  FLOATquat3D_PlusInplace(mp_handle, q2);
  return *this;
}

__forceinline FLOATquat3D FLOATquat3D::operator-(const FLOATquat3D& q2) const
{
  return FLOATquat3D(FLOATquat3D_Minus(mp_handle, q2), true);
}

inline FLOATquat3D& FLOATquat3D::operator-=(const FLOATquat3D& q2)
{
  FLOATquat3D_MinusInplace(mp_handle, q2);
  return *this;
}

__forceinline FLOATquat3D FLOATquat3D::operator*(const FLOATquat3D& q2) const
{
  return FLOATquat3D(FLOATquat3D_Multiply(mp_handle, q2), true);
}

inline FLOATquat3D& FLOATquat3D::operator*=(const FLOATquat3D& q2)
{
  FLOATquat3D_MultiplyInplace(mp_handle, q2);
  return *this;
}

inline FLOAT FLOATquat3D::operator%(const FLOATquat3D& q2) const
{
  return FLOATquat3D_Dot(mp_handle, q2);
}

inline FLOAT FLOATquat3D::Norm() const
{
  return FLOATquat3D_Norm(mp_handle);
}

__forceinline FLOATquat3D operator*(FLOAT t, FLOATquat3D q)
{
  return FLOATquat3D(FLOATquat3D_Multiply_scalar(q, t), true);
}

__forceinline FLOATquat3D Exp(const FLOATquat3D& q)
{
  return FLOATquat3D(FLOATquat3D_Exp(q), true);
}

__forceinline FLOATquat3D Log(const FLOATquat3D& q)
{
  return FLOATquat3D(FLOATquat3D_Log(q), true);
}

__forceinline FLOATquat3D Slerp(FLOAT tT, const FLOATquat3D& q1, const FLOATquat3D& q2)
{
  return FLOATquat3D(FLOATquat3D_Slerp(tT, q1, q2), true);
}

__forceinline FLOATquat3D Squad(FLOAT tT,
  const FLOATquat3D& q1, const FLOATquat3D& q2,
  const FLOATquat3D& qa, const FLOATquat3D& qb)
{
  return FLOATquat3D(FLOATquat3D_Squad(tT, q1, q2, qa, qb), true);
}

inline DOUBLEquat3D::DOUBLEquat3D(DOUBLEquat3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline DOUBLEquat3D::DOUBLEquat3D()
  : m_owner(true)
  , mp_handle(DOUBLEquat3D_new())
{
}

inline DOUBLEquat3D::DOUBLEquat3D(const DOUBLEquat3D& o)
  : m_owner(true)
  , mp_handle(DOUBLEquat3D_clone(o))
{
}

inline DOUBLEquat3D::DOUBLEquat3D(DOUBLE w, DOUBLE x, DOUBLE y, DOUBLE z)
  : m_owner(true)
  , mp_handle(DOUBLEquat3D_new_args(w, x, y, z))
{
}

inline DOUBLEquat3D::~DOUBLEquat3D()
{
  if (m_owner)
    DOUBLEquat3D_delete(mp_handle);
}

inline DOUBLEquat3D& DOUBLEquat3D::operator=(const DOUBLEquat3D& o)
{
  DOUBLEquat3D_copy(mp_handle, o);
  return *this;
}

inline DOUBLE DOUBLEquat3D::x() const
{
  return DOUBLEquat3D_x(mp_handle);
}

inline DOUBLE DOUBLEquat3D::y() const
{
  return DOUBLEquat3D_y(mp_handle);
}

inline DOUBLE DOUBLEquat3D::z() const
{
  return DOUBLEquat3D_z(mp_handle);
}

inline DOUBLE DOUBLEquat3D::w() const
{
  return DOUBLEquat3D_w(mp_handle);
}

inline void DOUBLEquat3D::setx(DOUBLE x)
{
  DOUBLEquat3D_setx(mp_handle, x);
}

inline void DOUBLEquat3D::sety(DOUBLE y)
{
  DOUBLEquat3D_sety(mp_handle, y);
}

inline void DOUBLEquat3D::setz(DOUBLE z)
{
  DOUBLEquat3D_setz(mp_handle, z);
}

inline void DOUBLEquat3D::setw(DOUBLE w)
{
  DOUBLEquat3D_setw(mp_handle, w);
}

inline void DOUBLEquat3D::FromEuler(const DOUBLE3D& a)
{
  DOUBLEquat3D_FromEuler(mp_handle, a);
}

inline void DOUBLEquat3D::ToMatrix(DOUBLEmatrix3D& m) const
{
  DOUBLEquat3D_ToMatrix(mp_handle, m);
}

inline void DOUBLEquat3D::FromMatrix(DOUBLEmatrix3D& m)
{
  DOUBLEquat3D_FromMatrix(mp_handle, m);
}

inline void DOUBLEquat3D::FromAxisAngle(const DOUBLE3D& n, DOUBLE a)
{
  DOUBLEquat3D_FromAxisAngle(mp_handle, n, a);
}

inline void DOUBLEquat3D::ToAxisAngle(DOUBLE3D& n, DOUBLE& a)
{
  DOUBLEquat3D_ToAxisAngle(mp_handle, n, &a);
}

__forceinline DOUBLEquat3D DOUBLEquat3D::operator-() const
{
  return DOUBLEquat3D(DOUBLEquat3D_Flip(mp_handle), true);
}

__forceinline DOUBLEquat3D DOUBLEquat3D::operator~() const
{
  return DOUBLEquat3D(DOUBLEquat3D_Conjugate(mp_handle), true);
}

__forceinline DOUBLEquat3D DOUBLEquat3D::Inv() const
{
  return DOUBLEquat3D(DOUBLEquat3D_Inv(mp_handle), true);
}

__forceinline DOUBLEquat3D DOUBLEquat3D::operator*(DOUBLE t) const
{
  return DOUBLEquat3D(DOUBLEquat3D_Multiply_scalar(mp_handle, t), true);
}

inline DOUBLEquat3D& DOUBLEquat3D::operator*=(DOUBLE t)
{
  DOUBLEquat3D_MultiplyInplace_scalar(mp_handle, t);
  return *this;
}

__forceinline DOUBLEquat3D DOUBLEquat3D::operator/(DOUBLE t) const
{
  return DOUBLEquat3D(DOUBLEquat3D_Divide_scalar(mp_handle, t), true);
}

inline DOUBLEquat3D& DOUBLEquat3D::operator/=(DOUBLE t)
{
  DOUBLEquat3D_DivideInplace_scalar(mp_handle, t);
  return *this;
}

__forceinline DOUBLEquat3D DOUBLEquat3D::operator+(const DOUBLEquat3D& q2) const
{
  return DOUBLEquat3D(DOUBLEquat3D_Plus(mp_handle, q2), true);
}

inline DOUBLEquat3D& DOUBLEquat3D::operator+=(const DOUBLEquat3D& q2)
{
  DOUBLEquat3D_PlusInplace(mp_handle, q2);
  return *this;
}

__forceinline DOUBLEquat3D DOUBLEquat3D::operator-(const DOUBLEquat3D& q2) const
{
  return DOUBLEquat3D(DOUBLEquat3D_Minus(mp_handle, q2), true);
}

inline DOUBLEquat3D& DOUBLEquat3D::operator-=(const DOUBLEquat3D& q2)
{
  DOUBLEquat3D_MinusInplace(mp_handle, q2);
  return *this;
}

__forceinline DOUBLEquat3D DOUBLEquat3D::operator*(const DOUBLEquat3D& q2) const
{
  return DOUBLEquat3D(DOUBLEquat3D_Multiply(mp_handle, q2), true);
}

inline DOUBLEquat3D& DOUBLEquat3D::operator*=(const DOUBLEquat3D& q2)
{
  DOUBLEquat3D_MultiplyInplace(mp_handle, q2);
  return *this;
}

inline DOUBLE DOUBLEquat3D::operator%(const DOUBLEquat3D& q2) const
{
  return DOUBLEquat3D_Dot(mp_handle, q2);
}

inline DOUBLE DOUBLEquat3D::Norm() const
{
  return DOUBLEquat3D_Norm(mp_handle);
}

__forceinline DOUBLEquat3D operator*(DOUBLE t, DOUBLEquat3D q)
{
  return DOUBLEquat3D(DOUBLEquat3D_Multiply_scalar(q, t), true);
}

__forceinline DOUBLEquat3D Exp(const DOUBLEquat3D& q)
{
  return DOUBLEquat3D(DOUBLEquat3D_Exp(q), true);
}

__forceinline DOUBLEquat3D Log(const DOUBLEquat3D& q)
{
  return DOUBLEquat3D(DOUBLEquat3D_Log(q), true);
}

__forceinline DOUBLEquat3D Slerp(DOUBLE tT, const DOUBLEquat3D& q1, const DOUBLEquat3D& q2)
{
  return DOUBLEquat3D(DOUBLEquat3D_Slerp(tT, q1, q2), true);
}

__forceinline DOUBLEquat3D Squad(DOUBLE tT,
  const DOUBLEquat3D& q1, const DOUBLEquat3D& q2,
  const DOUBLEquat3D& qa, const DOUBLEquat3D& qb)
{
  return DOUBLEquat3D(DOUBLEquat3D_Squad(tT, q1, q2, qa, qb), true);
}
