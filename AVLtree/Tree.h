#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "Buffer.h"
using namespace std;

template<typename T, int linkSize>
class Tree
{
private:
	typedef Node<T, linkSize> treeNode;
protected:	
	treeNode* rootPtr;	
public:
	enum PrintOrder { PREORDER, INORDER, POSTORDER, LEVEL, TREE};
public:
	Tree();
	Tree(const T& newRoot);
	~Tree();
	
	
	void append(const T& data, const std::vector<int>& position);
	void print(PrintOrder order);
	
private:
	void DestoryRecursive(Node<T,linkSize>*);
	void printPreOrder(treeNode*);
	void printInOrder(treeNode*);
	void printPostOrder(treeNode*);
	void printLeveled(treeNode*);
	void printTree(treeNode*);
	void printTree(treeNode*, Buffer* buffer);
	int width(int n);
	int depth(int n);
	int layerCount()const;
	int depthRecur(treeNode* node)const;
};

template<typename T, int linkSize>
inline Tree<T, linkSize>::Tree()
{
	rootPtr = nullptr;
}

template<typename T, int linkSize>
inline Tree<T, linkSize>::Tree(const T& newRoot)
{
	append(newRoot, std::vector<int>());
}

template<typename T, int linkSize>
inline Tree<T, linkSize>::~Tree()
{
	DestoryRecursive(rootPtr);
}
template<typename T, int linkSize>
inline int  Tree<T, linkSize>::width(int n)
{
	int result = 0;
	for (size_t i = 0; i <= n; i++)
	{
		result = 2 * result + 1;
	}
	return result;
}
template<typename T, int linkSize>
inline int Tree<T, linkSize>::depth(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	return  depth(n - 1) + width(n - 1) / 2 + 2;
}
//
template<typename T, int linkSize>
inline void Tree<T, linkSize>::append(const T& data, const std::vector<int>& position)
{
	if (position.empty())
	{
		rootPtr = new treeNode(data);
		return;
	}
	Node<T, linkSize>* insertPos = rootPtr;
	for (size_t i = 0; i < position.size() && insertPos!= nullptr; i++)
	{
		insertPos = insertPos->getPointer(position[i]);
	}
	if (insertPos == nullptr )
	{
		return;
	}
	insertPos->setPointer(new treeNode(data), position.back());
}

template<typename T, int linkSize>
inline void Tree<T, linkSize>::print(Tree<T,linkSize>::PrintOrder order)
{
	switch (order)
	{
	case PREORDER:
		printPreOrder(rootPtr);
		break;
	case INORDER:
		printInOrder(rootPtr);
		break;
	case POSTORDER:
		printPostOrder(rootPtr);
		break;
	case LEVEL:
		printLeveled(rootPtr);
		break;
	case TREE:
		printTree(rootPtr);
		break;
	default:
		cout << "Incorrect print type. \n";
		break;
	}
}



template<typename T, int linkSize>
inline void Tree<T, linkSize>::DestoryRecursive(Node<T,linkSize>* node)
{
	if (node == nullptr) return;
	for (size_t i = 0; i < linkSize; i++)
	{
		DestoryRecursive(node->getPointer(i));
	}
	if (node != nullptr) delete node;
}

template<typename T, int linkSize>
inline void Tree<T, linkSize>::printPreOrder(treeNode* node)
{
	if (node == nullptr)return;
	cout << (*node) << endl;
	for (size_t i = 0; i < linkSize; i++)
	{
		printPreOrder(node->getPointer(i));
	}
}

template<typename T, int linkSize>
inline void Tree<T, linkSize>::printInOrder(treeNode* node)
{
	if (linkSize != 2) {
		cout << "Inorder traversal makes no sense except for binary tree \n";
		return;
	}
	if (node == nullptr)return;
	printInOrder(node->getPointer(0));
	for (size_t i = 1; i < linkSize; i++)
	{
		cout << (*node) << endl;
		printInOrder(node->getPointer(i));
	}
}

template<typename T, int linkSize>
inline void Tree<T, linkSize>::printPostOrder(treeNode* node)
{
	if (node == nullptr)return;	
	for (size_t i = 0; i < linkSize; i++)
	{
		printPreOrder(node->getPointer(i));
	}
	cout << *node << endl;
}

template<typename T, int linkSize>
inline void Tree<T, linkSize>::printLeveled(treeNode*)
{
}

template<typename T, int linkSize>
inline void Tree<T, linkSize>::printTree(treeNode*)
{
	Buffer<depth(layerCount()), width(layerCount())> buffer();
	

}



template<typename T, int linkSize>
inline void Tree<T, linkSize>::printTree(treeNode*, Buffer<depth(layerCount() , width(layerCount()) >* buffer)
{
}



template<typename T, int linkSize>
inline int Tree<T, linkSize>::layerCount()const
{
	return depthRecur(rootPtr);

}

template<typename T, int linkSize>
inline int Tree<T, linkSize>::depthRecur(treeNode* node)const
{
	if (node == nullptr) return 0;
	int maxSubTreeSize = 0;
	int temp =0;
	for (treeNode* child : node->getPointers())
	{
		maxSubTreeSize = std::max(depthRecur(child), maxSubTreeSize);
	}
	return maxSubTreeSize + 1;
}

