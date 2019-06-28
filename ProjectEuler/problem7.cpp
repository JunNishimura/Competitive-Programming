#include <iostream> 
#include <vector> 
#include <math.h>
using namespace std; 

int prime_cnt = 0;
vector<int> prime_vector;
int target;

void Prime_Function() 
{
    prime_vector.push_back(2); // はじめに2と3だけ加えておく
    prime_vector.push_back(3);
    prime_cnt += 2; // 何番目の素数かを数える変数

    int current_number = 5; // 素数かを判定する現在の数
    while (1) 
    { 
        int i = 3;
        while (1) 
        {
            if (current_number % i == 0) break;

            i+=2;
            if (i > int(sqrt(current_number))) 
            {
                // if current number is prime number, add it to vector and count up
                ++prime_cnt;
                prime_vector.push_back(current_number);
                break;
            }
        }

        current_number += 2;

        if (prime_cnt == target) 
        {
            cout << prime_vector.back() << endl;
            break;
        }
    }
}


int main() 
{
    cout << "What is a target prime? -> " << flush;
    cin >> target;
    
    Prime_Function();
}