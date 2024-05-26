#define _CRT_SECURE_NO_WARNINGS
#include"SqStack.h"
void InitStack(SqStack* ps)
{

	assert(ps);

	ps->base = (SElemType*)malloc(MAXSIZE*sizeof(SElemType));                           //为顺序栈动态分配一个容量为MAXZISE的空间

	assert(ps->base);                                                 //判断是否存储失败                        

	ps->top = ps->base;                                               //将栈置空
	ps->stacksize = MAXSIZE;                                          //stacksize置为栈的容量
	 
}
bool StackEmpty(SqStack* ps)
{
	assert(ps);

	return ps->top == ps->base;                                     

}
void PushStack(SqStack* ps, SElemType e)
{

	assert(ps);

	if (ps->top - ps->base == ps->stacksize)                         //栈满扩容
	{
		SElemType* tem = (SElemType*)realloc(ps->base, sizeof(SElemType)*ps->stacksize* 2); //先用临时指针变量接收realloc的返回值，防止realloc失败返回空使ps->top找不到使用realloc之前的地址
		assert(tem);                                                 //判断是否realloc成功
		ps->base = tem;                                              //如果成功将realloc的副会长赋给ps->base
		ps->top = ps->base + ps->stacksize;                          //realloc有可能会新开辟一段空间而不是在原来基础上开辟
		ps->stacksize *= 2;                                          //栈的最大容量增加两倍
	}
	*ps->top++ = e;                                                  //将元素e压入栈顶，栈顶指针加一

}
SElemType PopStack(SqStack* ps)
{

	assert(ps);

	if (StackEmpty(ps) )                                         //栈空
	{
		printf("栈中没有可以删除的元素");
		exit(-1);
	}
	else
	{
		return *--ps->top;                                          //栈顶指针减1，并返回出栈元素
	}

}
SElemType GetTop(SqStack* ps)
{

	assert(ps);

	if (StackEmpty(ps))                                        //栈空
	{
		printf("栈为空");
		exit(-1);
	}
	else
	{
		return *(ps->top - 1);                                    //返回栈顶元素的值，栈顶指针不变
	}
}
int StackSize(SqStack* ps)
{

	assert(ps);
	
	return ps->top - ps->base;;
}
void StackDestory(SqStack* ps)
{

	assert(ps);

	free(ps->base);                                              //释放内存空间
	ps->base = NULL;                                             //将指向栈顶的指针top置空
	ps->top = NULL;                                              //将指向栈底的指针base置空
	ps->stacksize = 0;                                           //将栈的最大容量赋值为0

}
