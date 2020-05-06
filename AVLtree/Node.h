#pragma once
#include <vector>
#include <iostream>
using namespace std;
template<typename T, int pointerCount>
class Node
{
protected:
	T data;
	std::vector<Node*> pointers;
public:
	Node();
	Node(T data);
	template<typename ... Types>
	Node(T data, Types ... args);
	Node* getPointer(int) const;
	const std::vector<Node*>& getPointers() const;
	std::vector<Node*>& getPointers();
	void setPointer(Node*, int);
	const T& getData() const;
	void setData(const T& data);
	Node<T, pointerCount>* left() const;
	Node<T, pointerCount>* right() const;
	
private:
	void append(Node* pointer);
	template<typename ... Types>
	void append(Node* pointer, Types ... args);
	
};

template<typename T, int pointerCount>
inline Node<T, pointerCount>::Node()
{
	data = T();
	pointers = std::vector<Node*>(pointerCount, nullptr);
}

template<typename T, int pointerCount>
inline Node<T, pointerCount>::Node(T data)
{
	this->data = data;
	pointers = std::vector<Node*>(pointerCount, nullptr);
}




template<typename T, int pointerCount>
inline Node<T,pointerCount>* Node<T, pointerCount>::getPointer(int index) const
{
	return pointers.at(index);
}

template<typename T, int pointerCount>
inline const std::vector<Node<T,pointerCount>*>& Node<T, pointerCount>::getPointers() const
{
	return pointers;
}

template<typename T, int pointerCount>
inline std::vector<Node<T,pointerCount>*>& Node<T, pointerCount>::getPointers()
{
	return pointers;
}

template<typename T, int pointerCount>
inline void Node<T, pointerCount>::setPointer(Node* pointer, int position)
{
	pointers.at(position) = pointer;
}



template<typename T, int pointerCount>
inline const T& Node<T, pointerCount>::getData() const
{
	return data;
}

template<typename T, int pointerCount>
inline void Node<T, pointerCount>::setData(const T& data)
{
	this->data = data;
}

template<typename T, int pointerCount>
inline Node<T,pointerCount>* Node<T, pointerCount>::left() const
{
	return pointers.at(0);
}

template<typename T, int pointerCount>
inline Node<T, pointerCount>* Node<T, pointerCount>::right() const
{
	return pointers.at(pointerCount-1);
}

template<typename T, int pointerCount>
inline void Node<T, pointerCount>::append(Node* pointer)
{
	pointers.push_back(pointer);
	Node::emptyPointerCount = pointerCount - pointers.size();
	for (size_t i = 0; i < Node::emptyPointerCount; i++)
	{
		pointers.push_back(nullptr);
	}
}

template<typename T, int pointerCount>
template<typename ...Types>
inline Node<T, pointerCount>::Node(T data, Types ...args)
{
	this->data = data;
	append(args ...);
}

template<typename T, int pointerCount>
template<typename ... Types>
inline void Node<T, pointerCount>::append(Node* pointer, Types ...args)
{
	append(pointer);
	append(args...);
}

template<typename T, int pointerCount>
inline std::ostream& operator<<(std::ostream& os, const Node<T, pointerCount>& output)
{
	os << output.getData();
	return os;
}