#include <iostream>
#include <cstring>
using namespace std;

struct Card
{
    char mark;
    int number;
};

void Print(Card _c[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i != len-1) cout << _c[i].mark << _c[i].number << " ";
        else cout << _c[i].mark << _c[i].number << endl;
    }
}

bool isStable(Card a1[], Card a2[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (a1[i].mark != a2[i].mark) 
        {
            return false;
        }
    }
    return true;
}

void BubbleSort(Card _c[], int len)
{
    int j = 0;
    while (j < len-1)
    {
        for (int i = len-1; i > j; i--)
        {
            if (_c[i].number < _c[i-1].number) swap(_c[i], _c[i-1]);
        }
        j++;
    }
    Print(_c, len);
    cout << "Stable" << endl;
}

void SelectionSort(Card _c[], int len)
{
    int j = 0;
    while (j < len-1)
    {
        int minI = j;
        for (int i = j+1; i < len; i++)
        {
            if (_c[minI].number > _c[i].number) minI = i; 
        }
        swap(_c[j], _c[minI]);
        j++;
    }
    Print(_c, len);
}

int main() 
{
    Card a[40], b[40], c[40];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i].mark >> a[i].number;
    }
    memcpy(b, a, sizeof b);
    memcpy(c, a, sizeof c);
    BubbleSort(b, n);
    SelectionSort(c, n);
    if(isStable(b, c, n)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
}