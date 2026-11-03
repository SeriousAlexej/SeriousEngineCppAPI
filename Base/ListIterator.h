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

/* simple list iterator */
template<typename TObjectPtr, typename TObjectPtr::THandleType*(*getterFunc)(CListNode_*)>
class CListIter
{
public:
  /* constructor with list attaching */
  inline CListIter(const CListHead& lhHead)
    : li_CurrentNode(lhHead.Head())
  {
    _UpdateObject();
  }
  /* constructor to start from given node */
  inline CListIter(CListNode& lnNode)
    : li_CurrentNode(&lnNode)
  {
    _UpdateObject();
  }
  inline CListIter(const CListNodePtr& lnNodePtr)
    : li_CurrentNode(lnNodePtr)
  {
    _UpdateObject();
  }
  /* start iterating */
  inline void Reset(const CListHead& lhHead) {
    li_CurrentNode = lhHead.Head();
    _UpdateObject();
  }
  /* move to next node */
  inline void MoveToNext() {
    li_CurrentNode = li_CurrentNode->Succ();
    _UpdateObject();
  }
  /* move to previous node */
  inline void MoveToPrev() {
    li_CurrentNode = li_CurrentNode->Pred();
    _UpdateObject();
  }
  /* check if finished */
  inline BOOL IsPastEnd() {
    return li_CurrentNode->IsTailMarker();
  }
  /* Insert a node after current one. */
  inline void InsertAfterCurrent(CListNode& lnNew) {
    li_CurrentNode->IterationInsertAfter(lnNew);
  }
  /* Insert a node before current one. */
  inline void InsertBeforeCurrent(CListNode& lnNew) {
    li_CurrentNode->IterationInsertBefore(lnNew);
  }

  /* Get current element. */
  typename TObjectPtr::TObjectType& Current() { return *mp_object; }
  typename TObjectPtr::TObjectType& operator*() { return *mp_object; }
  operator typename TObjectPtr::TObjectType* () { return &(*mp_object); }
  typename TObjectPtr::TObjectType* operator->() { return &(*mp_object); }

private:
  inline void _UpdateObject()
  {
    if (li_CurrentNode && !IsPastEnd())
      mp_object = getterFunc(*li_CurrentNode);
    else
      mp_object.Reset();
  }

private:
  CListNodePtr li_CurrentNode;
  TObjectPtr mp_object;
};

// declare a list iterator for a class with a CListNode member
#define LISTITER(baseclass, member) CListIter<TPointer<baseclass, baseclass##_>, baseclass##_from_##member>

// make 'for' construct for walking a list
#define FOREACHINLIST(baseclass, member, head, iter) \
  for ( LISTITER(baseclass, member) iter(head); !iter.IsPastEnd(); iter.MoveToNext() )

// make 'for' construct for deleting a list
#define FORDELETELIST(baseclass, member, head, iter)  \
   for ( LISTITER(baseclass, member) iter(head), iter##next(head);  \
   iter##next=iter, iter##next.IsPastEnd() || (iter##next.MoveToNext(),1), !iter.IsPastEnd(); \
     iter = iter##next)
