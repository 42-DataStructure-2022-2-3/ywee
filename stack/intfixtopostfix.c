#include "linkedstack.h"

int main()
{
	char *expression = "A*(B+C)";

	intfixToPostfix(expression);
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");

	return 0;
}


void intfixToPostfix(char *expression) //ABC/D*EF+*+
{
	LinkedStack *pStack;
	StackNode	*popNode;
	StackNode	element;

	pStack = createLinkedStack();
	if (!pStack)
		return ;

	while (*expression)
	{
		if (!isOperator(*expression))
		{
			printf("%c", *expression);
		}
		else if (*expression == ')')
		{
			while((popNode = peekLS(pStack))->data != '(')
			{
				StackNode *popOper = popLS(pStack);
				printf("%c", popOper->data);
				free(popOper);
			}
			free(popNode = popLS(pStack));
		}
		else if (*expression == '(')
		{
			element.data = *expression;
			pushLS(pStack, element);
		}
		else
		{
			if (pStack->currentElementCount != 0)
			{
				while(!isLinkedStackEmpty(pStack) && checkPriority(*expression, (popNode=peekLS(pStack))->data) <= 0 && popNode->data != '(')
				{
				//	displayLinkedList(pStack);
					StackNode *popOper = popLS(pStack);
					printf("%c", popOper->data);
					free(popOper);
				}
			}
			element.data = *expression;
			pushLS(pStack, element);
			// printf("탑 : %c\n", peekLS(pStack)->data);
		}
		expression++;
	}
//	printf("남은것 : %d", pStack->currentElementCount);
	while (pStack->currentElementCount)
	{
		popNode = popLS(pStack);
		printf("%c", popNode->data);
		free(popNode);
	}
	printf("\n");
	return ;
}

int isOperator(char c)
{
	char *s = "()*/+-";
	while(*s)
	{
		if (*s == c)
			return (TRUE);
		s++;
	}
	return (FALSE);
}

int checkPriority(char c, int data)
{
	int prio1;
	int prio2;

	switch (c)
	{
		case '*':
		case '/':
			prio1 = 2;
			break;
		case '+':
		case '-':
			prio1 = 1;
			break;
		case '(':
			prio1 = 0;
	}

	switch (data)
	{
		case '*':
		case '/':
			prio2 = 2;
			break;
		case '+':
		case '-':
			prio2 = 1;
			break;
		case '(':
			prio2 = 0;
	}

	return (prio1 - prio2);

}
