#pragma once
//#include <vector>
#include <functional>
using namespace std;
#define MYDEBUG 0
// linked list for chaining
template<class T>
struct HNODE
{
  T data;
  HNODE<T> * next; 

  HNODE()
  {
	next = nullptr;
	data = T();
  }

  HNODE(const T & val)
  {
	next = nullptr;
	data = val;
  }
};

// actual hash entry
// hash table = array of hash entries
template <class T>
struct HASHENTRY
{
  int key;
  HNODE<T> * pLLRootedAtKey;
  HASHENTRY()
  {
	key = 0;
	pLLRootedAtKey = nullptr;
  }
};

  // array of hash entries
  // arr[key] = address of linked list containing data hashing to the same key
template <class T>
class HashTab
{
  private: 
static  const int hash_func_a = 17;
static  const int hash_func_m = 1009;

  private:
  HASHENTRY<T> * m_arrHashEntryTable;
  unsigned int m_uHashSize;

  int resize();

  // default hash function 
  static unsigned int hash_func(const T & val);

  public:
  // lifecycle
  HashTab(unsigned int size=10);
  ~HashTab();
  //IDynamicSet

  // insert using default hash fucntion
  int Insert(const T &val);
  int Insert(const T& val, std::function <unsigned int (const T & val)> hashFuncObj);

  // returns true if val is found, false otherwise
  bool Query(const T & val)const;

  // remove value from hash table
  bool Delete(const T & val);
  
  // print
  void Print()const;
  
};
