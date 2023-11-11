#pragma once
#include <iostream>
#include <queue>
#include "IDataStructure.h";
using namespace std;
struct Node {
        int item;
        Node* left;
        Node* right;
};
class BST:IDataStructure {
    Node* root;
public:
    BST();
    bool IsEmpty(); // O(1)
    Node* GetMinNode(Node* Root); // O(h)
    Node* GetMxNode(Node* Root); // O(h)
    int GetMinKey(); // O(h)
    int GetMxKey(); // O(h)
    int Height(Node* cur); // O(h)
    Node* InsertRec(int key, Node* cur); // O(h)
    void Insert(int item); // O(h)
    Node* DeleteNode(int key, Node* Root); // O(h)
    bool search(Node* cur, int key); // O(h)
    void INOrder(Node* cur); // O(n)
    void PreOrder(Node* cur); // O(n)
    void PostOrder(Node* cur); // O(n)
    void LevelOrder(Node* Root); // O(n)
    void PrintGivenLevel(int level, Node* cur); // O(n)
    void PrintAllLeafNodes(Node* cur); // O(n)
    void PrintAllNoneLeafNodes(Node* cur); // O(n)
    void RightView(); // O(n)
    void LeftView(); // O(n)
    void DeleteNodeByKey(int key); // O(h)
    void DeleteNode(Node* node); // O(h)
    int CountNodes(Node* cur); // O(n)
    int Size();//O(n)
    void clear();//O(n)
    Node* clearBst(Node* root);//O(n)
    void Display();//O(h)
};

