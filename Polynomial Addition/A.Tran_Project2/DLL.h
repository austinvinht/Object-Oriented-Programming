#pragma once
#include "Node.h"
class DLL
{
public: Node* first;
      int listsize;
      DLL();
      bool empty();
      void insert(Node* newnode);
      void insert(Node* newnode, Node* pred);
      //void erase(Node* node_to_be_deleted);
      void display(Node* Node);
      void addpoly(Node* p1, Node* p2, Node* p);
      void out(struct Node* node);

};
