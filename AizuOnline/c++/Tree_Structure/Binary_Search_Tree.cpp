#include <iostream> 
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* l_child;
    Node* r_child;
};

Node* createNewNode(int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->l_child = nullptr;
    newNode->r_child = nullptr;
    return newNode;
}

bool Search(Node* root, int data) 
{
    if (root == nullptr) 
    {
        return false;
    } 
    else if (root->data == data)
    {
        return true;
    }
    else 
    {
        if (data < root->data) return Search(root->l_child, data);
        else return Search(root->r_child, data);
    }
}

Node* SearchMinimumNode(Node* root) 
{
    Node* tmpNode = root;
    while (tmpNode->l_child != nullptr)
    {
        tmpNode = tmpNode->l_child;
    }
    return tmpNode;
}

Node* SearchMaximumNode(Node* root)
{
    Node* tmpNode = root;
    while (tmpNode->r_child != nullptr) 
    {
        tmpNode = tmpNode->r_child;
    }
    return tmpNode;
}

// Insertion with recursion
void Insert_Recursion(Node** root, int data) 
{
    if (*root == nullptr) 
    {
        *root = createNewNode(data);
    }  
    else if (data <= (*root)->data)
    {
        Insert_Recursion(&((*root)->l_child), data);
    }
    else 
    {
        Insert_Recursion(&((*root)->r_child), data);
    }
}

// Insertion with loop
void Insert_Loop(Node** root, int data) 
{
    Node* newNode = createNewNode(data);
    Node* tmpNode = *root;
    Node* parentNode = *root;

    while (tmpNode != nullptr) 
    {
        parentNode = tmpNode;
        if (newNode->data <= tmpNode->data) 
        {
            tmpNode = tmpNode->l_child;
        } 
        else 
        {
            tmpNode = tmpNode->r_child;
        }
    }
    if (newNode->data <= parentNode->data) parentNode->l_child = newNode;
    else parentNode->r_child = newNode;
}

int GetHeight(Node* root)
{
    if (root == nullptr) return -1;
    return max(GetHeight(root->l_child), GetHeight(root->r_child)) + 1;
}

void PreorderPrinting(Node* root) 
{
    cout << root->data << " ";
    if (root->l_child != nullptr) PreorderPrinting(root->l_child);
    if (root->r_child != nullptr) PreorderPrinting(root->r_child);
}

void InorderPrinting(Node* root) 
{
    if (root->l_child != nullptr) InorderPrinting(root->l_child);
    cout << root->data << " ";
    if (root->r_child != nullptr) InorderPrinting(root->r_child);
}

void PostorderPrinting(Node* root) 
{
    if (root->l_child != nullptr) PostorderPrinting(root->l_child);
    if (root->r_child != nullptr) PostorderPrinting(root->r_child);
    cout << root->data << " ";
}  

void Levelorder_Traversal(Node* root) 
{
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        cout << Q.front()->data << " ";
        if (Q.front()->l_child != nullptr) Q.push(Q.front()->l_child);
        if (Q.front()->r_child != nullptr) Q.push(Q.front()->r_child);
        Q.pop();
    } 
    cout << endl;
}

bool SubtreeLesser(Node* root, int value) 
{
    if (root == nullptr) return true;
    else
    {
        Node* max = SearchMaximumNode(root);
        if (max->data <= value) return true; 
        else return false;
    }
}

bool SubtreeGreater(Node* root, int value) 
{
    if (root == nullptr) return true;
    else 
    {
        Node* min = SearchMinimumNode(root);
        if (min->data > value) return true;
        else return false;
    }
}

bool isBinarySearchTree(Node* root, int minValue, int maxValue) 
{
    if (root == nullptr) return true;
    
    if (root->data > minValue
        && root->data < maxValue
        && isBinarySearchTree(root->l_child, minValue, root->data)
        && isBinarySearchTree(root->r_child, root->data, maxValue))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

Node* DeleteNode(Node* root, int data) 
{
    if (root == nullptr) return root;
    else if (root->data > data) root->l_child = DeleteNode(root->l_child, data);
    else if (root->data < data) root->r_child = DeleteNode(root->r_child, data);
    else // found the node to delete 
    {
        if (root->l_child == nullptr && root->r_child == nullptr) 
        {
            delete root;
            root = nullptr;
        }
        else if (root->l_child != nullptr)
        {
            Node* tmp = root;
            root = root->r_child;
            delete tmp;
        } 
        else if (root->r_child != nullptr) 
        {
            Node* tmp = root;
            root = root->l_child;
            delete tmp;
        }
        else 
        {
            Node* min = SearchMinimumNode(root->r_child);
            root->data = min->data;
            root->r_child = DeleteNode(root->r_child, min->data);
        }

    }
    return root;
}

int main() 
{
    Node* root = nullptr;
    Insert_Recursion(&root, 15);
    Insert_Recursion(&root, 10);
    Insert_Recursion(&root, 20);
    Insert_Loop(&root, 5);
    Insert_Loop(&root, 25);
    Insert_Loop(&root, 30);

    int number;
    cout << "enter some number >> " << flush;
    cin >> number;
    if (Search(root, number)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    cout << "minimum node is: " << SearchMinimumNode(root)->data << endl;
    cout << "maximum node is: " << SearchMaximumNode(root)->data << endl;

    cout << "Height of Tree is: " << GetHeight(root) << endl;

    cout << "preorder printing: ";
    PreorderPrinting(root);
    cout << endl;
    cout << "inorder printing: ";
    InorderPrinting(root);
    cout << endl;
    cout << "postorder printing: ";
    PostorderPrinting(root);
    cout << endl;

    cout << "Level order priting: ";
    Levelorder_Traversal(root);

    cout << "Is this binary search tree? > ";
    if (isBinarySearchTree(root, -1000000000, 10000000000)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}