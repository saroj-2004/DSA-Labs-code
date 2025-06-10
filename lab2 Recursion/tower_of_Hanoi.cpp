// d. SOLVE TOWER OF HANOI PROBLEM FOR ‘N’ DISCS.
// By Saroj Rawal

#include<iostream>
using namespace std;
void towerofhanoi(int n, char s, char a, char d){
    if (n == 1){
        cout << "Move disk 1 from " << s << " to " << d << endl;
    } else {
        towerofhanoi(n - 1, s, d, a); 
        cout << "Move disk " << n << " from " << s << " to " << d << endl; 
        towerofhanoi(n - 1, a, s, d); 
    }
} 
int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    cout<<"steps to solve Tower of Hanoi problem are: " << endl;
    towerofhanoi(n, 'S', 'A', 'D'); 
    return 0;
}