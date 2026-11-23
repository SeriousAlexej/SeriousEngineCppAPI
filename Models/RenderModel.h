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
#include "../Math/Placement.h"
#include "../Math/Matrix.h"
#include "../Math/Projection.h"
#include "../Graphics/Texture.h"
#include "../Graphics/DrawPort.h"
#include <SeriousEngineCAPI/Models/RenderModel.h>

/*
 *  This object is used to define how models and their shadows will be rendered
 */
class CModelRenderPrefs
{
public:
  CModelRenderPrefs(CModelRenderPrefs_* p, bool owner = false);
  CModelRenderPrefs();
  CModelRenderPrefs(const CModelRenderPrefs& o);
  ~CModelRenderPrefs();
  CModelRenderPrefs& operator=(const CModelRenderPrefs& o);

  void SetRenderType(ULONG rtNew);      // set model rendering type
  void SetTextureType(ULONG rtNew);     // set model rendering texture type
  void SetShadingType(ULONG rtNew);     // set model shading texture type
  void SetShadowQuality(INDEX iNew);    // set shadow quality (best 0, worse -1, ...)
  void DesreaseShadowQuality();               // decrease shadow quality
  void IncreaseShadowQuality();               // increase shadow quality
  void SetWire(BOOL bWireOn);                     // set wire frame on/off
  void SetHiddenLines(BOOL bHiddenLinesOn);       // set hiden lines on/off
  BOOL BBoxFrameVisible();                        // bounding box frames visible?
  BOOL BBoxAllVisible();                          // bounding box all frames visible?
  BOOL WireOn();                              // returns TRUE if wire frame is on
  BOOL HiddenLines();                         // returns TRUE if hiden lines are visible
  void SetInkColor(COLOR clrNew);                 // set ink color
  COLOR GetInkColor();                            // get ink color
  void SetPaperColor(COLOR clrNew);               // set paper color
  COLOR GetPaperColor();                          // get paper color
  void BBoxFrameShow(BOOL bShow);                 // show bounding box frame
  void BBoxAllShow(BOOL bShow);                   // show bounding box all frames
  ULONG GetRenderType();                      // get model rendering type
  INDEX GetShadowQuality();                   // retrieves current shadow quality level
  void Read_t(CTStream* istrFile);   // throw char * // read and
  void Write_t(CTStream* ostrFile);  // throw char * // write functions

  inline CModelRenderPrefs_* C_Handle() { return mp_handle; }
  inline const CModelRenderPrefs_* C_Handle() const { return mp_handle; }
  inline operator CModelRenderPrefs_* () { return C_Handle(); }
  inline operator const CModelRenderPrefs_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CModelRenderPrefs_* mp_handle = nullptr;
};

/*
 *  This instance of render prefs object represents global preferences
 *  used for rendering of all models and their shadows
 */
#define _mrpModelRenderPrefs\
  CModelRenderPrefs(_mrpModelRenderPrefs_(), false)

// texture used for simple model shadows
#define _toSimpleModelShadow\
  CTextureObject(_toSimpleModelShadow_(), false)

// begin/end model rendering to screen
void BeginModelRenderingView(CAnyProjection3D& prProjection, CDrawPort_* pdp);
void EndModelRenderingView(BOOL bRestoreOrtho = TRUE);

// begin/end model rendering to shadow mask
void BeginModelRenderingMask(CAnyProjection3D& prProjection, UBYTE* pubMask, SLONG slMaskWidth, SLONG slMaskHeight);
void EndModelRenderingMask();

class CRenderModel
{
public:
  CRenderModel(CRenderModel_* p, bool owner = false);
  CRenderModel();
  CRenderModel(const CRenderModel& o) = delete;
  ~CRenderModel();
  CRenderModel& operator=(const CRenderModel& o);

  // set placement of the object
  void SetObjectPlacement(const CPlacement3D& pl);
  void SetObjectPlacement(const FLOAT3D& v, const FLOATmatrix3D& m);

  inline CRenderModel_* C_Handle() { return mp_handle; }
  inline const CRenderModel_* C_Handle() const { return mp_handle; }
  inline operator CRenderModel_* () { return C_Handle(); }
  inline operator const CRenderModel_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CRenderModel_* mp_handle = nullptr;

public:
  // placement of the object
  FLOAT3D rm_vObjectPosition;
  FLOATmatrix3D rm_mObjectRotation;
  // flags and blend color global for this rendering
  ULONG& rm_ulFlags;
  COLOR& rm_colBlend;
  FLOAT& rm_fDistanceFactor;           // mip factor not including scaling or biasing
  FLOAT& rm_fMipFactor;                // real mip factor 
  FLOAT3D rm_vLightDirection;         // direction shading light
  COLOR& rm_colLight;                  // color of the shading light
  COLOR& rm_colAmbient;                // color of the ambient
};

#include "RenderModel.inl"
