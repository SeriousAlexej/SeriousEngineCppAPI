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
#include "StaticStackArray.h"
#include <SeriousEngineCAPI/Templates/DynamicContainer.h>

#define DECLARE_CDynamicContainer(TYPE)\
  class CDynamicContainer_##TYPE\
  {\
    public:\
      CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_* p, bool owner = false);\
      CDynamicContainer_##TYPE();\
      CDynamicContainer_##TYPE(CDynamicContainer_##TYPE& o);\
      ~CDynamicContainer_##TYPE();\
      \
      CDynamicContainer_##TYPE& operator=(CDynamicContainer_##TYPE& o);\
      \
      /* Get index of an object from it's pointer. */\
      INDEX GetIndex(TYPE##_* ptMember);\
      /* Add a given object to container. */\
      void Add(TYPE##_* ptNewObject);\
      /* Remove a given object from container. */\
      void Remove(TYPE##_* ptOldObject);\
      /* Remove all objects, and reset the container to initial (empty) state. */\
      void Clear();\
      /* Test if a given object is in the container. */\
      BOOL IsMember(TYPE##_* ptOldObject);\
      \
      /* Get pointer to a object from it's index. */\
      TYPE##Ptr Pointer(INDEX iObject);\
      const TYPE##Ptr Pointer(INDEX iObject) const;\
      /* Random access operator. */\
      TYPE##Ptr operator[](INDEX iObject);\
      const TYPE##Ptr operator[](INDEX iObject) const;\
      /* Move all elements of another container into this one. */\
      void MoveContainer(CDynamicContainer_##TYPE& coOther);\
      INDEX Count() const;\
      \
      /* Get first object in container (there must be at least one when calling this). */\
      TYPE##Ptr GetFirst();\
      \
      inline CDynamicContainer_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CDynamicContainer_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CDynamicContainer_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicContainer_##TYPE##_* () const { return C_Handle(); }\
    protected:\
      bool m_owner = true;\
      CDynamicContainer_##TYPE##_* mp_array = nullptr;\
  };\
  class CDynamicContainerIterator_##TYPE {\
  private:\
    INDEX dci_Index;\
    CDynamicContainer_##TYPE& dci_Array;\
    TYPE##Ptr p_cur;\
  public:\
    inline CDynamicContainerIterator_##TYPE(CDynamicContainer_##TYPE& da) : dci_Array(da) { dci_Index = 0; if(!IsPastEnd()) p_cur = dci_Array.Pointer(dci_Index); }\
    inline ~CDynamicContainerIterator_##TYPE() { dci_Index = -1; p_cur.Reset(); }\
    inline void MoveToNext() { dci_Index++; if(IsPastEnd()) p_cur.Reset(); else p_cur = dci_Array.Pointer(dci_Index); }\
    inline BOOL IsPastEnd() { return dci_Index>=dci_Array.Count(); }\
    inline TYPE##Ptr& Current() { return p_cur; }\
    inline TYPE##Ptr& operator*() { return p_cur; }\
    inline operator TYPE##Ptr& () { return p_cur; }\
    inline TYPE##Ptr& operator->() { return p_cur; }\
  };

DECLARE_CDynamicContainer(CTextureData)

#define DECLARE_CDynamicContainer_simple(TYPE)\
  class CDynamicContainer_##TYPE\
  {\
    public:\
      CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_* p, bool owner = false);\
      CDynamicContainer_##TYPE();\
      CDynamicContainer_##TYPE(CDynamicContainer_##TYPE& o);\
      ~CDynamicContainer_##TYPE();\
      \
      CDynamicContainer_##TYPE& operator=(CDynamicContainer_##TYPE& o);\
      \
      /* Get index of an object from it's pointer. */\
      INDEX GetIndex(TYPE* ptMember);\
      /* Add a given object to container. */\
      void Add(TYPE* ptNewObject);\
      /* Remove a given object from container. */\
      void Remove(TYPE* ptOldObject);\
      /* Remove all objects, and reset the container to initial (empty) state. */\
      void Clear();\
      /* Test if a given object is in the container. */\
      BOOL IsMember(TYPE* ptOldObject);\
      \
      /* Get pointer to a object from it's index. */\
      TYPE* Pointer(INDEX iObject);\
      const TYPE* Pointer(INDEX iObject) const;\
      /* Random access operator. */\
      TYPE& operator[](INDEX iObject);\
      const TYPE& operator[](INDEX iObject) const;\
      /* Move all elements of another container into this one. */\
      void MoveContainer(CDynamicContainer_##TYPE& coOther);\
      INDEX Count() const;\
      \
      /* Get first object in container (there must be at least one when calling this). */\
      TYPE& GetFirst();\
      \
      inline CDynamicContainer_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CDynamicContainer_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CDynamicContainer_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicContainer_##TYPE##_* () const { return C_Handle(); }\
    protected:\
      bool m_owner = true;\
      CDynamicContainer_##TYPE##_* mp_array = nullptr;\
  };\
  class CDynamicContainerIterator_##TYPE {\
  private:\
    INDEX dci_Index;\
    CDynamicContainer_##TYPE& dci_Array;\
  public:\
    inline CDynamicContainerIterator_##TYPE(CDynamicContainer_##TYPE& da) : dci_Array(da) { dci_Index = 0; }\
    inline ~CDynamicContainerIterator_##TYPE() { dci_Index = -1; }\
    inline void MoveToNext() { dci_Index++; }\
    inline BOOL IsPastEnd() { return dci_Index>=dci_Array.Count(); }\
    inline TYPE& Current() { return *dci_Array.Pointer(dci_Index); }\
    inline TYPE& operator*() { return *dci_Array.Pointer(dci_Index); }\
    inline operator TYPE* () { return dci_Array.Pointer(dci_Index); }\
    inline TYPE* operator->() { return dci_Array.Pointer(dci_Index); }\
  };

// iterate whole dynamic container
/* NOTE: The iterator defined by this macro must be destroyed before adding/removing
 * elements in the container. To do so, embed the for loop in additional curly braces.
 */
#define FOREACHINDYNAMICCONTAINER(container, type, iter) \
  for(CDynamicContainerIterator_##type iter(container); !iter.IsPastEnd(); iter.MoveToNext() )

#include "DynamicContainer.inl"
