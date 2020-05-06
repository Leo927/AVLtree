#pragma once
#include "BinaryTree.h"
#include <cassert>
using namespace std;
template<typename T>
class BinarySearchTree: public Tree<T,2>
{
private:
	typedef Tree<T, 2> sTree;
	typedef Node<T, 2> BinaryNode;
	enum Child {left =0,right =1};
public:
	BinarySearchTree() :Tree<T,2>() {}
	template<typename ... Types>
	void append(const T& data, Types ... args);

	void append(const T& data);
	void remove(const T& data);
	bool contains(const T& data);
private:
	void append(BinaryNode*, const T& data);
	bool invariant() const;
	bool invariant(BinaryNode* node)const;
};

template<typename T>
inline void BinarySearchTree<T>::append(const T& data)
{
	assert(invariant());
	if (sTree::rootPtr == NULL)
	{
		sTree::rootPtr = new BinaryNode(data);
		return;
	}
	append(sTree::rootPtr, data);
	assert(invariant());
}

template<typename T>
inline void BinarySearchTree<T>::remove(const T& data)
{

}

template<typename T>
inline void BinarySearchTree<T>::append(BinaryNode* node, const T& data)
{
	Child next = data < node->getData() ? left : right;
	BinaryNode* nextNode = (next == left ? node->left() : node->right());
	if (node->getData() == data) return;
	if (nextNode == nullptr)
	{
		next == left ? node->setPointer(new BinaryNode(data),0) : node->setPointer(new BinaryNode(data), 1);
		return;		
		
	}
	append(nextNode, data);
}

template<typename T>
inline bool BinarySearchTree<T>::invariant() const
{
	return invariant(sTree::rootPtr);
}

template<typename T>
inline bool BinarySearchTree<T>::invariant(BinaryNode* node) const
{
	if (node == nullptr) return true;
	bool result = true;
	if (node->left()!=nullptr)
		result &= (node->left()->getData() <= node->getData());
	if (node->right() != nullptr)
		result &= (node->right()->getData() >= node->getData());
	return result && invariant(node->left()) && invariant(node->right());
}

template<typename T>
template<typename ... Types>
inline void BinarySearchTree<T>::append(const T& data, Types ...args)
{
	append(data);
	append(args...);
}
