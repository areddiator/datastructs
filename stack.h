/*
* stack.h
*/

template<class T, int maxLen>
class Stack
{
private:
T* m_stackImpl;
int m_maxSize;
int m_topIndex;

public: // constructor
Stack(int len);

public: // istack
	T pop();
	T push(T obj);
	T top();

public: // idatastruct
	void printStack();
};
