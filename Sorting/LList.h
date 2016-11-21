#ifndef LLIST_H_INCLUDED
#define LLIST_H_INCLUDED
#include "sorting.h"
class listnode
{
	public:
		char data;//holds data variable
		listnode* next;//points to next memory location in list
};

class LList{
    friend class sorting;
	private:
		listnode* head;//points to head's listnode
		listnode* tail;//points to tail's listnode
	public:
		LList();//constructor
		~LList();//destructor
		void Clean();//Deletes entire Linked List
		//void ReadForward();//Reads user input FIFO
		//void ReadBackward();//Reads user input FILO
		void Print();
		//void InsertHead(element val);//Inserts at the head element of the linked list
		void InsertTail(int val);//Inserts character at the tail element of the linked list
		int DeleteHead();//Deletes head element of linked list and returns its value
		//void Duplicate(LList& Helper);
		//void Steal(LList& Victim);
		void Append(LList& Source);
		void Reverse();
		//listnode* locate();//returns pointer to head
		int GetListSize();
};

class LQueue{
    private:
        LList Helper;
    public:
        LQueue();
        ~LQueue();
        void Enqueue(int item);
        int dequeue();
        bool isEmpty();
        bool isFull();
};

#endif // LLIST_H_INCLUDED
