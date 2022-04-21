#include "polynomial.h"

int main()
{
    LinkedList	*List_A;
    LinkedList	*List_B;
	ListNode	new_node;

	List_A = createLinkedList();

	int i = 0;
	float j = 0;
    
	while (i < 10)
	{
		new_node.coef = j;
		new_node.degree = i;
		addLLElement(List_A, i + 1, j * 2);
		i++;
		j++;
	}
   /*
	// clearLinkedList(List);
	displayLinkedList(List);
	removeLLElement(List, 2);

	printf("+++++++++++++afterremove+++++++++++++++++\n");
	// deleteLinkedList(List);
    */
	displayLinkedList(List_A);
	printf("+++++++++++++afterremove+++++++++++++++++\n");
    clearLinkedList(List_A);
    displayLinkedList(List_A);
}

LinkedList* createLinkedList()
{
	LinkedList	*pList;

	pList = calloc(1, sizeof(LinkedList));
	if (!pList)
		return (NULL);
	pList->headerNode.pLink = NULL;
	return (pList);
}

int addLLElement(LinkedList* pList, float coef, int degree)
{
    ListNode *curr;
    ListNode *add_node;

	if (degree < 0 || coef == 0 || findDegree(pList, degree))
        return (FALSE); //exit();
    add_node = calloc(1, sizeof(ListNode));
    add_node->coef = coef;
    add_node->degree = degree;
    if (pList->currentElementCount == 0)
    {
        pList->headerNode.pLink = add_node;
        add_node->pLink = NULL;
    }
    else
    {
        curr = &pList->headerNode;
        while (curr->pLink->degree > degree && curr->pLink != NULL)
            curr = curr->pLink;
        add_node->pLink = curr->pLink;
        curr->pLink = add_node;
    }
    pList->currentElementCount++;
    return (TRUE);
}

int removeLLElement(LinkedList* pList, int degree)
{
	ListNode	*curr;
	ListNode	*remove_node;
	int			i;

	if (!findDegree(pList, degree))
		return (FALSE); //exit();
	i = 0;
	curr = &pList->headerNode;
    while (curr->pLink->degree > degree && curr->pLink != NULL)
            curr = curr->pLink;
	remove_node = curr->pLink;
	curr->pLink = remove_node->pLink;
	free(remove_node);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int degree)
{
	ListNode	*curr;

    if (!findDegree(pList, degree))
        return (NULL); //exit()
	curr = pList->headerNode.pLink;
    while (curr->degree != degree && curr->pLink != NULL)
            curr = curr->pLink;
	return (curr);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	int			count;

	count = pList->currentElementCount;
	while (count > 0)
	{
		removeLLElement(pList, count);
		count--;
	}
	pList->currentElementCount = 0;
	pList->headerNode.pLink = NULL;
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}

void	displayLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	int			i;

	i = 0;
	curr = pList->headerNode.pLink;
	printf("currentElementCount : %d\n", pList->currentElementCount);
	while (curr != NULL)
	{
		printf("%d th data is %fx^%d\n", i + 1, curr->coef, curr->degree);
		curr = curr->pLink;
		i++;
	}
}

int findDegree(LinkedList* pList, int degree)
{
    ListNode *curr;

    curr = pList->headerNode.pLink;
    while (curr != NULL)
    {
        if (curr->degree == degree)
            return (TRUE);
        curr = curr->pLink;
    }
    return (FALSE);
}

LinkedList* sumpoly(LinkedList *A, LinkedList *B)
{
    
}