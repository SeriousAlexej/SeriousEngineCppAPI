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
#include "../Base/Serial.h"
#include <SeriousEngineCAPI/Sound/SoundData.h>

#define SDF_ENCODED       SDF_ENCODED_ // this is ogg or mpx compressed file
#define SDF_STREAMING     SDF_STREAMING_ // streaming from disk

class CSoundData : public CSerial
{
public:
  CSoundData(CSoundData_* p, bool owner = false);
  CSoundData();
  ~CSoundData();
  CSoundData(const CSoundData& o) = delete;
  CSoundData& operator=(const CSoundData& o) = delete;

  // get sound length in seconds
  DOUBLE GetSecondsLength();

  inline CSoundData_* C_Handle() { return (CSoundData_*)CSerial::C_Handle(); }
  inline const CSoundData_* C_Handle() const { return (const CSoundData_*)CSerial::C_Handle(); }
  inline operator CSoundData_* () { return C_Handle(); }
  inline operator const CSoundData_* () const { return C_Handle(); }
};

#include "SoundData.inl"
