#include <iostream> 
#include <queue>
using namespace std;

int main() 
{
    priority_queue<int> PQ;
    int key;
    char order[10];
    while (true) 
    {
        cin >> order;
        if (order[0] == 'e' && order[1] == 'n') break;
        if (order[0] == 'i') 
        {
            cin >> key;
            PQ.push(key);
        }
        else 
        {
            cout << PQ.top() << endl;
            PQ.pop();
        }
    }
}