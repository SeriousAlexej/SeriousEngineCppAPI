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
#include "../Templates/DynamicStackArray.h"
#include <stdarg.h>

inline CChunkID::CChunkID(CChunkID_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CChunkID::CChunkID(const char* strString)
  : m_owner(true)
  , mp_handle(CChunkID_new(strString))
{
}

inline CChunkID::~CChunkID()
{
  if (m_owner)
    CChunkID_delete(mp_handle);
}

inline BOOL CChunkID::operator==(const CChunkID& cidOther) const
{
  return CChunkID_equal(mp_handle, cidOther);
}

inline BOOL CChunkID::operator!=(const CChunkID& cidOther) const
{
  return CChunkID_notequal(mp_handle, cidOther);
}

inline CChunkID::operator const char* () const
{
  return CChunkID_str_const(mp_handle);
}

inline CChunkID::operator char* ()
{
  return CChunkID_str(mp_handle);
}

inline void CTStream::ExecuteWithStreamHandling(const std::function<void()>& func)
{
  static thread_local const std::function<void()>* p_func = nullptr;
  static thread_local std::exception_ptr p_exc;
  static thread_local std::exception_ptr* const p_exc_raw = &p_exc;
  p_func = &func;
  p_exc = nullptr;
  void (*callback)(void) noexcept(true) = []() noexcept(true) { try { (*p_func)(); } catch (...) { (*p_exc_raw) = std::current_exception(); } };
  CTStream_ExecuteWithStreamHandling(callback);
  if (p_exc)
    std::rethrow_exception(p_exc);
}

inline void CTStream::Read_t(void* pvBuffer, SLONG slSize)
{
  CTStream_Read_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

inline void CTStream::Write_t(const void* pvBuffer, SLONG slSize)
{
  CTStream_Write_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

inline void CTStream::Seek_t(SLONG slOffset, enum SeekDir sd)
{
  CTStream_Seek_t(mp_stream, slOffset, (INDEX)sd);
  SECppAPI_CheckException();
}

inline void CTStream::SetPos_t(SLONG slPosition)
{
  CTStream_SetPos_t(mp_stream, slPosition);
  SECppAPI_CheckException();
}

inline SLONG CTStream::GetPos_t()
{
  const auto res = CTStream_GetPos_t(mp_stream);
  SECppAPI_CheckException();
  return res;
}

inline SLONG CTStream::GetStreamSize()
{
  return CTStream_GetStreamSize(mp_stream);
}

inline ULONG CTStream::GetStreamCRC32_t()
{
  const auto res = CTStream_GetStreamCRC32_t(mp_stream);
  SECppAPI_CheckException();
  return res;
}

inline BOOL CTStream::AtEOF()
{
  return CTStream_AtEOF(mp_stream);
}

inline void CTStream::PutLine_t(const char* strBuffer)
{
  CTStream_PutLine_t(mp_stream, strBuffer);
  SECppAPI_CheckException();
}

inline void CTStream::PutString_t(const char* strString)
{
  CTStream_PutString_t(mp_stream, strString);
  SECppAPI_CheckException();
}

inline void CTStream::FPrintF_t(const char* strFormat, ...)
{
  const SLONG slBufferSize = 2048;
  char strBuffer[slBufferSize];
  // format the message in buffer
  va_list arg;
  va_start(arg, strFormat); // variable arguments start after this argument
  vsnprintf(strBuffer, slBufferSize, strFormat, arg);
  va_end(arg);
  // print the buffer
  PutString_t(strBuffer);
}

inline void CTStream::GetLine_t(char* strBuffer, SLONG slBufferSize, char cDelimiter)
{
  CTStream_GetLine_t(mp_stream, strBuffer, slBufferSize, cDelimiter);
  SECppAPI_CheckException();
}

inline void CTStream::GetLine_t(CTString& strLine, char cDelimiter)
{
  CTStream_GetLine_t_str(mp_stream, strLine, cDelimiter);
  SECppAPI_CheckException();
}

inline void CTStream::ExpectID_t(const CChunkID& cidExpected)
{
  CTStream_ExpectID_t(mp_stream, cidExpected);
  SECppAPI_CheckException();
}

inline void CTStream::ExpectKeyword_t(const CTString& strKeyword)
{
  CTStream_ExpectKeyword_t(mp_stream, strKeyword);
  SECppAPI_CheckException();
}

inline SLONG CTStream::GetSize_t()
{
  const auto res = CTStream_GetSize_t(mp_stream);
  SECppAPI_CheckException();
  return res;
}

inline void CTStream::ReadRawChunk_t(void* pvBuffer, SLONG slSize)
{
  CTStream_ReadRawChunk_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

inline void CTStream::ReadChunk_t(void* pvBuffer, SLONG slExpectedSize)
{
  CTStream_ReadChunk_t(mp_stream, pvBuffer, slExpectedSize);
  SECppAPI_CheckException();
}

inline void CTStream::ReadFullChunk_t(const CChunkID& cidExpected, void* pvBuffer, SLONG slExpectedSize)
{
  CTStream_ReadFullChunk_t(mp_stream, cidExpected, pvBuffer, slExpectedSize);
  SECppAPI_CheckException();
}

inline void CTStream::WriteID_t(const CChunkID& cidSave)
{
  CTStream_WriteID_t(mp_stream, cidSave);
  SECppAPI_CheckException();
}

inline void CTStream::WriteSize_t(SLONG slSize)
{
  CTStream_WriteSize_t(mp_stream, slSize);
  SECppAPI_CheckException();
}

inline void CTStream::WriteRawChunk_t(void* pvBuffer, SLONG slSize)
{
  CTStream_WriteRawChunk_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

inline void CTStream::WriteChunk_t(void* pvBuffer, SLONG slSize)
{
  CTStream_WriteChunk_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

inline void CTStream::WriteFullChunk_t(const CChunkID& cidSave, void* pvBuffer, SLONG slSize)
{
  CTStream_WriteFullChunk_t(mp_stream, cidSave, pvBuffer, slSize);
  SECppAPI_CheckException();
}

inline void CTStream::DictionaryWriteBegin_t(const CTFileName& fnmImportFrom, SLONG slImportOffset)
{
  CTStream_DictionaryWriteBegin_t(mp_stream, fnmImportFrom, slImportOffset);
  SECppAPI_CheckException();
}

inline void CTStream::DictionaryWriteEnd_t()
{
  CTStream_DictionaryWriteEnd_t(mp_stream);
  SECppAPI_CheckException();
}

inline SLONG CTStream::DictionaryReadBegin_t()
{
  const auto res = CTStream_DictionaryReadBegin_t(mp_stream);
  SECppAPI_CheckException();
  return res;
}

inline void CTStream::DictionaryReadEnd_t()
{
  CTStream_DictionaryReadEnd_t(mp_stream);
  SECppAPI_CheckException();
}

inline void CTStream::DictionaryPreload_t()
{
  CTStream_DictionaryPreload_t(mp_stream);
  SECppAPI_CheckException();
}

inline CTStream::CTStream(CTStream_* p, bool owner)
  : m_owner(owner)
  , mp_stream(p)
{
}

inline CTFileStream::CTFileStream(CTFileStream_* p, bool owner)
  : CTStream((CTStream_*)p, owner)
{
}

inline CTFileStream::CTFileStream()
  : CTFileStream(CTFileStream_new(), true)
{
}

inline CTFileStream::~CTFileStream()
{
  if (m_owner)
    CTFileStream_delete(C_Handle());
  m_owner = false;
  mp_stream = nullptr;
}

inline void CTFileStream::Open_t(const CTFileName& fnFileName, enum CTStream::OpenMode om)
{
  CTFileStream_Open_t(C_Handle(), fnFileName, (INDEX)om);
  SECppAPI_CheckException();
}

inline void CTFileStream::Create_t(const CTFileName& fnFileName)
{
  CTFileStream_Create_t(C_Handle(), fnFileName);
  SECppAPI_CheckException();
}

inline void CTFileStream::Close()
{
  CTFileStream_Close(C_Handle());
}

inline CTMemoryStream::CTMemoryStream(CTMemoryStream_* p, bool owner)
  : CTStream((CTStream_*)p, owner)
{
}

inline CTMemoryStream::CTMemoryStream()
  : CTMemoryStream(CTMemoryStream_new(), true)
{
}

inline CTMemoryStream::CTMemoryStream(void* pvBuffer, SLONG slSize, CTStream::OpenMode om)
  : CTMemoryStream(CTMemoryStream_new_buffer(pvBuffer, slSize, (INDEX)om), true)
{
}

inline CTMemoryStream::~CTMemoryStream()
{
  if (m_owner)
    CTMemoryStream_delete(C_Handle());
  m_owner = false;
  mp_stream = nullptr;
}

inline void CTMemoryStream::LockBuffer(void** ppvBuffer, SLONG* pslSize)
{
  CTMemoryStream_LockBuffer(C_Handle(), ppvBuffer, pslSize);
}

inline void CTMemoryStream::UnlockBuffer()
{
  CTMemoryStream_UnlockBuffer(C_Handle());
}

inline BOOL FileExists(const CTFileName& fnmFile)
{
  return FileExists_(fnmFile);
}

inline BOOL FileExistsForWriting(const CTFileName& fnmFile)
{
  return FileExistsForWriting_(fnmFile);
}

inline SLONG GetFileTimeStamp_t(const CTFileName& fnmFile)
{
  const auto res = GetFileTimeStamp_t_(fnmFile);
  SECppAPI_CheckException();
  return res;
}

inline ULONG GetFileCRC32_t(const CTFileName& fnmFile)
{
  const auto res = GetFileCRC32_t_(fnmFile);
  SECppAPI_CheckException();
  return res;
}

inline BOOL IsFileReadOnly(const CTFileName& fnmFile)
{
  return IsFileReadOnly_(fnmFile);
}

inline BOOL RemoveFile(const CTFileName& fnmFile)
{
  return RemoveFile_(fnmFile);
}

inline INDEX ExpandFilePath(ULONG ulType, const CTFileName& fnmFile, CTFileName& fnmExpanded)
{
  return ExpandFilePath_(ulType, fnmFile, fnmExpanded);
}

inline void MakeDirList(
  CDynamicStackArray_CTFileName& adeDir,
  const CTFileName& fnmDir,
  const CTString& strPattern,
  ULONG ulFlags)
{
  return MakeDirList_(adeDir, fnmDir, strPattern, ulFlags);
}

inline void UseApplicationPath()
{
  UseApplicationPath_();
}

inline void IgnoreApplicationPath()
{
  IgnoreApplicationPath_();
}
