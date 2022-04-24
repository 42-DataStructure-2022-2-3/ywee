#include "linkedstack.h"

int main()
{
	LinkedStack *pStack = createLinkedStack();
	char *source = "abc";

	char *str = str_rev(pStack, 3, source);
	printf("%s\n", str);
	return 0;

}

char *str_rev(LinkedStack *pStack, int size, char *pSource)
{
	StackNode *pNode;
	char *pReturn;
	int i;

	pReturn = calloc(size + 1, sizeof(char));
	if (pStack != NULL)
	{
		StackNode node;
		for (i = 0; i < size; i++)
		{
			node.data = pSource[i];
			pushLS(pStack, node);
		}
		for(i = 0; i < size; i++)
		{
			pNode = popLS(pStack);
			if (pNode != NULL)
			{
				pReturn[i] = pNode->data;
				free(pNode);
			}
 		}
		pReturn[i] = '\0';
		deleteLinkedStack(pStack);
	}
	return (pReturn);
}
