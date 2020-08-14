#include<stdio.h>
#include <malloc.h>

typedef struct ListNode
{
	int data;
	struct ListNode* m_pNext;
} ListNode;


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
 	if(pListHead == NULL || k <= 0)
 		return NULL;
 	ListNode *pAhead = pListHead;
 	ListNode *pBehind = NULL;
 	int i;
	for(i = 0; i < k - 1; ++ i) {
		if(pAhead == NULL)
		{
			return NULL;
		}

 		pAhead = pAhead->m_pNext;
	}

 	pBehind = pListHead;
 	while(pAhead->m_pNext != NULL) {
 		pAhead = pAhead->m_pNext;
 		pBehind = pBehind->m_pNext;
	}

 	return pBehind;
}

void main()
{
	ListNode* list;
	list = malloc(sizeof(ListNode));
	ListNode* listHead = list;
	int i;
	for(i = 0; i < 20; i++)
	{
		list->data = i;
		list->m_pNext = malloc(sizeof(ListNode));
		list = list->m_pNext;
	}
	
	ListNode* result = FindKthToTail(listHead, 12);
	if(result != NULL)
	{
		printf("%d \n", result->data);
	}
	else
	{
		printf("Not in range \n");
	}
}
