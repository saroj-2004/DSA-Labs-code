// b. FIND THE FIBONACCI NUMBER FOR GIVEN TERM‘N’.
// By Saroj Rawal

#include <iostream>
using namespace std;
int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;
    cout << "enter value of n: ";
    cin >> n;
    int result = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is: " << result << endl;
    for (int i =0;i<=n;i++){
        cout<<fibonacci(i)<<" ";
    }
    return 0;
}
