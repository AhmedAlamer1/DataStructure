#pragma once
#include <iostream>
#include "IDataStructure.h"
using namespace std;
class ArrayStack:IDataStructure
{
    int top;
    int MxSize;
    int *arr;
public:
    ArrayStack(int Size);
    bool IsEmpty();
    bool IsFull();
    void Insert(int item);
    void Delete();
    int GetTop();
    int Size();
    void Display();
    void clear();
};

