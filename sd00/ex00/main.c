#include <stdio.h>
#include "average.h"

int main()
{
	int items1[] = {70, 80, 90, 100, 60};
	int count1 = sizeof(items1) / sizeof(items1[0]);
	printf("Average: %.2f\n", average(items1, count1));

	int items2[] = {70, 80, -90, 100, 60};
	int count2 = sizeof(items2) / sizeof(items2[0]);
	printf("Average: %.2f\n", average(items2, count2));

	printf("Empty list average: %.2f\n", average(items1, 0));
	return 0;
}