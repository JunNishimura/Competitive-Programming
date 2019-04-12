#include <iostream>
#include <list>
using namespace std;

int main() 
{
    list<int> lst;

    int n=0, x=0;
    char c[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", c, &x);
        if (c[0] == 'i') lst.push_front(x);
        else if (c[6] == 'F') lst.pop_front();
        else if (c[6] == 'L') lst.pop_back();
        else 
        {
            for (auto itr = lst.begin(); itr != lst.end(); ++itr) 
            {
                if (*itr == x) 
                {
                    lst.erase(itr);
                    break;
                }
            }
        }
    }

    for (auto itr = lst.begin(); itr != lst.end(); ++itr)
    {
        if (itr == lst.begin()) printf("%d", *itr);
        else printf(" %d", *itr);
    }
    printf("\n");
}