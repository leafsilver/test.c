#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define MAXSIZE 10                                               //顺序栈存储空间的初始分配量

typedef int SElemType;
typedef struct Sqstack                                               //定义顺序栈的存储结构
{
	SElemType* base;                                                 //定义栈底指针
	SElemType* top;                                                  //定义栈顶指针
	int stacksize;                                                   //栈可用的最大容量
}SqStack;

void InitStack(SqStack* ps);                                         //栈的初始化
void PushStack(SqStack* ps, SElemType e);                            //入栈
SElemType PopStack(SqStack* ps);                                     //出栈
SElemType GetTop(SqStack* ps);                                       //取栈顶元素
bool StackEmpty(SqStack* ps);                                        //判空
int StackSize(SqStack* ps);                                          //判断栈的大小
void StackDestory(SqStack* ps);                                      //栈的销毁