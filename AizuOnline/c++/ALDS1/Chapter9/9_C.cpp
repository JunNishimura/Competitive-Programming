#include <iostream> 
using namespace std;
#define MAX 2000000
#define INF (1<<30)

int H(0), A[MAX+1];

void maxHeapify(int id) 
{
    int l, r, largest;
    l = 2 * id;
    r = 2 * id + 1;
    if (l <= H && A[l] > A[id]) largest = l;
    else largest = id;
    if (r <= H && A[r] > A[largest]) largest = r;

    if (largest != id) 
    {
        swap(A[id], A[largest]);
        maxHeapify(largest);
    }
}

int extract() 
{
    int max = A[1];
    A[1] = A[H];
    H--;
    maxHeapify(1);
    return max;
}

void HeapIncreaseKey(int key, int id) 
{
    if (key < A[id]) return;
    A[id] = key;
    while (id > 1 && A[id/2] < A[id])
    {
        swap(A[id/2], A[id]);
        id = id/2;
    }
}   

void Insert(int key)
{
    H++;
    A[H] = -INF;
    HeapIncreaseKey(key, H);
}

int main() 
{
    int key;
    char order[10];
    while(true){
        scanf("%s", order);
        if (order[0] == 'e' && order[2] == 'd') break;
        
        if (order[0] == 'i')
        {
            scanf("%d", &key);
            Insert(key);
        }
        else cout << extract() << endl;
    }
}