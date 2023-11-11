#pragma once
#include <iostream>
#include <assert.h>
#include "IDataStructure.h";
using namespace std;
class LinkedQueue:IDataStructure {
    struct QNode {
        int item;
        QNode* next;
    };
    QNode* front, * rear;
    int len;
public:
    LinkedQueue();
    bool IsEmpty();//O(1)
    int Size();//O(1)
    void Insert(int item);//O(1)
    void DeQueue();//O(1)
    int GetFront();//O(1)
    int GetRear();//O(1)
    void Display();//O(n)
    void clear();//O(n)
};

