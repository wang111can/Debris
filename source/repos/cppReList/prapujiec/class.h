#pragma once
#include<iostream>

using namespace std;
typedef int VAL_;
class List {

private:
	typedef struct Node{
		VAL_ val;

		struct Node* next;

	}Node;
	
public:
	List()
	{
		head = new Node;
		head->next = head;
	}
	Node* head;
	
	void HeadNonde(VAL_ x);
	void HeadDes();
	void EndNode(VAL_ x);
	void EndDes();
	void Print()const;
	void SpDele(VAL_ x);
	~List()
	{	
		Node* p = head->next;
		while (p != head)
		{
			Node* q = p->next;
			delete p;
			p = q;
			
		}
		delete p;
		p = nullptr;

	}
};