#include <iostream> 
#include <vector>
#include <time.h> 
#include "math.h"
using namespace std;

// judge if the nubmer is prime or not by eratosthenes algorithm
int isPrime(int number) 
{
    if (number < 2) return false;
    else if (number == 2) return true;
    else if (number % 2 == 0) return false;

    for (int i = 3; i <= sqrt(number); i+= 2)
    {
        if (number % i == 0) return false;
    }

    return true;
}

// judge if the number is prime or not by using prime array
int isPrime2(int number, vector<int> p_array) 
{
    for (auto itr = p_array.begin(); itr != p_array.end(); ++itr) 
    {
        if (number % *itr == 0) return false;
    }
    return true;
}

// function to generate prime numbers under the given number
void prime_generator(int number, vector<int>& p_array) 
{
    for (int i = 3; i <= number; i += 2) 
    {
        if (isPrime(i)) p_array.push_back(i);
    } 
}

void print_primes(vector<int> p_array) 
{
    for (auto itr = p_array.begin(); itr != p_array.end(); ++itr) 
    {
        printf("%d ", *itr);
    }
    printf("\n");
}

int main() 
{
    vector<int> p_array;
    p_array.push_back(2);
    
    clock_t start = clock();
    prime_generator(65550, p_array);
    clock_t end = clock();
    cout << "duration = " << (double)(end-start) / CLOCKS_PER_SEC << endl;

    print_primes(p_array);
}