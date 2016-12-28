#pragma once

// node

//template<class T>
//struct tnode;
// do not need to typedef structs in C++

template<class T>
struct NODE{

  T data;
  NODE<T> * next;

};

/*
   single linked list
 */
template <class T>
class CSingleLinkedList
{
  public: 
	NODE<T> * root;

  public:
	CSingleLinkedList();

  public: // IDynamicSet
	NODE<T> * Insert(T const & val);
	T * Delete(NODE<T> * node);
	int Print()const;

	NODE<T> * Search(T val)const;
};
