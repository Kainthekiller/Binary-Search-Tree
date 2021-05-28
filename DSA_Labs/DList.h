/*
File:			DList.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:    Yates, Phillip

Created:		12.27.2020
Last Modified:	02.26.2021
Purpose:		A doubly-linked list (similar to std::list)
Notes:			Property of Full Sail University
*/

//Header protection
#pragma once

/***********/
/* Defines */
/***********/

/*
How to use:

	When working on a lab, turn that lab's #define from 0 to 1

		Example:	#define LAB_1	1

	When working on an individual unit test, turn that #define from 0 to 1

		Example:	#define DYNARRAY_DEFAULT_CTOR	1

NOTE: If the unit test is not on, that code will not be compiled!
*/


// Master toggle
#define LAB_3	0

// Individual unit test toggles
#define LIST_CTOR						1 //Passing // Hammas FTW
#define LIST_NODE_CTOR_DEFAULT			1 //Passing
#define LIST_NODE_CTOR					1 //Passing
#define LIST_ADDHEAD_EMPTY				1 //Passing
#define LIST_ADDHEAD					1 //Passing
#define LIST_ADDTAIL_EMPTY				1 //Passing
#define LIST_ADDTAIL					1 //Passing
#define LIST_CLEAR						1 //Passing
#define LIST_DTOR						1 //Passing
#define LIST_ITER_BEGIN					1 //Passing 
#define LIST_ITER_END					1 //Passing
#define LIST_ITER_INCREMENT_PRE			1 //Passing
#define LIST_ITER_INCREMENT_POST		1 //Passing
#define LIST_ITER_DECREMENT_PRE			1 //Passing
#define LIST_ITER_DECREMENT_POST		1 //Passing
#define LIST_INSERT_EMPTY				1 //Passing
#define LIST_INSERT_HEAD				1 //Passing
#define LIST_INSERT						1 //Passing
#define LIST_ERASE_EMPTY				1 //Passing
#define LIST_ERASE_HEAD					1 //Passing
#define LIST_ERASE_TAIL					1 //Passing
#define LIST_ERASE						1 //Passing
#define LIST_COPY_CTOR_INT				1 //Passing
#define LIST_COPY_CTOR_USER_DEFINED		1 //Passing
#define LIST_ASSIGNMENT_OP_INT			1 //Passing
#define LIST_ASSIGNMENT_OP_USER_DEFINED	1 //Passing

#if LAB_3

template<typename T>
class DList {

	friend class DSA_TestSuite_Lab3;	// Giving access to test code

	struct Node {
		T data;
		Node* next, * prev;									//Tail
		Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr)
		{			
				data = _data;
				next = _next;
				prev = _prev;
			
			// TODO: Implement this method
		
		}

	};

public:

	class Iterator {
	public:

		Node* mCurr;

		// Pre-fix increment operator
		//
		// Return: Invoking object with curr pointing to next node
		// 
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
							I
							R
		*/
		Iterator& operator++() {
			// TODO: Implement this method
			//mCurr->next holds the value I need
			//mCurr->next is a node
			//I need to return a Iterator

			mCurr = mCurr->next;

			return *this;

	/*		Iterator iter;
			iter.mCurr = mHead;
			return iter;*/

		}

		// Post-fix increment operator
		//
		// In:	(unused)		Post-fix operators take in an unused int, so that the compiler can differentiate
		//
		// Return:	An iterator that has its curr pointing to the "old" curr
		// NOTE:	Will need a temporary iterator 
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
					  R		I

		*/
		Iterator operator++(int) {
			// TODO: Implement this method
			Iterator temp = *this; // OLD
			mCurr = mCurr->next; //Change Data

			return temp; //Return OLD;
		}

		// Pre-fix decrement operator
		//
		// Return: Invoking object with curr pointing to previous node
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
				I
				R
		*/
		Iterator& operator--() {
			// TODO: Implement this method
			mCurr = mCurr->prev;

			return *this;
		
		}

		// Post-fix decrement operator
		//
		// In:	(unused)		Post-fix operators take in an unused int, so that the compiler can differentiate
		//
		// Return:	An iterator that has its curr pointing to the "old" curr
		// NOTE:	Will need a temporary iterator 
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
				I	  R

		*/
		Iterator operator--(int) {
			// TODO: Implement this method
			Iterator temp = *this;
			mCurr = mCurr->prev;
			return temp;
		}

		// Dereference operator
		//
		// Return: The data the curr is pointing to
		T& operator*() {
			// TODO: Implement this method
		}

		// Not-equal operator (used for testing)
		// 
		// In:	_iter		The iterator to compare against
		//
		// Return: True, if the iterators are not pointing to the same node
		bool operator != (const Iterator& _iter) const {
			return mCurr != _iter.mCurr;
		}
	};

	// Data members
	Node* mHead;		// The head (first node) of the list
	Node* mTail;		// The tail (last node) of the list
	size_t mSize;		// Current number of nodes being stored

public:

	// Default constructor
	//		Creates a new empty linked list
	DList() {
		// TODO: Implement this method

		mHead = nullptr;
		mTail = nullptr;
		mSize = 0;
	}

	// Destructor
	//		Cleans up all dynamically allocated memory
	~DList() {
		// TODO: Implement this method
		//Dont use a method here
		Node* temp = mHead;
		while (mHead != nullptr) {
			mHead = mHead->next;
			delete temp;
			temp = mHead;
		}
		mSize = 0;
		mTail = nullptr;
		
	}

	// Copy constructor
	//		Used to initialize one object to another
	//
	// In:	_copy			The object to copy from
	DList(const DList& _copy) {
		// TODO: Implement this method
	
		*this = _copy;
	


	}

	// Assignment operator
	//		Used to assign one object to another
	// In:	_asign			The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	DList& operator=(const DList& _assign) {   
		// TODO: Implement this method
		

	}

private:
	// Optional recursive helper method for use with Rule of 3
	//
	// In:	_curr		The current Node to copy 
	void RecursiveCopy(const Node* _curr) {     // 0<-[4]<->[5]<->[6]->0
		// TODO (optional): Implement this method      C     CN
		if (_curr != NULL) {
			RecursiveCopy(_curr->next);  //This builds the list A too Z     // 0<-[4]<->[5]<->[6]->0
			AddHead(_curr->data); //ADD head inserts starting with 6 then 5 then 4 so it ends up // 0<-[4]<->[5]<->[6]->0
		}

	}

public:
	// Add a piece of data to the front of the list
	//
	// In:	_data			The object to add to the list
	void AddHead(const T& _data) {
		// TODO: Implement this method
										//Next  //Prev
		Node* holder = new Node(_data, nullptr, nullptr);
		if (mHead == nullptr)
		{
			mHead = holder; //Head (_data, next->NUll, Prev->nullptr)
			mTail = holder; // Tail (_data, next->NULL, Prev->nullptr)
			
		}
		else
		{
			mHead->prev = holder; //Mhead->Next = (Data, Next->Null, Prev->mHead)
			holder->next = mHead;
			mHead = holder;
			
		}
		mSize++;

		
	}
	

	// Add a piece of data to the end of the list
	//
	// In:	_data			The object to add to the list
	void AddTail(const T& _data) {
		// TODO: Implement this method

										//Next  //Behind
		Node* holder = new Node(_data, nullptr, mTail);
		if (mTail == nullptr) {
			mHead = holder;
			mTail = holder;
		}
		else
		{
			 mTail->next = holder;
			 mTail = holder;
		}
		mSize++;
	}

	// Clear the list of all dynamic memory
	//			Resets the list to its default state
	void Clear() {
		// TODO: Implement this method
		Node* temp = mHead;
		while (mHead != nullptr) {
			mHead = mHead->next;
			delete temp;
			temp = mHead;
		}
			mSize = 0;
			mTail = nullptr;
	}

private:
	// Optional recursive helper method for use with Clear
	// 
	// In:	_curr		The current Node to clear
void RecursiveClear(const Node* _curr) {
		// TODO (Optional): Implement this method
	}

public:

	// Insert a piece of data *before* the passed-in iterator
	//
	// In:	_iter		The iterator
	//		_data		The value to add
	//
	// Example:
	/*
		Before

			0<-[4]<->[5]<->[6]->0
					  I

		After

			0<-[4]<->[9]<->[5]<->[6]->0
					  I
	*/
	// Return:	The iterator
	// SPECIAL CASE:	Inserting at head or empty list
	// NOTE:	The iterator should now be pointing to the new node created
	Iterator Insert(Iterator& _iter, const T& _data) {
		// TODO: Implement this method
		Node* n = new Node(_data); //Create a new Node
			mSize++;
		if (mHead == nullptr) {
			mHead = n;
			mTail = n;
		}
		else if (_iter.mCurr == mHead) 
			//[2]<->[3]
	//[n] <->
		{
			n->next = mHead;
			mHead->prev = n;
			mHead = n;
		}
		else
		{
			Node* current = _iter.mCurr;
			Node* previous = _iter.mCurr->prev;
			current->prev = n;
			n->next = current;
			n->prev = previous;
			previous->next = n;
		}
		_iter.mCurr = n; // It needs to point to the new Node Created;
		return _iter;
		
	}

	// Erase a Node from the list
	//
	// In:	_iter		The iterator
	//
	// Example
	/*

		Before

			0<-[4]<->[5]<->[6]->0
					  I

		After

			0<-[4]<->[6]->0
					  I
	*/
	// Return:	The iterator
	// SPECIAL CASE:	Erasing head or tail
	// NOTE:	The iterator should now be pointing at the node after the one erased
	Iterator Erase(Iterator& _iter) {
		// TODO: Implement this method
		Node* current = _iter.mCurr;
		Node* Holder = NULL; //Used for next mostly
		if (_iter.mCurr == mHead && _iter.mCurr == mTail)
		{
			mHead = nullptr;
			mTail = nullptr;
		}
		//HEAD ERASER IF CURR != NPTR
		else if (_iter.mCurr == mHead)
		{
			Holder = _iter.mCurr->next;
			mHead = mHead->next;
			mHead->prev = NULL;
		}
		//TAIL ERASER
		else if (_iter.mCurr == mTail)
		{
			//No need for Holder No mans land no return. *Sorry these help me understand
			mTail = mTail->prev;
			mTail->next = NULL;
		}
		else 
		{
			Node* previous = _iter.mCurr->prev;
			Holder = _iter.mCurr->next;

			previous->next = Holder;
			Holder->prev = previous;
		}


		

		delete current;
		_iter.mCurr = Holder;
		mSize--;
		return _iter;
	}

	// Set an Iterator at the front of the list
	// 
	// Return: An iterator that has its curr pointing to the list's head
	Iterator Begin() {
		// TODO: Implement this method
		//Node* temp = mHead;
		Iterator iter;
		iter.mCurr = mHead;
		return iter;
	}

	// Set an Iterator pointing to the end of the list
	// 
	// Return: An iterator that has its curr pointing to a null pointer
	Iterator End() {
		// TODO: Implement this method
		Iterator iter;
		mTail = nullptr;
		iter.mCurr = mTail;

		return iter;
	}
};

#endif	// End LAB_3