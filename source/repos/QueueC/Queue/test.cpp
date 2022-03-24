#define  _CRT_SECURE_NO_WARNINGS

#include"queue.h"

bool Queue::Push(VAL x)
{
	Node* newnode = new Node;
	newnode->val = x;
	newnode->next = nullptr;
	Ram++;
	if (head == nullptr)
	{
		head = newnode;
	}
	else
	{
		now->next = newnode;
	}
	now = newnode;
	return true;

}
bool Queue::Pop()
{
	if (head == NULL)
	{
		return false;
	}
	Node* tmp = head;
	head = head->next;
	Ram--;
	delete tmp;
	if (Ram == 0)
		now = nullptr;
	return true;

}
VAL Queue::RePop(Queue& p) {
	 
	if (!head)
		return NULL;
	return head->val;
}