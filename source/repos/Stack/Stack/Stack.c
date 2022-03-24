#define  _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
void InitStack(Tc* ps)//初始化
{
	assert(ps);
	ps->data =(DATA*)malloc(sizeof(DATA) * 4);
	ps->max = 4;
	ps->top = -1;//指向栈顶数据
	
}
 void AddStack(Tc* ps, int x)//入
 {
	 assert(ps);

	 if (ps->top == ps->max-1)
	 {
		 MaxStack(ps);

	}
	 ps->top++;
	 ps->data[ps->top]= x;
	 
}

 void PusStack(Tc* ps)//出
 {
	 assert(ps);
	 assert(ps->top > -1);

	 ps->top--;
 }

 int TopStack(Tc* ps)//出数据
 {
	 assert(ps);
	 assert(ps->top > -1);
	 return ps->data[ps->top];
 }
 
 void MaxStack(Tc* ps)//增容
 {
	 assert(ps);
	 DATA*tmp= (DATA*)realloc(ps->data, ps->max * 2*sizeof(DATA));
	 if (tmp == NULL)
	 {
		 printf("error!\n");
		 return;
	 }
	 else
	 {
		 ps->data = tmp;
	ps->max *= 2;
	 }
	

 }
 void DesStack(Tc* ps)//销毁
 {
	 assert(ps);
	 free(ps->data);
	 ps->data = NULL;
	 ps->max = 0;
	 ps->top = -1;
 }
 int PanStack(Tc* ps)//判断空
 {
	 assert(ps);
	 return ps->top;
 }
 //PrintStack(Tc* ps)//输出
 //{
	// assert(ps);
	// assert(ps->top > -1);
	// int a = ps->top;
	// while (a>-1)
	// {
	//	 printf("%d ", ps->data[a]);
	//	 a--;
	// }

 //}