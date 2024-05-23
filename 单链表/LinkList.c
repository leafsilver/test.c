#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
LNode* InitList()
{
	LNode* head = (LNode*)malloc(sizeof(LNode));    //创建头结点
	assert(head);
	head->next = NULL;                              //将头结点的指针域置空
	
}
LNode* CreateNode(ElemType e)
{
	LNode* newnode = (LNode*)malloc(sizeof(LNode));//动态创建新结点
	
	assert(newnode);

	newnode->data = e;
	newnode->next = NULL;
}
void print(LNode* head)                             
{
	assert(head);

	LNode* cur = head->next;   

	while (cur != NULL)                             //遍历链表
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	printf("\n");

}
void ListPushBack(LNode* head,ElemType e)
{
	assert(head);

	LNode* tail = head;                             //创建尾指针并将其指向头结点
	
	LNode*newnode=CreateNode(e);

	while (tail->next != NULL)                      //将尾指针指向尾结点
	{
		tail = tail->next;
	}
	tail->next = newnode;                           //连接新结点
}
void ListPushFront(LNode* head, ElemType e)
{   
	assert(head);

	LNode*newnode=CreateNode(e);

	newnode->next = head->next;                    //将新结点的指针域指向首元结点
	head->next = newnode;                          //将头结点的指针域指向新结点

}
ElemType GetElem(LNode* head, int i)
{
	assert(head);

	int j=1;                                       //用j做计数器初值赋为1
	LNode* cur = head->next;                       //用指针cur指向首元结点

	while (j < i && cur)                           //顺序遍历终止条件为cur指向第i个元素或遍历完链表
	{
		cur = cur->next;                           //cur指向下一个结点
		++j;                                       //计数器相应加一
	}    

	if (j > i || !cur)                             //i的范围应为1<=i<=n
	{
		printf("输入的i值不合法");
	}
	else                                           //若i值合法返回第i个结点的数据域
	{
		return cur->data;
	}
	

}
LNode* LocateElem(LNode* head, ElemType e)
{
	{
		assert(head);

		LNode* cur = head->next;                        //将cur指向首元结点

		while (cur && cur->data != e)                   //遍历链表，直到cur为空或者cur所指结点的数据域等于e
		{
			cur = cur->next;
		}

		return cur;                                     //查找成功返回值为e的结点地址cur,查找失败cur为NULL
	}
}
void PopFront(LNode* head)
{
	
	assert(head);

	LNode* first = head->next;                          //将first指向首元结点

	assert(first);                                      //判断链表是为否空

	head->next = first->next;                           //将头结点的指针域指向第二个结点

	free(first);                                        //释放第一个结点的空间
	first = NULL;                                       

}
void PopBack(LNode* head)
{
	assert(head);

	LNode* prev = head;                                
	LNode* tail = head->next;                        

	assert(tail);                                      //判断链表是否为空

	while (tail->next != NULL)                         //遍历链表直到尾指针指向最后一个结点
	{
		prev = tail;                                   //始终使prev指向尾指针指向的前一个结点
		tail = tail->next;                             
	}
	free(tail);                                        //释放尾结点
	prev->next = NULL;                                 //释放尾结点以后让新的尾结点指针域置空
}
void ListInsert(LNode* head, int i, ElemType e)
{

	assert(head);

	LNode* newnode=CreateNode(e);

	int j = 0;
	LNode* cur = head;
	

	while ((j<i-1)&&cur)                       //查找第i-1个结点，cur指向该结点
	{
		cur = cur->next;                  
		++j;
	}

	if ((j>i-1) || !cur)                       //i的取值范围为1<=i<=n+1
	{
		printf("输入的i值不合法\n");
	}

	else                                        //一些两步顺序不能换否则找不到第i个结点
	{
		newnode->next = cur->next;             //将新结点的指针域指向第i个结点
		cur->next = newnode;                   //将第i-1个结点的指针域指向新结点
	}

}
void ListDelete(LNode* head, int i)
{

	assert(head);

	int j = 1;
	LNode* prev = head;
	LNode* cur = head->next;

	while (j < i && cur)                      //查找第i个结点，cur指向该结点
	{
		prev = cur;
		cur = cur->next;
		j++;
	}

	if (j > i || !cur)                       //i的取值范围为1<=i<=n;
	{
		printf("输入的i值不合法");
	}
	else
	{
		prev->next = cur->next;              //将i-1个结点指针域指向第i+1个结点指针域
		free(cur);                           //释放第i个结点的空间
		cur = NULL;
	}
}
