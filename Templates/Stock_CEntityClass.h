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
#include <SeriousEngineCAPI/Templates/Stock_CEntityClass.h>

inline CEntityClassPtr _pEntityClassStock_Obtain_t(const CTFileName_* f)
{
  auto res = _pEntityClassStock_Obtain_t_(f);
  SECppAPI_CheckException();
  return res;
}

inline void _pEntityClassStock_Release(CEntityClass_* p)
{
  _pEntityClassStock_Release_(p);
  SECppAPI_CheckException();
}

inline void _pEntityClassStock_FreeUnused()
{
  _pEntityClassStock_FreeUnused_();
  SECppAPI_CheckException();
}
