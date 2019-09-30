#include <bits/stdc++.h>
using namespace std;

int main() 
{
    double n;
    cin >> n;
    if ((int)n % 2 == 0) printf("%.10lf\n", (n/2)/n);
    else printf("%.10lf\n", ((n+1)/2)/n);
}