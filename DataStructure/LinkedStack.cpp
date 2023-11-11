#include "LinkedStack.h"

LinkedStack::LinkedStack()
{
	top = NULL;
	len = 0;
}

bool LinkedStack::IsEmpty()
{
	return top == NULL;
}

int LinkedStack::Size()
{
	return len;
}

int LinkedStack::GetTop()
{
	if (IsEmpty())
		return INT_MIN;
	else
		return top->item;
}

void LinkedStack::Insert(int item)
{
	SNode* NewNode = new SNode;
	NewNode->item = item;
	NewNode->next = top;
	top = NewNode;
	len++;
}

void LinkedStack::Delete()
{
	if (IsEmpty()) {
		cout << "Stack is underflow" << endl;
	}
	else {
		SNode* tmp = top;
		top = top->next;
		delete tmp;
		len--;
	}
}

void LinkedStack::Display()
{
	SNode* curr = top;
	while (curr != NULL) {
		cout << curr->item << ' ';
		curr = curr->next;
	}
	cout << endl;
}

void LinkedStack::clear()
{
	SNode* tmp;
	while (top != NULL) {
		tmp = top;
		top = top->next;
		delete tmp;
	}
	len = 0;
}
