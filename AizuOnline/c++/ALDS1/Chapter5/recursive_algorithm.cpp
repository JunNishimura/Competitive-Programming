#include <iostream>
using namespace std;

int Factorial(int n) {
    if (n == 0) {
        printf("Reached the base. from here return the number\n");
        return 1;
    }
    printf("I am calculating: f(%d) = %d * f(%d)\n", n, n, n-1);
    int m = Factorial(n-1);
    printf("Returning the value: f(%d) = %d * %d\n", n, n, m);
    return n * m;
}

int Fibonacci(int n) {
    printf("%d\n", n);
    if (n <= 1) return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
    printf("This is the final result: %d\n", Factorial(10));
}