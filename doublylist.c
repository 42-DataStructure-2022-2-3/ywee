#include "doublylist.h"

int main()
{
	DoublyList *pList;

	pList = createDoublyList();
	int i = 1;
	DoublyListNode Node;

	Node.data = 3;
	while (i < 5)
	{
		addDLElement(pList, i, Node);
		i++;
	}
	printf("%d\n", pList->headerNode.pRLink->data);
	//displayDoublyList(pList);
	return 0;
}

DoublyList* createDoublyList()
{
	DoublyList *pList;

	pList = malloc(sizeof(DoublyList));
	if (!pList)
		return (NULL);
	pList->currentElementCount = 0;
	pList->headerNode.pLLink = NULL;
	pList->headerNode.pRLink = NULL;
	return (pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *add_node;
	DoublyListNode *curr;

	if (pList->currentElementCount < position + 1)
		return (FALSE);
	add_node = malloc(sizeof(DoublyListNode));
	if (!add_node)
		return (FALSE);
	add_node->data = element.data;
	curr = &pList->headerNode;
	for (int i = 0; i < position - 1 ; i++)
		curr = curr->pRLink;
	add_node->pRLink = curr->pRLink;
	add_node->pLLink = curr;
	// curr->pRLink->pLLink = add_node;
	curr->pRLink = add_node;
	pList->currentElementCount++;
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



void displayDoublyList(DoublyList* pList)
{
	DoublyListNode	*curr;

	int i = 1;
	printf("currentElementCount is %d\n", pList->currentElementCount);
	curr = &pList->headerNode;
	for(curr = &pList->headerNode; curr->pRLink != NULL; )
	{
		curr = curr->pRLink;
		printf("%d th data is %d\n", i++, curr->data);
	}
}
