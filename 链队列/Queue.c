#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

void InitQueue(Queue*pq)
{

	assert(pq);

	pq->front=pq->rear = (QNode*)malloc(sizeof(QNode));       //�����½����Ϊͷ���,��ͷ�Ͷ�βָ�붼ָ��˽��

	pq->front->next = NULL;                                   //ͷ����ָ�����ÿ�

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

	QNode* newnode=CreateNode(e);                            //���½��ĵ�ַ����newnode
	pq->rear->next = newnode;                                //���½������β
	pq->rear = newnode;                                      //����βָ��ָ��β���
}
QElemType DeQueue(Queue* pq)
{

	assert(pq);
	assert(!QueueEmpty(pq));                                  //�����ж϶����Ƿ�Ϊ��

	QNode* first = pq->front->next;                         //pָ���ͷԪ��

	pq->front->next = first->next;                          //�޸�ͷ����ָ����ʹ��ָ��ڶ������
	QElemType e = first->data;                              //e�����ͷԪ�ص�ֵ

	if (first == pq->rear)                                  //������һ��Ԫ�ر�ɾ����βָ��ָ��ͷ���
	{
		pq->rear = pq->front;
	}
	free(first);                                            //�ͷ�ԭ��ͷԪ�صĿռ�
	first = NULL;                                           //�����ÿ�

	return e;                                               //����e��ֵ
}
bool QueueEmpty(Queue* pq)
{

	assert(pq);

	return pq->front == pq->rear;                          //��ͷָ��Ͷ�βָ�붼ָ��ͷ���

}
QElemType GetHead(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));                               //�����ж϶����Ƿ�Ϊ��

	return pq->front->next->data;
}
int QueueSize(Queue* pq)
{

	assert(pq);

	QNode* cur = pq->front->next;                         //��curָ����Ԫ���
	int size = 0;                                         //���������size������ֵΪ0

	while (cur != NULL)                                   //��������
	{
		++size;
		cur = cur->next;
	}
	return size;
}
void DestroyQueue(Queue* pq)
{

	assert(pq);

	QNode* cur = pq->front;                                    //��cur��ʼ��ָ��ͷ���

	while (cur)                                                //����
	{
		QNode* next = cur->next;                               //������һ������ַ��ֹfree���Ҳ���
		free(cur);
		cur = next;
	}
	pq->front = pq->rear = NULL;                               //����ͷָ��Ͷ�βָ���ÿ�

}