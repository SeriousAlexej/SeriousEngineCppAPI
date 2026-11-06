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
#include <SeriousEngineCAPI/Base/CTString.h>

class CTString
{
public:
  CTString(CTString_* p, bool owner = false);
  CTString();
  CTString(const CTString& strOriginal);
  CTString(const char* pString);
  CTString(INDEX iDummy, const char* strFormat, ...);
  ~CTString();

  void Clear();

  /* Conversion into character string. */
  operator const char* () const;

  /* Assignment. */
  CTString& operator=(const char* strCharString);
  CTString& operator=(const CTString& strOther);


  // return length of the string
  INDEX Length() const;
  INDEX LengthNaked() const;

  // strip decorations from the string
  __forceinline CTString Undecorated() const { return CTString(CTString_Undecorated(mp_string), true); }

  /* Find index of a substring in a string (returns -1 if not found). */
  INDEX FindSubstr(const CTString& strSub);
  /* Replace a substring in a string. */
  BOOL ReplaceSubstr(const CTString& strSub, const CTString& strNewSub);
  /* Check if has given prefix */
  BOOL HasPrefix(const CTString& strPrefix) const;
  /* Remove given prefix string from this string */
  BOOL RemovePrefix(const CTString& strPrefix);
  /* Trim the string to contain at most given number of characters. */
  INDEX TrimLeft(INDEX ctCharacters);
  INDEX TrimRight(INDEX ctCharacters);
  /* Trim the string from spaces. */
  INDEX TrimSpacesLeft();
  INDEX TrimSpacesRight();
  /* Calcuate hashing value for the string. */
  ULONG GetHash() const;
  // retain only first line of the string
  void OnlyFirstLine();

  /* Equality comparison. */
  BOOL operator==(const CTString& strOther) const;
  BOOL operator==(const char* strOther) const;
  friend BOOL operator==(const char* strThis, const CTString& strOther);
  /* Inequality comparison. */
  BOOL operator!=(const CTString& strOther) const;
  BOOL operator!=(const char* strOther) const;
  friend BOOL operator!=(const char* strThis, const CTString& strOther);
  // wild card comparison (other string may contain wildcards)
  BOOL Matches(const CTString& strOther) const;
  BOOL Matches(const char* strOther) const;

  /* String concatenation. */
  __forceinline CTString operator+(const CTString& strSecond) const { return CTString(CTString_Concatenate(mp_string, strSecond.mp_string), true); }
  CTString& operator+=(const CTString& strSecond);
  __forceinline friend CTString operator+(const char* strFirst, const CTString& strSecond)
  {
    CTString_* pFirst = CTString_new_str(strFirst);
    CTString_ConcatenateInplace(pFirst, strSecond.C_Handle());
    return CTString(pFirst, true);
  }

  // split string in two strings at specified position (char AT splitting position goes to str2)
  void Split(INDEX iPos, CTString& str1, CTString& str2);
  void InsertChar(INDEX iPos, char cChr); // insert char at position
  void DeleteChar(INDEX iPos); // delete char at position

  /* Throw exception */
  void Throw_t();

  /* Read from stream. */
  friend CTStream& operator>>(CTStream& strmStream, CTString& strString);
  void ReadFromText_t(CTStream& strmStream, const CTString& strKeyword); // throw char *
  /* Write to stream. */
  friend CTStream& operator<<(CTStream& strmStream, const CTString& strString);

  /* Load an entire text file into a string. */
  void Load_t(const CTFileName& fnmFile);  // throw char *
  void LoadKeepCRLF_t(const CTFileName& fnmFile);  // throw char *
  void ReadUntilEOF_t(CTStream& strmStream);  // throw char *
  /* Save an entire string into a text file. */
  void Save_t(const CTFileName& fnmFile);  // throw char *
  void SaveKeepCRLF_t(const CTFileName& fnmFile);  // throw char *

  // Print formatted to a string
  INDEX PrintF(const char* strFormat, ...);
  INDEX VPrintF(const char* strFormat, va_list arg);
  // Scan formatted from a string
  INDEX ScanF(const char* strFormat, ...);

  // variable management functions
  void LoadVar(const CTFileName& fnmFile);
  void SaveVar(const CTFileName& fnmFile);

  inline CTString_* C_Handle() { return mp_string; }
  inline const CTString_* C_Handle() const { return mp_string; }
  inline operator CTString_* () { return C_Handle(); }
  inline operator const CTString_* () const { return C_Handle(); }
protected:
  bool m_owner = true;
  CTString_* mp_string = nullptr;
};

// general variable functions
void LoadStringVar(const CTFileName& fnmVar, CTString& strVar);
void SaveStringVar(const CTFileName& fnmVar, CTString& strVar);
void LoadIntVar(const CTFileName& fnmVar, INDEX& iVar);
void SaveIntVar(const CTFileName& fnmVar, INDEX iVar);

CTString RemoveSpecialCodes(const CTString& str);

#include "FileNameDecl.h"
