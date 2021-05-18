/*
File:			DynArray.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:	Yates, Phillip

Created:		11.21.2020
Last Modified:	05.06.2021
Purpose:		A dynamically-allocated resizeable array (similar to std::vector)
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
#define LAB_1	0

// Individual unit test toggles
#define LAB1_DYNARRAY_DEFAULT_CTOR						0 // Passing
#define LAB1_DYNARRAY_CONSTRUCTOR_WITH_ARGS				0 // Passing
#define LAB1_DYNARRAY_BRACKET_OP_READ_ONLY_BUILT_IN		0 // Passing
#define LAB1_DYNARRAY_BRACKET_OP_WRITE_BUILT_IN			0 // Passing
#define LAB1_DYNARRAY_SIZE								0 // Passing
#define LAB1_DYNARRAY_CAPACITY							0 // Passing
#define LAB1_DYNARRAY_RESERVE_ZERO						0 // Passing
#define LAB1_DYNARRAY_RESERVE_DOUBLE					0 // Passing
#define LAB1_DYNARRAY_RESERVE_VALUE						0 // Passing
#define LAB1_DYNARRAY_RESERVE_SMALLER					0 // Passing
#define LAB1_DYNARRAY_APPEND_NO_RESIZE					0 // Passing
#define LAB1_DYNARRAY_APPEND_RESIZE						0 // Passing
#define LAB1_DYNARRAY_CLEAR								0 // Passing
#define LAB1_DYNARRAY_DTOR								0 // Passing
#define LAB1_DYNARRAY_COPY_CTOR_BUILT_IN				0 // Passing
#define LAB1_DYNARRAY_COPY_CTOR_CLASS					0 // Passing
#define LAB1_DYNARRAY_ASSIGNMENT_BUILT_IN				0 // Passing
#define LAB1_DYNARRAY_ASSIGNMENT_CLASS					0 // Passing

#if LAB_1

// Our implementation of a vector (simplified)
template<typename Type>
class DynArray {

	// Gives access to test code
	friend class DSA_TestSuite_Lab1;

	// Data members
	//* == Pointer
	Type* mArray;			// The dynamic array that will be managed within the class
	size_t mSize;			// The number of elements currently storing valid data
	size_t mCapacity;		// The total number of elements available in the currently allocated array
	int append = 0;
public:

	// Default constructor
	//		Creates an empty object
	//		
	// In:	_startingCap		An initial size to start the array at
	//
	// Note: Do not allocate any memory if the _startingCap is 0

	DynArray(size_t _startingCap = 0) {
		// TODO: Implement this method
		if (_startingCap == 0) {
			mArray = nullptr;
			mSize = 0;
			mCapacity = 0;
		}
		else {
			mArray = new Type[_startingCap];
			mCapacity = _startingCap;
			mSize = 0;
		}

	}

	// Destructor
	//		Cleans up all dynamically allocated memory
	~DynArray() {
		// TODO: Implement this method

		delete[] mArray;

	}

	// Copy constructor                                   ------------------------------
	//		Used to initialize one object to another
	// In:	_da				The object to copy from
	DynArray(const DynArray& _copy) : mArray(nullptr) {
		// TODO: Implement this method
		mSize = _copy.mSize;
		mCapacity = _copy.mCapacity;
		mArray = new Type[mCapacity];
		for (int i = 0; i < mSize; i++)
		{
			mArray[i] = _copy.mArray[i];
		}



	}

	// Assignment operator
	//		Used to assign one object to another
	// In:	_da				The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	DynArray& operator=(const DynArray& _assign) {
		// TODO: Implement this method
		if (this != &_assign)
		{
			mSize = _assign.mSize;
			mCapacity = _assign.mCapacity;
			mArray = new Type[mCapacity];
			for (int i = 0; i < mSize; i++)
			{
				mArray[i] = _assign.mArray[i];
			}
		}
		return *this;
	}

	// Clear
	//		Cleans up all dynamically allocated memory
	//		Sets all data members back to default values
	void Clear() {
		// TODO: Implement this method
		delete[] mArray;
		mArray = nullptr;
		mCapacity = 0;
		mSize = 0;
	}

	// Overloaded [] operator
	//		Used to access an element in the internal array (read-only)
	// In:	_index			The index to access at
	//
	// Return: The item at the specified index (by reference)
	const Type& operator[](int _index) const {
		// TODO: Implement this method


		return mArray[0];
	}

	// Overloaded [] operator
	//		Used to access an element in the internal array (writeable)
	// In:	_index			The index to access at
	//
	// Return: The item at the specified index (by reference)
	Type& operator[](int _index) {
		// TODO: Implement this method

		return mArray[_index];
	}

	// Get the current number of elements actively being used
	//
	// Return: The current number of elements used
	size_t Size() const {
		// TODO: Implement this method

		return mSize;
	}

	// Get the current capacity of the internal array
	//
	// Return: The capacity of the array
	size_t Capacity() const {
		// TODO: Implement this method
		return mCapacity;
	}

	// Add an item to the end of the array
	//		Should resize the array if needed
	//
	// In:	_data			The item to be added
	void Append(const Type& _data) {
		// TODO: Implement this method
		if (mSize != mCapacity) {
			mArray[mSize] = _data;
			mSize++;
		}
		else {
			Reserve();
			mArray[mSize] = _data;
			mSize++;
		}
		
	}
		
			

			
	
	

		
	
	// Resizes the internal array, and copies all data over
	// In: _newCapacity		The new capacity of the array
	//		NOTE:	If 0 is passed, the array should double in size
	//				If _newCapacity < mCapacity, do nothing
	//
	//	SPECIAL CASE: If mCapacity is 0, then it should be set to 1
	void Reserve(size_t _newCapacity = 0) {
		// TODO: Implement this method
		/* A > B
		   B > C
		   C > A
		*/

		/*
		1) Set you mCapacity its new value
		2) create a new array of that capacity
		3) copy values from mArray to that new array
		4) point mArray to the new array
		*/
		if (mCapacity == 0) {
			mCapacity = 1;
			mArray = new Type[mCapacity];
			return;
		}
		if (_newCapacity == 0 && mCapacity != 0) {
			size_t tempCap = mCapacity * 2;
			Type* temp = new Type[tempCap];

			for (int i = 0; i < mSize; i++)
			{
				temp[i] = mArray[i];
			}
			delete[] mArray;
			mArray = temp;
			mCapacity = tempCap;
		}

		
		
	

	
	}
};
 
#endif	// End LAB_1