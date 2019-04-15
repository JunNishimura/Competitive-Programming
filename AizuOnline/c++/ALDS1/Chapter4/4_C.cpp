#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() 
{
    set<string> s;
    int n; 
    char ord[10], moji[15];
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s %s", ord, moji);
        if (ord[0] == 'i') s.insert(moji);
        else printf(s.find(moji) != s.end() ? "yes\n" : "no\n");
    }
}