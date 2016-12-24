#include <ostream>
#include "stack.h"

Stack<T>::Stack<T>(int len): m_maxSize(len), m_topIndex(0)
{
    m_stackImpl = NULL;
    m_stackImpl = new T(maxSize * size of(T));
}

Stack::~Stack()
{
    if(m_stackImpl != NULL)
    {
        delete m_stackImpl;
    }	
}

/*
delete the top index unless there is an underflow
return popped element.
*/
T Stack<T>::pop()
{
    T popped;

    if(topIndex >= 0){
        popped = *(m_stackImpl + m_topIndex);
        --m_topIndex;
    }

    return popped;
}

/*
push: insert obj T unless there is an overflow
*/
T Stack::push(T obj)
{
    if(m_topIndex +1 < m_maxSize)
    {
        m_stackImpl[++m_topIndex]= obj;

    }
    else{
         return NULL;
    }

    return m_stackImpl[m_topIndex];
}

T Stack::top()
{
    if(m_topIndex < 0) return default(T);
    return 
}

void Stack::printStack()
{
    for(int i= 0; i < m_topIndex ; ++i)
    {
        std::cout<< *(m_stackImpl+_i);
    }

    std::cout<<std::endl;
}
