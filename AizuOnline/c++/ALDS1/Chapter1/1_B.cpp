#include <iostream>
using namespace std;
// int main()
// {
//     int i, j;
//     scanf("%d %d", &i, &j);
//     while (true)
//     {
//         if (i > j) i = i % j;
//         else j = j % i;
//         if (i == 0 || j == 0) break;
//     }
//     printf("%d", i+j);
// }

// revise 
int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}