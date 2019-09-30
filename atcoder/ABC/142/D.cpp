#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }

vector<pair<ll, int>> factorize(ll n) 
{
    vector<pair<ll, int>> res;
    
    for (ll i = 2; i*i <= n; ++i) 
    {
        if(n % i) continue;
        res.emplace_back(i, 0);
        while( n % i == 0 )
        {
            n /= i;
            res.back().second++;
        }
    }
    if (n != 1) res.emplace_back(n, 1);
    return res;
}

int main() 
{
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    auto f = factorize(g);
    int ans = f.size() + 1;
    cout << ans << endl;
    return 0;
}