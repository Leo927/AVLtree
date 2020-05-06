#pragma once
#include "Node.h"
template<typename T>
class BinaryNode :
	public Node<T, 2>
{
public:
	BinaryNode();
	BinaryNode(T);
	BinaryNode(T, BinaryNode*, BinaryNode*);
	BinaryNode<T>* getLeft() const;
	BinaryNode<T>* getRight() const;
	void setLeft(BinaryNode* pointer);
	void setRight(BinaryNode* pointer);
};

template<typename T>
inline BinaryNode<T>::BinaryNode():Node<T,2>()
{
}

template<typename T>
inline BinaryNode<T>::BinaryNode(T data):Node<T,2>(data)
{
}

template<typename T>
inline BinaryNode<T>::BinaryNode(T data, BinaryNode* left, BinaryNode* right)
{
	Node<T, 2>::setData(data);
	setLeft(left);
	setRight(right);
}

template<typename T>
inline BinaryNode<T>* BinaryNode<T>::getLeft() const
{
	return Node<T, 2>::getPointer(0);
}

template<typename T>
inline BinaryNode<T>* BinaryNode<T>::getRight() const
{
	return Node<T,2>::getPointer(1);
}

template<typename T>
inline void BinaryNode<T>::setLeft(BinaryNode* pointer)
{
	Node<T,2>::setPointer(pointer, 0);
}

template<typename T>
inline void BinaryNode<T>::setRight(BinaryNode* pointer)
{
	Node<T,2>::setPointer(pointer, 1);
}
