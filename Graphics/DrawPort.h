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
#include "../Math/Projection.h"
#include "Raster.h"
#include "Font.h"
#include "ImageInfo.h"
#include "Texture.h"
#include <SeriousEngineCAPI/Graphics/DrawPort.h>

class CDrawPort
{
public:
  CDrawPort(CDrawPort_* p, bool owner = false);
  // Create a drawport for full raster
  CDrawPort(CRaster_* praBase = nullptr);
  // Clone a drawport
  CDrawPort(CDrawPort_* pdpBase, DOUBLE rMinI, DOUBLE rMinJ, DOUBLE rSizeI, DOUBLE rSizeJ);
  CDrawPort(CDrawPort_* pdpBase, const PIXaabbox2D& box);
  // dualhead cloning
  CDrawPort(CDrawPort_* pdpBase, BOOL bLeft);
  ~CDrawPort();
  CDrawPort(const CDrawPort& o) = delete;
  CDrawPort& operator=(const CDrawPort& o) = delete;

  CRaster dp_Raster(); // pointer to the Raster this refers to
  const CRaster dp_Raster() const;
  CFontDataPtr dp_FontData(); // pointer to the current text font
  const CFontDataPtr dp_FontData() const;

  // set orthogonal projection
  void SetOrtho() const;
  // set given projection
  void SetProjection(CAnyProjection3D& apr) const;

  //  wide-screen cloning
  void MakeWideScreen(CDrawPort_* pdp);

  // check if a drawport is dualhead
  BOOL IsDualHead();
  // check if a drawport is wide screen
  BOOL IsWideScreen();

  // set/get rendering in overlay mode
  void SetOverlappedRendering(BOOL bOverlay);
  BOOL IsOverlappedRendering() const;

  // returns unique drawport number
  ULONG GetID();

  // Get dimensions and location of drawport
  PIX GetWidth() const;
  PIX GetHeight() const;

  // text manipulation
  void SetFont(CFontDataPtr pfd);   // WARNING: this resets text variables
  void SetTextCharSpacing(PIX pixSpacing);
  void SetTextLineSpacing(PIX pixSpacing);
  void SetTextScaling(FLOAT fScalingFactor);
  void SetTextAspect(FLOAT fAspectRatio);
  void SetTextMode(INDEX iMode);
  // returns width of entire text string (with scale included)
  ULONG GetTextWidth(const CTString& strText) const;

  // writes text string on drawport (left-aligned)
  void PutText(const CTString& strText, PIX pixX0, PIX pixY0, const COLOR colBlend = 0xFFFFFFFF) const;
  // writes text string on drawport (centered arround X)
  void PutTextC(const CTString& strText, PIX pixX0, PIX pixY0, const COLOR colBlend = 0xFFFFFFFF) const;
  // writes text string on drawport (centered arround X and Y)
  void PutTextCXY(const CTString& strText, PIX pixX0, PIX pixY0, const COLOR colBlend = 0xFFFFFFFF) const;
  // writes text string on drawport (right-aligned)
  void PutTextR(const CTString& strText, PIX pixX0, PIX pixY0, const COLOR colBlend = 0xFFFFFFFF) const;

  // plain texture display
  void PutTexture(CTextureObject_* pTO, const PIXaabbox2D& boxScreen,
    const COLOR colBlend = 0xFFFFFFFF) const;
  void PutTexture(CTextureObject_* pTO, const PIXaabbox2D& boxScreen,
    const COLOR colUL, const COLOR colUR, const COLOR colDL, const COLOR colDR) const;
  void PutTexture(CTextureObject_* pTO, const PIXaabbox2D& boxScreen,
    const MEXaabbox2D& boxTexture, const COLOR colBlend = 0xFFFFFFFF) const;
  void PutTexture(CTextureObject_* pTO, const PIXaabbox2D& boxScreen, const MEXaabbox2D& boxTexture,
    const COLOR colUL, const COLOR colUR, const COLOR colDL, const COLOR colDR) const;

  // advanced texture display
  void InitTexture(CTextureObject_* pTO, const BOOL bClamp = FALSE) const; // prepares texture and rendering arrays
  // adds one full texture to rendering queue
  void AddTexture(const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const COLOR col) const;
  // adds one part of texture to rendering queue
  void AddTexture(const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1,
    const FLOAT fU0, const FLOAT fV0, const FLOAT fU1, const FLOAT fV1, const COLOR col) const;
  // adds one textured quad to rendering queue (up-left start, counter-clockwise)
  void AddTexture(const FLOAT fI0, const FLOAT fJ0, const FLOAT fU0, const FLOAT fV0, const COLOR col0,
    const FLOAT fI1, const FLOAT fJ1, const FLOAT fU1, const FLOAT fV1, const COLOR col1,
    const FLOAT fI2, const FLOAT fJ2, const FLOAT fU2, const FLOAT fV2, const COLOR col2,
    const FLOAT fI3, const FLOAT fJ3, const FLOAT fU3, const FLOAT fV3, const COLOR col3) const;
  // adds one flat triangle rendering queue (up-left start, counter-clockwise)
  void AddTriangle(const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1,
    const FLOAT fI2, const FLOAT fJ2, const COLOR col) const;

  // renders all textures from rendering queue and flushed rendering arrays
  void FlushRenderingQueue() const;

  // lock and unlock raster thru drawport functions
  BOOL Lock();
  void Unlock();

  // draw point (can be several pixels - depends on radius)
  void DrawPoint(PIX pixI, PIX pixJ, COLOR col, PIX pixRadius = 1) const;
  void DrawPoint3D(FLOAT3D v, COLOR col, FLOAT fRadius = 1.0f) const; // in 3D
  // draw line
  void DrawLine(PIX pixI0, PIX pixJ0, PIX pixI1, PIX pixJ1, COLOR col, ULONG typ = _FULL_) const;
  void DrawLine3D(FLOAT3D v0, FLOAT3D v1, COLOR col) const; // in 3D
  // draw border
  void DrawBorder(PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR col, ULONG typ = _FULL_) const;

  // fill with blending part of a drawport with a given color
  void Fill(PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR col) const;
  // fill with blending part of a drawport with a four corner colors
  void Fill(PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight,
    COLOR colUL, COLOR colUR, COLOR colDL, COLOR colDR) const;
  // fill a part of Z-Buffer with a given value
  void FillZBuffer(PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, FLOAT zval) const;

  // fill without blending an entire drawport with a given color
  void Fill(COLOR col) const;
  // fill an entire Z-Buffer with a given value
  void FillZBuffer(FLOAT zval) const;

  // grab screen (iGrabZBuffer: 0=no, 1=if allowed, 2=yes)
  void GrabScreen(class CImageInfo& iiGrabbedImage, INDEX iGrabZBuffer = 0) const;
  // functions for getting depth of points on drawport
  BOOL IsPointVisible(PIX pixI, PIX pixJ, FLOAT fOoK, INDEX iID, INDEX iMirrorLevel = 0) const;
  // render one lens flare
  void RenderLensFlare(CTextureObject* pto, FLOAT fI, FLOAT fJ,
    FLOAT fSizeI, FLOAT fSizeJ, ANGLE aRotation, COLOR colLight) const;

  // blend entire drawport with accumulated colors
  void BlendScreen();

  inline CDrawPort_* C_Handle() { return mp_handle; }
  inline const CDrawPort_* C_Handle() const { return mp_handle; }
  inline operator CDrawPort_* () { return C_Handle(); }
  inline operator const CDrawPort_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CDrawPort_* mp_handle = nullptr;

public:
  PIX& dp_Width; // width, height in pixels
  PIX& dp_Height;
  PIX& dp_MinI; // I,J coord of the upper left edge in the Raster
  PIX& dp_MinJ;
  PIX& dp_MaxI; // I,J coord of the lower right edge in the Raster
  PIX& dp_MaxJ;
  PIX& dp_ScissorMinI; // I,J coord of the upper left edge in the Raster
  PIX& dp_ScissorMinJ;
  PIX& dp_ScissorMaxI; // I,J coord of the lower right edge in the Raster
  PIX& dp_ScissorMaxJ;
  PIX& dp_pixTextCharSpacing; // space between chars in text
  PIX& dp_pixTextLineSpacing; // space between lines in text
  FLOAT& dp_fTextScaling; // scaling factor for font size
  FLOAT& dp_fTextAspect; // aspect ratio for font (x/y)
  INDEX& dp_iTextMode; // text output mode (-1 = print special codes, 0 = ignore special codes, 1 = parse special codes)
  FLOAT& dp_fWideAdjustment; // for wide (16:9 or 16:10) screen support (needed in some calculations) = 1.0f or >1 (10/12 perhaps)
  BOOL& dp_bRenderingOverlay; // set when scene renderer requires overlay mode (don't clear z-buffer)

  // dimensions and position relative to the raster size
  DOUBLE& dp_SizeIOverRasterSizeI;
  DOUBLE& dp_SizeJOverRasterSizeJ;
  DOUBLE& dp_MinIOverRasterSizeI;
  DOUBLE& dp_MinJOverRasterSizeJ;

  // adjust this during frame to be used for screen blending
  ULONG& dp_ulBlendingRA; // r*a, g*a, b*a
  ULONG& dp_ulBlendingGA;
  ULONG& dp_ulBlendingBA;
  ULONG& dp_ulBlendingA;
};

enum ParticleBlendType : ParticleBlendType_
{
  PBT_BLEND = PBT_BLEND_,
  PBT_ADD = PBT_ADD_,
  PBT_MULTIPLY = PBT_MULTIPLY_,
  PBT_ADDALPHA = PBT_ADDALPHA_,
  PBT_FLEX = PBT_FLEX_, // premultiplied alpha (ONE + [1-SRC_ALPHA])
  PBT_TRANSPARENT = PBT_TRANSPARENT_,
};

void Particle_PrepareSystem(CDrawPort_* pdpDrawPort, CAnyProjection3D& prProjection);
void Particle_PrepareEntity(FLOAT fMipFactor, BOOL bHasFog, BOOL bHasHaze, CEntity_* penViewer);
void Particle_EndSystem(BOOL bRestoreOrtho = TRUE);
FLOAT Particle_GetMipFactor();
INDEX Particle_GetDrawPortID();
CEntity_* Particle_GetViewer();
CProjection3DPtr Particle_GetProjection();
void Particle_PrepareTexture(CTextureObject_* pto, ParticleBlendType pbt);
void Particle_SetTexturePart(MEX mexWidth, MEX mexHeight, INDEX iCol, INDEX iRow);
void Particle_RenderSquare(const FLOAT3D& vPos, FLOAT fSize, ANGLE aRotation, COLOR col, FLOAT fYRatio = 1.0f);
void Particle_RenderQuad3D(const FLOAT3D& vPos0, const FLOAT3D& vPos1, const FLOAT3D& vPos2,
  const FLOAT3D& vPos3, COLOR col);
void Particle_RenderLine(const FLOAT3D& vPos0, const FLOAT3D& vPos1, FLOAT fWidth, COLOR col);
void Particle_Sort(BOOL b3D = FALSE);
void Particle_Flush();

#include "DrawPort.inl"
