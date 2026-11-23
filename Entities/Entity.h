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
#include "../Brushes/Brush.h"
#include "../Terrain/Terrain.h"
#include "../Light/LightSource.h"
#include "EntityEvent.h"
#include "EntityClass.h"
#include "ShadingInfo.h"
#include <SeriousEngineCAPI/Entities/Entity.h>

/*
 *  General structure of an entity instance.
 */
class CEntity
{
public:
  CEntity(CEntity_* p, bool dummy = false);
  ~CEntity();
  CEntity(const CEntity& ln) = delete;
  CEntity& operator=(const CEntity& ln) = delete;

  enum RenderType : RenderType_ {
    RT_ILLEGAL = RT_ILLEGAL_,
    RT_NONE = RT_NONE_,                     // not rendered ever -- used internally
    RT_MODEL = RT_MODEL_,                   // drawn as model
    RT_BRUSH = RT_BRUSH_,                   // rendered as brush
    RT_EDITORMODEL = RT_EDITORMODEL_,       // rendered as model, but only in editor
    RT_VOID = RT_VOID_,                     // not rendered ever
    RT_FIELDBRUSH = RT_FIELDBRUSH_,         // brush used for field effects (like triggers, force fields etc.)
    RT_SKAMODEL = RT_SKAMODEL_,             // render as ska model
    RT_SKAEDITORMODEL = RT_SKAEDITORMODEL_, // render as ska model, but only in editor
    RT_TERRAIN = RT_TERRAIN_,               // render as terrain
  };

  // brush -- if brush entity
  CBrush3DPtr en_pbrBrush();
  inline CBrush3DPtr GetBrush() { return en_pbrBrush(); }
  // terrain -- if terrain entity
  CTerrainPtr en_ptrTerrain();
  inline CTerrainPtr GetTerrain() { return en_ptrTerrain(); }
  // shading info -- used for shadow projection
  CShadingInfoPtr en_psiShadingInfo();

  BOOL IsSelected() const;
  void Select();
  void Deselect();

  /* Get pointer to entity property from its name. */
  CEntityPropertyPtr PropertyForName(const CTString& strPropertyName);
  /* Copy one entity property from property of another entity. */
  void CopyOneProperty(CEntityProperty& epPropertySrc, CEntityProperty& epPropertyDest,
    CEntity& enOther, ULONG ulFlags);
  /* Reinitialize the entity. */
  void Reinitialize();
  /* Handle all sent events. */
  static void HandleSentEvents();
  /* Prepare entity (call after setting properties). */
  void Initialize();
  /* Clean-up entity. */
  void End();
  /* Destroy this entity (entity must not be targetable). */
  void Destroy();
  void SetPlacement(const CPlacement3D& plNew);     // use this only in WEd
  void FallDownToFloor();
  inline const CPlacement3D& GetPlacement() const { return en_plPlacement; }
  inline const FLOATmatrix3D& GetRotationMatrix() const { return en_mRotation; }
  /* Find first sector that entity is in */
  CBrushSectorPtr GetFirstSector();
  /* Find first sector that entity is in (for UI purpuses) */
  CBrushSectorPtr GetFirstSectorWithName();
  inline RenderType GetRenderType() { return en_RenderType; }
  void SetFlags(ULONG ulFlags);
  inline ULONG GetFlags() const { return en_ulFlags; }
  void SetSpawnFlags(ULONG ulFlags);
  inline ULONG GetSpawnFlags() const { return en_ulSpawnFlags; }
  void SetPhysicsFlags(ULONG ulFlags);
  inline ULONG GetPhysicsFlags() const { return en_ulPhysicsFlags; }
  void SetCollisionFlags(ULONG ulFlags);
  inline ULONG GetCollisionFlags() const { return en_ulCollisionFlags; }
  inline CEntityClassPtr GetClass() { return en_pecClass; }
  CEntityPtr GetParent();
  void SetParent(CEntity* penNewParent);
  void SetParent(CEntity_* penNewParent);
  /* Test if the entity is an empty brush. */
  BOOL IsEmptyBrush() const;
  /* Get size of this entity - for UI purposes only. */
  void GetSize(FLOATaabbox3D& box);
  /* Get name of this entity. */
  CTString GetName() const;
  CTString GetDescription() const; // name + some more verbose data
  /* Check if entity can be used as a target. */
  BOOL IsTargetable() const;
  /* Check if entity is marker */
  BOOL IsMarker() const;
  /* Check if entity is important */
  BOOL IsImportant() const;
  /* Check if entity is moved on a route set up by its targets. */
  BOOL MovesByTargetedRoute(CTString& strTargetProperty) const;
  /* Check if entity can drop marker for making linked route. */
  BOOL DropsMarker(CTFileName& fnmMarkerClass, CTString& strTargetProperty) const;
  /* Get light source information - return NULL if not a light source. */
  CLightSourcePtr GetLightSource();
  /* Is target valid. */
  BOOL IsTargetValid(SLONG slPropertyOffset, CEntity_* penTarget);
  /* Get force type name, return empty string if not used. */
  CTString GetForceName(INDEX iForce);
  /* Get fog type name, return empty string if not used. */
  CTString GetFogName(INDEX iFog);
  /* Get haze type name, return empty string if not used. */
  CTString GetHazeName(INDEX iHaze);
  /* Get mirror type name, return empty string if not used. */
  CTString GetMirrorName(INDEX iMirror);
  /* Get gradient type name, return empty string if not used. */
  CTString GetGradientName(INDEX iGradient);
  /* Get anim data for given animation property - return NULL for none. */
  CAnimDataPtr GetAnimData(SLONG slPropertyOffset);
  // apply mirror and stretch to the entity if supported
  void MirrorAndStretch(FLOAT fStretch, BOOL bMirrorX);
  /* Send an event to this entity. */
  void SendEvent(const CEntityEvent& ee);
  /* Terrain change notify */
  void TerrainChangeNotify();

  inline CEntity_* C_Handle() { return mp_handle; }
  inline const CEntity_* C_Handle() const { return mp_handle; }
  inline operator CEntity_* () { return C_Handle(); }
  inline operator const CEntity_* () const { return C_Handle(); }
private:
  CEntity_* mp_handle = nullptr;

public:
  CWorld_*& en_pwoWorld;        // the world this entity belongs to
  RenderType& en_RenderType;    // how is it rendered
  ULONG& en_ulPhysicsFlags;     // ways of interacting with environment
  ULONG& en_ulCollisionFlags;   // which entities to collide with
  ULONG& en_ulFlags;            // various flags
  ULONG& en_ulSpawnFlags;       // in what game types is this entity active
  ULONG& en_ulID;               // unique entity identifier
  CPlacement3D en_plPlacement; // placement in world space
  FLOATmatrix3D en_mRotation;       // precalc. matrix for object rotation
  CEntityClassPtr en_pecClass;         // class used to construct this entity
  CListHead en_rdSectors;      // relation to sectors this entity is in
  CListNode en_lnInParent;      // node in the parent entity
  CListHead en_lhChildren;      // list of child entities
};

DECLARE_CDynamicContainer(CEntity)
IMPL_CDynamicContainer(CEntity)
DECLARE_CSelection(CEntity)
IMPL_CSelection(CEntity)

using CEntitySelection = CSelection_CEntity;

#include "Entity.inl"
