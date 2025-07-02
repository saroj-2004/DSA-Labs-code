
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void push(Node*& top, int value){
    Node*newNode= new Node;
    newNode->data= value;
    newNode->next= top;
    top= newNode;
}
int pop(Node*& top){
    if(top==nullptr) {
        cout<<"Stack Underflow"<<endl;
        return -1; 
    }
    Node* temp= top;
    int poppedValue= temp->data;
    top= top->next;
    delete temp;
    return poppedValue;
}

void display(Node* top){
    if(top==nullptr){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Stack elements: ";
    while (top != nullptr){
        cout<<top->data<< " ";
        top=top->next;
    }
    cout<<endl;
   
}
int main(){
    Node* stackTop = nullptr; 
    push(stackTop, 10);
    push(stackTop, 20);
    push(stackTop, 30);
    display(stackTop);
    cout<<"Popped element: "<<pop(stackTop)<<endl;
    display(stackTop);
     
    return 0;
}