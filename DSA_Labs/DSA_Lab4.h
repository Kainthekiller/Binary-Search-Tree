/*
File:			DSA_Lab4.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:    Phillip, Yates

Created:		12.27.2020
Last Modified:	02.26.2021
Purpose:		Usage of the std::list class
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
#define LAB_4	0

// Individual unit test toggles
#define LIST_QUEUE_ADD				1 //Passing
#define LIST_STACK_ADD				1 //Passing
#define LIST_QUEUE_REMOVE			1 //Passing
#define LIST_STACK_REMOVE			1 //Passing
#define LIST_INSERT_INDEX			1 //Passing
#define LIST_INSERT_ITER			1 //Passing
#define LIST_REMOVE_DECIMAL			1 //Passing

/************/
/* Includes */
/************/
#include <list>

#if LAB_4

class DSA_Lab4 {

	friend class DSA_TestSuite_Lab4;	// Giving access to test code

	// Data members
	std::list<float> mList;				// The list used in all methohods

public:

	// Add all of the values from the array into the list using queue ordering
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	void QueueOrderingAdd(const float* _arr, size_t _size) {
		// TODO: Implement this method
		for (int i = 0; i < _size; i++)
		{
			//DONT CHANGE ANYMORE !!!!
			mList.push_back(_arr[i]);
		}
	


	}

	// Add all of the values from the array into the list using queue ordering
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	void StackOrderingAdd(const float* _arr, size_t _size) {
		// TODO: Implement this method
		int temp = _size - 1;
		for (int i = 0; i < _size; i++)
		{
			//DONT CHANGE ANYMORE !!!
			mList.push_back(_arr[temp]);
			
			temp--;
		}

	}

	// Remove a single value from the list using queue ordering
	//
	// Return: The value that was removed
	float QueueOrderingRemove() {
		// TODO: Implement this method
		std::list<float>::iterator it = mList.begin();
		float holder = *it;
		mList.remove(*it);
		return holder;
	}

	// Remove a single value from the list using stack ordering
	//
	// Return: The value that was removed
	float StackOrderingRemove() {
		// TODO: Implement this method
		std::list<float>::iterator it = mList.begin();
		float holder = *it;
		mList.remove(*it);
		return holder;
	}

	// Insert a value _index nodes away from the head node
	//		If _index is 0 - insert in front of the head/front node
	//		If _index is 5 - insert in front of the 5th node in the list
	//
	// Example:	
	//			0<-[5]<->[1]<->[6]<->[4]<->[2]->0
	//	
	// Inserting a 7 at index 2
	//
	//			0<-[5]<->[1]<->[7]<->[6]<->[4]<->[2]->0
	//
	//
	// In:	_index		The "index" to add at
	//		_val		The value to insert
	void Insert(int _index, float _val) {
		// TODO: Implement this method
		int temp = 0;
		for (int i = 0; i <= _index; i++)
		{
			temp++;
		}
		std::list<float>::iterator it = mList.begin();
		std::advance(it, temp - 1);
		mList.insert(it, _val);
		
	}

	// Insert a value at the spot specified by the iterator passed in
	// 
	// In:	_iter		The iterator at the place to insert
	//		_val		The value to insert
	void Insert(std::list<float>::iterator _iter, float _val) {
		// TODO: Implement this method
		mList.insert(_iter, _val);

	}

	// Remove all values from mList that have a decimal place > _decimal
	//		Example:   If _decimal is 0.5, then 2.84 would be removed, but 0.5 would not be, and neither would 482.043
	//
	// In:	_decimal		The decimal value to check against
	//
	// Return: The total number of values removed
	int RemoveDecimalGreater(float _decimal) {
		// TODO: Implement this method
		int count = 0;
		int round = (int)_decimal; //0.41
		float holder = _decimal - round; //Compare Value 
		int itWhole;
		float realChecker;


		for (std::list<float>::const_iterator iter = mList.begin(); iter != mList.end();) {
			itWhole = (int)*iter;  //12.55 = 13 // 12.33 = 12
			realChecker = *iter - itWhole; //13 - 12.55 = 0.45  
			if (realChecker > holder) {
				iter = mList.erase(iter);
				count++;
			}
			else {
				++iter;
			}
		}
			
		return count;
	}
};

#endif	// End LAB_4