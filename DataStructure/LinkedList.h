#pragma once
#include <iostream>
#include "IDataStructure.h";
using namespace std;

class LinkedList:IDataStructure{
    struct Node {
        int item;
        Node* next;
    };
    Node* Head, * Tail;
    int length;
public:
    LinkedList();
    bool IsEmpty(); // O(1)
    int Size(); // O(1)
    void FirstAdd(int item);// O(1)
    void Insert(int item);// O(1) //insert first
    void InsertLast(int item) ;// O(1)
    void InsertAt(int idx, int item);// O(n)
    void RemoveFirst();//O(1)
    void RemoveLast();//O(n)
    void RemoveElement(int element);//O(n)
    void RemoveAt(int idx);//O(n)
    void Reverse();//O(n)
    void Display();// O(n)
    int Search(int element);//O(n)
    void clear();//O(n)
};

