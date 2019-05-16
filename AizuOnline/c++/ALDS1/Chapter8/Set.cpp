#include <iostream> 
#include <set> 
using namespace std;

void Print(set<int> S) 
{
    cout << S.size() << ":";
    for (set<int>::iterator it = S.begin(); it != S.end(); it++) 
    {
        cout << " " << (*it);
    }
    cout << endl;
}

int main() 
{
    set<int> S;
    S.insert(8);
    S.insert(1);
    S.insert(5);
    S.insert(10);
    S.insert(7);

    Print(S);
    
    S.erase(10);
    Print(S);

    S.erase(5);
    Print(S);

    if(S.find(23) == S.end()) cout << "Not found." << endl;

    return 0;
}