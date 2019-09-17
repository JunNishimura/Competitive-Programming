#include <iostream> 
#include <stack> 
using namespace std;

int main() 
{
    stack<int> S;
    char c[100];
    int a, b;

    while (scanf("%s", c) != EOF) 
    {
        if (c[0] == '+') 
        {
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a + b);
        }
        else if (c[0] == '-')
        {
            b = S.top(); S.pop();
            a = S.top(); S.pop();
            S.push(a - b);
        }
        else if (c[0] == '*')
        {
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a * b);
        }
        else 
        {
            S.push(atoi(c));
        }
    }

    cout << S.top() << endl;
}