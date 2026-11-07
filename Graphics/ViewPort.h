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
#include "Raster.h"
#include <SeriousEngineCAPI/Graphics/ViewPort.h>

// base class for viewport
class CViewPort
{
public:
  CViewPort(CViewPort_* p, bool owner = false);
  CViewPort(PIX width, PIX height, HWND hwnd);
  ~CViewPort();
  CViewPort(const CViewPort& o) = delete;
  CViewPort& operator=(const CViewPort& o) = delete;

  // open/close canvas window
  void OpenCanvas();
  void CloseCanvas(BOOL bRelease = FALSE);
  /* Display the back buffer on screen. */
  void SwapBuffers();
  // change size of this viewport, it's raster and all it's drawports to fit it window
  void Resize();

  inline CViewPort_* C_Handle() { return mp_handle; }
  inline const CViewPort_* C_Handle() const { return mp_handle; }
  inline operator CViewPort_* () { return C_Handle(); }
  inline operator const CViewPort_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CViewPort_* mp_handle = nullptr;

public:
  HWND& vp_hWnd;                 // canvas (child) window
  HWND& vp_hWndParent;           // window of the viewport
  CRaster vp_Raster;            // the used Raster
};

#include "ViewPort.inl"
