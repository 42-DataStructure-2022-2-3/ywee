#include <stdio.h>

int sort[8];

void    merge(int list[], int left, int right)
{
    int i, j, k, l;
    int mid = (left + right) / 2;

    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
            sort[k++] = list[i++];
        else
            sort[k++] = list[j++];
    }

    if (i > mid)
    {
        for (l = j; l <= right; l++)
            sort[k++] = list[l];
    }
    else
    {
        for (l = i; l <= mid; l++)
            sort[k++] = list[l];
    }

    for (l = left; l <= right; l++)
        list[l] = sort[l];
}

void    merge_sort(int list[], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, right);
    }
}

int main()
{
    int i;

    int list[] = {21, 10, 12, 20, 25, 13, 15, 22};

    merge_sort(list, 0, 7);
    for (i = 0; i < 8; i++)
        printf("%d ", list[i]);
    return 0;
}
