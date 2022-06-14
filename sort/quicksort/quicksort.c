#include "quicksort.h"

void	quicksort(int list[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(list, start, end);
		printf("pivot : %d\n", pivot);
		for (int i = 0; i < 9; i++)
			printf("%d ", list[i]);
		printf("\n");
		quicksort(list, start, pivot - 1);
		quicksort(list, pivot + 1, end);
	}

}

int partition(int list[], int start, int end)
{
	int pivot = list[(start + end)/ 2];
	int tmp;

	while (start < end)
	{
		while (list[start] < pivot)
			start++;
		while (list[end] > pivot)
			end--;
		if (start <= end)
		{
			tmp = list[start];
			list[start] = list[end];
			list[end] = tmp;
		}
	}
	return start;
}
