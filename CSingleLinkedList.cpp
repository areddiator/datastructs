#include "CSingleLinkedList.h"
#include <iostream>
#include <cstdlib>
// constructor

template <class T>
CSingleLinkedList<T>::CSingleLinkedList(){
  root = NULL;
}

///*
///  Insert: Insert a new node at the beginning
///		  of the list.
///  InParam: Value to be inserted
///  Returns: new root
///
///*/
  template <class T>
NODE<T> * CSingleLinkedList<T>::Insert (T const & val)
{
  // create a new node with data = val
  NODE<T> * temp = new NODE<T>();
  temp -> data = val;

  if(root != NULL)
  {
	// add to the beginning of the list
	temp-> next = root;
  }

  // we have a new root
  root = temp;

  return root;
}



///*
///   Deletes single linked list node
///Inparam: pointer to node to be deleted
///Returns: the value of the node just deleted OR
///NULL if node was not found 

//Remarks: The value returned should be checked by the caller
//that the right node was deleted
/// */ 
  template <class T>
T * CSingleLinkedList<T>::Delete(NODE<T> * node)
{
  //if root = null aka empty list
  if(root == NULL)
  {
	return NULL;
  }

  // if first node
  // if middle node
  if(node-> next != NULL)
  {
	T tempData = node -> data;
	NODE<T> * temp = node -> next;
	node -> next = temp -> next;
	node -> data = temp -> data;
	delete node -> next;
	node -> next = temp -> next;
	temp = NULL;

	return &tempData;
  }
  else{
	// if last node 
	T tempData = node -> data;
	delete node;

	return &tempData;
  }
}

///*
///  Print the linked list
///   
/// */
template<class T>
int CSingleLinkedList<T>::Print() const
{
  NODE<T> * temp = root;
  while(temp && temp -> next)
  {
	std::cout << temp-> data << " ";
	temp = temp -> next;
  }

  std::cout<<std::endl;
}

template<class T>
NODE<T> * CSingleLinkedList<T>::Search(T val) const
{
  NODE<T> * temp = root;
  while(temp)
  {
	if(temp-> data == val)
	{		
	  return temp;
	}

	temp = temp -> next;
  }
  return NULL;
}

int main()
{
  std::cout<<" hello";

  CSingleLinkedList<int> list;
  // insert driver
  for(int i = 0 ; i < 20; ++i)
  {
	list.Insert(rand() % 453);
  }

  // print test
  list.Print();
  std::cout<<"\n"; 
  // search driver
  for(int i = 0; i< 5; i++)
  {
	int val = rand() % 453;

	if(i == 4)
	{
	 // val = root -> x;
	}
	if(NULL == list.Search(val)){
	  std::cout<<"\n[" << i << "] NOT Found "<< val<< std::endl;
	}
	else
	{
	  std::cout<<"\n["<< i << "]  found " << val<< std::endl;
	}
  }

  // delete driver
  list.Delete(list.root);
  list.Print();
  std::cout<<"\n"; 
  list.Delete(list.root);
  list.Delete(list.root);

  list.Print();

  // edge cases
  // delete last element
  //NODE<int> * temp = root;
  //while(temp->next)
  //{
//	temp = temp-> next;	
 // }

 // std::cout<< "\nDeleting %d\n", temp -> data;
 // list.Delete(temp);

  list.Print();
  std::cout<<"\n"; 
} 
