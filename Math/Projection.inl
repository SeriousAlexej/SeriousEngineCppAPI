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

inline CProjection3D::CProjection3D(CProjection3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , pr_ObjectPlacement(CProjection3D_pr_ObjectPlacement(mp_handle), false)
  , pr_vObjectHandle(CProjection3D_pr_vObjectHandle(mp_handle), false)
  , pr_ViewerPlacement(CProjection3D_pr_ViewerPlacement(mp_handle), false)
  , pr_vViewerPosition(CProjection3D_pr_vViewerPosition(mp_handle), false)
  , pr_NearClipDistance(*CProjection3D_pr_NearClipDistance(mp_handle))
  , pr_FarClipDistance(*CProjection3D_pr_FarClipDistance(mp_handle))
  , pr_ScreenBBox(CProjection3D_pr_ScreenBBox(mp_handle), false)
  , pr_AspectRatio(*CProjection3D_pr_AspectRatio(mp_handle))
  , pr_ObjectStretch(CProjection3D_pr_ObjectStretch(mp_handle), false)
  , pr_bFaceForward(*CProjection3D_pr_bFaceForward(mp_handle))
  , pr_bHalfFaceForward(*CProjection3D_pr_bHalfFaceForward(mp_handle))
  , pr_bMirror(*CProjection3D_pr_bMirror(mp_handle))
  , pr_bWarp(*CProjection3D_pr_bWarp(mp_handle))
  , pr_plMirror(CProjection3D_pr_plMirror(mp_handle), false)
  , pr_plMirrorView(CProjection3D_pr_plMirrorView(mp_handle), false)
  , pr_fViewStretch(*CProjection3D_pr_fViewStretch(mp_handle))
  , pr_Prepared(*CProjection3D_pr_Prepared(mp_handle))
  , pr_bInverted(*CProjection3D_pr_bInverted(mp_handle))
  , pr_RotationMatrix(CProjection3D_pr_RotationMatrix(mp_handle), false)
  , pr_mDirectionRotation(CProjection3D_pr_mDirectionRotation(mp_handle), false)
  , pr_ViewerRotationMatrix(CProjection3D_pr_ViewerRotationMatrix(mp_handle), false)
  , pr_TranslationVector(CProjection3D_pr_TranslationVector(mp_handle), false)
  , pr_ScreenCenter(CProjection3D_pr_ScreenCenter(mp_handle), false)
  , pr_fDepthBufferFactor(*CProjection3D_pr_fDepthBufferFactor(mp_handle))
  , pr_fDepthBufferMul(*CProjection3D_pr_fDepthBufferMul(mp_handle))
  , pr_fDepthBufferAdd(*CProjection3D_pr_fDepthBufferAdd(mp_handle))
  , pr_fDepthBufferNear(*CProjection3D_pr_fDepthBufferNear(mp_handle))
  , pr_fDepthBufferFar(*CProjection3D_pr_fDepthBufferFar(mp_handle))
  , pr_plClipL(CProjection3D_pr_plClipL(mp_handle), false)
  , pr_plClipR(CProjection3D_pr_plClipR(mp_handle), false)
  , pr_plClipU(CProjection3D_pr_plClipU(mp_handle), false)
  , pr_plClipD(CProjection3D_pr_plClipD(mp_handle), false)
{
}

inline CProjection3D::~CProjection3D()
{
}

inline CPlacement3D& CProjection3D::ObjectPlacementL()
{
  return pr_ObjectPlacement;
}

inline const CPlacement3D& CProjection3D::ObjectPlacementR() const
{
  return pr_ObjectPlacement;
}

inline FLOAT3D& CProjection3D::ObjectHandleL()
{
  return pr_vObjectHandle;
}

inline const FLOAT3D& CProjection3D::ObjectHandleR() const
{
  return pr_vObjectHandle;
}

inline CPlacement3D& CProjection3D::ViewerPlacementL()
{
  return pr_ViewerPlacement;
}

inline const CPlacement3D& CProjection3D::ViewerPlacementR() const
{
  return pr_ViewerPlacement;
}

inline FLOAT& CProjection3D::FrontClipDistanceL()
{
  return pr_NearClipDistance;
}

inline const FLOAT& CProjection3D::FrontClipDistanceR() const
{
  return pr_NearClipDistance;
}

inline FLOAT& CProjection3D::NearClipDistanceL()
{
  return pr_NearClipDistance;
}

inline const FLOAT& CProjection3D::NearClipDistanceR() const
{
  return pr_NearClipDistance;
}

inline FLOAT& CProjection3D::FarClipDistanceL()
{
  return pr_FarClipDistance;
}

inline const FLOAT& CProjection3D::FarClipDistanceR() const
{
  return pr_FarClipDistance;
}

inline FLOATaabbox2D& CProjection3D::ScreenBBoxL()
{
  return pr_ScreenBBox;
}

inline const FLOATaabbox2D& CProjection3D::ScreenBBoxR() const
{
  return pr_ScreenBBox;
}

inline FLOAT& CProjection3D::AspectRatioL()
{
  return pr_AspectRatio;
}

inline const FLOAT& CProjection3D::AspectRatioR() const
{
  return pr_AspectRatio;
}

inline FLOAT3D& CProjection3D::ObjectStretchL()
{
  return pr_ObjectStretch;
}

inline const FLOAT3D& CProjection3D::ObjectStretchR() const
{
  return pr_ObjectStretch;
}

inline FLOATplane3D& CProjection3D::MirrorPlaneL()
{
  pr_bMirror = TRUE;
  return pr_plMirror;
}

inline const FLOATplane3D& CProjection3D::MirrorPlaneR() const
{
  return pr_plMirror;
}

inline void CProjection3D::TurnOffMirrorPlane()
{
  CProjection3D_TurnOffMirrorPlane(mp_handle);
}

inline FLOATplane3D& CProjection3D::WarpPlaneL()
{
  pr_bWarp = TRUE;
  return pr_plMirror;
}

inline const FLOATplane3D& CProjection3D::WarpPlaneR() const
{
  return pr_plMirror;
}

inline void CProjection3D::TurnOffWarpPlane()
{
  CProjection3D_TurnOffWarpPlane(mp_handle);
}

inline BOOL& CProjection3D::ObjectFaceForwardL()
{
  return pr_bFaceForward;
}

inline const BOOL& CProjection3D::ObjectFaceForwardR() const
{
  return pr_bFaceForward;
}

inline BOOL& CProjection3D::ObjectHalfFaceForwardL()
{
  return pr_bHalfFaceForward;
}

inline const BOOL& CProjection3D::ObjectHalfFaceForwardR() const
{
  return pr_bHalfFaceForward;
}

inline FLOAT& CProjection3D::DepthBufferNearL()
{
  return pr_fDepthBufferNear;
}

inline const FLOAT& CProjection3D::DepthBufferNearR() const
{
  return pr_fDepthBufferNear;
}

inline FLOAT& CProjection3D::DepthBufferFarL()
{
  return pr_fDepthBufferFar;
}

inline const FLOAT& CProjection3D::DepthBufferFarR() const
{
  return pr_fDepthBufferFar;
}

inline FLOAT& CProjection3D::ViewStretchL()
{
  return pr_fViewStretch;
}

inline const FLOAT& CProjection3D::ViewStretchR() const
{
  return pr_fViewStretch;
}

inline void CProjection3D::Prepare()
{
  CProjection3D_Prepare(mp_handle);
}

inline BOOL CProjection3D::IsPerspective()
{
  return CProjection3D_IsPerspective(mp_handle);
}

inline void CProjection3D::ProjectCoordinate(const FLOAT3D& v3dObjectPoint, FLOAT3D& v3dViewPoint) const
{
  CProjection3D_ProjectCoordinate(mp_handle, v3dObjectPoint, v3dViewPoint);
}

__forceinline FLOAT3D CProjection3D::ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const
{
  return FLOAT3D(v3dViewPoint);
}

inline FLOAT CProjection3D::GetDistance(const FLOAT3D& v3dObjectPoint) const
{
  return CProjection3D_GetDistance(mp_handle, v3dObjectPoint);
}

inline void CProjection3D::ProjectDirection(const FLOAT3D& v3dObjectPoint, FLOAT3D& v3dViewPoint) const
{
  CProjection3D_ProjectDirection(mp_handle, v3dObjectPoint, v3dViewPoint);
}

inline void CProjection3D::ProjectAABBox(const FLOATaabbox3D& boxObject, FLOATaabbox3D& boxView) const
{
  CProjection3D_ProjectAABBox(mp_handle, boxObject, boxView);
}

inline void CProjection3D::PreClip(const FLOAT3D& v3dObjectPoint, FLOAT3D& v3dTransformedPoint) const
{
  CProjection3D_PreClip(mp_handle, v3dObjectPoint, v3dTransformedPoint);
}

inline ULONG CProjection3D::ClipLine(FLOAT3D& v3dPoint0, FLOAT3D& v3dPoint1) const
{
  return CProjection3D_ClipLine(mp_handle, v3dPoint0, v3dPoint1);
}

inline void CProjection3D::PostClip(const FLOAT3D& v3dTransformedPoint, FLOAT3D& v3dViewPoint) const
{
  CProjection3D_PostClip(mp_handle, v3dTransformedPoint, v3dViewPoint);
}

inline void CProjection3D::PostClip(const FLOAT3D& v3dTransformedPoint, FLOAT fTransformedR, FLOAT3D& v3dViewPoint, FLOAT& fViewR) const
{
  CProjection3D_PostClip_r(mp_handle, v3dTransformedPoint, fTransformedR, v3dViewPoint, &fViewR);
}

inline INDEX CProjection3D::TestSphereToFrustum(const FLOAT3D& vViewPoint, FLOAT fRadius) const
{
  return CProjection3D_TestSphereToFrustum(mp_handle, vViewPoint, fRadius);
}

inline INDEX CProjection3D::TestBoxToFrustum(const FLOATobbox3D& boxView) const
{
  return CProjection3D_TestBoxToFrustum(mp_handle, boxView);
}

inline void CProjection3D::RayThroughPoint(const FLOAT3D& v3dViewPoint, CPlacement3D& plRay) const
{
  CProjection3D_RayThroughPoint(mp_handle, v3dViewPoint, plRay);
}

inline void CProjection3D::Project(const FLOATplane3D& p3dObjectPlane, FLOATplane3D& v3dTransformedPlane) const
{
  CProjection3D_Project(mp_handle, p3dObjectPlane, v3dTransformedPlane);
}

inline BOOL CProjection3D::IsObjectPlaneVisible(const FLOATplane3D& p3dObjectPlane) const
{
  return CProjection3D_IsObjectPlaneVisible(mp_handle, p3dObjectPlane);
}

inline BOOL CProjection3D::IsViewerPlaneVisible(const FLOATplane3D& p3dViewerPlane) const
{
  return CProjection3D_IsViewerPlaneVisible(mp_handle, p3dViewerPlane);
}

inline FLOAT CProjection3D::MipFactor(FLOAT fDistance) const
{
  return CProjection3D_MipFactor_d(mp_handle, fDistance);
}

inline FLOAT CProjection3D::MipFactor() const
{
  return CProjection3D_MipFactor(mp_handle);
}

inline void CProjection3D::MakeOoKGradient(const FLOATplane3D& plViewerPlane, CPlanarGradients& pgOoK) const
{
  CProjection3D_MakeOoKGradient(mp_handle, plViewerPlane, pgOoK);
}

inline CPerspectiveProjection3D::CPerspectiveProjection3D(CPerspectiveProjection3D_* p, bool owner)
  : CProjection3D((CProjection3D_*)p, owner)
  , ppr_FOVWidth(*CPerspectiveProjection3D_ppr_FOVWidth(C_Handle()))
  , ppr_fMipRatio(*CPerspectiveProjection3D_ppr_fMipRatio(C_Handle()))
  , ppr_PerspectiveRatios(CPerspectiveProjection3D_ppr_PerspectiveRatios(C_Handle()), false)
  , ppr_fMetersPerPixel(*CPerspectiveProjection3D_ppr_fMetersPerPixel(C_Handle()))
  , ppr_fViewerDistance(*CPerspectiveProjection3D_ppr_fViewerDistance(C_Handle()))
  , ppr_boxSubScreen(CPerspectiveProjection3D_ppr_boxSubScreen(C_Handle()), false)
{
}

inline CPerspectiveProjection3D::CPerspectiveProjection3D()
  : CPerspectiveProjection3D(CPerspectiveProjection3D_new(), true)
{
}

inline CPerspectiveProjection3D::CPerspectiveProjection3D(const CPerspectiveProjection3D& o)
  : CPerspectiveProjection3D(CPerspectiveProjection3D_clone(o), true)
{
}

inline CPerspectiveProjection3D::~CPerspectiveProjection3D()
{
  if (m_owner)
    CPerspectiveProjection3D_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline CPerspectiveProjection3D& CPerspectiveProjection3D::operator=(const CPerspectiveProjection3D& o)
{
  CPerspectiveProjection3D_copy(C_Handle(), o);
  return *this;
}

inline ANGLE& CPerspectiveProjection3D::FOVL()
{
  return ppr_FOVWidth;
}

inline const ANGLE& CPerspectiveProjection3D::FOVR() const
{
  return ppr_FOVWidth;
}

__forceinline FLOAT3D CPerspectiveProjection3D::ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const
{
  FLOAT3D v3dObjectPoint = v3dViewPoint;
  v3dObjectPoint(1) = (v3dObjectPoint(1) - pr_ScreenCenter(1)) / ppr_PerspectiveRatios(1) * v3dObjectPoint(3);
  v3dObjectPoint(2) = (v3dObjectPoint(2) - pr_ScreenCenter(2)) / ppr_PerspectiveRatios(2) * v3dObjectPoint(3);
  return (v3dObjectPoint - pr_TranslationVector) * (!pr_RotationMatrix);
}

inline CIsometricProjection3D::CIsometricProjection3D(CIsometricProjection3D_* p, bool owner)
  : CProjection3D((CProjection3D_*)p, owner)
  , ipr_ZoomFactor(*CIsometricProjection3D_ipr_ZoomFactor(C_Handle()))
{
}

inline CIsometricProjection3D::CIsometricProjection3D()
  : CIsometricProjection3D(CIsometricProjection3D_new(), true)
{
}

inline CIsometricProjection3D::CIsometricProjection3D(const CIsometricProjection3D& o)
  : CIsometricProjection3D(CIsometricProjection3D_clone(o), true)
{
}

inline CIsometricProjection3D::~CIsometricProjection3D()
{
  if (m_owner)
    CIsometricProjection3D_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline CIsometricProjection3D& CIsometricProjection3D::operator=(const CIsometricProjection3D& o)
{
  CIsometricProjection3D_copy(C_Handle(), o);
  return *this;
}

inline FLOAT& CIsometricProjection3D::ZoomFactorL()
{
  return ipr_ZoomFactor;
}

inline const FLOAT& CIsometricProjection3D::ZoomFactorR() const
{
  return ipr_ZoomFactor;
}

__forceinline FLOAT3D CIsometricProjection3D::ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const
{
  FLOAT3D v3dObjectPoint = v3dViewPoint;
  v3dObjectPoint(1) = (v3dObjectPoint(1) - pr_ScreenCenter(1)) / ipr_ZoomFactor / pr_fViewStretch;
  v3dObjectPoint(2) = (v3dObjectPoint(2) - pr_ScreenCenter(2)) / ipr_ZoomFactor / pr_fViewStretch;
  return (v3dObjectPoint - pr_TranslationVector) * (!pr_RotationMatrix);
}

inline CParallelProjection3D::CParallelProjection3D(CParallelProjection3D_* p, bool owner)
  : CProjection3D((CProjection3D_*)p, owner)
  , pr_vStepFactors(CParallelProjection3D_pr_vStepFactors(C_Handle()), false)
  , pr_vZoomFactors(CParallelProjection3D_pr_vZoomFactors(C_Handle()), false)
  , pr_vViewDirection(CParallelProjection3D_pr_vViewDirection(C_Handle()), false)
{
}

inline CParallelProjection3D::CParallelProjection3D()
  : CParallelProjection3D(CParallelProjection3D_new(), true)
{
}

inline CParallelProjection3D::CParallelProjection3D(const CParallelProjection3D& o)
  : CParallelProjection3D(CParallelProjection3D_clone(o), true)
{
}

inline CParallelProjection3D::~CParallelProjection3D()
{
  if (m_owner)
    CParallelProjection3D_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline CParallelProjection3D& CParallelProjection3D::operator=(const CParallelProjection3D& o)
{
  CParallelProjection3D_copy(C_Handle(), o);
  return *this;
}

__forceinline FLOAT3D CParallelProjection3D::ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const
{
  FLOAT3D v3dObjectPoint = v3dViewPoint;
  v3dObjectPoint(1) = (v3dObjectPoint(1) - pr_ScreenCenter(1) - v3dObjectPoint(3) * pr_vStepFactors(1)) / pr_vZoomFactors(1);
  v3dObjectPoint(2) = (v3dObjectPoint(2) - pr_ScreenCenter(2) - v3dObjectPoint(3) * pr_vStepFactors(2)) / pr_vZoomFactors(2);
  return (v3dObjectPoint - pr_TranslationVector) * (!pr_RotationMatrix);
}

inline CSimpleProjection3D::CSimpleProjection3D(CSimpleProjection3D_* p, bool owner)
  : CProjection3D((CProjection3D_*)p, owner)
{
}

inline CSimpleProjection3D::CSimpleProjection3D()
  : CSimpleProjection3D(CSimpleProjection3D_new(), true)
{
}

inline CSimpleProjection3D::CSimpleProjection3D(const CSimpleProjection3D& o)
  : CSimpleProjection3D(CSimpleProjection3D_clone(o), true)
{
}

inline CSimpleProjection3D::~CSimpleProjection3D()
{
  if (m_owner)
    CSimpleProjection3D_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline CSimpleProjection3D& CSimpleProjection3D::operator=(const CSimpleProjection3D& o)
{
  CSimpleProjection3D_copy(C_Handle(), o);
  return *this;
}

__forceinline FLOAT3D CSimpleProjection3D::ProjectCoordinateReverse(const FLOAT3D& v3dViewPoint) const
{
  return (v3dViewPoint - pr_TranslationVector) * (!pr_RotationMatrix);
}

inline CAnyProjection3D::CAnyProjection3D(CAnyProjection3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CAnyProjection3D::CAnyProjection3D()
  : m_owner(true)
  , mp_handle(CAnyProjection3D_new())
{
}

inline CAnyProjection3D::CAnyProjection3D(const CAnyProjection3D& o)
  : m_owner(true)
  , mp_handle(CAnyProjection3D_clone(o))
{
}

inline CAnyProjection3D::~CAnyProjection3D()
{
  if (m_owner)
    CAnyProjection3D_delete(mp_handle);
}

inline CAnyProjection3D& CAnyProjection3D::operator=(const CAnyProjection3D& o)
{
  CAnyProjection3D_copy(mp_handle, o);
  return *this;
}

inline void CAnyProjection3D::BeSimple()
{
  CAnyProjection3D_BeSimple(mp_handle);
}

inline BOOL CAnyProjection3D::IsSimple()
{
  return CAnyProjection3D_IsSimple(mp_handle);
}

inline void CAnyProjection3D::BeIsometric()
{
  CAnyProjection3D_BeIsometric(mp_handle);
}

inline BOOL CAnyProjection3D::IsIsometric()
{
  return CAnyProjection3D_IsIsometric(mp_handle);
}

inline void CAnyProjection3D::BePerspective()
{
  CAnyProjection3D_BePerspective(mp_handle);
}

inline BOOL CAnyProjection3D::IsPerspective()
{
  return CAnyProjection3D_IsPerspective(mp_handle);
}

inline void CAnyProjection3D::BeParallel()
{
  CAnyProjection3D_BeParallel(mp_handle);
}

inline BOOL CAnyProjection3D::IsParallel()
{
  return CAnyProjection3D_IsParallel(mp_handle);
}

inline CProjection3D* CAnyProjection3D::operator->()
{
  if (IsPerspective())
    mp_proj.reset(new CPerspectiveProjection3D((CPerspectiveProjection3D_*)CAnyProjection3D_GetActive(mp_handle), false));
  else if (IsIsometric())
    mp_proj.reset(new CIsometricProjection3D((CIsometricProjection3D_*)CAnyProjection3D_GetActive(mp_handle), false));
  else if (IsParallel())
    mp_proj.reset(new CParallelProjection3D((CParallelProjection3D_*)CAnyProjection3D_GetActive(mp_handle), false));
  else if (IsSimple())
    mp_proj.reset(new CSimpleProjection3D((CSimpleProjection3D_*)CAnyProjection3D_GetActive(mp_handle), false));
  else
    mp_proj.reset();
  return mp_proj.get();
}

inline CAnyProjection3D::operator CProjection3D* ()
{
  if (IsPerspective())
    mp_proj.reset(new CPerspectiveProjection3D((CPerspectiveProjection3D_*)CAnyProjection3D_GetActive(mp_handle), false));
  else if (IsIsometric())
    mp_proj.reset(new CIsometricProjection3D((CIsometricProjection3D_*)CAnyProjection3D_GetActive(mp_handle), false));
  else if (IsParallel())
    mp_proj.reset(new CParallelProjection3D((CParallelProjection3D_*)CAnyProjection3D_GetActive(mp_handle), false));
  else if (IsSimple())
    mp_proj.reset(new CSimpleProjection3D((CSimpleProjection3D_*)CAnyProjection3D_GetActive(mp_handle), false));
  else
    mp_proj.reset();
  return mp_proj.get();
}

inline void CAnyProjection3D::operator=(const CSimpleProjection3D& prSimple)
{
  CAnyProjection3D_SetSimple(mp_handle, prSimple);
}

inline void CAnyProjection3D::operator=(const CIsometricProjection3D& prIsometric)
{
  CAnyProjection3D_SetIsometric(mp_handle, prIsometric);
}

inline void CAnyProjection3D::operator=(const CPerspectiveProjection3D& prPerspective)
{
  CAnyProjection3D_SetPerspective(mp_handle, prPerspective);
}

inline void CAnyProjection3D::operator=(const CParallelProjection3D& prParallel)
{
  CAnyProjection3D_SetParallel(mp_handle, prParallel);
}
