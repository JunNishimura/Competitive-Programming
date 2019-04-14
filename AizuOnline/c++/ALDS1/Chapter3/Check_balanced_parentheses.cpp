#include <iostream>
#include <stack>
using namespace std;


stack<char> S;

bool CheckBalancedParentheses(char ch)
{
    if (ch == '{' || ch == '(' || ch == '[')
    {
        S.push(ch);
    }
    else if (ch == '}')
    {
        if (S.empty() || S.top() != '{') return false;
        else S.pop();
    }
    else if (ch == ')')
    {
        if (S.empty() || S.top() != '(') return false;
        else S.pop();
    }
    else if (ch == ']')
    {
        if (S.empty() || S.top() != ']') return false;
        else S.pop();
    }
    return true;
}
int main() 
{
    char ch;
    while (cin >> ch) {
        if (!CheckBalancedParentheses(ch)) 
        {
           break;
        }
    }
    if (S.empty()) printf("Balanced!\n");
    else printf("Not Balanced!\n");
}