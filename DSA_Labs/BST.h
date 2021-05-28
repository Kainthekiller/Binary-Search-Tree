/*
File:			BST.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Created:		03.05.2021
Last Modified:	03.21.2021
Purpose:		A binary search tree
Notes:			Property of Full Sail University
*/

// Header protection
#pragma once

/************/
/* Includes */
/************/
#include <string>

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
#define LAB_7	1
//Hack Header
// Individual unit test toggles
#define BST_CTOR								1 //Passing 
#define BST_NODE_CTOR							1 //Passing
#define BST_CLEAR								1 //Passing
#define BST_DTOR								1 //Passing
#define BST_PUSH_ROOT							1 //Passing
#define BST_PUSH_ROOT_LEFT						1 //Passing
#define BST_PUSH_ROOT_RIGHT						1 //Passing
#define BST_PUSH_LEFT							1 //Passing
#define BST_PUSH_RIGHT							1 //Passing
#define BST_CONTAINS_TRUE						1 //Passing
#define BST_CONTAINS_FALSE						1 //Passing
#define BST_REMOVE_CASE0_ROOT					1 //Passing
#define BST_REMOVE_CASE0_LEFT					1 //Passing
#define BST_REMOVE_CASE0_RIGHT					1 //Passing 
#define BST_REMOVE_CASE1_ROOT_LEFT				1 //Passing
#define BST_REMOVE_CASE1_ROOT_RIGHT				1 //Passing
#define BST_REMOVE_CASE1_LEFT_LEFT				1 //Passing
#define BST_REMOVE_CASE1_LEFT_RIGHT				1 //Passing
#define BST_REMOVE_CASE1_RIGHT_LEFT				1 //Passing
#define BST_REMOVE_CASE1_RIGHT_RIGHT			1 //Passing
#define BST_REMOVE_CASE2_NO_SUBTREE				1 //Passing
#define BST_REMOVE_CASE2_SUBTREE				1 //Passing
#define BST_REMOVE								1 //Passing //Passes half the time fails the other.
#define BST_REMOVE_NOT_FOUND					1 //Passing 
#define BST_IN_ORDER_TRAVERSAL					1 //Passing
#define BST_ASSIGNMENT_OP						1 //Passing
#define BST_COPY_CTOR							1 //Passing


#if LAB_7
// Templated binary search tree
template<typename Type>
class BST {

	friend class DSA_TestSuite_Lab7;	// Giving access to test code

	struct Node {
		Type data;					// The value being stored
		Node* left, * right;		// The left and right nodes
		Node* parent;				// The parent node

		// Constructor
		//		Always creates a leaf node
		//
		// In:	_data		The value to store in this node
		//		_parent		The parent pointer (optional)
		Node(const Type& _data, Node* _parent = nullptr) {
			// TODO: Implement this method

			data = _data;
			parent = _parent;
			left = nullptr;
			right = nullptr;
		}
	};

	// Data members
	Node* mRoot;	// The top-most Node in the tree

public:

	// Default constructor
	//			Always creates an empty tree
	BST() {
		// TODO: Implement this method
		mRoot = nullptr;

	}


	// Destructor
	//			Clear all dynamic memory
	~BST() {
		// TODO: Implement this method
		Clear(mRoot);
	}

	// Copy constructor
		//			Used to initialize one object to another
		//
		// In:	_copy		The object to copy from
	BST(const BST<Type>& _copy) {
		// TODO: Implement this method
		*this = _copy;
	}

	// Assignment operator
	//			Used to assign one object to another
	//
	// In:	_assign		The object to assign from
	//
	// Return:	The invoking object (by reference)
	//		This allows us to daisy-chain
	BST<Type>& operator=(const BST<Type>& _assign) {
		// TODO: Implement this method
		Copy(_assign.mRoot);
		return *this;
	}

private:
	// Recursive helper method for use with Rule of 3
	// 
	// In:	_curr		The current Node to copy
	//
	// NOTE:	Use pre-order traversal
	void Copy(const Node* _curr) {
		// TODO: Implement this method
		if (_curr == nullptr) 
			return;
		Push(_curr->data);
		Copy(_curr->left);
		Copy(_curr->right);
			
			
		
	}

	//Hack Copy
public:

	// Clears out the tree and readies it for re-use
	void Clear() {
		// TODO: Implement this method
		Clear(mRoot);
		mRoot = nullptr;
	}

private:

	// Recursive helper method for use with Clear
	// 
	// In:	_curr		The current Node to clear
	//
	// NOTE:	Use post-order traversal
	void Clear(Node* _curr) {
		// TODO: Implement this method
		if (_curr == nullptr) 
			return;
		Clear(_curr->left);
		Clear(_curr->right);
		delete _curr;

	}
	//Hack Clear
public:

	// Add a value into the tree
	//
	// In:	_val			The value to add
	void Push(const Type& _val) {
		// TODO: Implement this method

		if (mRoot == NULL)
		{
			mRoot = new Node(_val);
			return;
		}
		Push(_val, mRoot, mRoot->parent);


	}

private:

	// Optional recursive helper method for use with Push
	//
	// In:	_val		The value to add
	//		_curr		The current Node being looked at
	void Push(const Type& _val, Node* _curr, Node* _parent) {
		// TODO: Implement this method (Optional)
		Node* temp = _curr;




		//Left Side
		if (_val < temp->data)
		{
			if (temp->left == NULL)
			{
				temp->left = new Node(_val);
				temp->left->parent = _curr;
				return;
			}
			else
			{
				temp = temp->left;
				Push(_val, temp, temp->parent);
			}
		}



		//Right Side
		if (_val > temp->data)
		{
			if (temp->right == NULL)
			{
				temp->right = new Node(_val);
				temp->right->parent = _curr;
				return;
			}
			else
			{
				temp = temp->right;
				Push(_val, temp, temp->parent);
			}

		}



	}

public:

	// Checks to see if a value is in the tree
	//
	// In:	_val		The value to search for
	//
	// Return:	True, if found
	bool Contains(const Type& _val) {
		// TODO: Implement this method
		bool trueFalse = false;
		Node* temp = mRoot;

		while (temp != NULL)
		{

			if (temp == nullptr)
			{
				return false;
				break;
			}
			//Found
			if (_val == temp->data)
			{
				trueFalse = true;
				return trueFalse;
			}
			//Left move
			else if (_val < temp->data)
			{
				temp = temp->left;

			}
			//Right move
			else if (_val > temp->data)
			{
				temp = temp->right;
			}
		}
		return trueFalse;

	}
private:

	// Opti	onal helper method for use with Contains and Remove methods
	//
	// In:	_val		The value to search for
	//
	// Return: The node containing _val (or nullptr if not found)
	Node* FindNode(const Type& _val) {
		// TODO: Implement this method (Optional)


		Node* temp = mRoot;

		while (temp != nullptr)
		{
			if (_val < temp->data)
			{
				temp = temp->left;
			}
			else if (_val > temp->data)
			{
				temp = temp->right;
			}
			else if (_val == temp->data)
			{
				return temp;
			}


		}
		return nullptr;
	}
	//Hack Find Node
	// Remove a leaf node from the tree
	//		Case 0
	// 	   
	// In:	_node		The Case 0 node to remove
	//
	// Note: The node being passed in will always be a Case 0
	//		Remember to check all 3 subcases
	//		1. Root only
	//		2. Left leaf node
	//		3. Right leaf node
	void RemoveCase0(Node* _node) {
		// TODO: Implement this method
		Node* temp = _node;

		if (mRoot == _node)
		{
			mRoot = NULL;
		}

		// if node is not root change the connections 
		else if (_node->parent->left == _node)
		{
			_node->parent->left = NULL;
		}
		else
		{
			_node->parent->right = NULL;
		}
		delete temp;

		//Example:
		//	    24
		//		/ \
		//		10  48
		//		\   \
		//		12   50

			//	temp->parent->left = NULL;
			//	temp->parent->right = NULL;
			//	delete temp;
			//	return;


	}
	//HACK Case 0

	// Remove a node from the tree that has only one child
	//		Case 1
	//
	// In:	_node		The Case 1 node to remove
	//
	// Note: The node being passed in will always be a Case 1
	//		Remember to check all 6 subcases
	//		1. Root with left child
	//		2. Root with right child
	//		3. Left node with left child
	//		4. Left node with right child
	//		5. Right node with left child
	//		6. Right node with right child
	void RemoveCase1(Node* _node) {
		// TODO: Implement this method
		Node* temp = _node;

		//Root /W Left Child

		if (mRoot == _node && _node->left != NULL)
		{
			mRoot = mRoot->left;
			mRoot->parent = nullptr;
			delete temp;
			return;
		}

		//Root /W Right Child
		else if (mRoot == _node && _node->right != NULL)
		{
			mRoot = mRoot->right;
			mRoot->parent = nullptr;
			delete temp;
			return;
		}
		//Root Left Child /W Left Child
		if (_node->parent->left == temp && temp->left != NULL)
		{
			_node->parent->left = temp->left;
			temp->left->parent = temp->parent;
			delete temp;
			return;
		}
		//Root Right Child /W Right Child
		if (_node->parent->right == temp && temp->right != NULL)
		{
			_node->parent->right = temp->right;
			temp->right->parent = temp->parent;
			delete temp;
			return;
		}
		//Right Child /W Left Child
		if (_node->parent->right == temp && temp->right == NULL)
		{
			_node->parent->right = temp->left;
			temp->left->parent = temp->parent;
		}
		//Right Child /W right Child
		if (_node->parent->right == temp && temp->left == NULL)
		{
			_node->parent->right = temp->right;
			temp->right->parent = temp->parent;
		}
		delete temp;
	}//Hack Case1

	// Remove a node from the tree that has both children
	//		Case 2
	//
	// In:	_node		The Case 2 node to remove
	//
	// Note: The node being passed in will always be a Case 2
	void RemoveCase2(Node* _node) {
		// TODO: Implement this method

		Node* min = _node->right;

		while (min->left != NULL)
		{
			min = min->left;

		}
		_node->data = min->data;

		if (min->left == NULL && min->right == NULL)
		{
			RemoveCase0(min);
		}
		else
		{
			RemoveCase1(min);
		}






	}

	//Hack Case 2
public:

	// Removes a value from tree (first instance only)
	//
	// In:	_val			The value to search for
	//
	// Return:	True, if a Node was removed
	//
	// Note: Can use FindNode to get the node* to remove, 
	//		 and then call one of the RemoveCase methods
	bool Remove(const Type& _val) {
		// TODO: Implement this method
		Node* holder = FindNode(_val);

		if (holder == nullptr)
		{
			return false;
		}
		if (holder->right == nullptr && holder->left == nullptr) {
			RemoveCase0(holder);
			return true;
		}

		else if (holder->right != nullptr && holder->left != nullptr)
		{
			RemoveCase2(holder);
			return true;
		}
		else {
			RemoveCase1(holder);
			return true;
		}

	}//Hack Remove

	// Returns a space-delimited string of the tree in order
	/*
	 Example:
			 24
			/ \
		   10  48
			\   \
			12   50

	 Should return: "10 12 24 48 50"
	*/
	// Note:	Use to_string to convert an int to its string equivelent
	//			Don't forget about the trailing space!

	std::string InOrder() {
		// TODO: Implement this method
		std::string str;
		Node* temp = mRoot;
		InOrder(mRoot, str);
		if (!str.empty()) {
			str.resize(str.size() - 1); // KILLS THE TRAIL 
		}
		return  str;
	}
	//Hack Inorder


private:

	// Recursive helper method to help with InOrder
	//
	// In:	_curr		The current Node being looked at
	//		_str		The string to add to
	//
	// NOTE:	Use in-order traversal
	void InOrder(Node* _curr, std::string& _str) {
		// TODO: Implement this method
		int _val;
		if (_curr == NULL)
			return;
		InOrder(_curr->left, _str);
		_val = _curr->data;
		_str.append(std::to_string(_val) + " ");
		InOrder(_curr->right, _str);


	}
};

#endif	// End LAB_7