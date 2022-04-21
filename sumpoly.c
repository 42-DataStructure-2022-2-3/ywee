int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*new_node;
	ListNode	*curr;
	int			i;

	if (position < 0 || position > pList->currentElementCount + 1)
		return (FALSE);
	i = 0;
	if (!new_node = malloc(sizeof(ListNode)))
		return (FALSE);
	*new_node = element;
	curr = &pList->headerNode;
	while (i < position - 1)
	{
		curr = curr->pLink;
		i++;
	}
	new_node->pLink = curr->pLink;
	curr->pLink = new_node;
	pList->currentElementCount++;
	return (TRUE);
}

int addPolyNodeLast(LinkedList* pList, float coef, int degree)
{
	int i = 0;

	ListNode node = {0,};
	node.coef = coef;
 	node.degree = degree;

	 if (pList != NULL)
	 {
		int length = getLinkedListLength(pList);
		if (addLLElement(pList, length, node))
			return (TRUE);
	}
	return (FALSE);
}

LinkedList *sumpoly(LinkedList *A, LinkedList *B)
{
	if (A->headerNode.pLink == NULL && B->headerNode.pLink == NULL)
		return (NULL);
	if (A->headerNode.pLink == NULL)
		return (B);
	if (B->headerNode.pLink == NULL)
		return (A);

	LinkedList *sumpolylist;
	ListNode *Acurr;
	ListNode *Bcurr;
	int		flag;
	sumpolylist = calloc(1, sizeof(LinkedList));
	Acurr = A->headerNode.pLink;
	Bcurr = B->headerNode.pLink;
	flag = 0;

	while (Acurr != NULL && Bcurr != NULL)
	{
		if (Acurr->degree > Bcurr->degree)
		{
			flag = addPolyLast(sumpolylist, Acurr->coef, Acurr->degree);
			Acurr = Acurr->pLink;
		}
		else if (Acurr->degree < Bcurr->degree)
		{
			flag = addPolyLast(sumpolylist, Bcurr->coef, Bcurr->degree);
			Bcurr = Bcurr->pLink;
		}
		else if (Acurr->degree == Bcurr->degree)
		{
			flag = addPolyLast(sumpolylist, Acurr->coef + Bcurr->coef, Acurr->degree);
			Acurr = Acurr->pLink;
			Bcurr = Bcurr->pLink;
		}
		else if (Acurr == NULL)
		{
			while (Bcurr != NULL)
			{
				flag = addPolyLast(sumpolylist, Bcurr->coef, Bcurr->degree);
				Bcurr = Bcurr->pLink;
			}
		}
		else if (Bcurr == NULL)
		{
			while (Acurr != NULL)
			{
				flag = addPolyLast(sumpolylist, Acurr->coef, Acurr->degree);
				Acurr = Acurr->pLink;
			}
		}
	}
	if (!flag)
		return (NULL);
	return (sumpolylist);
}
