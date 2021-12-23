#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"

DLL::DLL() {
    first = nullptr;
    listsize;

}
bool DLL::empty()
{
    if (first == nullptr)
        return true;
    else
        return false;
}

void DLL::insert(Node* newnode) {
    if (first == nullptr)
        first = newnode;
    else
    {
        first->prev = newnode;
        newnode->next = first;
        first = newnode;
    }
}
void DLL::insert(Node* newnode, Node* pred)
{
    if (pred->next != nullptr)
    {
        pred->next->prev = newnode;
        newnode->next = pred->next;
    }
    pred->next = newnode;
    newnode->prev = pred;
}
void DLL::addpoly(Node* p1, Node* p2, Node* p)
{

    while (p1->next && p2->next)
    {
        // Same exponet
        if (p1->exponet == p2->exponet)
        {
            p->exponet = p1->exponet;
            p->coefficient = p1->coefficient + p2->coefficient;
            p1 = p1->next;
            p2 = p2->next;
        }
        // if poly 2 exponet is larger than poly 1 exponet
        else if (p1->exponet < p2->exponet)
        {
            p->exponet = p1->exponet;
            p->coefficient = p1->coefficient;
            p1 = p1->next;
        }
        // if poly 1 exponet is larger than poly 2 exponet
        else if (p1->exponet > p2->exponet)
        {
            p->exponet = p2->exponet;
            p->coefficient = p2->coefficient;
            p2 = p2->next;
        }


        // Dynamically create new node
        p->next = (struct Node*)malloc(sizeof(struct Node));
        p = p->next;
        p->next = nullptr; //ground
    }
    while (p1->next || p2->next)
    {
        if (p1->next)
        {
            p->exponet = p1->exponet;
            p->coefficient = p1->coefficient;
            p1 = p1->next;
        }
        if (p2->next)
        {
            p->exponet = p2->exponet;
            p->coefficient = p2->coefficient;
            p2 = p2->next;
        }
        p->next = (struct Node*)malloc(sizeof(struct Node));
        p = p->next;
        p->next = nullptr; //ground
    }
}


void DLL::out(struct Node* node)
{


    while (node->next != nullptr) {
        cout << node->coefficient << "x^" << node->exponet;
        node = node->next;
        if (node->next != nullptr)
        {
            cout << " + ";
        }
    }
}


/*void DLL::erase(Node* n) {
    if (n->prev == nullptr)
    {
        first = n->next;
    }
    else
    {
        n->prev->next = n->next;
    }
    if (n->next == nullptr)
    {
        n->prev->next = nullptr;
    }
    else
    {
        n->next->prev = n->prev;
    }
    n->prev = nullptr;
    n->next = nullptr;
}*/




void DLL::display(Node* current1)
{
    if (current1 == nullptr)
    {
        cout << "The list is empty\n";
    }; //empty list
    while (current1->next != nullptr)
    {
        current1 = current1->next; //going to last node
        listsize++;
    }

    while (current1 != nullptr)
    {
        cout << current1->coefficient << "x^" << current1->exponet;
        if (listsize > 0)
        {
            cout << " + ";
        }
        current1 = current1->prev;
        listsize--;
    }
}
