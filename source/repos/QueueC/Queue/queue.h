#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
typedef int VAL;
class Queue {
	//该队列没有上限

	
private:
	typedef	struct Node {

		VAL val;
		struct Node* next;

	}Node;
public:
	Queue()
	{
		Ram = 0;
		head = now = nullptr;
	}
	int Ram;//对内成员数
	Node* head;
	Node* now;
	bool Push(VAL x);
	bool Pop();
	VAL RePop(Queue& p);
	void Print()
	{
		Node* tmp = head;
		while (tmp)
		{
			std::cout << tmp->val << " ";
			tmp = tmp->next;
		}
	}
	~Queue()
	{	
		Node* tmp ;
		while (head)
		{
			tmp = head;
			head = head->next;
			delete tmp;

		}
	}
};
