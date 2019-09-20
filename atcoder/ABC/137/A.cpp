#include <iostream> 
using namespace std;

int main() 
{
    int A, B;
    cin >> A >> B;
    int max_v;

    max_v = A + B;
    if (max_v < A-B) max_v = A-B;
    if (max_v < A*B) max_v = A*B;
    cout << max_v << endl;
}