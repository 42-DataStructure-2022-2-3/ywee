#include "linkedstack.h"

// int main()
// {
// 	char *expression = "187*-";

// 	StackNode *result;

// 	result = calcExpr(expression);
// 	printf("%d\n", result->data);
// 	return 0;
// }

StackNode* calcExpr (char *expression)
{
	LinkedStack *pStack;
	StackNode	element;
	StackNode	*operand1;
	StackNode	*operand2;


	pStack = createLinkedStack();

	while (*expression)
	{
		if (!isoperator(*expression))
		{
			if (*expression >= '0' || *expression <= '9')
			{
				element.data = *expression;
				element.data -= '0';
			 	pushLS(pStack, element);
			}
			else
			{
				deleteLinkedStack(pStack);
				return (NULL);
			}
		}
		else if (isoperator(*expression))
		{
			if (pStack->currentElementCount < 2)
			{
				deleteLinkedStack(pStack);
				return (NULL);
			}
			operand2 = popLS(pStack);
			operand1 = popLS(pStack);
			if (*expression == '/' && operand2->data == 0)
			{
				free(operand2);
				free(operand1);
				deleteLinkedStack(pStack);
				return (NULL);
			}
			element.data = doop(operand1->data, operand2->data, *expression);
			pushLS(pStack, element);
			free(operand2);
			free(operand1);
		}
		expression++;
	}
	if (pStack->currentElementCount != 1)
	{
		deleteLinkedStack(pStack);
		return (NULL);
	}
	return (popLS(pStack));
}

int	isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c== '/')
		return (TRUE);
	return (FALSE);
}

int doop(int data1, int data2, char expression)
{
	int result;

	switch(expression)
	{
		case '+' :
			result = (data1 + data2);
			break ;
		case '-' :
			result = (data1 - data2);
			break ;
		case '*' :
			result = (data1 * data2);
			break ;
		case '/' :
			result = (data1 / data2);
			break ;
	}
	return (result);
}
