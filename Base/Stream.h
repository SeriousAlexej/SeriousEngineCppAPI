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
#include <SeriousEngineCAPI/Base/Stream.h>
#include <functional>

#define CID_LENGTH 4
class CChunkID {
public:
  CChunkID(CChunkID_* p, bool owner = false);
  CChunkID(const char* strString = "    ");
  ~CChunkID();
  CChunkID(const CChunkID& cidOther) = delete;
  CChunkID& operator=(const CChunkID& cidOther) = delete;
  BOOL operator==(const CChunkID& cidOther) const;
  BOOL operator!=(const CChunkID& cidOther) const;
  operator const char* () const;
  operator char* ();

  inline CChunkID_* C_Handle() { return mp_handle; }
  inline const CChunkID_* C_Handle() const { return mp_handle; }
  inline operator CChunkID_* () { return C_Handle(); }
  inline operator const CChunkID_* () const { return C_Handle(); }
private:
  const bool m_owner = true;
  CChunkID_* mp_handle = nullptr;
};

class CTStream
{
public:
  // modes for opening streams
  enum OpenMode {
    OM_READ = CTStream_OM_READ,
    OM_WRITE = CTStream_OM_WRITE,
    OM_READTEXT = OM_READ,
    OM_WRITETEXT = OM_WRITE,
    OM_READBINARY = OM_READ,
    OM_WRITEBINARY = OM_WRITE,
  };
  // direction for seeking
  enum SeekDir {
    SD_BEG = CTStream_SD_BEG,
    SD_END = CTStream_SD_END,
    SD_CUR = CTStream_SD_CUR,
  };

  /* Read a block of data from stream. */
  void Read_t(void* pvBuffer, SLONG slSize); // throw char *
  /* Write a block of data to stream. */
  void Write_t(const void* pvBuffer, SLONG slSize); // throw char *

  /* Seek in stream. */
  void Seek_t(SLONG slOffset, enum SeekDir sd); // throw char *
  /* Set absolute position in stream. */
  void SetPos_t(SLONG slPosition); // throw char *
  /* Get absolute position in stream. */
  SLONG GetPos_t(); // throw char *
  /* Get size of stream */
  SLONG GetStreamSize();
  /* Get CRC32 of stream */
  ULONG GetStreamCRC32_t();
  /* Check if file position points to the EOF */
  BOOL AtEOF();

  /* Read an object from stream. */
  inline CTStream& operator>>(FLOAT& f) { Read_t(&f, sizeof(f)); return *this; } // throw char *
  inline CTStream& operator>>(DOUBLE& d) { Read_t(&d, sizeof(d)); return *this; } // throw char *
  inline CTStream& operator>>(ULONG& ul) { Read_t(&ul, sizeof(ul)); return *this; } // throw char *
  inline CTStream& operator>>(COLOR& ul) { Read_t(&ul, sizeof(ul)); return *this; } // throw char *
  inline CTStream& operator>>(UWORD& uw) { Read_t(&uw, sizeof(uw)); return *this; } // throw char *
  inline CTStream& operator>>(UBYTE& ub) { Read_t(&ub, sizeof(ub)); return *this; } // throw char *
  inline CTStream& operator>>(SWORD& sw) { Read_t(&sw, sizeof(sw)); return *this; } // throw char *
  inline CTStream& operator>>(SBYTE& sb) { Read_t(&sb, sizeof(sb)); return *this; } // throw char *
  inline CTStream& operator>>(BOOL& b) { Read_t(&b, sizeof(b)); return *this; } // throw char *
  /* Write an object into stream. */
  inline CTStream& operator<<(const FLOAT& f) { Write_t(&f, sizeof(f)); return *this; } // throw char *
  inline CTStream& operator<<(const DOUBLE& d) { Write_t(&d, sizeof(d)); return *this; } // throw char *
  inline CTStream& operator<<(const ULONG& ul) { Write_t(&ul, sizeof(ul)); return *this; } // throw char *
  inline CTStream& operator<<(const COLOR& ul) { Write_t(&ul, sizeof(ul)); return *this; } // throw char *
  inline CTStream& operator<<(const UWORD& uw) { Write_t(&uw, sizeof(uw)); return *this; } // throw char *
  inline CTStream& operator<<(const UBYTE& ub) { Write_t(&ub, sizeof(ub)); return *this; } // throw char *
  inline CTStream& operator<<(const SWORD& sw) { Write_t(&sw, sizeof(sw)); return *this; } // throw char *
  inline CTStream& operator<<(const SBYTE& sb) { Write_t(&sb, sizeof(sb)); return *this; } // throw char *
  inline CTStream& operator<<(const BOOL& b) { Write_t(&b, sizeof(b)); return *this; } // throw char *

  /* Put a line of text into stream. */
  void PutLine_t(const char* strBuffer); // throw char *
  void PutString_t(const char* strString); // throw char *
  void FPrintF_t(const char* strFormat, ...); // throw char *
  /* Get a line of text from stream. */
  void GetLine_t(char* strBuffer, SLONG slBufferSize, char cDelimiter = '\n'); // throw char *
  void GetLine_t(CTString& strLine, char cDelimiter = '\n'); // throw char *

  __forceinline CChunkID GetID_t() // throw char *
  {
    CChunkID_* pid = CTStream_GetID_t(mp_stream);
    SECppAPI_CheckException();
    return CChunkID(pid, true);
  }

  __forceinline CChunkID PeekID_t() // throw char *
  {
    CChunkID_* pid = CTStream_PeekID_t(mp_stream);
    SECppAPI_CheckException();
    return CChunkID(pid, true);
  }
  void ExpectID_t(const CChunkID& cidExpected); // throw char *
  void ExpectKeyword_t(const CTString& strKeyword); // throw char *
  SLONG GetSize_t(); // throw char *
  void ReadRawChunk_t(void* pvBuffer, SLONG slSize); // throw char *
  void ReadChunk_t(void* pvBuffer, SLONG slExpectedSize); // throw char *
  void ReadFullChunk_t(const CChunkID& cidExpected, void* pvBuffer, SLONG slExpectedSize); // throw char *

  void WriteID_t(const CChunkID& cidSave); // throw char *
  void WriteSize_t(SLONG slSize); // throw char *
  void WriteRawChunk_t(void* pvBuffer, SLONG slSize); // throw char *  // doesn't write length
  void WriteChunk_t(void* pvBuffer, SLONG slSize); // throw char *
  void WriteFullChunk_t(const CChunkID& cidSave, void* pvBuffer, SLONG slSize); // throw char *

  // start writing a with a dictionary
  void DictionaryWriteBegin_t(const CTFileName& fnmImportFrom, SLONG slImportOffset);
  // stop writing a with a dictionary
  void DictionaryWriteEnd_t();
  // start reading a with a dictionary
  SLONG DictionaryReadBegin_t();  // returns offset of dictionary for cross-file importing
  // stop reading a with a dictionary
  void DictionaryReadEnd_t();
  // preload all files mentioned in the dictionary
  void DictionaryPreload_t();

  static void ExecuteWithStreamHandling(const std::function<void()>& func);

  inline CTStream_* C_Handle() { return mp_stream; }
  inline const CTStream_* C_Handle() const { return mp_stream; }
  inline operator CTStream_* () { return C_Handle(); }
  inline operator const CTStream_* () const { return C_Handle(); }

protected:
  CTStream(CTStream_* p, bool owner);

protected:
  bool m_owner = true;
  CTStream_* mp_stream = nullptr;
};

class CTFileStream : public CTStream
{
public:
  CTFileStream(CTFileStream_* p, bool owner = false);
  CTFileStream();
  ~CTFileStream();
  CTFileStream(const CTFileStream& o) = delete;
  CTFileStream& operator=(const CTFileStream& o) = delete;

  /* Open an existing file. */
  void Open_t(const CTFileName& fnFileName, enum CTStream::OpenMode om = CTStream::OM_READ); // throw char *
  /* Create a new file or overwrite existing. */
  void Create_t(const CTFileName& fnFileName); // throw char *
  /* Close an open file. */
  void Close();

  inline CTFileStream_* C_Handle() { return (CTFileStream_*)mp_stream; }
  inline const CTFileStream_* C_Handle() const { return (const CTFileStream_*)mp_stream; }
  inline operator CTFileStream_* () { return C_Handle(); }
  inline operator const CTFileStream_* () const { return C_Handle(); }
};

class CTMemoryStream : public CTStream
{
public:
  CTMemoryStream(CTMemoryStream_* p, bool owner = false);
  CTMemoryStream();
  CTMemoryStream(void* pvBuffer, SLONG slSize, CTStream::OpenMode om = CTStream::OM_READ);
  ~CTMemoryStream();
  CTMemoryStream(const CTMemoryStream& o) = delete;
  CTMemoryStream& operator=(const CTMemoryStream& o) = delete;

  /* Lock the buffer contents and it's size. */
  void LockBuffer(void** ppvBuffer, SLONG* pslSize);
  /* Unlock buffer. */
  void UnlockBuffer();

  inline CTMemoryStream_* C_Handle() { return (CTMemoryStream_*)mp_stream; }
  inline const CTMemoryStream_* C_Handle() const { return (const CTMemoryStream_*)mp_stream; }
  inline operator CTMemoryStream_* () { return C_Handle(); }
  inline operator const CTMemoryStream_* () const { return C_Handle(); }
};

// Test if a file exists.
BOOL FileExists(const CTFileName& fnmFile);
// Test if a file exists for writing. 
// (this is can be diferent than normal FileExists() if a mod uses basewriteexclude.lst
BOOL FileExistsForWriting(const CTFileName& fnmFile);
// Get file timestamp
SLONG GetFileTimeStamp_t(const CTFileName& fnmFile); // throw char *
// Get CRC32 of a file
ULONG GetFileCRC32_t(const CTFileName& fnmFile); // throw char *
// Test if a file is read only (also returns FALSE if file does not exist)
BOOL IsFileReadOnly(const CTFileName& fnmFile);
// Delete a file (called 'remove' to avid name clashes with win32)
BOOL RemoveFile(const CTFileName& fnmFile);

// Expand a file's filename to full path

// these are input flags for describing what you need the file for
#define EFP_READ   CTStream_EFP_READ  // will open for reading
#define EFP_WRITE  CTStream_EFP_WRITE  // will open for writing
#define EFP_NOZIPS CTStream_EFP_NOZIPS // add this flag to forbid searching in zips
#define EFP_NODISK CTStream_EFP_NODISK // add this flag to forbid searching on disk
// these are return values 
#define EFP_NONE       CTStream_EFP_NONE  // doesn't exist
#define EFP_FILE       CTStream_EFP_FILE  // generic file on disk
#define EFP_BASEZIP    CTStream_EFP_BASEZIP  // file in one of base zips
#define EFP_MODZIP     CTStream_EFP_MODZIP  // file in one of mod zips
INDEX ExpandFilePath(ULONG ulType, const CTFileName& fnmFile, CTFileName& fnmExpanded);

// these are input flags for directory reading
#define DLI_RECURSIVE  CTStream_DLI_RECURSIVE  // recurse into subdirs
#define DLI_SEARCHCD   CTStream_DLI_SEARCHCD  // search the CD path also
// make a list of all files in a directory
void MakeDirList(
  CDynamicStackArray_CTFileName& adeDir,
  const CTFileName& fnmDir,     // directory to list
  const CTString& strPattern,   // pattern for each file to match ("" matches all)
  ULONG ulFlags                 // additional flags
);

// global string with application path
#define _fnmApplicationPath\
  CTFileName(_fnmApplicationPath_(), false)
// global string with current MOD path
#define _fnmMod\
  CTFileName(_fnmMod_(), false)
// global string with current name (the parameter that is passed on cmdline)
#define _strModName\
  CTString(_strModName_(), false)
// global string with url to be shown to users that don't have the mod installed
// (should be set by game.dll)
#define _strModURL\
  CTString(_strModURL_(), false)
// global string with current MOD extension (for adding to dlls)
#define _strModExt\
  CTString(_strModExt_(), false)
// global string with CD path (for minimal installations)
#define _fnmCDPath\
  CTFileName(_fnmCDPath_(), false)
// global string with filename of the started application
#define _fnmApplicationExe\
  CTFileName(_fnmApplicationExe_(), false)

// application path usage funtions
void UseApplicationPath();
void IgnoreApplicationPath();

inline CTFileName GetGroFileAtIndex(INDEX i) { return CTFileName(_GetGroFileAtIndex(i), true); }
inline CTFileName GetGroFileArchiveAtIndex(INDEX i) { return CTFileName(_GetGroFileArchiveAtIndex(i), false); }

#include "Stream.inl"
