#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ElemType;
typedef struct LNode                                   //����������Ľṹ������
{
	ElemType data;
	struct LNode* next;
}LNode;
LNode* InitList();                                    //��ʼ������
LNode* CreateNode(ElemType e);
void ListPushBack(LNode* head,ElemType e);            //β�巨��������
void ListPushFront(LNode* head, ElemType e);          //ͷ�巨��������
void print(LNode* head);                              //��ӡ����
ElemType GetElem(LNode* head, int i);                 // ȡֵ
LNode* LocateElem(LNode* head, ElemType e);           //����
void PopFront(LNode* head);                           //ͷɾ
void PopBack(LNode* head);                            //βɾ
void ListInsert(LNode* head, int i, ElemType e);      //������Ĳ���
void ListDelete(LNode* head, int i);                  //�������ɾ��