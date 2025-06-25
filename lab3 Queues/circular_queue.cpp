
// 2. Perform enqueue and dequeue operations in Circular Queue 
// By Saroj Rawal

#include <iostream>
using namespace std;
#define MAX 3
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) { 
        cout << "Queue is full" << endl;
        return;
    } else if (front == -1) { 
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) { 
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    cout << "Enqueued: " << value << endl;
}
void dequeue() {
    if (front == -1) { 
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Dequeued: " << queue[front] << endl;
    if (front == rear) { 
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}
void display() {
    if (front == -1) { 
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    } else {
        for (int i = front; i < MAX; i++) {
            cout << queue[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    }
    cout << endl;
}
int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    enqueue(50);
    display();

    // int choice, value;
    // while (true) {
    //     cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
    //     cout << "Enter your choice: ";
    //     cin >> choice;
    //     switch (choice) {
    //         case 1:
    //             cout << "Enter value to enqueue: ";
    //             cin >> value;
    //             enqueue(value);
    //             break;
    //         case 2:
    //             dequeue();
    //             break;
    //         case 3:
    //             display();
    //             break;
    //         case 4:
    //             return 0;
    //         default:
    //             cout << "Invalid choice, please try again." << endl;
    //     }
    // }
    return 0;
}