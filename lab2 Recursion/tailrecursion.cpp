// c. SOLVE ABOVE QUESTIONS USING TAIL RECURSION.
// By Saroj Rawal

#include<iostream>
using namespace std;
int factorial(int n, int result = 1) {
    if (n == 0 || n == 1) {
        return result; 
    } else {
        return factorial(n - 1, n * result); 
    }
}
int fibonacci(int n, int a = 0, int b = 1) {
    if (n == 0) {
        return a; 
    } else if (n == 1) {
        return b; 
    } else {
        return fibonacci(n - 1, b, a + b); 
    }
}

int main() {
    int num;
    cout << "Enter a positive integer for factorial: ";
    cin >> num;
    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        int result = factorial(num);
        cout << "Factorial of " << num << " is " << result << endl;
    }

    cout << "Enter a positive integer for Fibonacci series: ";
    cin >> num;

    if (num < 0) {
        cout << "enter positive number." << endl;
    } else {
        int fib_result = fibonacci(num);
        cout << "Fibonacci number at position " << num << " is " << fib_result << endl;
    }
    
    return 0;
}