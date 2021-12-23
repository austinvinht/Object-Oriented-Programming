#include <iostream>
using namespace std;
#include "OpStack.h"
#include "IntStack.h"
#include <string>

int priority(char x) 
{
  if (x == '/' || x == '*')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '(' || x == ')')
        return 0;

}
string convert_to_postFix(string infix)
{
    OpStack my_stack;
    string postfix_exp;
    char token;
    for (int i = 0; i < infix.length(); i++)
    {
        token = infix[i];
        switch (token)
        {
        case ' ':break;
        case '(':my_stack.push(token); break;
        case ')':
            token = my_stack.pop();
            while (token != '(')
            {
                postfix_exp = postfix_exp.append(1, token);
                token = my_stack.pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            while (!my_stack.empty() && priority(token) <= priority(my_stack.top()))
            {
                postfix_exp = postfix_exp.append(1, my_stack.top());
                my_stack.pop();
            }
            
            my_stack.push(token); break;
            default:
            postfix_exp = postfix_exp.append(1, token);
        }
    }
    token = my_stack.pop();
    while (token != '\0')
    {
        postfix_exp = postfix_exp.append(1, token);
        token = my_stack.pop();
    }
    //cout << postfix_exp.length() << "\n";
    return postfix_exp;
}
double compute(string postFix)
{
    IntStack opStack;
    char token;
    double answer = 0;
    int x;
    int y;
    for (int i = 0; i < postFix.length(); i++)
    {
        token = postFix[i];
        switch (token)
        {
        case '*':
            x = opStack.pop();
            y = opStack.pop();
            opStack.push(y * x);
            break;
        case '+':
            x = opStack.pop();
            y = opStack.pop();
            opStack.push(y + x);
            break;
        case '/':
            x = opStack.pop();
            y = opStack.pop();
            opStack.push(y / x);
            break;
        case '-':
            x = opStack.pop();
            y = opStack.pop();
            opStack.push(y - x);
            break;
        case '0':
            opStack.push(0);
            break;
        case '1':
            opStack.push(1);
            break;
        case '2':
            opStack.push(2);
            break;
        case '3':
            opStack.push(3);
            break;
        case '4':
            opStack.push(4);
            break;
        case '5':
            opStack.push(5);
            break;
        case '6':
            opStack.push(6);
            break;
        case '7':
            opStack.push(7);
            break;
        case '8':
            opStack.push(8);
            break;
        case '9':
            opStack.push(9);
            break;
        default:
            answer = opStack.pop();
        }
    }
    answer = opStack.pop();
    return answer;
}

int main()
{
    string infixExp;
    string postfixExp;
    cout << "\nEnter a Infix Expression :";
    getline(cin, infixExp);
    cout << "\nThe infix expression you entered is : " << infixExp;
    postfixExp = convert_to_postFix(infixExp);
    cout << "\nThe postfix is " << postfixExp << "\n\n";
    cout << "\nThe postfix expression is evaluated as: " << compute(postfixExp) << endl;
    return 0;
}

