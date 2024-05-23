#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
int main()
{
	LNode*head=InitList();
	ListPushFront(head,1);
	ListPushFront(head,2);
	ListPushFront(head,3);
	ListPushFront(head,4);
	ListPushFront(head,5);

	//PopFront(head);
	//PopFront(head);
	//PopFront(head);
	//PopFront(head);
	//PopFront(head);
	

	//PopBack(head);
	//PopBack(head);
	//PopBack(head);
	//PopBack(head);
	//PopBack(head);
	//PopBack(head);
	
	//ListInsert(head, 1, 6);
	//ListInsert(head, 7, 0);
	//ListInsert(head, 2, 100);
	//ListInsert(head, 11, 6);
	
	ListDelete(head, 1);
	ListDelete(head, 4);
	ListDelete(head, 2);
	ListDelete(head, 1); 
	ListDelete(head, 1);
	ListDelete(head, 1);
	print(head);

	/*ElemType e=GetElem(head, 6);
	printf("%d", e);
	LNode* p=LocateElem(head,5);
	;*/
	return 0;
}