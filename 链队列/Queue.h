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
	QueuePtr front;                                     //队头指针
	QueuePtr rear;                                      //队尾指针
}Queue;

void InitQueue(Queue*pq);                               //链队的初始化
QNode* CreateNode(QElemType e);                         //创建新结点
void EnQueue(Queue* pq, QElemType e);                   //入队
QElemType DeQueue(Queue* pq);                           //出队
bool QueueEmpty(Queue* pq);                             //判空
QElemType GetHead(Queue* pq);                           //取队头元素
int QueueSize(Queue* pq);                               //判断队内元素个数
void DestroyQueue(Queue* pq);                           //队列的销毁