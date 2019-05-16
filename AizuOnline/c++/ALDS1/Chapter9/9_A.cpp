#include <iostream>
#define A_SIZE 300
using namespace std;

int main() 
{
    int h_size, array[A_SIZE], value;
    scanf("%d", &h_size);
    for (int id = 1; id <= h_size; ++id) 
    {
        scanf("%d", &value);
        array[id] = value;
    }
    for (int id = 1; id <= h_size; ++id) 
    {
        printf("node %d: key = %d, ", id, array[id]);
        if (id/2 >= 1) printf("parent key = %d, ", array[id/2]);
        if (id*2 <= h_size) printf("left key = %d, ", array[id*2]);
        if (id*2+1 <= h_size) printf("right key = %d, ", array[id*2+1]);
        printf("\n");
    }
}