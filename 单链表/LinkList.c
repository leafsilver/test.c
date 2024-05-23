#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
LNode* InitList()
{
	LNode* head = (LNode*)malloc(sizeof(LNode));    //����ͷ���
	assert(head);
	head->next = NULL;                              //��ͷ����ָ�����ÿ�
	
}
LNode* CreateNode(ElemType e)
{
	LNode* newnode = (LNode*)malloc(sizeof(LNode));//��̬�����½��
	
	assert(newnode);

	newnode->data = e;
	newnode->next = NULL;
}
void print(LNode* head)                             
{
	assert(head);

	LNode* cur = head->next;   

	while (cur != NULL)                             //��������
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	printf("\n");

}
void ListPushBack(LNode* head,ElemType e)
{
	assert(head);

	LNode* tail = head;                             //����βָ�벢����ָ��ͷ���
	
	LNode*newnode=CreateNode(e);

	while (tail->next != NULL)                      //��βָ��ָ��β���
	{
		tail = tail->next;
	}
	tail->next = newnode;                           //�����½��
}
void ListPushFront(LNode* head, ElemType e)
{   
	assert(head);

	LNode*newnode=CreateNode(e);

	newnode->next = head->next;                    //���½���ָ����ָ����Ԫ���
	head->next = newnode;                          //��ͷ����ָ����ָ���½��

}
ElemType GetElem(LNode* head, int i)
{
	assert(head);

	int j=1;                                       //��j����������ֵ��Ϊ1
	LNode* cur = head->next;                       //��ָ��curָ����Ԫ���

	while (j < i && cur)                           //˳�������ֹ����Ϊcurָ���i��Ԫ�ػ����������
	{
		cur = cur->next;                           //curָ����һ�����
		++j;                                       //��������Ӧ��һ
	}    

	if (j > i || !cur)                             //i�ķ�ΧӦΪ1<=i<=n
	{
		printf("�����iֵ���Ϸ�");
	}
	else                                           //��iֵ�Ϸ����ص�i������������
	{
		return cur->data;
	}
	

}
LNode* LocateElem(LNode* head, ElemType e)
{
	{
		assert(head);

		LNode* cur = head->next;                        //��curָ����Ԫ���

		while (cur && cur->data != e)                   //��������ֱ��curΪ�ջ���cur��ָ�������������e
		{
			cur = cur->next;
		}

		return cur;                                     //���ҳɹ�����ֵΪe�Ľ���ַcur,����ʧ��curΪNULL
	}
}
void PopFront(LNode* head)
{
	
	assert(head);

	LNode* first = head->next;                          //��firstָ����Ԫ���

	assert(first);                                      //�ж�������Ϊ���

	head->next = first->next;                           //��ͷ����ָ����ָ��ڶ������

	free(first);                                        //�ͷŵ�һ�����Ŀռ�
	first = NULL;                                       

}
void PopBack(LNode* head)
{
	assert(head);

	LNode* prev = head;                                
	LNode* tail = head->next;                        

	assert(tail);                                      //�ж������Ƿ�Ϊ��

	while (tail->next != NULL)                         //��������ֱ��βָ��ָ�����һ�����
	{
		prev = tail;                                   //ʼ��ʹprevָ��βָ��ָ���ǰһ�����
		tail = tail->next;                             
	}
	free(tail);                                        //�ͷ�β���
	prev->next = NULL;                                 //�ͷ�β����Ժ����µ�β���ָ�����ÿ�
}
void ListInsert(LNode* head, int i, ElemType e)
{

	assert(head);

	LNode* newnode=CreateNode(e);

	int j = 0;
	LNode* cur = head;
	

	while ((j<i-1)&&cur)                       //���ҵ�i-1����㣬curָ��ý��
	{
		cur = cur->next;                  
		++j;
	}

	if ((j>i-1) || !cur)                       //i��ȡֵ��ΧΪ1<=i<=n+1
	{
		printf("�����iֵ���Ϸ�\n");
	}

	else                                        //һЩ����˳���ܻ������Ҳ�����i�����
	{
		newnode->next = cur->next;             //���½���ָ����ָ���i�����
		cur->next = newnode;                   //����i-1������ָ����ָ���½��
	}

}
void ListDelete(LNode* head, int i)
{

	assert(head);

	int j = 1;
	LNode* prev = head;
	LNode* cur = head->next;

	while (j < i && cur)                      //���ҵ�i����㣬curָ��ý��
	{
		prev = cur;
		cur = cur->next;
		j++;
	}

	if (j > i || !cur)                       //i��ȡֵ��ΧΪ1<=i<=n;
	{
		printf("�����iֵ���Ϸ�");
	}
	else
	{
		prev->next = cur->next;              //��i-1�����ָ����ָ���i+1�����ָ����
		free(cur);                           //�ͷŵ�i�����Ŀռ�
		cur = NULL;
	}
}
