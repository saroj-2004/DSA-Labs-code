
# include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
void insertAtBeginning(Node*& start, int value){
    Node* newNode= new Node;
    newNode->data= value;
    newNode->next= nullptr;
    newNode->prev= nullptr;
    if(start == nullptr){
        start = newNode;
    } else {
        start->prev = newNode;
        newNode->next = start;
        start = newNode;
    }  
}
void insertAtEnd(Node*& start, int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if(start == nullptr){
        newNode->prev = nullptr;
        start = newNode;
    } else {
        Node* ptr = start;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
    }
}
void insertAfter(Node*& start, int value, int afterValue){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    Node* ptr = start;
    while(ptr != nullptr && ptr->data != afterValue){
        ptr = ptr->next;
    }
    if(ptr == nullptr) {
        cout << "Node with value " << afterValue << " not found." << endl;
        delete newNode; 
        return;
    }
    newNode->next = ptr->next;
    newNode->prev = ptr;
    ptr->next->prev = newNode;
    ptr->next = newNode;
}
void insertBefore(Node*& start, int value, int beforeValue){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if(start == nullptr) {
        cout << "List is empty." << endl;
        delete newNode; 
        return;
    }
    Node* ptr = start;
    while(ptr != nullptr && ptr->data != beforeValue){
        ptr = ptr->next;
    }
    if(ptr == nullptr) {
        cout << "Node with value " << beforeValue << " not found." << endl;
        delete newNode; 
        return;
    }
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    if(ptr->prev != nullptr) {
        ptr->prev->next = newNode;
    } else {
        start = newNode; 
    }
    ptr->prev = newNode;
}

void deleteFromBeginning(Node*& start){
    if(start == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = start;
    start = start->next;
    if(start != nullptr) {
        start->prev = nullptr;
    }
    delete temp;
}
void deleteFromEnd(Node*& start){
    if(start == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* ptr = start;
    while(ptr->next != nullptr) {
        ptr = ptr->next;
    }
    if(ptr->prev != nullptr) {
        ptr->prev->next = nullptr;
    } else {
        start = nullptr; 
    }
    delete ptr;
}
void deleteAfter(Node*& start, int afterValue){
    Node* ptr = start;
    while(ptr != nullptr && ptr->data != afterValue){
        ptr = ptr->next;
    }
    if(ptr == nullptr || ptr->next == nullptr) {
        cout << "Node with value " << afterValue << " not found or has no next node." << endl;
        return;
    }
    Node* toDelete = ptr->next;
    ptr->next = toDelete->next;
    if(toDelete->next != nullptr) {
        toDelete->next->prev = ptr;
    }
    delete toDelete;
}
void deleteBefore(Node*& start, int beforeValue){
    if(start == nullptr || start->next == nullptr) {
        cout << "List is empty or has only one node." << endl;
        return;
    }
    Node* ptr = start;
    while(ptr->next != nullptr && ptr->next->data != beforeValue){
        ptr = ptr->next;
    }
    if(ptr->next == nullptr || ptr == start) {
        cout << "Node with value " << beforeValue << " not found or is the first node." << endl;
        return;
    }
    Node* toDelete = ptr;
    if(toDelete->prev != nullptr) {
        toDelete->prev->next = toDelete->next;
    } else {
        start = toDelete->next; 
    }
    if(toDelete->next != nullptr) {
        toDelete->next->prev = toDelete->prev;
    }
    delete toDelete;
}
void displayList(Node* start){
    Node* ptr = start;
    while(ptr != nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    Node* start = nullptr;
    insertAtBeginning(start, 10);
    insertAtBeginning(start, 20);
    insertAtEnd(start, 30);
    insertAfter(start, 25, 20);
    insertBefore(start, 15, 20);
    
    cout << "List after insertions: ";
    displayList(start);
    
    deleteFromBeginning(start);
    cout << "List after deleting from beginning: ";
    displayList(start);
    
    deleteFromEnd(start);
    cout << "List after deleting from end: ";
    displayList(start);
    
    deleteAfter(start, 20);
    cout << "List after deleting after node with value 20: ";
    displayList(start);
    
    deleteBefore(start, 30);
    cout << "List after deleting before node with value 30: ";
    displayList(start);

    return 0;
}