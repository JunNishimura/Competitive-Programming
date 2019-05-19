#include <iostream> 
#define A_SIZE 500001
using namespace std;

void MaxHeapify(int id, int H, int array[])
{
    int largest;
    int l = 2 * id;
    int r = 2 * id + 1;
    if (l <= H && array[l] > array[id]) largest = l;
    else largest = id;
    if (r <= H && array[r] > array[largest]) largest = r;

    if (largest != id)
    {
        swap(array[largest], array[id]);
        MaxHeapify(largest, H, array);
    }
}

void MinHeapify(int id, int H, int array[])
{
    int smallest, l, r;
    l = 2 * id;
    r = 2 * id + 1;
    if (l <= H && array[l] < array[id]) smallest = l;
    else smallest = id;
    if (r <= H && array[r] < array[smallest]) smallest = r;

    if (smallest != id)
    {
        swap(array[id], array[smallest]);
        MinHeapify(smallest, H, array);
    }
}

int main()
{
    int H, array[A_SIZE], value;
    scanf("%d", &H);
    for (int id = 1; id <= H; ++id)
    {
        scanf("%d", &value);
        array[id] = value;
    }

    for (int id = H/2; id >= 1; --id) MinHeapify(id, H, array);

    for (int i = 1; i <= H; ++i)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}