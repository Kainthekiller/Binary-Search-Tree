/*
File:			DList.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Created:		1.17.2021
Last Modified:	2.26.2021
Purpose:		A hash-mapped data structure using key/value pairs and separate chaining
Notes:			Property of Full Sail University
*/

// Header protection
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
#define LAB_5	1

// Individual unit test toggles
#define DICT_CTOR					1 //Passing
#define DICT_PAIR_CTOR				1 //Passing
#define DICT_DTOR					1 //Passing
#define DICT_CLEAR					1 //Passing
#define DICT_INSERT					1 //Passing
#define DICT_INSERT_EXISTING		1 //Passing
#define DICT_FIND					1 //Passing
#define DICT_FIND_NOT_FOUND			1 //Passing
#define DICT_REMOVE					1 //Passing
#define DICT_REMOVE_NOT_FOUND		1 //Passing
#define DICT_ASSIGNMENT_OP			1 //Passing
#define DICT_COPY_CTOR				1 //Passing

/************/
/* Includes */
/************/
#include <list>

#if LAB_5
//Key First Value 2nd
template<typename Key, typename Value>
class Dictionary {

	friend class DSA_TestSuite_Lab5;	// Giving access to test code

	// The objects stored in the hash-table
	struct Pair {
		Key key;			// The key for insertion/lookup
		Value value;		// The data

		// Constructor
		// In:	_key
		//		_value
		Pair(const Key& _key, const Value& _value) {
			// TODO: Implement this method
			key = _key;
			value = _value;
		}

		// For testing
		bool operator==(const Pair& _comp) {
			return (_comp.key == key &&
				_comp.value == value);
		}
	};
	//*Linked List
	std::list<Pair>* mTable;				// A dynamic array of lists (these are the buckets)
	size_t mNumBuckets;						// Number of elements in mTable
	unsigned int(*mHashFunc)(const Key&);	// Pointer to the hash function
	//Function pointer

public:

	// Constructor
	// In:	_numBuckets			The number of elements to allocate
	//		_hashFunc			The hashing function to be used
	Dictionary(size_t _numBuckets, unsigned int (*_hashFunc)(const Key&)) {
		// TODO: Implement this method

		mNumBuckets = _numBuckets;
		mHashFunc = _hashFunc;
		mTable = new std::list<Pair>[_numBuckets];

	}

	// Destructor
	//		Cleans up any dynamically allocated memory
	~Dictionary() {
		// TODO: Implement this method
		delete[] mTable;
	}

	// Copy constructor
	//		Used to initialize one object to another
	// In:	_copy				The object to copy from
	Dictionary(const Dictionary& _copy) {
		// TODO: Implement this method
		mHashFunc = _copy.mHashFunc;
		mNumBuckets = _copy.mNumBuckets;
		mTable = new std::list<Pair>[mNumBuckets];
		for (int i = 0; i < mNumBuckets; i++)
		{
			mTable[i] = _copy.mTable[i];
		}
		
		
	
	}

	// Assignment operator
	//		Used to assign one object to another
	// In:	_assign				The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	Dictionary& operator=(const Dictionary& _assign) {
		// TODO: Implement this method
		delete[] mTable;
		mTable = new std::list<Pair>[_assign.mNumBuckets];
		if (this != &_assign)
		{
			this->mNumBuckets = _assign.mNumBuckets;
			this->mHashFunc = _assign.mHashFunc;
			for (int i = 0; i < mNumBuckets; i++)
			{
				
					mTable[i] = _assign.mTable[i];	
			}
		}

		return *this;
		}




	// Clear
	//		Clears all internal data being stored
	//  NOTE:	Does not delete table or reset hash function
	void Clear() {
		// TODO: Implement this method
		
		for (int i = 0; i < mNumBuckets; i++)
		{
			mTable[i].clear();
		}
			
		
		
	}


	// Insert an item into the table
	// In:	_key		The key to add at	
	//		_value		The value at the key
	//
	// NOTE:	If there is already an item at the provided key, overwrite it.
	void Insert(const Key& _key, const Value& _value) {
		// TODO: Implement this method
		//Call Hash Function
		int hashValue = mHashFunc(_key);
		auto& tableCell = mTable[hashValue];
		auto Itr = begin(tableCell);
		bool keyExist = false;
		for (; Itr != end(tableCell); ++Itr) {
			if (Itr->key == _key) {
				keyExist = true;
				Itr->value = _value;
				break;
			}
		}
		if (!keyExist) {
			tableCell.emplace_back(_key, _value);
		}
		return;
		

		
	}

	// Find a value at a specified key
	// In:	_key		The key to search for	
	//
	// Return: A const pointer to the value at the searched key
	// NOTE:		Return a null pointer if key is not present
	const Value* Find(const Key& _key) {
		// TODO: Implement this method
		//Call Has function

		int hashValue = mHashFunc(_key);
		auto& tableCell = mTable[hashValue];
		auto Itr = begin(tableCell);
		bool keyExist = false;
		for (; Itr != end(tableCell); ++Itr) {
			if (Itr->key == _key) {
				keyExist = true;
				
				return &Itr->value;
				break;
			}
		}
		if (!keyExist) {
			return nullptr;
		}
	
	



	}

	// Remove a value at a specified key
	// In:	_key		The key to remove
	//
	// Return: True, if an item was removed
	bool Remove(const Key& _key) {
		// TODO: Implement this method
		int currBucket = mHashFunc(_key);
		for (typename std::list<Pair>::iterator it = mTable[currBucket].begin(); it != mTable[currBucket].end(); ++it)
		{
			if (it->key == _key) {
				mTable[currBucket].erase(it);
				return true;
			}
		}
		return false;
	}
};

#endif	// End LAB_5