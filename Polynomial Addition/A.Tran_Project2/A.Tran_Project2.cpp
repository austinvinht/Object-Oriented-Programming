#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"
int main()
{
    struct Node* result = NULL;

    DLL p, p2, r, x1, x2;
    Node* p1_1 = new Node(1, 0);
    Node* p1_2 = new Node(2, 3);
    Node* p1_3 = new Node(3, 12);
    Node* p1_4 = new Node(4, 25);
    Node* p1_5 = new Node(5, 99);
    Node* p1_6 = new Node(0, 99); //dummy
    Node* p2_1 = new Node(1, 0);
    Node* p2_2 = new Node(9, 4);
    Node* p2_3 = new Node(13, 12);
    Node* p2_4 = new Node(0, 25); //dummy
    Node* p2_5 = new Node(0, 99); //dummy


    p.insert(p1_1);
    p.insert(p1_2, p1_1);
    p.insert(p1_3, p1_2);
    p.insert(p1_4, p1_3);
    p.insert(p1_5, p1_4);
    p2.insert(p2_1);
    p2.insert(p2_2, p2_1);
    p2.insert(p2_3, p2_2);
    cout << "\n";
    cout << "P1(x)= ";
    p.display(p1_1);
    cout << "\n\n\nP2(x)= ";
    p2.display(p2_1);

    p.insert(p1_6, p1_5);
    p2.insert(p2_4, p2_3);
    p2.insert(p2_5, p2_4);
    cout << "\n\n\nP1(x) + P2(x) = ";
    result = (struct Node*)malloc(sizeof(struct Node));
    r.addpoly(p1_1, p2_1, result);
    r.out(result);


    cout << "\n\n\nDifferent Polynomials\n";
    Node* x1_1 = new Node(35, 0);
    Node* x1_2 = new Node(10, 2);
    Node* x1_3 = new Node(84, 4);
    Node* x1_4 = new Node(63, 60);
    Node* x1_5 = new Node(51, 100);
    Node* x1_6 = new Node(0, 100); //dummy
    Node* x2_1 = new Node(84, 0);
    Node* x2_2 = new Node(94, 4);
    Node* x2_3 = new Node(15, 5);
    Node* x2_4 = new Node(0, 60); //dummy
    Node* x2_5 = new Node(0, 100); //dummy


    x1.insert(x1_1);
    x1.insert(x1_2, x1_1);
    x1.insert(x1_3, x1_2);
    x1.insert(x1_4, x1_3);
    x1.insert(x1_5, x1_4);
    x2.insert(x2_1);
    x2.insert(x2_2, x2_1);
    x2.insert(x2_3, x2_2);
    cout << "\n";
    cout << "X1(x)= ";
    x1.display(x1_1);
    cout << "\n\n\nX2(x)= ";
    x2.display(x2_1);

    x1.insert(x1_6, x1_5);
    x2.insert(x2_4, x2_3);
    x2.insert(x2_5, x2_4);
    cout << "\n\n\nX1(x) + X2(x) = ";
    result = (struct Node*)malloc(sizeof(struct Node));
    r.addpoly(x1_1, x2_1, result);
    r.out(result);


    cout << endl;
    cout << endl;
    cout << "\n\n";
    return 0;

}
