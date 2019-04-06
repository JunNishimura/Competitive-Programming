#include <iostream>
#include <stack>
using namespace std;

int main() 
{ 
    int a1, a2;
    char c[3];
    stack<int> s;
    while(cin >> c)
    {
        if (isdigit(c[0]))
        {
            s.push(atoi(c));
        }
        else
        {
            a1 = s.top(); s.pop();
            a2 = s.top(); s.pop();
            if (c[0]=='+') s.push(a2+a1);
            else if (c[0]=='-') s.push(a2-a1);
            else if (c[0]=='*') s.push(a2*a1);
        }
    }
    printf("%d\n", s.top());
}