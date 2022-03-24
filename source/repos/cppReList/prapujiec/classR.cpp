#define  _CRT_SECURE_NO_WARNINGS
#include"class.h"

void List::HeadNonde(VAL_ x)
{
	Node* newnode = new Node;
	newnode->val = x;
	newnode->next = head->next;
	head->next = newnode;
	
}
void List::HeadDes()
{
	if (head->next == head)
	{
		cout << "NO NODE!" << endl;
		return;
	}
	Node*q = head->next;
	head->next = q->next;
	delete q;

}
void List::Print()const
{
	if (head->next == head)
	{
		cout << "NO NODE!(Head)" << endl;
		return;
	}
	Node* p = head->next;
	while (p!= head)
	{
		cout << p->val << "->";
		p = p->next;
	}
	cout <<"nullptr"<< endl;
}


void List::EndNode(VAL_ x)
{
	Node* p = head;
	while (p->next != head)
	{
		p = p->next;
	}
	Node* newnode = new Node;
	newnode->val = x;
	newnode->next = head;
	p->next = newnode;

}

void List::EndDes()
{
	if (head->next == head)
	{
		cout << "NO NODE!(End)" << endl;
		return;
	}
	Node* p = head;
	Node* q = head->next;
	while (q->next != head)
	{
		p = q;
		q = q->next;
	}
	p->next = head;
	delete q;



}

void List::SpDele(VAL_ x)
{
	if (head->next == head)
	{
		cout << "NO NODE!(Dele)" << endl;
		return;
	}
	Node* p = head;
	Node* q = head->next;
	while (q->val != x&&q!=head)
	{
		p = q;
		q = q->next;
	}
	if (q == head)
	{
		cout << "There is no such element" << endl;
		return;
	}
	p->next = q->next;
	delete q;
	cout << "¡Ì" << endl;
}
