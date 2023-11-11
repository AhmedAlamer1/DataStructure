#pragma once
#include <iostream>
#include "IDataStructure.h"
using namespace std;
class ArrayList:IDataStructure {
    int* arr;
    int length;
    int MxSize;
public:
    ArrayList(int s);
    bool IsEmpty();
    bool IsFull();
    int Size();
    void Display();
    int GetElement(int idx);
    void InsertAt(int idx, int val);
    void Insert(int val);
    void Update(int idx, int val);
    int search(int val);
    void Delete(int idx);
    void clear();
    ~ArrayList();
};

