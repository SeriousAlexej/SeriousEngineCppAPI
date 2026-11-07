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

inline void ThrowF_t [[noreturn]] (const char* strFormat, ...)
{
  const SLONG slBufferSize = 256;
  char strBuffer[slBufferSize + 1];
  // format the message in buffer
  va_list arg;
  va_start(arg, strFormat); // variable arguments start after this argument
  _vsnprintf(strBuffer, slBufferSize, strFormat, arg);
  strBuffer[slBufferSize] = '\0';
  va_end(arg);
  ThrowF_t_(strBuffer);
  SECppAPI_CheckException();
}

inline void FatalError [[noreturn]] (const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  CTString strBuffer;
  strBuffer.VPrintF(strFormat, arg);
  va_end(arg);
  FatalError_(strBuffer);
}

inline void WarningMessage(const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  CTString strBuffer;
  strBuffer.VPrintF(strFormat, arg);
  va_end(arg);
  WarningMessage_(strBuffer);
}

inline void InfoMessage(const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  CTString strBuffer;
  strBuffer.VPrintF(strFormat, arg);
  va_end(arg);
  InfoMessage_(strBuffer);
}

__forceinline const CTString GetWindowsError(DWORD dwWindowsErrorCode)
{
  return CTString(GetWindowsError_(dwWindowsErrorCode), true);
}
