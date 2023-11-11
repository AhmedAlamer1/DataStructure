#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	length = 0;
	Head = Tail = NULL;
}

bool DoublyLinkedList::IsEmpty()
{
    return length == 0;
}

void DoublyLinkedList::FirstAdd(int item)
{
    Node* NewNode = new Node;
    NewNode->item = item;
    NewNode->prev = NewNode->next = NULL;
    Head = Tail = NewNode;
    length++;
}

void DoublyLinkedList::Insert(int item)
{
    if (IsEmpty()) {
        FirstAdd(item);
    }
    else {
        Node* NewNode = new Node;
        NewNode->item = item;
        NewNode->next = Head;
        NewNode->prev = NULL;
        Head->prev = NewNode;
        Head = NewNode;
        length++;
    }
}

void DoublyLinkedList::InsertLast(int item)
{
    if (IsEmpty()) {
        FirstAdd(item);
    }
    else {
        Node* NewNode = new Node;
        NewNode->item = item;
        NewNode->next = NULL;
        NewNode->prev = Tail;
        Tail->next = NewNode;
        Tail = NewNode;
        length++;
    }
}

void DoublyLinkedList::InsertAt(int idx, int item)
{
    if (idx == 0)
        Insert(item);
    else if (idx == length)
        Insert(item);
    else {
        Node* NewNode = new Node, * pre = Head;
        for (int pos = 0; pos < idx - 1; pos++)
            pre = pre->next;
        NewNode->item = item;
        NewNode->prev = pre;
        NewNode->next = pre->next;
        pre->next->prev = NewNode;
        pre->next = NewNode;
        length++;
    }
}

void DoublyLinkedList::RemoveFirst()
{
    if (length == 1) {
        Head = Tail = NULL;
        length = 0;
        return;
    }
    Node* curr = Head;
    Head = Head->next;
    Head->prev = NULL;
    delete curr;
    length--;
}

void DoublyLinkedList::RemoveLast()
{
    if (length == 1) {
        Head = Tail = NULL;
        length = 0;
        return;
    }
    Node* curr = Tail;
    Tail = Tail->prev;
    Tail->next = NULL;
    delete curr;
    length--;
}

void DoublyLinkedList::RemoveAt(int idx)
{
    if (idx == 0) {
        RemoveFirst();
    }
    else if (idx == length - 1) {
        RemoveLast();
    }
    else {
        Node* curr = Head, * tmp;
        for (int pos = 0; pos < idx - 1; pos++)
            curr = curr->next;
        tmp = curr->next;
        curr->next = curr->next->next;
        curr->next->next->prev = curr;
        delete tmp;
        length--;
    }
}

void DoublyLinkedList::Display()
{
    Node* curr = Head;
    while (curr != NULL) { cout << curr->item << ' ', curr = curr->next; }
    cout << endl;
}

void DoublyLinkedList::ReversedDisplay()
{
    Node* curr = Tail;
    while (curr != NULL) {
        cout << curr->item << ' ', curr = curr->prev;
    }
    cout << endl;
}

void DoublyLinkedList::clear()
{
    while (Head != NULL) {
        Node* tmp = Head;
        Head = Head->next;
        delete tmp;
    }
    length = 0;
}

int DoublyLinkedList::Size()
{
    return length;
}

