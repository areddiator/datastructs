#pragma once

// node

<template class T>
typedef struct tnode{

T data;
struct tnode * next;

}NODE;

/*
single linked list
*/
<template class T>
class CSingleLinkedList<T>
{
private: 
    NODE<T> * root;

public:
    CSingleLinkedList<T>();

public: // IDynamicSet
    NODE<T> * Insert(T val);
    T Delete(NODE<T> * node);
    int Print();
};
