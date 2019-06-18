#ifndef HASHSET_HPP_20190612_1130_
#define HASHSET_HPP_20190612_1130_

#include <iostream>
#include <string> 

struct HashNode
{
    int data;
    HashNode* next;
    HashNode(int data = 0, HashNode* next = nullptr) 
    {
        this->data = data;
        this->next = next;
    }
};

class HashSet 
{
public: 
    HashSet();
    ~HashSet();
    void Add(int value);
    bool Contains(int value);
    void PrintStructure() const;
    void Remove(int value); 
private: 
    HashNode** elements;
    int capacity;
    int size;

    int hashCode(int value) const;
};

#endif 