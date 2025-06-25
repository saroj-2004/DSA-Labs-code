// delete node from the beginning of the linked list

#include <iostream>
using namespace std;
struct newnode{
    int data;
    newnode* next;
};
// **********************************************************************************************************************
void deletefrombeg(newnode*& start){
    if(start== NULL){
        cout<< "List is empty."<<endl;
        return;
    }
    newnode* temp= start;
    start= start->next;
    delete temp;
}
// **********************************************************************************************************************
void deletefromend(newnode*& start){
    if(start== NULL){
        cout<< "List is empty."<<endl;
        return;
    }
    newnode* ptr= start;
    newnode* preptr;
    while(ptr->next!= NULL){
        newnode* preptr= ptr;
        ptr= ptr->next;
    }
    preptr->next= NULL;
    delete ptr;
}
// **********************************************************************************************************************
void deleteafter(newnode*& start, int myData){
    if(start== NULL){
        cout<< "List is empty."<<endl;
        return;
    }
    newnode* ptr= start;
    while(ptr != NULL && ptr->data != myData){
        ptr= ptr->next;
    }
    
    if(ptr== NULL || ptr->next == NULL){
        cout<<"Node not found."<<endl;
        return;
    }
    
    newnode* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

// **********************************************************************************************************************
void deleteNthpos(newnode*& start, int position){
    if(start== NULL){
        cout<< "List is empty."<<endl;
        return;
    }
    if(position == 1){
        newnode* temp = start;
        start = start->next;
        delete temp;
        return;
    }
    
    newnode* ptr = start;
    for(int i = 1; i < position - 1 && ptr != NULL; i++){
        ptr = ptr->next;
    }
    
    if(ptr == NULL || ptr->next == NULL){
        cout<<"Position out of bounds."<<endl;
        return;
    }
    
    newnode* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

// **********************************************************************************************************************
void display(newnode* start){
    if(start == NULL){
        cout << "List is empty." << endl;
        return;
    }
    newnode* temp = start;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



// **********************************************************************************************************************
int main(){
    newnode* start = NULL;
    int choice, value, myData, position;
    cout << "Choose an option:" << endl;
    cout << "1. Delete from beginning" << endl; 
    cout << "2. Delete from end" << endl;
    cout << "3. Delete after a node" << endl;
    cout << "4. Delete at nth position" << endl;
    cout << "5. Display the list" << endl;
    cout << "6. Exit" << endl;
    while(true){
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
              case 1:
                  deletefrombeg(start);
                  break;
              case 2:
                  deletefromend(start);
                  break;
              case 3:
                  cout << "Enter the node after which to delete: ";
                  cin >> myData;
                  deleteafter(start, myData);
                  break;
              case 4:
                  cout << "Enter position to delete at: ";
                  cin >> position;
                  deleteNthpos(start, position);
                  break;
              case 5:
                  display(start);
                  break;
              case 6:
                  return 0;
              default:
                  cout << "Invalid choice." << endl;
        }
    }
}