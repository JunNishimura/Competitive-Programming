#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;

static const int SIZE = 1000;

int LCS(string X, string Y) 
{
    int c[SIZE+1][SIZE+1];
    int m = X.size();
    int n = Y.size();
    X = ' ' + X;
    Y = ' ' + Y;
    int max_len = 0;
    for (int i = 1; i <= m; i++) c[i][0] = 0;
    for (int j = 1; j <= n; j++) c[0][j] = 0;

    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (X[i] == Y[j]) c[i][j] = c[i-1][j-1]+1;
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
            max_len = max(max_len, c[i][j]);
        }
    }
    return max_len;
}

int main() 
{
    int q;
    string X, Y;

    cin >> q;
    for (int i = 0; i < q; ++i) 
    {
        cin >> X >> Y;
        cout << LCS(X, Y) << endl;
    }
}