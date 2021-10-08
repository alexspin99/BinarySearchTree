
#include "bstree.h"

using namespace std;

//Private Member Functions -----------------------------------------------

template<typename SomeType>
void BSTree<SomeType>::Delete(BSTreeNode<SomeType>*&  treePtr, SomeType& item)
{
	//finds item in tree by recursively calling function
	if (item < treePtr->data)
		Delete(treePtr->leftPtr, item);
	else if (item > treePtr->data)
		Delete(treePtr->rightPtr, item);


	//base condition, node found or DNE
	else if (item == treePtr->data)
		DeleteNode(treePtr);
	else
		throw NotFoundBSTree();
}

template<typename SomeType>
void BSTree<SomeType>::DeleteNode(BSTreeNode<SomeType>*& treePtr)
{
	BSTreeNode<SomeType>* deletePtr;
	SomeType data;
	
	deletePtr = treePtr;
	
	//if left subtree DNE, replace root with right subtree root
	if(treePtr->leftPtr == NULL)
	{
		treePtr = treePtr->rightPtr;
		delete deletePtr;
	}
	//if right subtree DNE, replace root with left subtree root
	else if(treePtr->rightPtr == NULL)
	{
		treePtr = treePtr->leftPtr;
		delete deletePtr;
	}
	//find largest node in left subtree & replace
	else 
	{
		data = GetPredecessor(treePtr->leftPtr);
		treePtr->data = data;
		Delete(treePtr->leftPtr, data);
	}
	
}

template<typename SomeType>
void BSTree<SomeType>::Insert(BSTreeNode<SomeType>*& ptr, SomeType item)
{
	//base condition
	if (ptr == NULL)
	{
		//fills null node with new item
		ptr = new BSTreeNode<SomeType>;
		ptr -> rightPtr = NULL;
		ptr -> leftPtr = NULL;
		ptr -> data = item;
	}
	
	//recursive calls
	else if (item < ptr -> data)
		Insert(ptr->leftPtr, item);
	else if (item > ptr->data)
		Insert(ptr->rightPtr, item);
	else if (item == ptr->data)
		throw FoundInBSTree();
}

template<typename SomeType>
void BSTree<SomeType>::Destroy(BSTreeNode<SomeType>*& ptr)
{
	//destroys entire tree
	if(ptr != NULL)
	{
		Destroy(ptr->leftPtr);
		Destroy(ptr->rightPtr);
		delete ptr;
	}
	
}

template<typename SomeType>
void BSTree<SomeType>::CopyTree(BSTreeNode<SomeType>*& copy, const BSTreeNode<SomeType>* originalTree)
{
	if (originalTree == NULL)
		copy = NULL;
	else 
	{
		//copies data at node
		copy = new BSTreeNode<SomeType>;
		copy->data = originalTree->data;
		
		//Recursively calls to copy all the children in the tree
		CopyTree(copy->leftPtr, originalTree->leftPtr);
		CopyTree(copy->rightPtr, originalTree->rightPtr);
	}
}

template<typename SomeType>
SomeType BSTree<SomeType>::GetPredecessor(BSTreeNode<SomeType>* treePtr) const
{
	//returns largest value in left subtree
	while(treePtr->rightPtr != NULL)
		treePtr = treePtr->rightPtr;
	return treePtr->data;
	
}

template<typename SomeType>
int BSTree<SomeType>::CountNodes(BSTreeNode<SomeType>* treePtr) const
{
	//base condition
	if (treePtr == NULL)
		return 0;
	//recursive call
	else
		return CountNodes(treePtr->leftPtr) + CountNodes(treePtr->rightPtr) + 1;
}

template<typename SomeType>
int BSTree<SomeType>::LevelCount(BSTreeNode<SomeType>* treePtr) const
{
	
	if (treePtr ==NULL)
		return 0;
	//if tree isn't null, find maximum value of tree height
	else 
		return 1 + max(LevelCount(treePtr->leftPtr), LevelCount(treePtr->rightPtr));
}

template<typename SomeType>
int BSTree<SomeType>::FindLevel(BSTreeNode<SomeType>* treePtr, SomeType item) const
{
	
	
	
	if(treePtr->data > item)
		return 1 + FindLevel(treePtr->leftPtr, item);
	else if(treePtr->data < item)
		return 1 + FindLevel(treePtr->rightPtr, item);
	else if (treePtr->data == item)
		return 0;
	else 
		throw NotFoundBSTree();
	
	
	
}

template<typename SomeType>
void BSTree<SomeType>::SearchForParent(BSTreeNode<SomeType>* treePtr, SomeType item) const
{
	
	if(treePtr == NULL)
		throw NotFoundBSTree();
	else if (item == treePtr->data)
		return;
	else if (item > treePtr->data)
		SearchForParent(treePtr->rightPtr, item);
	else if (item < treePtr->data)
		SearchForParent(treePtr->leftPtr, item);
	else 
		throw NotFoundBSTree();
	
	throw treePtr->data;
	
}

//Public Member Functions ----------------------------------------------

//constructor
template <typename SomeType>
BSTree<SomeType>::BSTree()
{
	rootPtr = NULL;
}

template<typename SomeType>
BSTree<SomeType>::BSTree(const BSTree<SomeType>& someTree)
{
	CopyTree(rootPtr, someTree.rootPtr);
}

template<typename SomeType>
void BSTree<SomeType>::operator=(const BSTree<SomeType>& originalTree)
{
	CopyTree(rootPtr, originalTree.rootPtr);
}

template<typename SomeType>
BSTree<SomeType>::~BSTree()
{
	MakeEmpty();
}

template<typename SomeType>
void BSTree<SomeType>::InsertItem(SomeType item)
{
	
	if(IsFull())
		throw FullBSTree();
		
	Insert(rootPtr, item);	
	
}

template<typename SomeType>
SomeType BSTree<SomeType>::DeleteItem(SomeType item)
{
	
	if(IsEmpty())
		throw EmptyBSTree();
	
	Delete(rootPtr, item);
}

template<typename SomeType>
void BSTree<SomeType>::MakeEmpty()
{
	Destroy(rootPtr);
	rootPtr = NULL;
	
}

template<typename SomeType>
int BSTree<SomeType>::Size() const
{
	return CountNodes(rootPtr);
}

template<typename SomeType>
bool BSTree<SomeType>::IsFull() const
{
	//try to allocate another item
	BSTreeNode<SomeType>* temp;
	
	try 
	{
		temp = new BSTreeNode<SomeType>;
		delete temp;
		return false;
	}
	catch(std::bad_alloc exception)
	{
		return true;
	}
}

template<typename SomeType>
bool BSTree<SomeType>::IsEmpty() const
{
	if(rootPtr == NULL)
		return true;
	return false;
}

template<typename SomeType>
SomeType BSTree<SomeType>::Min() const
{
	//Finds leftmost item in tree
	BSTreeNode<SomeType>* tempPtr = rootPtr;
	if (tempPtr == NULL)
		throw EmptyBSTree();
		
	while(tempPtr->leftPtr != NULL)
	{
		tempPtr = tempPtr->leftPtr;
	}
	return tempPtr->data;
}

template<typename SomeType>
SomeType BSTree<SomeType>::Max() const
{
	//Finds rightmost item in BST
	BSTreeNode<SomeType>* tempPtr = rootPtr;
	if (tempPtr == NULL)
		throw EmptyBSTree();
		
	while(tempPtr->rightPtr != NULL)
	{
		tempPtr = tempPtr->rightPtr;
	}
	return tempPtr->data;
}

template<typename SomeType>
int BSTree<SomeType>::TotalLevels() const
{
	return LevelCount(rootPtr);
}

template<typename SomeType>
int BSTree<SomeType>::Level(SomeType item) const
{
	if(IsEmpty())
		throw EmptyBSTree();
	return FindLevel(rootPtr, item);
	
}

template<typename SomeType>
SomeType BSTree<SomeType>::Parent(SomeType item)
{
	if(IsEmpty())
		throw EmptyBSTree();
	if(rootPtr->data == item)
		throw NoParentBSTree();
	
	
	//find parent
	try
	{
		SearchForParent(rootPtr, item);
	}
	catch(NotFoundBSTree)
	{
		throw NotFoundBSTree();
	}
	catch (SomeType parent) 
	{
		return parent;
	}
	


	
}