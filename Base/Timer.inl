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

inline CTimerValue::CTimerValue(CTimerValue_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , tv_llValue(*CTimerValue_tv_llValue(mp_handle))
{
}

inline CTimerValue::CTimerValue()
  : CTimerValue(CTimerValue_new(), true)
{
}

inline CTimerValue::CTimerValue(int64_t i64)
  : CTimerValue(CTimerValue_new_i64(i64), true)
{
}

inline CTimerValue::CTimerValue(DOUBLE dSeconds)
  : CTimerValue(CTimerValue_new_s(dSeconds), true)
{
}

inline CTimerValue::CTimerValue(const CTimerValue& o)
  : CTimerValue(CTimerValue_clone(o), true)
{
}

inline CTimerValue::~CTimerValue()
{
  if (m_owner)
    CTimerValue_delete(mp_handle);
}

inline CTimerValue& CTimerValue::operator=(const CTimerValue& o)
{
  CTimerValue_copy(mp_handle, o);
  return *this;
}

inline void CTimerValue::Clear()
{
  CTimerValue_Clear(mp_handle);
}

inline CTimerValue& CTimerValue::operator+=(const CTimerValue& tvOther)
{
  tv_llValue += tvOther.tv_llValue;
  return *this;
}

__forceinline CTimerValue CTimerValue::operator+(const CTimerValue& tvOther) const
{
  return CTimerValue(tv_llValue + tvOther.tv_llValue);
}

inline CTimerValue& CTimerValue::operator-=(const CTimerValue& tvOther)
{
  tv_llValue -= tvOther.tv_llValue;
  return *this;
}

__forceinline CTimerValue CTimerValue::operator-(const CTimerValue& tvOther) const
{
  return CTimerValue(tv_llValue - tvOther.tv_llValue);
}

inline BOOL CTimerValue::operator<(const CTimerValue& tvOther) const
{
  return tv_llValue < tvOther.tv_llValue;
}

inline BOOL CTimerValue::operator>(const CTimerValue& tvOther) const
{
  return tv_llValue > tvOther.tv_llValue;
}

inline BOOL CTimerValue::operator<=(const CTimerValue& tvOther) const
{
  return tv_llValue <= tvOther.tv_llValue;
}

inline BOOL CTimerValue::operator>=(const CTimerValue& tvOther) const
{
  return tv_llValue >= tvOther.tv_llValue;
}

inline DOUBLE CTimerValue::GetSeconds()
{
  return CTimerValue_GetSeconds(mp_handle);
}

inline int64_t CTimerValue::GetMilliseconds()
{
  return CTimerValue_GetMilliseconds(mp_handle);
}


inline CTimerHandler::CTimerHandler(void(*callback)(void) noexcept(true))
  : mp_handle(CTimerHandler_new(callback))
{
}

inline CTimerHandler::~CTimerHandler()
{
  CTimerHandler_delete(mp_handle);
}

__forceinline CTCriticalSectionPtr _pTimer_tm_csHooks()
{
  return _pTimer_tm_csHooks_();
}

__forceinline CTimerValue _pTimer_GetHighPrecisionTimer()
{
  return CTimerValue(_pTimer_GetHighPrecisionTimer_(), true);
}

__forceinline CTString TimeToString(FLOAT fTime)
{
  return CTString(TimeToString_(fTime), true);
}
