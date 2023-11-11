#include "LinkedQueue.h"

using namespace std;

LinkedQueue::LinkedQueue()
{
    len = 0;
    front = rear = NULL;
}

bool LinkedQueue::IsEmpty() {
    return len == 0;
}

int LinkedQueue::Size() {
    return len;
}

void LinkedQueue::Insert(int item) {
    QNode* NewNode = new QNode;
    NewNode->item = item;
    NewNode->next = NULL;

    if (IsEmpty()) {
        front = rear = NewNode;
    }
    else {
        rear->next = NewNode;
        rear = NewNode;
    }

    len++;
}

void LinkedQueue::DeQueue() {
    if (IsEmpty()) {
        cout << "Empty Queue" << endl;
    }
    else {
        QNode* tmp = front;
        front = front->next;
        if (len == 1) {
            rear = NULL;
        }
        delete tmp;
        len--;
    }
}

int LinkedQueue::GetFront() {
    assert(!IsEmpty());
    return front->item;
}

int LinkedQueue::GetRear() {
    assert(!IsEmpty());
    return rear->item;
}

void LinkedQueue::Display() {
    QNode* curr = front;
    while (curr != NULL) {
        cout << curr->item << ' ';
        curr = curr->next;
    }
    cout << endl;
}

void LinkedQueue::clear() {
    while (front != NULL) {
        QNode* tmp = front;
        front = front->next;
        delete tmp;
    }
    rear = NULL;
    len = 0;
}