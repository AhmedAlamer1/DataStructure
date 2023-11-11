#include "LinkedList.h"

LinkedList::LinkedList()
{
    Head = Tail = NULL;
    length = 0;
}

bool LinkedList::IsEmpty()
{
    return length == 0;
}

int LinkedList::Size()
{
    return length;
}

void LinkedList::FirstAdd(int item)
{
    Node* NewNode = new Node;
    NewNode->item = item;
    NewNode->next = NULL;
    Head = Tail = NewNode;
    length++;
}

void LinkedList::Insert(int item)
{
    if (IsEmpty())
        FirstAdd(item);
    else {
        Node* NewNode = new Node;
        NewNode->item = item;
        NewNode->next = Head;
        Head = NewNode;
        length++;
    }
}
void LinkedList::InsertLast(int item)
{
    if (IsEmpty())
        FirstAdd(item);
    else {
        Node* NewNode = new Node;
        NewNode->item = item;
        NewNode->next = NULL;
        Tail->next = NewNode;
        Tail = NewNode;
        length++;
    }
}

void LinkedList::InsertAt(int idx, int item)
{
    if (idx == 0)
        Insert(item);
    else if (idx == length)
        InsertLast(item);
    else {
        Node* PreNode = Head;
        for (int pos = 0; pos < idx - 1; pos++)
            PreNode = PreNode->next;
        Node* NewNode = new Node;
        NewNode->item = item;
        NewNode->next = PreNode->next;
        PreNode->next = NewNode;
        length++;
    }
}

void LinkedList::RemoveFirst()
{
    if (IsEmpty())
        return;
    else if (length == 1) {
        Head = Tail = NULL;
        length = 0;
    }
    else {
        Node* curr = Head;
        Head = Head->next;
        delete curr;
        length--;
    }
}

void LinkedList::RemoveLast()
{
    if (IsEmpty())
        return;
    else if (length == 1) {
        Head = Tail = NULL;
        length = 0;
    }
    else {
        Node* curr = Head;
        for (int pos = 0; pos < length - 2; pos++)
            curr = curr->next;
        Tail = curr;
        curr = curr->next;
        delete curr;
        Tail->next = NULL;
        length--;
    }
}

void LinkedList::RemoveElement(int element)
{
    if (IsEmpty())
        return;
    if (Head->item == element) {
        RemoveFirst();
        return;
    }
    if (Tail->item == element) {
        RemoveLast();
        return;
    }
    Node* Pre = Head, * tmp;
    while (Pre->next->item != element and Pre->next != NULL)
        Pre = Pre->next;
    if (Pre->next == NULL) {
        cout << "Not Found";
    }
    else {
        tmp = Pre->next;
        Pre->next = Pre->next->next;
        delete tmp;
        length--;
    }
}

void LinkedList::RemoveAt(int idx)
{
    if (idx == length - 1)
        RemoveLast();
    else if (idx == 0)
        RemoveFirst();
    else {
        Node* Pre = Head, * tmp;
        for (int pos = 0;pos < idx - 1;pos++)
            Pre = Pre->next;
        tmp = Pre->next;
        Pre->next = Pre->next->next;
        delete tmp;
        length--;
    }
}

void LinkedList::Reverse()
{
    Node* pre, * curr, * post;
    pre = NULL;curr = Head;post = curr->next;
    Head->next = NULL;
    Tail = Head;
    while (post != NULL) {
        curr->next = pre;
        pre = curr;
        curr = post;
        post = post->next;
    }
    curr->next = pre;
    Head = curr;
}

void LinkedList::Display()
{
    Node* node = Head;
    while (node != NULL) {
        cout << node->item << ' ';
        node = node->next;
    }
    cout << endl;
}

int LinkedList::Search(int element)
{
    int idx = 0;
    Node* curr = Head;
    while (curr != NULL) {
        if (curr->item == element)
            return idx;
        curr = curr->next;
        idx++;
    }
    return -1;
}

void LinkedList::clear()
{
    Node* node = Head;
    while (node != NULL) {
        Node* tmp = node;
        node = node->next;
        delete tmp;
    }
    Head = Tail = NULL;
    length = 0;
}
