#pragma once

template <class T>
typedef struct llNode
{
    T data;
    struct llNode * next;
}LLNODE;


template<class T, class Y>
class CLinkedList
{
    public:
    T * InsertFront(Y value);    
    int Delete(T * node);
    int EnumerateList(const T & node);
};
