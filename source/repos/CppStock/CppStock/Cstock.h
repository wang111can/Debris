#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
template<class T>
class CStock {

private:
	typedef struct Node {
		T val;
		struct Node* next;

	}Node;
	Node* Head;
	Node* Now;
	int num;
public:
	CStock()
	{
		Head = Now = nullptr;
		num = 0;
	}
	void Push(T x);//入元素
	void Pop();//出元素
	T& ReT();//返回栈顶元素并可对其修改

	

};

template<class T>

void CStock<T>::Push(T x)
{
	Node* newnode = new Node;
	newnode->next = nullptr;
	newnode->val = x;
	num++;
	if (!Head)
		Head = newnode;
	else
		Now->next = newnode;
	Now = newnode;
}

template<class T>

void CStock<T>::Pop()
{
	if (!num)
	{
		cout << "empty" << endl;
		return;
	}
	else
	{
		Node* p = Head;
		Head = Head->next;
		num--;
		delete p;
	}
}

template<class T>

T& CStock<T>::ReT()
{
	if (!num)
	{
		cout << "empty" << endl;
		return;
	}
	return Head->val;
}

//void Print();
//template<class T>
//void CStock<T>::Print()
//{		
//	Node* l1 = Head;
//	while (l1 != NULL)
//	{
//		cout << l1->val <<" ";
//		l1 = l1->next;
//	}
//}
