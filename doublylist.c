#include "doublylist.h"

DoublyList* createDoublyList()
{
	DoublyList *pList;

	pList = malloc(sizeof(DoublyList));
	if (!pList)
		return (NULL);
	pList->currentElementCount = 0;
	pList->headerNode = NULL;
	return (NULL);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *add_node;
	DoublyListNode *curr;
	int	i;

	add_node = malloc(sizeof(DoublyListNode));
	if (!add_node)
		return (NULL);
	add_node->data = element.data;
	curr = &pList->headerNode;
	for (i = 0; i < position -1 ; i++)
		curr = curr->pRLink;
	add_node->pRLink = curr->pRLink;
	add_node->pLLink = curr;
	curr->pRLink->pLLink = add_node;
	curr->pRLink = add_node;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *curr;

	for (int i = 0; i < position ; i++)
		curr = curr->pRLink;
	curr->pLLink->pRLink = curr->pRLink;
	curr->pRLink->pLLink = curr->pLLink;
	free(curr);
	return (TRUE);
}
