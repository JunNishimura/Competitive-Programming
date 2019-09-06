#include <iostream> 
#include <vector> 
#define N 100
using namespace std;

int AVL[N];
int current_size = 0;

void Inorder_show(int index) 
{
    while(AVL[index] != -1)  
    {
        Inorder_show(2 * index + 1);
        cout << AVL[index] << " ";
        Inorder_show(2 * index + 2);
    }
    cout << endl;
}

// if there is a number, return 1. if not, return 0.
int Check(int number) 
{
    int T_size = (sizeof(AVL)/sizeof(*AVL));
    int index = 0;
    while(index < T_size)
    {
        if (AVL[index] == number) 
        {
            return 1;
        }
        else if (AVL[index] > number) // 求めているかずが小さい時は左子部分木を探そう
        {
            index = index * 2 + 1;
        }
        else // 求めている数が大きい時は右子部分木を探そう
        {
            index = index * 2 + 2;
        }
    }
    return 0; // ここまで来るということは探索失敗
}

void Construct_AVL() 
{

}

void Insert(int number) 
{
    ++current_size;
}

void Delete(int number) 
{
    if (!Check(number)) // if the number isn't in an array, return here
    {
        return;
    }


}

int main() 
{
    int input;
    char order[10];

    // init by -1
    for (int i = 0; i < N; ++i) 
    {
        AVL[i] = -1;
    }

    while (1)
    {
        cout << "操作を入力してください(q:quit, i:insert, d:delete)" << endl;
        cin >> order;
        if (order[0] == 'q')
        {
            cout << "終了します" << endl;
            break;
        }
        else
        {
            cout << "数字を入力してください" << endl;
            cin >> input; 

            if (order[0] == 'i')
            {
                Insert(input);
            }
            else if (order[0] == 'd')
            {
                Delete(input);
            }
        }
    }
}