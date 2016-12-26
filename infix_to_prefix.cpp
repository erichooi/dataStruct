#include <iostream>
#include <stack>
#include <algorithm>
#include <typeinfo>
using namespace std;


void reverse_equation(string& equation) 
{
   reverse(equation.begin(), equation.end()); 
}

int is_operator(char character) 
{
    switch(character) {
        case '+': case '-': case'*': case '/': case '^': case '(': case ')':
            return 1;
        default:
            return 0;
    }
}

/*
 * The higher the value, the higher the precedence
 */
int get_precedence(char character) 
{
    switch(character) {
        case '(': case ')':
            return 1;
        case '+': case '-':
            return 2;
        case '*': case '/':
            return 3;
        case '^':
            return 4;
        default:
            return 0;
    }
}

int main() {
    stack <char> symbol;
    string prefix = "";
    string equation;
    cout << "Enter the equation: ";
    getline(cin, equation);
    reverse_equation(equation);
    for (string::iterator itr = equation.begin(); itr != equation.end(); itr++) {
        if (*itr == '(') {
            *itr = ')';
        } else if (*itr == ')') {
            *itr = '(';
        }
    }
    for (string::iterator itr = equation.begin(); itr != equation.end(); itr++) {
        if (is_operator(*itr)) {
            if (*itr == ')') {
                while (symbol.top() != '(') {
                    prefix += symbol.top();
                    symbol.pop();
                }
                symbol.pop();
            } else if (*itr == '(') {
                symbol.push(*itr);
            } else {
                if (symbol.empty()) {
                    symbol.push(*itr);
                } else if (get_precedence(symbol.top()) < get_precedence(*itr)) {
                    symbol.push(*itr);
                } else {
                    while (!symbol.empty()) {
                        if (get_precedence(symbol.top()) > get_precedence(*itr)) {
                            prefix += symbol.top();
                            symbol.pop();
                        } else {
                            break;
                        }
                    }
                    symbol.push(*itr);
                }
            }
        } else {
            prefix += *itr;
        }
    }
    while (!symbol.empty()) {
        prefix += symbol.top();
        symbol.pop();
    }
    reverse_equation(prefix);
    cout << prefix << endl;
    return 0;
}
