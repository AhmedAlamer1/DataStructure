#pragma once
#include <iostream>
#include "IDataStructure.h";
using namespace std;
struct Node {
    int item, height;
    Node* left;
    Node* right;
};
class AVLtree:IDataStructure {
    Node* root;
public:
    AVLtree();
    bool IsEmpty();// O(1)
    int Height(Node* node);// O(1)
    int balanceFactor(Node* node);// O(1)
    Node* GetMnNode(Node* node);// O(1)
    Node* RightRotation(Node* X);// O(1)
    Node* LeftRotation(Node* X);// O(1)
    Node* InsertRec(int key, Node* cur);// O(h)
    void Insert(int key);// O(h)
    Node* Delete(Node* cur, int key); // O(h)
    bool search(Node* cur, int key); // O(h)
    void InOrder(Node* cur);//O(n)
    Node* GetRoot();//O(1)
    Node* ClearAvl(Node* root);//O(n)
    void clear();//O(n)
    int CountNodes(Node* cur);//O(n)
    int Size();//O(n)
    void Display();//O(n)
};

