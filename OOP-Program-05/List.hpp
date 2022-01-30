//Programmer: Catherine Stringfellow AND Zachary Kingcade
//File: List.cpp
//Date:  11/29/19

template <class ItemType>
List<ItemType>::List ( ){
//here we create a dummy node to act as in unmoving head as illustrated
//in the assignment
head = new ListNode;
cursor = head;
count = 0;
} //  defaultconstructor

template <class ItemType>
List<ItemType>::List(List & other)
{
  ItemType Item;
  ListNode * temp;

  //construct empty list - same code as in default constructor goes here
  head = new ListNode;
  cursor = head;
  count = 0;
  //copy items in other to this list
  other.cursor = other.head;
  while (other.cursor->next!=NULL)
  {
	 Item = other.cursor->next->item;
	 
	 temp = new ListNode;
     temp->item = Item;
     temp->next =  cursor->next;
	 cursor->next = temp;
	 count++;

	 other.cursor = other.cursor->next;
	 cursor = cursor->next;
  }
}

template <class ItemType>
List<ItemType>::~List ()
{
	 ListNode * temp;
     
	 //starting at head of list, delete all nodes
	 ResetCursor();
	while (!CursorAtEnd()){DeleteItem();}

	 // dispose of dummy node
	 delete head;

	 
}       // destructor

template <class ItemType>
void List<ItemType>::SwapLists(List & other)
{
    ListNode * temp;
	int tempCount;

	//swap cursors 
	temp = cursor;
	cursor = other.cursor;
	other.cursor = temp;

	//swap heads
	temp = head;
	head = other.head;
	other.head = temp;

	//swap counts
	tempCount = count;
	count = other.count;
	other.count = count;
}

template <class ItemType>
void List<ItemType>::ClearList ()
{
	ResetCursor();
	while (!CursorAtEnd())
		DeleteItem();
}


template <class ItemType>
void List<ItemType>::ResetCursor (){cursor = head;}   // reset cursor

template <class ItemType>
bool List<ItemType>::CursorAtEnd (){
	if (cursor->next == nullptr){return true;}
	else {return false;}
}       // cursor at end


template <class ItemType>
void List<ItemType>::GetCurrentItem (ItemType & Item){
	if ( cursor != nullptr){
		Item = cursor->next->item;
	}else{
		std::cout << "Error: cursor either at end of list unable to access object\n";
	}
}    // get current item

template <class ItemType>
void List<ItemType>::UpdateCurrentItem (const ItemType & Item)
{
	 if ( cursor->next==NULL  )
		std::cout << "ERROR : cursor at end cannot get current item" << std::endl;
    else
		 cursor->next->item = Item;
}    // get current item

template <class ItemType>
void List<ItemType>::AdvanceCursor ()
{
    if ( cursor->next==NULL  )
		std::cout << "ERROR : cursor at end cannot advance cursor" << std::endl;
    else
       cursor =  cursor->next;
}        // advance cursor


template <class ItemType>
void List<ItemType>::InsertItem (const ItemType & Item){
	ListNode * temp;
	
	temp = new ListNode;
    temp->item = Item;
    temp->next =  cursor->next;
	cursor->next = temp;
	
	count++;
}

template <class ItemType>
void List<ItemType>::DeleteItem ()
{

	ListNode * temp;

	 if ( cursor->next==NULL  )
      std::cout << "ERROR : cursor at end cannot delete item" << std::endl;
    else
    {
		temp = cursor->next;
		cursor->next = temp->next;
		delete temp;
		count--;
    }
}        // delete item

template <class ItemType>
int List<ItemType>::getCount() {
	return count;
}