#include <iostream>
using namespace std;

// int n;
// int main()
// {
//     cin >> n;
//     int p = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         int b = 2;
//         while (true) 
//         {
//             if (b*b > a) 
//             {
//                 p++;
//                 break;
//             }
//             if (a % b == 0) break;
//             b++;
//         }
//     }
//     printf("%d\n", p);
// }

// revision

bool CNT(int x)
{
    for (int i = 2; i*i<=x; i++)
    {
        if (x%i==0) return false;
    }
    return true;
}

int main()
{
    int n, a, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        c+=CNT(a);
    }
    printf("%d\n", c);
}