#pragma once
#include <iostream>
#include "IDataStructure.h";
using namespace std;
class DoublyLinkedList:IDataStructure {
    struct Node {
        int item;
        Node* prev, * next;
    };
    int length;
    Node* Head, * Tail;
public:
    DoublyLinkedList();
    bool IsEmpty();//O(1)
    void FirstAdd(int item);//O(1)
    void Insert(int item);//O(1)//insert first
    void InsertLast(int item);//O(1)
    void InsertAt(int idx, int item);//O(n)
    void RemoveFirst();//O(1)
    void RemoveLast();//O(1)
    void RemoveAt(int idx);//O(n)
    void Display();//O(n)
    void ReversedDisplay();//O(n)
    void clear();//O(n)
    int Size();
};


