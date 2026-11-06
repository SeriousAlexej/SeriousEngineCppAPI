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
#include "Vector.h"
#include "Matrix.h"
#include "Plane.h"
#include "AABBox.h"
#include "OBBox.h"
#include "Placement.h"
#include "TextureMapping.h"
#include <SeriousEngineCAPI/Math/Projection.h>
#include <memory>

/*
 * Geometric projection of one 3D space onto another 3D space
 */
class CProjection3D
{
public:
  CProjection3D(CProjection3D_* p, bool owner = false);
  virtual ~CProjection3D();

  // member referencing
  /* Reference object placement. */
  CPlacement3D& ObjectPlacementL();
  const CPlacement3D& ObjectPlacementR() const;
  /* Reference object handle. */
  FLOAT3D& ObjectHandleL();
  const FLOAT3D& ObjectHandleR() const;
  /* Reference viewer placement. */
  CPlacement3D& ViewerPlacementL();
  const CPlacement3D& ViewerPlacementR() const;
  /* Reference clipping distances. */
  FLOAT& FrontClipDistanceL();
  const FLOAT& FrontClipDistanceR() const;
  FLOAT& NearClipDistanceL();
  const FLOAT& NearClipDistanceR() const;
  FLOAT& FarClipDistanceL();
  const FLOAT& FarClipDistanceR() const;
  /* Reference screen bounding box. */
  FLOATaabbox2D& ScreenBBoxL();
  const FLOATaabbox2D& ScreenBBoxR() const;
  /* Reference screen aspect ratio. */
  FLOAT& AspectRatioL();
  const FLOAT& AspectRatioR() const;
  /* Reference target object stretching. */
  FLOAT3D& ObjectStretchL();
  const FLOAT3D& ObjectStretchR() const;
  /* Reference miror plane. */
  FLOATplane3D& MirrorPlaneL();
  const FLOATplane3D& MirrorPlaneR() const;
  void TurnOffMirrorPlane();
  /* Reference warp plane. */
  FLOATplane3D& WarpPlaneL();
  const FLOATplane3D& WarpPlaneR() const;
  void TurnOffWarpPlane();
  /* Reference target object face-forward flag. */
  BOOL& ObjectFaceForwardL();
  const BOOL& ObjectFaceForwardR() const;
  BOOL& ObjectHalfFaceForwardL();
  const BOOL& ObjectHalfFaceForwardR() const;
  /* Reference corrections for depth buffer factor. */
  FLOAT& DepthBufferNearL();
  const FLOAT& DepthBufferNearR() const;
  FLOAT& DepthBufferFarL();
  const FLOAT& DepthBufferFarR() const;
  /* Reference view stretching. */
  FLOAT& ViewStretchL();
  const FLOAT& ViewStretchR() const;

  /* Prepare for projecting. */
  void Prepare();
  BOOL IsPerspective();

  /* Project 3D object point into 3D view space. */
  void ProjectCoordinate(const FLOAT3D& v3dObjectPoint, FLOAT3D& v3dViewPoint) const;
  /* Reverse project 3D view point into 3D object space */
  virtual FLOAT3D ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const;
  /* Get a distance of object point from the viewer. */
  FLOAT GetDistance(const FLOAT3D& v3dObjectPoint) const;
  /* Project 3D object direction vector into 3D view space. */
  void ProjectDirection(const FLOAT3D& v3dObjectPoint, FLOAT3D& v3dViewPoint) const;
  /* Project 3D object axis aligned bounding box into 3D view space. */
  void ProjectAABBox(const FLOATaabbox3D& boxObject, FLOATaabbox3D& boxView) const;
  /* Project 3D object point into 3D view space, before clipping. */
  void PreClip(const FLOAT3D& v3dObjectPoint, FLOAT3D& v3dTransformedPoint) const;
  /* Clip a line. */
  ULONG ClipLine(FLOAT3D& v3dPoint0, FLOAT3D& v3dPoint1) const;
  /* Project 3D object point into 3D view space, after clipping. */
  void PostClip(const FLOAT3D& v3dTransformedPoint, FLOAT3D& v3dViewPoint) const;
  void PostClip(const FLOAT3D& v3dTransformedPoint, FLOAT fTransformedR,
    FLOAT3D& v3dViewPoint, FLOAT& fViewR) const;
  /* Test if a sphere in view space is inside view frustum. */
  INDEX TestSphereToFrustum(const FLOAT3D& vViewPoint, FLOAT fRadius) const;
  /* Test if an oriented box in view space is inside view frustum. */
  INDEX TestBoxToFrustum(const FLOATobbox3D& boxView) const;

  /* Get placement for a ray through a projected point. */
  void RayThroughPoint(const FLOAT3D& v3dViewPoint, CPlacement3D& plRay) const;

  /* Project 3D object plane into 3D view space. */
  void Project(const FLOATplane3D& p3dObjectPlane, FLOATplane3D& v3dTransformedPlane) const;
  /* Check if an object-space plane is visible. */
  BOOL IsObjectPlaneVisible(const FLOATplane3D& p3dObjectPlane) const;
  /* Check if a viewer-space plane is visible. */
  BOOL IsViewerPlaneVisible(const FLOATplane3D& p3dViewerPlane) const;

  /* Calculate a mip-factor for a given object. */
  // by its distance from viewer
  FLOAT MipFactor(FLOAT fDistance) const;
  // general mip-factor for target object
  FLOAT MipFactor() const;

  /* Calculate plane gradient for a plane in 3D view space. */
  void MakeOoKGradient(const FLOATplane3D& plViewerPlane, CPlanarGradients& pgOoK) const;

  inline CProjection3D_* C_Handle() { return mp_handle; }
  inline const CProjection3D_* C_Handle() const { return mp_handle; }
  inline operator CProjection3D_* () { return C_Handle(); }
  inline operator const CProjection3D_* () const { return C_Handle(); }

protected:
  friend class CAnyProjection3D;
  bool m_owner = true;
  CProjection3D_* mp_handle = nullptr;

public:
  CPlacement3D pr_ObjectPlacement;  // placement of the projected object in absolute space
  FLOAT3D pr_vObjectHandle;         // handle the projected object in its own space
  CPlacement3D pr_ViewerPlacement;  // placement of the viewer in absolute space
  FLOAT3D pr_vViewerPosition;       // viewer position (possibly mirrored)
  FLOAT& pr_NearClipDistance;        // distance of near clipping plane from viewer
  FLOAT& pr_FarClipDistance;         // distance of far clipping plane from viewer
  FLOATaabbox2D pr_ScreenBBox;      // bounding box of viewing screen
  FLOAT& pr_AspectRatio;             // aspect ratio of viewing screen
  FLOAT3D pr_ObjectStretch;         // stretching coeficients for target object space
  BOOL& pr_bFaceForward;             // set if object is face-forward
  BOOL& pr_bHalfFaceForward;         // set if object is face-forward, but only on heading
  BOOL& pr_bMirror;                  // enable mirror projection
  BOOL& pr_bWarp;                    // enable warp clip
  FLOATplane3D pr_plMirror;         // plane to mirror(warp) about
  FLOATplane3D pr_plMirrorView;     // mirror(warp) clip plane in view space
  FLOAT& pr_fViewStretch;            // stretch of entire view

  // internal variables
  BOOL& pr_Prepared;                 // set if all precalculated variables are prepared
  BOOL& pr_bInverted;                // set if projection is inverted
  FLOATmatrix3D pr_RotationMatrix;  // matrix for rotating when projecting
  FLOATmatrix3D pr_mDirectionRotation;  // matrix for rotating direction vectors
  FLOATmatrix3D pr_ViewerRotationMatrix;  // viewer part of rotation matrix
  FLOAT3D pr_TranslationVector;     // vector for translating when projecting
  FLOAT2D pr_ScreenCenter;          // center of viewing screen

  FLOAT& pr_fDepthBufferFactor;  // correction to 0..1
  FLOAT& pr_fDepthBufferMul;     // correction to needed range
  FLOAT& pr_fDepthBufferAdd;
  FLOAT& pr_fDepthBufferNear;  // depth buffer range used
  FLOAT& pr_fDepthBufferFar;

  // clip planes (in view space)
  FLOATplane3D pr_plClipL;
  FLOATplane3D pr_plClipR;
  FLOATplane3D pr_plClipU;
  FLOATplane3D pr_plClipD;
};

/*
 * Perspective projection.
 */
class CPerspectiveProjection3D : public CProjection3D
{
public:
  CPerspectiveProjection3D(CPerspectiveProjection3D_* p, bool owner = false);
  CPerspectiveProjection3D();
  CPerspectiveProjection3D(const CPerspectiveProjection3D& o);
  ~CPerspectiveProjection3D();
  CPerspectiveProjection3D& operator=(const CPerspectiveProjection3D& o);

  // member referencing
  /* Reference field of view. */
  ANGLE& FOVL();
  const ANGLE& FOVR() const;

  /* Reverse project 3D view point into 3D object space */
  FLOAT3D ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const final;

  inline CPerspectiveProjection3D_* C_Handle() { return (CPerspectiveProjection3D_*)mp_handle; }
  inline const CPerspectiveProjection3D_* C_Handle() const { return (const CPerspectiveProjection3D_*)mp_handle; }
  inline operator CPerspectiveProjection3D_* () { return C_Handle(); }
  inline operator const CPerspectiveProjection3D_* () const { return C_Handle(); }

public:
  ANGLE& ppr_FOVWidth;                // width of field-of-view
  FLOAT& ppr_fMipRatio;               // for mip-factor calculation

  // internal variables
  FLOAT2D ppr_PerspectiveRatios;     // ratios for perspective projection

  // factors for shadow casting projections
  FLOAT& ppr_fMetersPerPixel;    // meters per pixel on destination plane
  FLOAT& ppr_fViewerDistance;    // distance between viewer and destination plane
  FLOATaabbox2D ppr_boxSubScreen;      // box-in-box for rendering on subdrawports
};

/*
 * Isometric projection.
 */
class CIsometricProjection3D : public CProjection3D
{
public:
  CIsometricProjection3D(CIsometricProjection3D_* p, bool owner = false);
  CIsometricProjection3D();
  CIsometricProjection3D(const CIsometricProjection3D& o);
  ~CIsometricProjection3D();
  CIsometricProjection3D& operator=(const CIsometricProjection3D& o);

  /* Reference zoom factor. */
  FLOAT& ZoomFactorL();
  const FLOAT& ZoomFactorR() const;

  /* Reverse project 3D view point into 3D object space */
  FLOAT3D ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const final;

  inline CIsometricProjection3D_* C_Handle() { return (CIsometricProjection3D_*)mp_handle; }
  inline const CIsometricProjection3D_* C_Handle() const { return (const CIsometricProjection3D_*)mp_handle; }
  inline operator CIsometricProjection3D_* () { return C_Handle(); }
  inline operator const CIsometricProjection3D_* () const { return C_Handle(); }

public:
  FLOAT& ipr_ZoomFactor;              // zoom factor
};

/*
 * Parallel projection.
 */
class CParallelProjection3D : public CProjection3D
{
public:
  CParallelProjection3D(CParallelProjection3D_* p, bool owner = false);
  CParallelProjection3D();
  CParallelProjection3D(const CParallelProjection3D& o);
  ~CParallelProjection3D();
  CParallelProjection3D& operator=(const CParallelProjection3D& o);

  /* Reverse project 3D view point into 3D object space */
  FLOAT3D ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const final;

  inline CParallelProjection3D_* C_Handle() { return (CParallelProjection3D_*)mp_handle; }
  inline const CParallelProjection3D_* C_Handle() const { return (const CParallelProjection3D_*)mp_handle; }
  inline operator CParallelProjection3D_* () { return C_Handle(); }
  inline operator const CParallelProjection3D_* () const { return C_Handle(); }

public:
  FLOAT2D pr_vStepFactors;    // gradient of x and y along z (angle of parallel projection)
  FLOAT2D pr_vZoomFactors;    // zoom of x and y

  // internal variables
  FLOAT3D pr_vViewDirection;  // heads in the direction of viewing
};

/*
 * Simple projection.
 */
class CSimpleProjection3D : public CProjection3D
{
public:
  CSimpleProjection3D(CSimpleProjection3D_* p, bool owner = false);
  CSimpleProjection3D();
  CSimpleProjection3D(const CSimpleProjection3D& o);
  ~CSimpleProjection3D();
  CSimpleProjection3D& operator=(const CSimpleProjection3D& o);

  /* Reverse project 3D view point into 3D object space */
  FLOAT3D ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const final;

  inline CSimpleProjection3D_* C_Handle() { return (CSimpleProjection3D_*)mp_handle; }
  inline const CSimpleProjection3D_* C_Handle() const { return (const CSimpleProjection3D_*)mp_handle; }
  inline operator CSimpleProjection3D_* () { return C_Handle(); }
  inline operator const CSimpleProjection3D_* () const { return C_Handle(); }
};

/*
 * Holder for any kind of 3D projection.
 */
class CAnyProjection3D
{
public:
  CAnyProjection3D(CAnyProjection3D_* p, bool owner = false);
  CAnyProjection3D();
  CAnyProjection3D(const CAnyProjection3D& o);
  ~CAnyProjection3D();
  CAnyProjection3D& operator=(const CAnyProjection3D& o);

  /* Start beeing CSimpleProjection3D. */
  void BeSimple();
  /* Test if CSimpleProjection3D. */
  BOOL IsSimple();
  /* Start beeing CIsometricProjection3D. */
  void BeIsometric();
  /* Test if CIsometricProjection3D. */
  BOOL IsIsometric();
  /* Start beeing CPerspectiveProjection3D. */
  void BePerspective();
  /* Test if CPerspectiveProjection3D. */
  BOOL IsPerspective();
  /* Start beeing CParallelProjection3D. */
  void BeParallel();
  /* Test if CParallelProjection3D. */
  BOOL IsParallel();
  /* Reference currently active projection. */
  CProjection3D* operator->();
  /* Get the pointer to currently active projection. */
  operator CProjection3D* ();

  /* Initialize from a simple projection. */
  void operator=(const CSimpleProjection3D& prSimple);
  /* Initialize from an isometric projection. */
  void operator=(const CIsometricProjection3D& prIsometric);
  /* Initialize from a perspective projection. */
  void operator=(const CPerspectiveProjection3D& prPerspective);
  /* Initialize from a parallel projection. */
  void operator=(const CParallelProjection3D& prParallel);

  inline CAnyProjection3D_* C_Handle() { return mp_handle; }
  inline const CAnyProjection3D_* C_Handle() const { return mp_handle; }
  inline operator CAnyProjection3D_* () { return C_Handle(); }
  inline operator const CAnyProjection3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CAnyProjection3D_* mp_handle = nullptr;
  std::unique_ptr<CProjection3D> mp_proj;
};

#include "Projection.inl"
