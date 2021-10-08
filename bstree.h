//
// bstree.h  Binary Search Tree Template
//
// Provides a declaration of the BSTree class template.
//
// NOTES:
// The public methods utilize several private helper methods to perform the desired tasks.
//
// DO NOT MODIFY OR SUBMIT THIS FILE 
//

#ifndef BSTREE_H
#define BSTREE_H

#include <cstddef>
#include <new>
#include <string>
#include <queue>

using namespace std;

// Exception classes
class FullBSTree      { /* No code here */ };  // Exception class models full BSTree condition

class EmptyBSTree     { /* No code here */ };  // Exception class models empty BSTree condition

class NotFoundBSTree  { /* No code here */ };  // Exception class models not found in BSTree condition

class FoundInBSTree   { /* No code here */ };  // Exception class models found in BSTree condition

class NoParentBSTree   { /* No code here */ };  // Exception class models no parent in BSTree condition


template <typename SomeType>
struct BSTreeNode                      // Node of BSTree
{
  SomeType data;                       // Data stored in node
  BSTreeNode<SomeType>* leftPtr;       // Pointer to left subtree
  BSTreeNode<SomeType>* rightPtr;      // Pointer to right subtree
};

template <typename SomeType>
class BSTree                           // BSTree Abstract Data Type
{
private:
  BSTreeNode<SomeType>* rootPtr;       // Pointer to root of BSTree
	
  /********  Start of Private Helper Functions You Must Implement for BSTree class template  *********/	
  void Delete(BSTreeNode<SomeType>*& treePtr, SomeType& item);
  // Delete()
  // Recursive function that traverses the tree starting at treePtr to locate the data value to be removed
  // Once located, DeleteNode is invoked to remove the value from the tree
  // If tree is not empty and item is NOT present, throw NotFoundBSTree	
	
  void DeleteNode(BSTreeNode<SomeType>*& treePtr);
  // DeleteNode()
  // Removes the node pointed to by treePtr from the tree
  // Hint:  calls GetPredecessor and Delete

  void Insert(BSTreeNode<SomeType>*& ptr, SomeType item);
  // Insert()
  // Recursive function that finds the correct position of item and adds it to the tree
  // Throws FoundInBSTree if item is already in the tree	

  void Destroy(BSTreeNode<SomeType>*& ptr);
  // Destroy()
  // Recursively deallocates every node in the tree pointed to by ptr

  void CopyTree(BSTreeNode<SomeType>*& copy, const BSTreeNode<SomeType>* originalTree);
  // CopyTree()
  // Recursively copies all data from original tree into copy
	
  SomeType GetPredecessor(BSTreeNode<SomeType>* treePtr) const;
  // GetPredecessor()
  // Finds the largest data value in the tree pointed to by treePtr and returns that data value
  // as the functions return value
	
  int CountNodes(BSTreeNode<SomeType>* treePtr) const;
  // CountNodes()
  // Recursive function that counts every node in the tree pointed to by treePtr and returns the
  // count as the function return value
	
  int LevelCount(BSTreeNode<SomeType>* treePtr) const;
  // LevelCount()
  // Recursive function that traverses the entire tree to determine the total number of levels in the tree

  int FindLevel(BSTreeNode<SomeType>* treePtr, SomeType item) const;
  // FindLevel()
  // Recursive function that traverses the tree looking for item and returns the level where
  // item was found

  void SearchForParent(BSTreeNode<SomeType>* treePtr, SomeType item) const;
  // SearchForParent()
  // Recursive function that traverses the tree looking for item's parent and throws the value of 
  // item's parent if found.  Otherwise, throws NotFoundBSTree

  /********  End of Private Helper Functions You Must Implement for BSTree class template *************/

public:

  /********  Start of Public Interface Functions You Must Implement for BSTree class template *********/
	
  BSTree();								
  // BSTree()
  // Default constructor initializes root pointer to NULL
	
  BSTree(const BSTree<SomeType>& someTree);
  // BSTree() 
  // Copy constructor for BSTree
  // Hint:  calls CopyTree
	
  void operator=(const BSTree<SomeType>& originalTree);
  // operator=() 
  // Overloaded assignment operator for BSTree.
  // Hint:  calls CopyTree

  ~BSTree();							
  // ~BSTree()
  // Destructor deallocates all tree nodes
  // Hint:  calls the private helper function Destroy
  
  void InsertItem(SomeType item);		
  // InsertItem()
  // Inserts item into BSTree;  if tree already full, throws FullBSTree exception
  // If item is already in BSTree, throw FoundInBSTree exception
  // Hint:  calls the private helper function Insert
  
  SomeType DeleteItem(SomeType item);		
  // DeleteItem()
  // Deletes item from BSTree if item is present AND returns object via function return value
  // If tree is empty, throw the EmptyBSTree exception
  // If tree is not empty and item is NOT present, throw NotFoundBSTree
  // Hint:  calls the private helper function Delete
  
  void MakeEmpty();						
  // MakeEmpty()
  // Deallocates all BSTree nodes and sets root pointer to NULL
  // Hint:  calls the private helper function Destroy
  
  int Size() const;	
  // Size()
  // Returns total number of data values stored in tree
  
  bool IsFull() const;					
  // IsFull()
  // Returns true if BSTree is full; returns false otherwise
  
  bool IsEmpty() const;					
  // IsEmpty()
  // Returns true if BSTree is empty; returns false otherwise
  	
  SomeType Min() const;                 
  // Min()
  // Returns minimum value in tree; throws EmptyBSTree if tree is empty
	
  SomeType Max() const;                 
  // Max()
  // Returns maximum value in tree; throws EmptyBSTree if tree is empty
	
  int TotalLevels() const;              
  // TotalLevels()
  // Returns the maximum level value for current tree contents
  // Levels are numbered 0, 1, ..., N-1.  This function returns N
  // Throws EmptyBSTree if empty
  // Hint:  calls the private helper function LevelCount

  int Level(SomeType item) const;       
  // Level()
  // Returns the level within the BSTree at which the value item is found
  // If tree is empty, throws EmptyBSTree
  // If tree is not empty and item is not found, throws NotFoundBSTree
  // Hint:  calls the private helper funtion FindLevel

  SomeType Parent(SomeType item);		
  // Parent()
  // Returns the value of item's parent from BSTree if item is present AND returns object via function return value
  // If tree is empty, throw the EmptyBSTree exception
  // If tree is not empty and item is NOT present, throw NotFoundBSTree
	
  /**************  End of Functions You Must Implement for BSTree class template ****************/
	
	
	
  void Print() const;  // DO NOT WRITE THIS FUNCTION
  // Print()
  // Prints binary search tree contents in inorder, preorder, and postorder forms
  // NOTE: THIS CODE HAS BEEN INCLUDED AT THE END OF bstree.h
};

// Note: Template classes cannot be compiled on their own
// since the data type argument is found in the client code.

#include "bstree.cpp" 


/**********************************************************************/
/************** Implementation of Print() function ********************/
/**********************************************************************/

// DO NOT MODIFY OR MOVE THIS CODE

#include <queue> 

// This code uses the Standard Template Libary queue class, container adapter wrapper
// that makes the deque (double-ended queue) look more like a single-ended queue.
// Note the different names used for the enqueue and dequeue operations.

template <typename SomeType>
void PreOrder(BSTreeNode<SomeType>* tree, queue<SomeType>& preorder)
// PreOrder()
// Post: preorder contains the tree items in preorder.
{
	if (tree != NULL)
	{
		preorder.push(tree->data);
		PreOrder(tree->leftPtr, preorder);
		PreOrder(tree->rightPtr, preorder);
	}
}

template <typename SomeType>
void InOrder(BSTreeNode<SomeType>* tree, queue<SomeType>& inorder)
// InOrder()
// Post: inorder contains the tree items in inorder.
{
	if (tree != NULL)
	{
		InOrder(tree->leftPtr, inorder);
		inorder.push(tree->data);
		InOrder(tree->rightPtr, inorder);
	}
}

template <typename SomeType>
void PostOrder(BSTreeNode<SomeType>* tree, queue<SomeType>& postorder)
// PostOrder()
// Post: postorder contains the tree items in postorder.
{
	if (tree != NULL)
	{
		PostOrder(tree->leftPtr, postorder);
		PostOrder(tree->rightPtr, postorder);
		postorder.push(tree->data);
	}
}

template <typename SomeType>
void BSTree<SomeType>::Print() const
// Print()
// Prints binary search tree contents in inorder, preorder, and postorder forms
{
	queue<SomeType> preorder, inorder, postorder;
	
	PreOrder(rootPtr, preorder);
	InOrder(rootPtr, inorder);
	PostOrder(rootPtr, postorder);
	
	cout << "Print() \n-- Inorder = { ";
	while (!inorder.empty())
	{
		cout << inorder.front() << " ";
		inorder.pop();
	}
	cout << "}   \n-- Preorder = { ";
	while (!preorder.empty())
	{
		cout << preorder.front() << " ";
		preorder.pop();		
	}
	cout << "}   \n-- Postorder = { ";
	while (!postorder.empty())
	{
		cout << postorder.front() << " ";
		postorder.pop();		
	}
	cout << "}" << endl;
}

#endif




