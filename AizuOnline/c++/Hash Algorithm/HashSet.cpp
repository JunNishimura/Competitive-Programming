#include "HashSet.hpp"
using namespace std;

HashSet::HashSet()
{
    cout << "called constructor" << endl;
    capacity = 10;
    size = 0;
    elements = new HashNode*[capacity];
}

HashSet::~HashSet() 
{
    delete[] *elements;
}

void HashSet::Add(int value) 
{
    // if (! Contains(value))
    // {
        HashNode* new_element = new HashNode(value, nullptr);
        new_element->next = elements[hashCode(value)];
        elements[hashCode(value)] = new_element;
        ++size;
    // }
} 

bool HashSet::Contains(int value) 
{
    int bucket = hashCode(value);
    HashNode* cur = elements[bucket];
    while (cur != nullptr) 
    {
        if (cur->data == value) return true;
        
        cur = cur->next;
    }
    return false;
}

void HashSet::Remove(int value) 
{
    if (!Contains(value)) return;
    int bucket = hashCode(value);

    HashNode* cur = elements[bucket];

    // if the front is target node to delete 
    if (cur->data == value) 
    {
        elements[bucket] = cur->next;
        delete cur;
    }
    while (cur->next != nullptr) 
    {
        if (cur->next->data == value) 
        {
            HashNode* delNode = cur->next;
            cur->next = delNode->next;
            delete delNode;
            --size;
            break;
        }
        cur = cur->next;
    }
}

void HashSet::PrintStructure() const
{
    for (int i = 0; i < capacity; ++i) 
    {
        cout << '[' << i << "]: ";
        HashNode* cur = elements[i];
        while (cur != nullptr) 
        {
            cout << cur->data << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
    cout << "size = " << size << endl;
}


int HashSet::hashCode (int value) const
{
    return abs(value) % this->capacity;
}