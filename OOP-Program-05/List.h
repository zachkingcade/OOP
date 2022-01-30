#pragma once
#include<iostream>

template<class ItemType>
class List
{
	//---------------ListNode Internal Class---------------
   struct ListNode
   {  ItemType item;
	  ListNode * next;
   };
   //---------------End ListNode Internal Class---------------

public:

//---------------Prototypes------------------------------

// requires : List is not created
// ensures : List is created and empty
List ( );

 // requires: this list and other are created
// ensures:  other is copied to this list
List (List & other);

// requires : List is created
// ensures : List is not created
~List ();

//requires: List is created
//ensures:  List is empty
void ClearList ();

//requires: this list and other are created
//ensures:   this = #other and other = #list, except that cursors are at heads
void SwapLists(List & other);

// requires : List is created
// ensures : List's cursor is placed before the first item in the sequence,
//           and the sequence is unchanged
void ResetCursor ();

// requires : L is created
// ensures : returns true iff L's cursor is located after
//           the last item in the sequence.  L is not changed
bool CursorAtEnd ();

// requires : List is created and the cursor is not at the end of the sequence
// ensures : Return in Item the item referenced by L's cursor.  The sequence
//           is unchanged and the cursor is not moved
// checks :  if Cursor is at the end of the list, write error message
void GetCurrentItem (ItemType & Item);

// requires : L is created and the cursor is not at the end of the sequence
// ensures : the item referenced by L's cursor is set to the value of I;
//            The sequence is unchanged otherwise and the cursor is not moved
// checks : if Cursor is at the end of the list, write error message
void UpdateCurrentItem (const ItemType & Item);

// requires : List is created and the cursor is not at the end of the sequence
// ensures : List's cursor is advanced one position in the sequence and the
//           sequence is unchanged
// checks : if Cursor is at the end of the list, write error message
void AdvanceCursor ();

// requires : List is created
// ensures : Item is inserted at the position of L's cursor. Otherwise the  
//           sequence is unchanged and the cursor is located before the
//           inserted item  
void InsertItem (const ItemType & Item);

// requires : List is created and the cursor is not at the end of the sequence
// ensures : the item at the position referenced by L's cursor is deleted.
//           Otherwise the sequence is unchanged and the cursor is located
//           before the next item in the sequence
// checks : if cursor is at the end of the list, write error message
void DeleteItem ();

//requires: List is created
//ensures: the number of items in the list is returned
int getCount();

private:
//---------------Member Data---------------

	ListNode * head;
	ListNode * cursor;
	int count;
};


#include"List.hpp"