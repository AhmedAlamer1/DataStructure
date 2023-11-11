#pragma once
#include <iostream>
#include "IDataStructure.h";
using namespace std;
class MaxHeap:IDataStructure {
    int* arr;
    int MaxSize;
    int size;
public:
    MaxHeap(int sz); // O(1)
    bool isempty(); // O(1)
    int Parent(int i); // O(1)
    int Lchild(int i); // O(1)
    int Rchild(int i); // O(1)
    void heapify(int i); // O(log(n))
    int removeMx(); // O(log(n))
    void increaseKey(int i, int val); // O(log(n))
    int GetMax(); // O(1)
    int Size(); // O(1)
    void DeleteKey(int i); // O(log(n))
    void Insert(int val); // O(log(n))
    void Display();//O(n)
    void clear();//O(n)
};

