#include <iostream> 
using namespace std;

int fib[50];

int Fibonacci(int n) 
{
    if (n <= 1) return fib[n]=1;
    if (fib[n] != -1) return fib[n];
    return fib[n] = Fibonacci(n-1) +  Fibonacci(n-2); 
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) fib[i] = -1;

    cout << Fibonacci(n) << endl;
}