#include "ArrayQueue.h"

ArrayQueueType::ArrayQueueType(int sz)
{
    MxSize = sz;
    rear = MxSize - 1;
    front = 0;
    len = 0;
    arr = new int[MxSize];
}

bool ArrayQueueType::IsEmpty()
{
    return len == 0;
}

bool ArrayQueueType::IsFull()
{
    return len == MxSize;
}

int ArrayQueueType::Size()
{
    return len;
}

void ArrayQueueType::Insert(int element)
{
    if (IsFull()) {
        cout << "Queue is Full" << endl;
    }
    else {
        rear = (rear + 1) % MxSize;
        arr[rear] = element;
        len++;
    }
}

void ArrayQueueType::Dequeue()
{
    if (IsEmpty()) {
        cout << "Queue is Empty" << endl;
    }
    else {
        front = (front + 1) % MxSize;
        len--;
    }
}

int ArrayQueueType::GetFront()
{
    assert(!IsEmpty());
    return arr[front];
}

int ArrayQueueType::GetRear()
{
    assert(!IsEmpty());
    return arr[rear];
}

void ArrayQueueType::Display()
{
    if (!IsEmpty()) {
        int curr = front;
        while (curr != rear) {
            cout << arr[curr] << ' ';
            curr = (curr + 1) % MxSize;
        }
        cout << arr[rear];
        cout << endl;
    }
}

int ArrayQueueType::Search(int element)
{
    if (!IsEmpty()) {
        int tmp = len, curr = front;
        while (tmp--) {
            if (arr[curr] == element)
                return curr;
            curr = (curr + 1) % MxSize;
        }
    }
    return -1;
}

void ArrayQueueType::clear()
{
    front = rear = len = 0;
    delete[] arr;
}

