#define _CRT_SECURE_NO_WARNINGS
#include"SqStack.h"
void InitStack(SqStack* ps)
{

	assert(ps);

	ps->base = (SElemType*)malloc(MAXSIZE*sizeof(SElemType));                           //Ϊ˳��ջ��̬����һ������ΪMAXZISE�Ŀռ�

	assert(ps->base);                                                 //�ж��Ƿ�洢ʧ��                        

	ps->top = ps->base;                                               //��ջ�ÿ�
	ps->stacksize = MAXSIZE;                                          //stacksize��Ϊջ������
	 
}
bool StackEmpty(SqStack* ps)
{
	assert(ps);

	return ps->top == ps->base;                                     

}
void PushStack(SqStack* ps, SElemType e)
{

	assert(ps);

	if (ps->top - ps->base == ps->stacksize)                         //ջ������
	{
		SElemType* tem = (SElemType*)realloc(ps->base, sizeof(SElemType)*ps->stacksize* 2); //������ʱָ���������realloc�ķ���ֵ����ֹreallocʧ�ܷ��ؿ�ʹps->top�Ҳ���ʹ��realloc֮ǰ�ĵ�ַ
		assert(tem);                                                 //�ж��Ƿ�realloc�ɹ�
		ps->base = tem;                                              //����ɹ���realloc�ĸ��᳤����ps->base
		ps->top = ps->base + ps->stacksize;                          //realloc�п��ܻ��¿���һ�οռ��������ԭ�������Ͽ���
		ps->stacksize *= 2;                                          //ջ�����������������
	}
	*ps->top++ = e;                                                  //��Ԫ��eѹ��ջ����ջ��ָ���һ

}
SElemType PopStack(SqStack* ps)
{

	assert(ps);

	if (StackEmpty(ps) )                                         //ջ��
	{
		printf("ջ��û�п���ɾ����Ԫ��");
		exit(-1);
	}
	else
	{
		return *--ps->top;                                          //ջ��ָ���1�������س�ջԪ��
	}

}
SElemType GetTop(SqStack* ps)
{

	assert(ps);

	if (StackEmpty(ps))                                        //ջ��
	{
		printf("ջΪ��");
		exit(-1);
	}
	else
	{
		return *(ps->top - 1);                                    //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
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

	free(ps->base);                                              //�ͷ��ڴ�ռ�
	ps->base = NULL;                                             //��ָ��ջ����ָ��top�ÿ�
	ps->top = NULL;                                              //��ָ��ջ�׵�ָ��base�ÿ�
	ps->stacksize = 0;                                           //��ջ�����������ֵΪ0

}
