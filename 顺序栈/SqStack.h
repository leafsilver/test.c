#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define MAXSIZE 10                                               //˳��ջ�洢�ռ�ĳ�ʼ������

typedef int SElemType;
typedef struct Sqstack                                               //����˳��ջ�Ĵ洢�ṹ
{
	SElemType* base;                                                 //����ջ��ָ��
	SElemType* top;                                                  //����ջ��ָ��
	int stacksize;                                                   //ջ���õ��������
}SqStack;

void InitStack(SqStack* ps);                                         //ջ�ĳ�ʼ��
void PushStack(SqStack* ps, SElemType e);                            //��ջ
SElemType PopStack(SqStack* ps);                                     //��ջ
SElemType GetTop(SqStack* ps);                                       //ȡջ��Ԫ��
bool StackEmpty(SqStack* ps);                                        //�п�
int StackSize(SqStack* ps);                                          //�ж�ջ�Ĵ�С
void StackDestory(SqStack* ps);                                      //ջ������