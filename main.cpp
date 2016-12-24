#include <iostream>
#include "stack.h"

int main(int argc, char **argv)
{
    Stack<int, 10> firstStack;

    for(int i =0; i< 10; ++i)
    {
        firstStack.push(i*298923 % 3422);
    }

    firstStack.printStack();


    return 0;
}
