#include <iostream>
#define ARRAY_MAX 300000
using namespace std;

// 配列の真ん中から前半部分、後半部分それぞれ昇順になっているかを確認する
// なっていないことがわかり次第falseを返す
bool IsAscendingOrder(int array[], int numArray) 
{
    if (numArray == 2) 
    {
        return array[0] < array[1] ? true : false;
    }
    int step_downwards = 1, step_upwards = 1;
    int mid_array = numArray / 2;
    int lastVal_downwards = array[mid_array];
    int lastVal_upwards = array[mid_array];
    while (step_downwards != -1 && step_upwards != -1) 
    {
        if (step_downwards != -1) 
        {
            if (lastVal_downwards < array[mid_array-step_downwards]) return false;
            lastVal_downwards = array[mid_array-step_downwards];
            step_downwards++;
            if (mid_array - step_downwards < 0) step_downwards = -1; // finish stepping downwards
        }

        if (step_upwards != -1) 
        {
            if (array[mid_array+step_upwards] < lastVal_upwards) return false;
            lastVal_upwards = array[mid_array+step_upwards];
            step_upwards++;
            if ( numArray-1 < mid_array + step_upwards ) step_upwards = -1; // finish stepping upwards
        }
    }
    return true;
}

// 問題は何回目でこの配列はもう昇順に成り得ないと判断できるか。
// 判断できた瞬間に-1を返せば、大きなデータにも対応できる。
int main() 
{
    int numArray, Array[ARRAY_MAX+10], numOrder;
    scanf("%d", &numArray);
    for (int i = 0; i < numArray; ++i) scanf("%d", &Array[i]);
    scanf("%d", &numOrder);
    if (IsAscendingOrder(Array, numArray)) printf("%d\n", 0);
    else 
    {
        int counting = 1;
        int ord1, ord2;
        while (true) 
        {
            scanf("%d %d", &ord1, &ord2);
            swap(Array[ord1-1], Array[ord2-1]); // swap element
            if (IsAscendingOrder(Array, numArray)) 
            {
                printf("%d\n", counting);
                break;
            }
            counting++;
            if (counting > numOrder) 
            {
                printf("%d\n", -1);
                break;
            }
        }
    }
}