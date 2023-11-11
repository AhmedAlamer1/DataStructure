#include "ArrayList.h"

ArrayList::ArrayList(int s)
{ 
    MxSize = s;
    length = 0;
    arr = new int[MxSize];
}

bool ArrayList::IsEmpty()
{
    return length == 0;
}

bool ArrayList::IsFull()
{
    return length == MxSize;
}

int ArrayList::Size()
{
    return length;
}

void ArrayList::Display()
{
    for (int i = 0;i < length;i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int ArrayList::GetElement(int idx)
{
    return arr[idx];
}

void ArrayList::InsertAt(int idx, int val)
{
    if (IsFull())
        cout << "List Full" << endl;
    else if (idx > length or idx < 0)
        cout << "Out Of Range" << endl;
    else {
        for (int i = length; i > idx; i--) {
            arr[i] = arr[i - 1];
        }
        arr[idx] = val;
        length++;
    }
}

void ArrayList::Insert(int val)
{
    arr[length] = val;
    length++;
}

void ArrayList::Update(int idx, int val)
{
    arr[idx] = val;
}

int ArrayList::search(int val)
{
    for (int i = 0;i < length;i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

void ArrayList::Delete(int idx)
{
    if (idx >= length or idx < 0) {
        cout << "Out Of Range" << endl;
    }
    else {
        for (int i = idx;i < length - 1;i++) {
            arr[i] = arr[i + 1];
        }
        length--;
    }
}

void ArrayList::clear()
{
    length = 0;
}

ArrayList::~ArrayList()
{
    delete[] arr;
}
