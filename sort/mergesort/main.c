#include "sort.h"

int main()
{
    int i;

    int list[] = {21, 10, 12, 20, 25, 13, 15, 22};

    merge_sort(list, 0, 7);
    for (i = 0; i < 8; i++)
        printf("%d ", list[i]);
    return 0;
}
