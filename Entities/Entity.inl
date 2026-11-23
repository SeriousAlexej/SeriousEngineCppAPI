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

inline CEntity::CEntity(CEntity_* p, bool)
  : mp_handle(p)
  , en_pwoWorld(*CEntity_en_pwoWorld(p))
  , en_RenderType(*((RenderType*)CEntity_en_RenderType(p)))
  , en_ulPhysicsFlags(*CEntity_en_ulPhysicsFlags(p))
  , en_ulCollisionFlags(*CEntity_en_ulCollisionFlags(p))
  , en_ulFlags(*CEntity_en_ulFlags(p))
  , en_ulSpawnFlags(*CEntity_en_ulSpawnFlags(p))
  , en_ulID(*CEntity_en_ulID(p))
  , en_plPlacement(CEntity_en_plPlacement(p), false)
  , en_mRotation(CEntity_en_mRotation(p), false)
  , en_pecClass(*CEntity_en_pecClass(p))
  , en_rdSectors(CEntity_en_rdSectors(p), false)
  , en_lnInParent(CEntity_en_lnInParent(p), false)
  , en_lhChildren(CEntity_en_lhChildren(p), false)
{
}

inline CEntity::~CEntity()
{
}

__forceinline CBrush3DPtr CEntity::en_pbrBrush()
{
  return *CEntity_en_pbrBrush(C_Handle());
}

__forceinline CTerrainPtr CEntity::en_ptrTerrain()
{
  return *CEntity_en_ptrTerrain(C_Handle());
}

__forceinline CShadingInfoPtr CEntity::en_psiShadingInfo()
{
  return *CEntity_en_psiShadingInfo(C_Handle());
}

inline BOOL CEntity::IsSelected() const
{
  return CEntity_IsSelected(C_Handle());
}

inline void CEntity::Select()
{
  CEntity_Select(C_Handle());
}

inline void CEntity::Deselect()
{
  CEntity_Deselect(C_Handle());
}

__forceinline CEntityPropertyPtr CEntity::PropertyForName(const CTString& strPropertyName)
{
  return CEntity_PropertyForName(C_Handle(), strPropertyName);
}

inline void CEntity::CopyOneProperty(CEntityProperty& epPropertySrc, CEntityProperty& epPropertyDest, CEntity& enOther, ULONG ulFlags)
{
  CEntity_CopyOneProperty(C_Handle(), epPropertySrc, epPropertyDest, enOther, ulFlags);
}

inline void CEntity::Reinitialize()
{
  CEntity_Reinitialize(C_Handle());
  SECppAPI_CheckException();
}

inline void CEntity::HandleSentEvents()
{
  CEntity_HandleSentEvents();
  SECppAPI_CheckException();
}

inline void CEntity::Initialize()
{
  CEntity_Initialize(C_Handle());
  SECppAPI_CheckException();
}

inline void CEntity::End()
{
  CEntity_End(C_Handle());
  SECppAPI_CheckException();
}

inline void CEntity::Destroy()
{
  CEntity_Destroy(C_Handle());
  SECppAPI_CheckException();
}

inline void CEntity::SetPlacement(const CPlacement3D& plNew)
{
  CEntity_SetPlacement(C_Handle(), plNew);
}

inline void CEntity::FallDownToFloor()
{
  CEntity_FallDownToFloor(C_Handle());
}

__forceinline CBrushSectorPtr CEntity::GetFirstSector()
{
  return CEntity_GetFirstSector(C_Handle());
}

__forceinline CBrushSectorPtr CEntity::GetFirstSectorWithName()
{
  return CEntity_GetFirstSectorWithName(C_Handle());
}

inline void CEntity::SetFlags(ULONG ulFlags)
{
  CEntity_SetFlags(C_Handle(), ulFlags);
}

inline void CEntity::SetSpawnFlags(ULONG ulFlags)
{
  CEntity_SetSpawnFlags(C_Handle(), ulFlags);
}

inline void CEntity::SetPhysicsFlags(ULONG ulFlags)
{
  CEntity_SetPhysicsFlags(C_Handle(), ulFlags);
}

inline void CEntity::SetCollisionFlags(ULONG ulFlags)
{
  CEntity_SetCollisionFlags(C_Handle(), ulFlags);
}

__forceinline CEntityPtr CEntity::GetParent()
{
  return *CEntity_en_penParent(C_Handle());
}

inline void CEntity::SetParent(CEntity* penNewParent)
{
  CEntity_SetParent(C_Handle(), penNewParent ? penNewParent->C_Handle() : nullptr);
}

inline void CEntity::SetParent(CEntity_* penNewParent)
{
  CEntity_SetParent(C_Handle(), penNewParent);
}

inline BOOL CEntity::IsEmptyBrush() const
{
  return CEntity_IsEmptyBrush(C_Handle());
}

inline void CEntity::GetSize(FLOATaabbox3D& box)
{
  CEntity_GetSize(C_Handle(), box);
}

inline CTString CEntity::GetName() const
{
  return CTString(CEntity_GetName(C_Handle()), true);
}

inline CTString CEntity::GetDescription() const
{
  return CTString(CEntity_GetDescription(C_Handle()), true);
}

inline BOOL CEntity::IsTargetable() const
{
  return CEntity_IsTargetable(C_Handle());
}

inline BOOL CEntity::IsMarker() const
{
  return CEntity_IsMarker(C_Handle());
}

inline BOOL CEntity::IsImportant() const
{
  return CEntity_IsImportant(C_Handle());
}

inline BOOL CEntity::MovesByTargetedRoute(CTString& strTargetProperty) const
{
  return CEntity_MovesByTargetedRoute(C_Handle(), strTargetProperty);
}

inline BOOL CEntity::DropsMarker(CTFileName& fnmMarkerClass, CTString& strTargetProperty) const
{
  return CEntity_DropsMarker(C_Handle(), fnmMarkerClass, strTargetProperty);
}

__forceinline CLightSourcePtr CEntity::GetLightSource()
{
  return CEntity_GetLightSource(C_Handle());
}

inline BOOL CEntity::IsTargetValid(SLONG slPropertyOffset, CEntity_* penTarget)
{
  return CEntity_IsTargetValid(C_Handle(), slPropertyOffset, penTarget);
}

inline CTString CEntity::GetForceName(INDEX iForce)
{
  return CTString(CEntity_GetForceName(C_Handle(), iForce), true);
}

inline CTString CEntity::GetFogName(INDEX iFog)
{
  return CTString(CEntity_GetFogName(C_Handle(), iFog), true);
}

inline CTString CEntity::GetHazeName(INDEX iHaze)
{
  return CTString(CEntity_GetHazeName(C_Handle(), iHaze), true);
}

inline CTString CEntity::GetMirrorName(INDEX iMirror)
{
  return CTString(CEntity_GetMirrorName(C_Handle(), iMirror), true);
}

inline CTString CEntity::GetGradientName(INDEX iGradient)
{
  return CTString(CEntity_GetGradientName(C_Handle(), iGradient), true);
}

__forceinline CAnimDataPtr CEntity::GetAnimData(SLONG slPropertyOffset)
{
  return CEntity_GetAnimData(C_Handle(), slPropertyOffset);
}

inline void CEntity::MirrorAndStretch(FLOAT fStretch, BOOL bMirrorX)
{
  CEntity_MirrorAndStretch(C_Handle(), fStretch, bMirrorX);
}

inline void CEntity::SendEvent(const CEntityEvent& ee)
{
  CEntity_SendEvent(C_Handle(), ee);
}

inline void CEntity::TerrainChangeNotify()
{
  CEntity_TerrainChangeNotify(C_Handle());
}
