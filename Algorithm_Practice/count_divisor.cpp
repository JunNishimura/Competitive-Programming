#include <iostream> 
#include "math.h"
#include <vector> 
using namespace std;

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

void Prime_generator(int number, vector<int>& V) 
{
    V.push_back(2);
    for (int i = 3; i <= number; i += 2)
    {
        if (isPrime(i)) V.push_back(i);
    }
}

int count_divisor(int number, vector<int> V) 
{
    int cnt = 1;
    for (int i = 0; i < V.size(); ++i) 
    {
        int l_time = 0;
        while (number % V[i] == 0) 
        {
            number /= V[i];
            l_time++;
        }

        if (l_time != 0) 
        {
            
            cnt *= ++l_time; // need to add 1
        }
    }
    return cnt;
}

int main() 
{
    int number;
    vector<int> V;
    cout << "調べたい数は何ですか？ > " << flush;
    cin >> number;
    Prime_generator(number, V);

    cout << "約数の個数は" << count_divisor(number, V) << endl;
}