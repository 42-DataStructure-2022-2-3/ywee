#include "radixsort.h"

int main()
{
    int list[] = {15, 27, 64, 25, 50, 17, 39, 280};

    radix_sort(list, 8);

    for (int i = 0; i < 8; i++)
        printf("%d ", list[i]);
    return 0;
}
