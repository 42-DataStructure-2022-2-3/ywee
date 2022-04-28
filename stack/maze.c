void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
 MapPosition endPos, LinkedMapStack *pStack)
{
    LinkedMapNode *position;
    int found = FALSE;
    int mark[HEIGHT][WIDTH] = {0, };

    if (!pStack)
    {
        pushLSMapPosition(pStack, startPos);

        while (isLinkedStackEmpty(pStack) && !found)
        {
            position = popLS(pStack);
            int x = position->pos.x;
            int y = position->pos.y;
            int direction = position->pos.direction;

            while (direction < 4 && !found)
            {
                int new_x = x + DIRECTION_OFFSETS[direction][0];
                int new_y = y + DIRECTION_OFFSETS[direction][1];

                if (new_x >= 0 && new_x < WIDTH && new_y >= 0 && new_y < HEIGHT
                && mazeArray[new_y][new_x] == NOT_VISIT && mark[new_y][new_x] == NOT_VISIT)
                {
                    MapPosition NewPosition;
                    NewPosition.x = x;
                    NewPosition.y = y;
                    NewPosition.direction = direction + 1;
                    pushLSMapPosition(pStack, NewPosition);
                    mark[y][x] = VISIT;

                    x = new_x;
                    y = new_y;
                    direction = 0;
                    if (new_x == endPos.x && new_y == endPos.y)
                    {
                        found = TRUE;
                        NewPosition.x = new_x;
                        NewPosition.y = new_y;
                        NewPosition.direction = 0;
                        pushLSMapPosition(pStack, NewPosition);
                        mark[new_y][new_x] = VISIT;
                    }
                }
                else
                    direction++;
            }
            free(position);
        }
    }
}
