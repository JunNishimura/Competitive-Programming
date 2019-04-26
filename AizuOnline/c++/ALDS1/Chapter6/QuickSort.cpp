#include <iostream>
#define MAX 100001
#define H 2000000000
using namespace std;

struct Card
{
    int value;
    char mark;
};

Card L[MAX/2+10], R[MAX/2+10];

int Partition(Card* card, int start, int end) 
{
    int j = start-1; // last index of smaller group
    for (int i = start; i < end; ++i) 
    {
        if (card[i].value <= card[end].value) 
        {
            j++;
            swap(card[i], card[j]);
        }
    }
    swap(card[j+1], card[end]);
    return j+1;
}

void QuickSort(Card* card, int start, int end) 
{
    if(start < end) 
    {
        int p = Partition(card, start, end);
        QuickSort(card, start, p-1);
        QuickSort(card, p+1, end);
    }
}

void Merge(Card* card, int start, int middle, int end) 
{
    int n1 = middle - start;
    int n2 = end - middle;
    for (int i = 0; i < n1; ++i) L[i] = card[start+i];
    for (int i = 0; i < n2; ++i) R[i] = card[middle+i];
    L[n1].value = L[n2].value = H;
    int j = 0, k = 0;
    for (int i = start; i < end; ++i) 
    {
        if (L[j].value <= R[k].value) card[i] = L[j++];
        else card[i] = R[k++];
    }
}

void MergeSort(Card* card, int start, int end)  
{
    if (start + 1 < end) 
    {
        int middle = (start+end)/2;
        MergeSort(card, start, middle);
        MergeSort(card, middle, end);
        Merge(card, start, middle, end);
    }
}



int main() 
{
    int n, v, stable=1;
    char ch[10];
    Card quick[MAX], merge[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
    {
        scanf("%s %d", ch, &v);
        quick[i].mark = merge[i].mark = ch[0];
        quick[i].value = merge[i].value = v;
    } 
    QuickSort(quick, 0, n-1);
    MergeSort(merge, 0, n);

    for (int i = 0; i < n; ++i) {
        if (quick[i].mark != merge[i].mark) stable = 0;
    }
    
    if (stable == 1) printf("Stable\n");
    else printf("Not stable\n");
    for (int i = 0; i < n; ++i) 
    {
        printf("%c %d\n", quick[i].mark, quick[i].value);
    } 
}