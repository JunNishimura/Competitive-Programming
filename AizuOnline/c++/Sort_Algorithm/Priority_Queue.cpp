#include <iostream> 
#define MAX 100
using namespace std; 

int A[MAX+1];
int H(0);

void Insert(int val)
{
    ++H;
    A[H] = val;

    int id = H;
    while(id > 1 && A[id] > A[id/2])
    {
        swap(A[id], A[id/2]);
        id = id/2;
    }
}

void maxHeapify(int i)
{
    int l = i * 2;
    int r = i * 2 + 1;
    int max_id = i;

    if (l <= H && A[l] > A[i]) max_id = l;

    if (r <= H && A[r] > A[max_id]) max_id = r;

    if (max_id != i) 
    {
        swap(A[i], A[max_id]);
        maxHeapify(max_id);
    }
}

int ExtractMax()
{
    if (H<1) return 0;
    int max_v = A[1];
    A[1] = A[H--];
    maxHeapify(1);
    return max_v;
}

int main() 
{
    char ord[10];
    while (true)
    {
        int val;
        cin >> ord;

        if (ord[0] == 'i') 
        {
            cin >> val;
            Insert(val);
        }
        else if (ord[0] == 'e' && ord[1] == 'x')
        {
            cout << ExtractMax() << endl;
        }
        else 
        {
            break;
        }
    }
}