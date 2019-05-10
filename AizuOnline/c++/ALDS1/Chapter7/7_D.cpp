#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder, inorder;


int main() 
{
    int size, node_id;
    
    scanf("%d", &size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &node_id);
        preorder.push_back(node_id);
    }

    for (int i = 0; i < size; ++i) 
    {
        scanf("%d", &node_id);
        inorder.push_back(node_id);
    }


}