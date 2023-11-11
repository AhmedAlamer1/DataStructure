#pragma once
#include <iostream>
#include "IDataStructure.h"
using namespace std;
class LinkedStack:IDataStructure
{
    struct SNode {
        int item;
        SNode* next;
    };
    SNode* top;
    int len;
public:
    LinkedStack();
    bool IsEmpty(); //O(1)
    int Size(); //O(1)
    int GetTop(); //O(1)
    void Insert(int item);//O(1)
    void Delete();//O(1)
    void Display();//O(n)
    void clear();//O(n)
};

