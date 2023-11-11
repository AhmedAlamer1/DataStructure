#pragma once
#include <iostream>
#include <assert.h>
#include "IDataStructure.h";
using namespace std;
class ArrayQueueType:IDataStructure {
    int rear;
    int front;
    int len;
    int* arr;
    int MxSize;
public:
    ArrayQueueType(int sz);
    bool IsEmpty();//O(1)
    bool IsFull();//O(1)
    int Size();//O(1)
    void Insert(int element);//O(1)
    void Dequeue();//O(1)
    int GetFront();//O(1)
    int GetRear();//O(1)
    void Display();//O(n)
    int Search(int element);//O(n)
    void clear();//O(n)
};

