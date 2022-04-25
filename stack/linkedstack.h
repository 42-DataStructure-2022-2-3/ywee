#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef enum PrecedenceType
{
	lparen,
	rparen,
	times,
	divide,
	plus,
	minus,
	operand
} Precedence;

typedef struct ExprTokenType {
	float value;
	Precedence type;
	struct ExprToken* pLink;
} ExprToken;

typedef struct LinkedTokenType
{
	int currentElementCount;	// ���� ������ ����
	ExprToken* pTopElement;		// Top ����� ������
} TokenStack;

typedef struct StackNodeType
{
	int	data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// ���� ������ ����
	StackNode* pTopElement;		// Top ����� ������
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

void	displayLinkedList(LinkedStack* pStack);

char *str_rev(LinkedStack *pStack, int size, char *pSource);
int	matchSymbol(StackNode *checkSymbol, StackNode symbol);
int checkBracketMatching(LinkedStack* pStack, char *expression);

StackNode* calcExpr (char *expression);
int	isOperator(char c);
int doop(int data1, int data2, char expression);

void intfixToPostfix(char *expression);
int checkPriority(char c, int data);

#include <stdio.h>
#include <stdlib.h>
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
