void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
 MapPosition endPos, LinkedMapStack *pStack)
{
    MapPosition curPos;

    if (!mazeArray || pStack)
        return (NULL);
    if (pStack->currentElementCount == 0)
        pushLSMapPosition(pStack, startPos);

    curPos = peekLS(pStack)->pos;
    mazeArray[curPos.y][curPos.x] = VISIT;

    if (curPos != endPos)
    {


    }
        // peek = 'u'
        // 1 1 1 1 1 1 1 1 1
        // 1 1 1 1 1 s 1 1 1
        // 1 1 1 1 1 0 1 1 1
        // 1 1 1 1 1 0 1 1 1
        // 1 1 1 1 1 0 1 1 1
        // 1 1 1 1 1 s 1 1 1
        // 1 1 1 1 1 1 1 1 1
        // 위로 갈수 있으면
        if(curPos.y-1 >= 0 && map[curPos.y-1][curPos.x] == NOT_VISIT) 
        { // + PEEK 이전 노드 반대방향은 안보도록
            pushLSMapPosition(pStack, curPos);
            findPath(mazeArray, startPos, endPos, pStack));
        }
        // 아래로 갈수 있으면
        if(curPos.y+1 < rows && map[curPos.y+1][curPos.x] == NOT_VISIT) 
        {
            pushLSMapPosition(pStack, curPos);
           findPath(mazeArray, startPos, endPos, pStack));
        }
        // 왼쪽으로 갈수 있으면
        if(curPos.x-1 >= 0 && map[curPos.y][curPos.x-1] == NOT_VISIT) 
        {
            pushLSMapPosition(pStack, curPos);
            findPath(mazeArray, startPos, endPos, pStack));
        }
        // 오른쪽으로 갈수 있으면
        if(curPos.x+1 < cols && map[curPos.y][curPos.x+1] == NOT_VISIT) 
        {
            pushLSMapPosition(pStack, curPos);
            findPath(mazeArray, startPos, endPos, pStack));
            move++;
        }
        while (move--)
        {
            pop(stack);
        }
    
    if (pStack->currentElementCount == 0)
        return ;
        // 지나간 자리를 다시 지나갈수 있도록 복구함.
        map[curPos.y][curPos.x] = NOT_VISIT;

    if ()



}

int pushLSMapPosition(LinkedMapStack* pStack, MapPosition data)
{
    StackNode element;
    if (!pStack)
        return (FALSE);
    element.node = data;
    pushLS(pStack, element);
    return (TRUE);
}

void showPath(LinkedMapStack *pStack, int mazeArray[HEIGHT][WIDTH])
{



}

void printMaze(int mazeArray[HEIGHT][WIDTH])
{


    
}

int pushLS(LinkedMapStack* pStack, LinkedMapNode element)
{
	LinkedMapNode* new;
	if (!pStack)
		return (FALSE);

	new = calloc(1, sizeof(LinkedMapNode));
	if (!new)
		return (FALSE);
	*new = element;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}