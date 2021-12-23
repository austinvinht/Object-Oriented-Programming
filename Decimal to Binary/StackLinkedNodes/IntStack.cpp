#pragma once
#include "IntStack.h"
#include <iostream>
using namespace std;

IntStack::IntStack()
{
	stack_top = nullptr;
	stack_size = 0;
}

bool IntStack::empty() 
{
	if (stack_size != 0)
		return false;
	else
		return true;
}

void IntStack::push(Node* item)
{
	if (stack_top == nullptr)
	{
		stack_top = item;
	}
	else
	{
		item->next = stack_top; //new node to top
		stack_top = item;
		
	}
	stack_size++;
	//cout << stack_top ->data << " ";

}
Node* IntStack :: pop()
{
	if (!empty())
	{
		Node* popped_node = stack_top;
		stack_size--;
		stack_top = stack_top->next;
		return popped_node;
	}
	else
	{
		cout << "The stack is empty\n";
		return nullptr;
	}
}

void IntStack::display()
{
	if (!empty())
	{
		Node* current_node;
		current_node = stack_top;
		while (current_node != nullptr)
		{
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
	}
	else
		cout << "The stack is empty\n";
}
