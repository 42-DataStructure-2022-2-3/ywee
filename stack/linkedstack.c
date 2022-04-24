#include "linkedstack.h"

int main()
{
	StackNode element;
	StackNode* popelement;
	LinkedStack *list;

	list = createLinkedStack();

	element.data = 'a';
	pushLS(list, element);
	element.data = 'b';
	pushLS(list, element);
	element.data = 'c';
	pushLS(list, element);

	printf("%c\n", list->pTopElement->data);
	popelement = popLS(list);
	printf("%c\n", popelement->data);
	printf("%c\n", list->pTopElement->data);

	deleteLinkedStack(list);
	// while(1)
	// {

	// }
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}
LinkedStack* createLinkedStack()
{
	LinkedStack *pStack;

	pStack = calloc(1, sizeof(StackNode));
	if (!pStack)
		return (NULL);
	pStack->currentElementCount = 0;
	return (pStack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode* new;
	if (!pStack)
		return (FALSE);

	new = calloc(1, sizeof(StackNode));
	if (!new)
		return (FALSE);
	*new = element;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode* ret;
	StackNode* del;
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	ret = calloc(1, sizeof(StackNode));
	*ret = *(pStack->pTopElement);
	del = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	free(del);
	pStack->currentElementCount--;
	return (ret);
}
StackNode* peekLS(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}
void deleteLinkedStack(LinkedStack* pStack)
{
	if (!pStack)
		return ;
	while (pStack->currentElementCount)
		free(popLS(pStack));
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

