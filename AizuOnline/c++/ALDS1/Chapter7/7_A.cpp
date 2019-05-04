#include <iostream>
#define NODE_MAX 100000
#define NIL -1
using namespace std;

struct Node
{
    int parent_node = NIL;
    int leftChild_node = NIL;
    int rightSibling_node = NIL;
};

Node Tree[NODE_MAX];
int Depth_of_Node[NODE_MAX];

// 対象となるノードのみの接点を求める。
int GetDepth(int node_id)
{
    int depth = 0;
    while (Tree[node_id].parent_node != NIL) 
    {
        node_id = Tree[node_id].parent_node;
        depth++;
    }
    return depth;
}

// 再帰関数を用いて全ノードの深さを求める
// 再帰の構造：
// (1) 現在のノードidの深さをセット
// (2) ノードの右兄弟が存在するなら、右兄弟にも同じ深さをセット
// (3) ノードの左子が存在するなら、左子には深さを1足してセット
void CalcDepthByRecursion(int node_id, int depth) 
{
    Depth_of_Node[node_id] = depth;
    if (Tree[node_id].rightSibling_node != NIL) 
    {
        CalcDepthByRecursion(Tree[node_id].rightSibling_node, depth);
    }
    if ( Tree[node_id].leftChild_node != NIL )
    {
        CalcDepthByRecursion(Tree[node_id].leftChild_node, depth+1);
    }
}

// Print out children nodes
void PrintChildrenNodes(int node_id) 
{
    printf("[");
    int child_node = Tree[node_id].leftChild_node, i = 0;
    while (child_node != NIL) 
    {
        if (i) printf(", ");
        printf("%d", child_node);
        child_node = Tree[child_node].rightSibling_node;
        ++i;
    }
    printf("]");
}

int main() 
{
    int num_node, node_id, num_child, root;
    scanf("%d", &num_node);
    for (int i = 0; i < num_node; ++i) 
    {
        scanf("%d %d", &node_id, &num_child);
        int child_node, prev_node;
        for (int j = 0; j < num_child; ++j) 
        {
            scanf("%d", &child_node);
            if (!j) Tree[node_id].leftChild_node = child_node; // set left_child node
            Tree[child_node].parent_node = node_id; // set parent_node
            if (j) Tree[prev_node].rightSibling_node = child_node; // set rightSibling of previous node
            prev_node = child_node; // set current node as prev node
        }
    }

    // search node
    for (int i = 0; i < num_node; ++i) 
    {
        if (Tree[i].parent_node == NIL) 
        {
            root = i;
            break;
        }
    }

    CalcDepthByRecursion(root, 0);
    for (int i = 0; i < num_node; ++i) 
    {
        printf("node %d: parent = %d, depth = %d, ", i, Tree[i].parent_node, Depth_of_Node[i]);
        if (Tree[i].parent_node == NIL) printf("root, ");
        else if (Tree[i].leftChild_node == NIL) printf("leaf, ");
        else printf("internal node, ");
        PrintChildrenNodes(i);
        printf("\n");
    }
}