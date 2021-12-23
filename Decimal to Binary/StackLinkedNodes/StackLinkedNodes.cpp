#include <iostream>
using namespace std;
#include "IntStack.h"
#include "Node.h"
int main()
{
    int n = 0, quotient = 0, remainder = 0, counter = 0;
    cout << "Enter an integer to convert to binary: ";
    cin >> n;
    quotient = n;
    IntStack mystack;
    
    while (quotient > 1)
    {
        Node* r = new Node(0);
        Node* q = new Node(0);
        r = new Node(remainder = quotient % 2);
        q = new Node(quotient = quotient / 2);
        mystack.push(r);
        counter++;
        if (quotient == 1)
        {
            mystack.push(q);
        }
    }
 
    cout << "\nThe binary number for " << n << " is: ";
    mystack.push(mystack.pop());
    mystack.display();
    cout << endl;

    return 0;
}

