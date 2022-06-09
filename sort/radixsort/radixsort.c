#include "radixsort.h"

void    radix_sort(int list[], int n)
{
    int powed = 1;
    int maxsize = getmaxsize(list, n);
    LinkedQueue *Queue[10];
    int idx = 0;

    for (int i = 0; i < 10; i++)
        Queue[i] = createLinkedQueue();

    for (int i = 0; i < maxsize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            QueueNode element;
            element.data = list[j];
            int index = (list[j]/powed) % 10;
            insertLQ(Queue[index], element);
        }

        for (int k = 0; k < 10; k++)
        {
            int count = Queue[k]->currentElementCount;
            for (int num = 0; num < count; num++)
            {
                QueueNode *del = deleteLQ(Queue[k]);
                int data = del->data;
                list[idx] = data;
                idx++;
            }
        }
        idx = 0;
        powed *= 10;
    }
}

int getmaxsize(int list[], int n)
{
    int maxsize = 0;
    int length;
    for (int i = 0; i < n; i++)
    {
        int tmp = list[i];
        length = 1;
        while (tmp / 10 > 0)
        {
            length++;
            tmp = tmp / 10;
        }
        if (length > maxsize)
            maxsize = length;
    }
    return maxsize;
}
