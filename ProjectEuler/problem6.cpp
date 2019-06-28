#include <iostream> 
#include "math.h"
using namespace std; 

int sum_of_square() 
{
    int r = 0;
    for (int i = 1; i <= 100; ++i)
    {
        r += pow(i, 2);
    }
    return r;
}

int square_of_sum() 
{
    int r = 0;
    r = (1+100)*50;
    return pow(r, 2);
}

int main() 
{
    cout << "sum of square: " << sum_of_square() << endl   
         << "square of sum: " << square_of_sum() << endl
         << "difference   : " << square_of_sum() - sum_of_square() << endl;
}