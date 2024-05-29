#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct Queue
{
	QueuePtr front;                                     //��ͷָ��
	QueuePtr rear;                                      //��βָ��
}Queue;

void InitQueue(Queue*pq);                               //���ӵĳ�ʼ��
QNode* CreateNode(QElemType e);                         //�����½��
void EnQueue(Queue* pq, QElemType e);                   //���
QElemType DeQueue(Queue* pq);                           //����
bool QueueEmpty(Queue* pq);                             //�п�
QElemType GetHead(Queue* pq);                           //ȡ��ͷԪ��
int QueueSize(Queue* pq);                               //�ж϶���Ԫ�ظ���
void DestroyQueue(Queue* pq);                           //���е�����