
#include <iostream>
using namespace std;
struct Node{
    int coeff; 
    int pow;   
    Node* next; 
};
void insertTerm(Node*& start, int coeff, int pow){
    Node* newNode= new Node;
    newNode->coeff= coeff;
    newNode->pow= pow;
    newNode->next= nullptr;

    if(start==nullptr||start->pow<pow){
        newNode->next= start;
        start= newNode;
    }else{
        Node* ptr= start;
        while(ptr->next !=nullptr &&ptr->next->pow >= pow){
            ptr= ptr->next;
        }
        if(ptr->pow == pow){
            ptr->coeff += coeff; 
            delete newNode;
        }else{
            newNode->next= ptr->next;
            ptr->next= newNode;
        }
    }
}
void display(Node* start){
    if(start==nullptr){
        cout<<"Polynomial is empty"<<endl;
        return;
    }
    Node* ptr= start;
    while(ptr != nullptr){
        cout<<ptr->coeff<<"x^"<<ptr->pow;
        if(ptr->next != nullptr) cout<<" + ";
        ptr= ptr->next;
    }
    cout<<endl;
}
void addPolynomials(Node*& poly1, Node*& poly2, Node*& result){
    Node* ptr1= poly1;
    Node* ptr2= poly2;

    while(ptr1 != nullptr && ptr2 != nullptr){
        if(ptr1->pow > ptr2->pow){
            insertTerm(result, ptr1->coeff, ptr1->pow);
            ptr1= ptr1->next;
        }else if(ptr1->pow < ptr2->pow){
            insertTerm(result, ptr2->coeff, ptr2->pow);
            ptr2= ptr2->next;
        }else{
            insertTerm(result, ptr1->coeff + ptr2->coeff, ptr1->pow);
            ptr1= ptr1->next;
            ptr2= ptr2->next;
        }
    }
    while(ptr1 != nullptr){
        insertTerm(result, ptr1->coeff, ptr1->pow);
        ptr1= ptr1->next;
    }
    while(ptr2 != nullptr){
        insertTerm(result, ptr2->coeff, ptr2->pow);
        ptr2= ptr2->next;
    }
}
int main(){
    Node* poly1 = nullptr; 
    Node* poly2 = nullptr; 
    Node* result = nullptr; 

  
    insertTerm(poly1, 3, 3);
    insertTerm(poly1, 4, 2);
    insertTerm(poly1, 5, 0);

   
    insertTerm(poly2, 2, 3);
    insertTerm(poly2, 6, 1);
    insertTerm(poly2, 1, 0);

    cout << "First Polynomial: ";
    display(poly1);
    
    cout << "Second Polynomial: ";
    display(poly2);

    addPolynomials(poly1, poly2, result);

    cout << "Resultant Polynomial after addition: ";
    display(result);

    return 0;
}