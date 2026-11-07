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
#include "Types.h"
#include <SeriousEngineCAPI/Base/Synchronization.h>

// intra-process mutex (only used by thread of same process)
// NOTE: mutex has no interface - it is locked using CTSingleLock
class CTCriticalSection
{
public:
  CTCriticalSection(CTCriticalSection_* p, bool owner = false);
  CTCriticalSection();
  ~CTCriticalSection();
  CTCriticalSection(const CTCriticalSection& o) = delete;
  CTCriticalSection& operator=(const CTCriticalSection& o) = delete;

  inline CTCriticalSection_* C_Handle() { return mp_handle; }
  inline const CTCriticalSection_* C_Handle() const { return mp_handle; }
  inline operator CTCriticalSection_* () { return C_Handle(); }
  inline operator const CTCriticalSection_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CTCriticalSection_* mp_handle = nullptr;
};

// lock object for locking a mutex with automatic unlocking
class CTSingleLock
{
public:
  CTSingleLock(CTSingleLock_* p, bool owner = false);
  CTSingleLock(CTCriticalSection_* pcs, BOOL bLock);
  ~CTSingleLock();
  CTSingleLock(const CTSingleLock& o) = delete;
  CTSingleLock& operator=(const CTSingleLock& o) = delete;

  void Lock();
  BOOL TryToLock();
  BOOL IsLocked();
  void Unlock();

  inline CTSingleLock_* C_Handle() { return mp_handle; }
  inline const CTSingleLock_* C_Handle() const { return mp_handle; }
  inline operator CTSingleLock_* () { return C_Handle(); }
  inline operator const CTSingleLock_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CTSingleLock_* mp_handle = nullptr;
};

#include "Synchronization.inl"
