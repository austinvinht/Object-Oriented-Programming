#include <iostream>
using namespace std;
#include "OpStack.h"

OpStack::OpStack()
{
    stack_top_index = 0;
}

bool OpStack::empty()
{
    if (stack_top_index == 0)
        return true;
    else
        return false;
}

void OpStack::push(OPStackElement item)
{
    if (stack_top_index == CAPACITY)
        cout << "\nstack is full\n";
    else
    {
        stackArray[stack_top_index] = item;
        stack_top_index++;
    }
}

OPStackElement OpStack::pop()
{
    OPStackElement item = 0;
    stack_top_index--;
    if (stack_top_index >= 0)
        item = stackArray[stack_top_index];
    else
        cout << "\n\n";
    return item;
}
OPStackElement OpStack::top()
{
    OPStackElement item = 0;
    item = stackArray[stack_top_index-1];
    return item;
}

void OpStack::display()
{
    int current_index = stack_top_index - 1;
    for (int i = current_index; i >= 0; i--)
    {
        cout << stackArray[i] << ", ";
    }
}

