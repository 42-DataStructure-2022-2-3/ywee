#include "arraystack.h"

int main()
{
	ArrayStack *pStack;
	StackNode element;

	element.data = 'a';

	pStack = createArrayStack(5);
	pushAS(pStack, element);
	element.data = 'b';
	pushAS(pStack, element);

	// deleteArrayStack(pStack);

	while (1)
	{

	}
	printf("%p\n", pStack);
	printf("%c\n", pStack->ArrayStack->data);
	printf("%c\n", pStack->pTopElement->data);
	return 0;
}

ArrayStack* createArrayStack(int maxelementCount)
{
	ArrayStack *pStack;

	pStack = calloc(1, sizeof(ArrayStack));
	if (!pStack)
		return (NULL);
	pStack->maxelementCount = maxelementCount;
	pStack->ArrayStack = calloc(maxelementCount, sizeof(StackNode));
	if (!pStack->ArrayStack)
		return (NULL);
	return (pStack);
}

int pushAS(ArrayStack* pStack, StackNode element)
{
	if (isArrayStackFull(pStack))
		return (FALSE);
	pStack->ArrayStack[pStack->currentElementCount] = element;
	pStack->pTopElement = &(pStack->ArrayStack[pStack->currentElementCount]);
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popAS(ArrayStack* pStack)
{
	StackNode* ret;

	if (isArrayStackEmpty(pStack))
		return (NULL);
	ret = calloc(1, sizeof(StackNode));
	if (!ret)
		return (NULL);
	ret->data = pStack->pTopElement->data;
	pStack->pTopElement->data = 0;
	pStack->currentElementCount--;
	pStack->pTopElement = &(pStack->ArrayStack[pStack->currentElementCount - 1]);
	return (ret);
}

StackNode* peekAS(ArrayStack* pStack)
{
	if (isArrayStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return ;
	free(pStack->ArrayStack);
	free(pStack);
	pStack = NULL;
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (pStack->currentElementCount == pStack->maxelementCount)
		return (TRUE);
	else
		return (FALSE);
}
int isArrayStackEmpty(ArrayStack* pStack)
{
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
