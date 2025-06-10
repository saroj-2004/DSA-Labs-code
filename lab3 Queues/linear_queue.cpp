// 1. perform enqueue and dequeue operations on a linear queue
// By Saroj Rawal

#include<iostream>
using namespace std;
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue is full!" << endl;
    } else {
        if (front == -1) {
            front = 0; 
        }
        rear++;
        queue[rear] = value;
        cout << "Enqueued: " << value << endl;
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Dequeued: " << queue[front] << endl;
        front++;
        if (front > rear) { 
            front = rear = -1;
        }
    }
}
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}
int main() {

    int choice, value;
    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

