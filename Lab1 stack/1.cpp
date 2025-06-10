// 1. Perform push and pop operations in stack
// By Saroj Rawal

#include <iostream>
using namespace std;
#define MAX 100
int stack[MAX];
int top = -1; 
void push(int x){

    if (top >= MAX - 1) {
        cout << "Stack is full" << endl;
    } else {
        stack[++top] = x;
        cout << x << " pushed onto stack" << endl;
    }
}
int pop() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return -1; 
    } else {
        return stack[top--]; 
    }
}
int peek() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return -1; 
    } else {
        return stack[top]; 
    }
}
bool isEmpty() {
    return top < 0;
}
void display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    push(10);
    push(20);
    push(30);
    display();

    cout << "Top element: " << peek() << endl; 
    cout << pop() << " popped from stack" << endl; 
    display(); 

    return 0;
}








