// 3. Evaluate the postfix expression 
// By Saroj Rawal

#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100
int precedence(char op) {
    if (op == '^' || op == '$') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
int evaluatePostfix(string postfix) {
    int stack[MAX];
    int top = -1;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack[++top] = ch - '0'; 
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch (ch) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                case '^': stack[++top] = pow(a, b); break;
            }
        }
    }
    
    return stack[top];
}
int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    
    int result = evaluatePostfix(postfix);
    cout << "Result of postfix evaluation: " << result << endl;
    
    return 0;
}

