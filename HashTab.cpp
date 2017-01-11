#include "HashTab.h"
#include <iostream>
using namespace std;
unsigned int hashmy(const int & valu)
{
  return valu%10;
}
int main()
{

  HashTab<int> htTable;
  htTable.Print();
  std::cout<<"Done empty print"<<endl;

  htTable.Insert(10);
  htTable.Print();
  std::cout<<"Done first element  print"<<endl;
 
  // add second element 
  htTable.Insert(13);
  htTable.Print();
  std::cout<<"Done second element print"<<endl;

  // add duplicate element
  htTable.Insert(10);
  htTable.Print();
  std::cout<<"Done duplicate print"<<endl;


  // add hash to the same bucket
  htTable.Insert(1019);
  htTable.Print();
  std::cout<<"Done collision print"<<endl;
  
  // add hash to the same bucket
  htTable.Insert(36);
  htTable.Print();
  std::cout<<"Done 5th element print"<<endl;

  for(int i = 0; i < 100; i++)
  {
	htTable.Insert(13 * i % 1001);
  }

  htTable.Print();

  // insert with different hash function
  std::function<unsigned int(const int & val)> myFun = hashmy;
  htTable.Insert(171, myFun);
  htTable.Print();


  // queries
  std::cout<<"Query(10) :" <<  htTable.Query(10)<<endl;
  std::cout<<"Query(210) :" <<  htTable.Query(210)<<endl;
  std::cout<<"Query(286) :" <<  htTable.Query(286)<<endl;;
}


// constructor
template<class T>
HashTab<T>::HashTab(unsigned int size) : m_uHashSize(size)
{
  m_arrHashEntryTable = new HASHENTRY<T>[m_uHashSize];
}

template<class T>
HashTab<T>::~HashTab()
{
  for(int i = 0; i < m_uHashSize; i++)
  {
/*	HASHENTRY<T> tempHashEntry = m_arrHashEntryTable[i];

	// delete the linked list created for chaining
	HNODE<T> * temp = tempHashEntry uu	while(temp)
	while(temp)
	{
	  HNODE<T> *nextTemp = temp->next;
	  delete temp;
	  temp = nextTemp;
	}

//	m_arrHashEntryTable[i] = NULL;
  */
  }
  delete m_arrHashEntryTable;

}

template<class T>
int HashTab<T>::Insert(const T & val)
{
  // 1. get hash
  //this->Insert(val, hash_func);
  Insert(val, hash_func);
}

template<class T>
int HashTab<T>::Insert(
	  const T& val,
	  std::function < unsigned int(const T & val)> hashFuncObj)
{
  int index = hashFuncObj(val);


  std::cout<< val << " indexed to " << index;
  index %= m_uHashSize;

  // 1b: create a new node with val
  HNODE<T> * newNode = new HNODE<T>(val);

  std::cout<<endl<<" Inserting " << val << " at index: " << index;
  std::cout<<endl<<" after: " << newNode->data << " at index: " << index;
  // 2. insert at root of linked list 
  if(m_arrHashEntryTable[index].pLLRootedAtKey == nullptr)
  {
	// first element
	std::cout<< val << " first element created" <<endl;
	 m_arrHashEntryTable[index].pLLRootedAtKey = newNode;
	 m_arrHashEntryTable[index].key = newNode->data;
  }
  else
  {
	// insert at the beginning
	newNode -> next = m_arrHashEntryTable[index].pLLRootedAtKey;
	m_arrHashEntryTable[index] . pLLRootedAtKey = newNode;
  }

  std::cout<<" value of root at index: "<< index << "  = " << m_arrHashEntryTable[index].pLLRootedAtKey->data;
}

template<class T>
bool HashTab<T>::Query(const T & val) const
{
  int index = hash_func(val);
  index %= m_uHashSize;

  if(m_arrHashEntryTable[index].pLLRootedAtKey == nullptr)
  {
	return false;
  }

  HNODE<T> * tempNode = m_arrHashEntryTable[index].pLLRootedAtKey;
  while(tempNode)
  {
	if(tempNode->data == val)
	{
	  return true;
	}

	tempNode = tempNode-> next;
  }

  return false;

}

template<class T>
bool HashTab<T>::Delete(const T & val)
{
  int index = hash_func(val);
  index %= m_uHashSize;

  if(m_arrHashEntryTable[index].pLLRootedAtKey == nullptr)
  {
	return false;
  }
/*
  HNODE<T> * tempNode = m_arrHashEntryTable[index].pLLRootedAtKey;
  while(tempNode && tempNode->next)
  {
	if(tempNode->data == val)
	{
	  return true;
	}

	tempNode = tempNode-> next;
  }
*/
  return false;
}

template<class T>
void HashTab<T>::Print() const
{
  std::cout << endl << " ***** Print : "<< m_uHashSize << " ****"<<endl;
  // go thru the table
  for(int i = 0; i < m_uHashSize; ++i)
  {
	HASHENTRY<T> he = m_arrHashEntryTable[i];

	// are any elements stored at key
	if(he.pLLRootedAtKey == nullptr) continue;

	// print key
	std::cout<< "Key:" << he.key << " Elements: ";
	// go thru the linked list
	HNODE<T> * temp = he.pLLRootedAtKey;
	
	while(nullptr != temp)
	{
	  std::cout<< temp->data<< "\t";
	  temp = temp -> next;	
	}

	std::cout<<endl;
  }

  std::cout << endl << " ***** End Print ****"<<endl;
}

template<class T>
int HashTab<T>::resize()
{
}

template<class T>
unsigned int HashTab<T>::hash_func(const T & val) 
{
  // using modular prime method 
  unsigned int hash = hash_func_a * val % hash_func_m;
  return hash;
}
