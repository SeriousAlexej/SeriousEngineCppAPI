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
#include <optional>

template<typename TObject, typename TObjectCHandle>
class TPointer
{
public:
  using TObjectType = TObject;
  using THandleType = TObjectCHandle;

  inline TPointer()
  {
  }
  inline TPointer(TObjectCHandle* p)
  {
    if (p)
      m_object.emplace(p, false);
  }
  inline TPointer(TObject* p)
  {
    if (p && p->C_Handle())
      m_object.emplace((TObjectCHandle*)p->C_Handle(), false);
  }
  inline TPointer(const TPointer<TObject, TObjectCHandle>& o)
  {
    if (o)
      m_object.emplace((TObjectCHandle*)o.m_object->C_Handle(), false);
  }
  inline TPointer(TPointer<TObject, TObjectCHandle>&& o)
  {
    if (o)
      m_object.emplace(o.m_object->C_Handle(), false);
    o.m_object.reset();
  }
  inline ~TPointer() = default;
  inline TPointer& operator=(TObjectCHandle* p)
  {
    m_object.reset();
    if (p)
      m_object.emplace(p, false);
    return *this;
  }
  inline TPointer& operator=(TObject* p)
  {
    TObjectCHandle* h = (p && p->C_Handle()) ? (TObjectCHandle*)p->C_Handle() : nullptr;
    m_object.reset();
    if (h)
      m_object.emplace(h, false);
    return *this;
  }
  inline TPointer& operator=(const TPointer<TObject, TObjectCHandle>& o)
  {
    if (this == &o)
      return *this;
    TObjectCHandle* h = o ? (TObjectCHandle*)o.m_object->C_Handle() : nullptr;
    m_object.reset();
    if (h)
      m_object.emplace(h, false);
    return *this;
  }
  inline TPointer& operator=(TPointer<TObject, TObjectCHandle>&& o)
  {
    if (this == &o)
      return *this;
    TObjectCHandle* h = o ? o.m_object->C_Handle() : nullptr;
    m_object.reset();
    if (h)
      m_object.emplace(h, false);
    o.m_object.reset();
    return *this;
  }
  inline operator bool()
  {
    return m_object.has_value() && m_object->C_Handle();
  }
  inline operator bool() const
  {
    return m_object.has_value() && m_object->C_Handle();
  }
  inline TObject* operator->()
  {
    if (m_object.has_value())
      return &(*m_object);
    return nullptr;
  }
  inline TObject& operator*()
  {
    return m_object.value();
  }
  inline const TObject* operator->() const
  {
    if (m_object.has_value())
      return &(*m_object);
    return nullptr;
  }
  inline const TObject& operator*() const
  {
    return m_object.value();
  }
  inline void Reset()
  {
    m_object.reset();
  }
  inline TObject* get()
  {
    if (m_object.has_value())
      return &(*m_object);
    return nullptr;
  }
  inline TObjectCHandle* get_handle()
  {
    if (m_object.has_value())
      return m_object->C_Handle();
    return nullptr;
  }
  inline const TObjectCHandle* get_handle() const
  {
    if (m_object.has_value())
      return m_object->C_Handle();
    return nullptr;
  }
  inline operator TObjectCHandle* ()
  {
    return get_handle();
  }
  inline operator const TObjectCHandle* () const
  {
    return get_handle();
  }
  inline bool operator==(const TObjectCHandle* p) const
  {
    return get_handle() == p;
  }
  inline bool operator==(const TObject* p) const
  {
    const TObjectCHandle* op = (p ? p->C_Handle() : nullptr);
    return get_handle() == op;
  }
  inline bool operator==(const TPointer<TObject, TObjectCHandle>& o) const
  {
    return get_handle() == o.get_handle();
  }
  inline bool operator!=(const TObjectCHandle* p) const { return !((*this) == p); }
  inline bool operator!=(const TObject* p) const { return !((*this) == p); }
  inline bool operator!=(const TPointer<TObject, TObjectCHandle>& o) const { return !((*this) == o); }
  inline bool operator<(const TPointer<TObject, TObjectCHandle>& o) const { return get_handle() < o.get_handle(); }

private:
  std::optional<TObject> m_object;
};
