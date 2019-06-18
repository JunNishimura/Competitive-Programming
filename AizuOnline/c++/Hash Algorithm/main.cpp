#include <iostream> 
#include <assert.h>
#include "HashSet.hpp"
#define SIZE 100
using namespace std;

int main() 
{
    HashSet h_set;
    while (true) 
    {
        cout << "挿入(0) / 削除(1)  >  " << flush;
        int n; cin >> n;
        if (n == 0) 
        {
            cout << "挿入する数字 > " << flush;
            int m; cin >> m;
            h_set.Add(m);
        }
        else if (n == 1) 
        {
            cout << "削除する数字 > " << flush;
            int m; cin >> m;
            h_set.Remove(m);
        }   
        else 
        {
            cout << "不適切な入力です。終了します。" << endl;
            break;
        }
        // h_set.PrintStructure();
    }
}