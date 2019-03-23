#include <iostream>
using namespace std;
typedef long long ll;

// int n, p, t, d=-1000000000; // t : current input, p : minimum value, d : largest difference
// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> t;
//         if (i>0)
//         {
//             if (t-p>d) d = t-p; // compare difference
//             if (p > t) p = t;   
//         }
//         else 
//         {
//             p = t;
//         }
//     }
//     printf("%d\n", d);
// }

// revision
int main() 
{
    int n, tmp;
    ll min=(1e13), max=-(1e13);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (tmp-min>max) max = tmp-min;
        if (min>tmp) min = tmp;
    }
    printf("%d\n", max);
    return 0;
}