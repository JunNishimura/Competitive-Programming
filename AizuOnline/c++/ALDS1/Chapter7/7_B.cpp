#include <iostream>
#define TREE_SIZE 30
#define NIL -1
using namespace std;

struct Node 
{
    int parent_node = NIL;
    int left_child = NIL;
    int right_child = NIL;
};

Node Tree[TREE_SIZE];
int Depth[TREE_SIZE];
int Height[TREE_SIZE];

// set depth of all nodes by recursion
void Set_depth_of_node(int node_id, int depth)
{
    Depth[node_id] = depth;
    // if there is a child
    if (Tree[node_id].left_child != NIL) Set_depth_of_node(Tree[node_id].left_child, depth+1);
    if (Tree[node_id].right_child != NIL) Set_depth_of_node(Tree[node_id].right_child, depth+1);
}

// set height of all nodes by recursion
int Set_height_of_node(int node_id) 
{
    int l_height = 0, r_height = 0;
    // if there is a child
    if (Tree[node_id].left_child != NIL) l_height = Set_height_of_node(Tree[node_id].left_child) + 1;
    if (Tree[node_id].right_child != NIL) r_height = Set_height_of_node(Tree[node_id].right_child) + 1;

    return Height[node_id] = (l_height < r_height ? r_height : l_height);
}

int main() 
{
    int node_num, node_id, l_child, r_child;
    scanf("%d", &node_num);
    for (int i = 0; i < node_num; ++i) 
    {
        scanf("%d %d %d", &node_id, &l_child, &r_child);
        Tree[node_id].left_child = l_child;  // set left child
        Tree[node_id].right_child = r_child; // set right child 
        
        // set parent if the node has children
        if (l_child != -1) Tree[l_child].parent_node = node_id;
        if (r_child != -1) Tree[r_child].parent_node = node_id;
    }

    // search root of Tree
    int root = 0;
    while (Tree[root].parent_node != NIL) 
    {
        root++;
    }

    // set depth of all nodes
    Set_depth_of_node(root, 0);

    // set height of all nodes
    Set_height_of_node(root);

    // print out below
    for (int i = 0; i < node_num; ++i) 
    {
        printf("node %d: parent = %d, ", i, Tree[i].parent_node);

        // print out siblings
        if (Tree[i].parent_node == NIL) printf("sibling = -1, "); // if this is root
        else 
        {
            if (i == Tree[Tree[i].parent_node].left_child) // if this is left child, print right child
            {
                printf("sibling = %d, ", Tree[Tree[i].parent_node].right_child);
            }
            else // if this is right child, print left child
            {
                printf("sibling = %d, ", Tree[Tree[i].parent_node].left_child);
            }
        }

        // print out degree (number of children)
        int degree = 0;
        if (Tree[i].left_child != NIL) degree++;
        if (Tree[i].right_child != NIL) degree++;
        printf("degree = %d, ", degree);

        // print out depth
        printf("depth = %d, ", Depth[i]);

        // print out height
        printf("height = %d, ", Height[i]);

        // print out position
        if (i == root) printf("root\n");
        else if (degree == 0) printf("leaf\n");
        else printf("internal node\n");
    }
}