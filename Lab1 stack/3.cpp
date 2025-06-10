// b. Infix expression to prefix expression 
// By Saroj Rawal

#include <iostream>
using namespace std;
#define MAX 100
int precedence(char op) {
    if (op == '^' || op == '$') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
void infixToPrefix(string infix) {
    string prefix = "";
    int n = infix.length();
    
    for (int i = n - 1; i >= 0; i--) {
        char ch = infix[i];
        
        if (isalnum(ch)) {
            prefix = ch + prefix;
        } else if (ch == ')') {
            prefix = '(' + prefix;
        } else if (ch == '(') {
            prefix += ')';
        } else {
            while (!prefix.empty() && precedence(ch) < precedence(prefix.back())) {
                prefix += prefix.back();
                prefix.pop_back();
            }
            prefix += ch;
        }
    }
    
    cout << "Prefix: " << prefix << endl;
}
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    
    infixToPrefix(infix);
    
    return 0;
}
