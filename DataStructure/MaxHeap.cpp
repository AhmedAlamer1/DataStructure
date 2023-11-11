#include "MaxHeap.h"

MaxHeap::MaxHeap(int sz) { // O(1)
    arr = new int[sz];
    MaxSize = sz;
    size = 0;
}

bool MaxHeap::isempty() { // O(1)
    return size == 0;
}

int MaxHeap::Parent(int i) { // O(1)
    return (i - 1) / 2;
}

int MaxHeap::Lchild(int i) { // O(1)
    return 2 * i + 1;
}

int MaxHeap::Rchild(int i) { // O(1)
    return 2 * i + 2;
}

void MaxHeap::heapify(int i) { // O(log(n))
    int left = Lchild(i);
    int right = Rchild(i);
    int mx = i;

    if (left < size && arr[left] > arr[mx]) {
        mx = left;
    }

    if (right < size && arr[right] > arr[mx]) {
        mx = right;
    }

    if (mx != i) {
        swap(arr[i], arr[mx]);
        heapify(mx);
    }
}

int MaxHeap::removeMx() { // O(log(n))
    if (size == 0) {
        return INT_MIN;
    }
    else if (size == 1) {
        size = 0;
        return arr[0];
    }
    else {
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    }
}

void MaxHeap::increaseKey(int i, int val) { // O(log(n))
    arr[i] = val;
    while (i != 0 && arr[i] > arr[Parent(i)]) {
        swap(arr[i], arr[Parent(i)]);
        i = Parent(i);
    }
}

int MaxHeap::GetMax() { // O(1)
    return arr[0];
}

int MaxHeap::Size() { // O(1)
    return size;
}

void MaxHeap::DeleteKey(int i) { // O(log(n))
    increaseKey(i, INT_MAX);
    removeMx();
}

void MaxHeap::Insert(int val) { // O(log(n))
    if (size == MaxSize) {
        cout << "Heap is OverFlow" << endl;
        return;
    }

    size++;
    int i = size - 1;
    arr[i] = val;

    while (i != 0 && arr[i] > arr[Parent(i)]) {
        swap(arr[i], arr[Parent(i)]);
        i = Parent(i);
    }
}

void MaxHeap::Display()
{
    for (int idx = 0;idx < size;idx++) {
        cout << arr[idx] << ' ';
    }
    cout << endl;
}

void MaxHeap::clear()
{
    size = 0;
    delete[] arr;
}
