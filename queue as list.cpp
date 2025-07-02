
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void enqueue(Node*& front, Node*& rear, int value){
    Node* newNode= new Node;
    newNode->data= value;
    newNode->next= nullptr;
    if (rear==nullptr){
        front=rear= newNode; 
    }else{
        rear->next= newNode; 
        rear= newNode;
    }
}
int dequeue(Node*& front, Node*& rear){
    if (front==nullptr) {
        cout<<"Queue Underflow"<<endl;
        return -1;
    }
    Node* temp= front;
    int dequeuedValue= temp->data;
    front= front->next;
    if(front==nullptr){
        rear= nullptr; 
    }
    delete temp;
    return dequeuedValue;
}
void display(Node* front){
    if (front==nullptr){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue elements: ";
    while (front != nullptr){
        cout<<front->data<< " ";
        front=front->next;
    }
    cout<<endl;
}
int main(){
    Node* queueFront = nullptr; 
    Node* queueRear = nullptr; 
    enqueue(queueFront, queueRear, 10);
    enqueue(queueFront, queueRear, 20);
    enqueue(queueFront, queueRear, 30);
    display(queueFront);
    cout<<"Dequeued element: "<<dequeue(queueFront, queueRear)<<endl;
    display(queueFront);
    
    return 0;
}