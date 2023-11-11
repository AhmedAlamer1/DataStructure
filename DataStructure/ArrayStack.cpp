#include "ArrayStack.h"

ArrayStack::ArrayStack(int Size)
{
    top = -1;
    MxSize = Size;
    arr = new int[MxSize];
}

bool ArrayStack::IsEmpty()
{
    return top == -1;
}

bool ArrayStack::IsFull()
{
    return top == MxSize - 1;
}

void ArrayStack::Insert(int item)
{
    if (IsFull())
        cout << "Stack is overflow" << endl;
    else {
        top++;
        arr[top] = item;
    }
}

void ArrayStack::Delete()
{
    if (IsEmpty())
        cout << "Stack is underflow" << endl;
    else
        top--;
}

int ArrayStack::GetTop()
{
    if (IsEmpty())
        return INT_MIN;
    else
        return arr[top];
}

int ArrayStack::Size()
{
    return top + 1;
}

void ArrayStack::Display()
{
    for (int i = top;i >= 0;i--)
        cout << arr[i] << ' ';
    cout << endl;
}

void ArrayStack::clear()
{
    top = -1;
    delete[] arr;
}
