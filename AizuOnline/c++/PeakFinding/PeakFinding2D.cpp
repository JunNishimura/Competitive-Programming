#include <iostream> 
#include <random>
#define MAX 10
using namespace std;

void Random2DarrayGenerator(int (*array)[MAX+1]) 
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_real_distribution<> dist(0, 100);

    for (int i = 0; i <= MAX; ++i) 
    {
        for (int j = 0; j <= MAX; ++j) 
        {
            if (i == 0 || j == 0) array[i][j] = -1;
            else array[i][j] = dist(engine);
        }
    }
}

void Display2Darray(int (*array)[MAX+1]) 
{
    for (int i = 1; i <= MAX; ++i) 
    {
        for (int j = 1; j <= MAX; ++j) 
        {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}

int FindGlobalMaxima_row(int *array) 
{
    int max_id = 1;
    for (int i = 2; i < MAX; ++i) 
    {   
        if (array[i] > array[max_id]) max_id = i;
    } 
    return max_id;
}   

int PeakFinding2D(int (*array)[MAX+1], int top, int bottom) 
{
    int middle = ( top + bottom ) / 2;
    int max_id = FindGlobalMaxima_row(array[middle]);

    if (array[middle][max_id] > array[middle-1][max_id] &&
        array[middle][max_id] > array[middle+1][max_id] )
    {
        printf("peak at(%d, %d) -> %d\n", middle, max_id, array[middle][max_id]);
        return array[middle][max_id];
    } 
    else if (array[middle][max_id] < array[middle-1][max_id]) 
    {
        return PeakFinding2D(array, 0, middle-1 );
    }
    else 
    {
        return PeakFinding2D(array, middle+1, bottom);
    } 

}

int main() 
{
    int array[MAX+1][MAX+1];
    Random2DarrayGenerator(array);
    Display2Darray(array);

    PeakFinding2D(array, 1, MAX);
}