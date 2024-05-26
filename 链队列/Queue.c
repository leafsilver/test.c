#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

void InitQueue(Queue*pq)
{

	assert(pq);

	pq->front=pq->rear = (QNode*)malloc(sizeof(QNode));       //生成新结点作为头结点,队头和队尾指针都指向此结点

	pq->front->next = NULL;                                   //头结点的指针域置空

}
QNode* CreateNode(QElemType e)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));

	newnode->data = e;
	newnode->next = NULL;

}
void EnQueue(Queue* pq, QElemType e)
{
	assert(pq);

	QNode* newnode=CreateNode(e);                            //将新结点的地址赋给newnode
	pq->rear->next = newnode;                                //将新结点插入队尾
	pq->rear = newnode;                                      //将队尾指针指向尾结点
}
QElemType DeQueue(Queue* pq)
{

	assert(pq);
	assert(!QueueEmpty(pq));                                  //断言判断队列是否为空

	QNode* first = pq->front->next;                         //p指向队头元素

	pq->front->next = first->next;                          //修改头结点的指针域使其指向第二个结点
	QElemType e = first->data;                              //e保存队头元素的值

	if (first == pq->rear)                                  //如果最后一个元素被删，队尾指针指向头结点
	{
		pq->rear = pq->front;
	}
	free(first);                                            //释放原队头元素的空间
	first = NULL;                                           //将其置空

	return e;                                               //返回e的值
}
bool QueueEmpty(Queue* pq)
{

	assert(pq);

	return pq->front == pq->rear;                          //队头指针和队尾指针都指向头结点

}
QElemType GetHead(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));                               //断言判断队列是否为空

	return pq->front->next->data;
}
int QueueSize(Queue* pq)
{

	assert(pq);

	QNode* cur = pq->front->next;                         //将cur指向首元结点
	int size = 0;                                         //定义计数器size并赋初值为0

	while (cur != NULL)                                   //遍历队列
	{
		++size;
		cur = cur->next;
	}
	return size;
}
void DestroyQueue(Queue* pq)
{

	assert(pq);

	QNode* cur = pq->front;                                    //将cur初始化指向头结点

	while (cur)                                                //遍历
	{
		QNode* next = cur->next;                               //保存下一个结点地址防止free掉找不到
		free(cur);
		cur = next;
	}
	pq->front = pq->rear = NULL;                               //将队头指针和队尾指针置空

}