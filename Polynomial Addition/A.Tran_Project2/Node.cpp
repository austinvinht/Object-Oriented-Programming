#include <iostream>
using namespace std;
#include "Node.h"
Node::Node(int c, int e)
{
	coefficient = c;
	exponet = e;
	next = nullptr;
	prev = nullptr;
}
