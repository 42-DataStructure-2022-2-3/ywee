#include "linkedstack.h"

int main()
{
	char *expression = "({a+b}) + c";

	LinkedStack *pStack;
	pStack = createLinkedStack();

	printf("%d\n", checkBracketMatching(pStack, expression));

	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return 0;
}


int	matchSymbol(StackNode *checkSymbol, StackNode symbol)
{
	int ret = FALSE;

	switch (symbol.data)
	{
		case ')' :
			if (checkSymbol->data == '(')
				ret = TRUE;
			break ;
		case '}' :
			if (checkSymbol->data == '{')
				ret = TRUE;
			break ;
		case ']' :
			if (checkSymbol->data == '[')
				ret = TRUE;
			break ;
	}
	return (ret);
}

int checkBracketMatching(LinkedStack* pStack, char *expression)
{
	StackNode	symbol;
	StackNode*	checksymbol;
	int	result = TRUE;

	while (*expression && result)
	{
		symbol.data = *expression;
		switch( symbol.data )
		{
			case '(':
			case '[':
			case '{':
				pushLS(pStack, symbol);
				break;
			case ')':
			case ']':
			case '}':
			if (isLinkedStackEmpty(pStack))
			{
				result = FALSE;
			}
			else
			{
				checksymbol = popLS(pStack);
				if (!matchSymbol(checksymbol, symbol))
				{
					result = FALSE;
				}
				free(checksymbol);
				checksymbol = NULL;
			}
			break;
		}
		expression++;
	}
	if (!isLinkedStackEmpty(pStack))
		result = FALSE;
	return result;
}
