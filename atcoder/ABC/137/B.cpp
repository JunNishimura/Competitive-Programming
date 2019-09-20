#include <iostream> 
using namespace std;

int main() 
{
    int K, X;
    cin >> K >> X;
    int min_v, max_v;

    min_v = X - (K - 1);
    max_v = X + (K - 1);
    if (min_v < -1000000) min_v = -1000000;
    if (max_v > 1000000) max_v = 1000000;

    for (int i = min_v; i <= max_v; i++) 
    {
        if (i != min_v) cout << " ";
        cout << i;
    }
    cout << endl;
}