#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ElemType;
typedef struct LNode                                   //创建单链表的结构体类型
{
	ElemType data;
	struct LNode* next;
}LNode;
LNode* InitList();                                    //初始化链表
LNode* CreateNode(ElemType e);
void ListPushBack(LNode* head,ElemType e);            //尾插法创建链表
void ListPushFront(LNode* head, ElemType e);          //头插法创建链表
void print(LNode* head);                              //打印链表
ElemType GetElem(LNode* head, int i);                 // 取值
LNode* LocateElem(LNode* head, ElemType e);           //查找
void PopFront(LNode* head);                           //头删
void PopBack(LNode* head);                            //尾删
void ListInsert(LNode* head, int i, ElemType e);      //单链表的插入
void ListDelete(LNode* head, int i);                  //单链表的删除