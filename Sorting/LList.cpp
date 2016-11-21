#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <exception>
#include "LList.h"

using namespace std;

//-------------------------LList Implementation---------------------

//
LList::LList()
{
	//PRE:None
	//POST:The N.O. is valid and empty
	head=NULL;//headpoints to NULL
}

//
LList::~LList()
{
	//PRE:The N.O. LList is valid
	//POST:The N.O. LList is still valid, butempty
	//and all of its listnodes have been deleted
	Clean();//leaves no castaway listnodes
}

//
void LList::Clean()
{
	//PRE:The N.O. LList is valid
	//POST:The N.O. is now empty and
	//all of its listnodes have been deleted
	listnode * temp;//temporary pointer to a listnode
	while(head!=NULL)
        {
            temp=head;//temp points to same listnode as head pointer
            head=(head->next);
            delete temp;
		}
}

//
void LList::Print()
{
	//PRE:The N.O. LList is valid
	//POST:The N.O LList is unchanged and its
	//elements have been displayed

	listnode* temp;//temp pointer to a listnode
	int size;
	size=GetListSize();
	temp=head;
	cout<<endl;

	for(int i=0; i<size; i++)
        {
            if( size==4 && i==1 )
                cout << ", ";
            else if( size==5 && i==2 )
                cout << ", ";
            else if( size > 5 && (size-i)%3 == 0 && i!=0 )
                cout << ", ";

            cout << temp->data <<" ";
            temp = temp->next;
		}
	cout << endl << endl;
}

//
void LList::InsertTail(element val)
{
	//PRE:The N.O. LList is valid and
	//val is valid
	//POST:The N.O. LList is unchanged
	//except it now has a new listnode at
	//the tail-end containing val

	listnode * temp;
	temp=new listnode;
	temp->data = val;
	temp->next = NULL;
	if(head==NULL)
		head = temp;
	else
		tail->next = temp;
		tail = temp;
}

//
int LList::DeleteHead()
{
	//PRE:The N.O. LList is valid and not empty
	//POST:The N.O. LList is unchanged
	//except the listnode at its head-end has
	//been deleted and its element returned
	element val;
	listnode * temp;
	temp = head;
	head = head->next;
	val = temp->data;
	delete temp;
	return val;
}


//
void LList::Append(LList &Source)
{
	//PRE:The N.O. LList and the Source LList are valid
	//POST:The N.O. LList and the Source LList are
	//unchanged except the N.O. LList contains all of its
	//original listnodes and all of the source's original
	//listnodes, and the Source is now empty
	if(head!=NULL)
		tail->next = Source.head;
	else
		head = Source.head;
	if(Source.head!=NULL)
		tail = Source.tail;
	Source.head = NULL;
}

//
listnode* LList::locate()
{
	//PRE:The N.O. LList is valid
	//POST:The N.O. LList is still valid and the
	//address its head points to has been returned
	return head;
}

int LList::GetListSize()
{
	//PRE:The N.O. LList is valid
	//POST:The N.O. LList is still valid and
	//the size of the current list has been returned
	listnode * temp;
	temp=head;
	int size=1;
	while(temp!=NULL)
        {
            size++;
            temp=temp->next;
		}
	return size-1;
}
//-------------------------LList Implementation---------------------

//-------------------------LQUEUE Implementation---------------------

//
LQueue::LQueue()
{
    //PRE: none
    //POST: none

}

//
LQueue::~LQueue()
{
    //PRE: none
    //POST: none
}

//
void LQueue::Enqueue(int val)
{
    //PRE: The N.O. Helper is valid and not full
    //POST: val has been placed onto the tail end of the queue
    Helper.InsertTail(val);
}

//
int LQueue::dequeue()
{
    //PRE: The N.O. Helper is valid
    //POST: the head element of the queue has been removed and returned to the calling function
    return Helper.DeleteHead();
}

//
bool LQueue::isEmpty()
{
    //PRE: none
    //POST: Returns whether the queue's head pointer is null
    if( Helper.head == NULL )
        return true;
    return false;
}

//
bool LQueue::isFull()
{
    //PRE:
    //POST:
}

//-------------------------LQUEUE Implementation---------------------
