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
#include "FileName.h"
#include "../Templates/DynamicArray.h"
#include <SeriousEngineCAPI/Base/Translation.h>

inline void InitTranslation()
{
  InitTranslation_();
}

inline void AddTranslationTable_t(const CTFileName& fnmTable)
{
  AddTranslationTable_t_(fnmTable);
  SECppAPI_CheckException();
}

inline void AddTranslationTablesDir_t(const CTFileName& fnmDir, const CTFileName& fnmPattern)
{
  AddTranslationTablesDir_t_(fnmDir, fnmPattern);
  SECppAPI_CheckException();
}

inline void FinishTranslationTable()
{
  FinishTranslationTable_();
}

inline void ReadTranslationTable_t(CDynamicArray_CTranslationPair& atpPairs, const CTFileName& fnmTable)
{
  ReadTranslationTable_t_(atpPairs, fnmTable);
  SECppAPI_CheckException();
}

inline char* Translate(const char* str, INDEX iOffset)
{
  return Translate_((char*)str, iOffset);
}

inline const char* TranslateConst(const char* str, INDEX iOffset)
{
  return TranslateConst_(str, iOffset);
}
