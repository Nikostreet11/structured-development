#include <stdio.h>
#include "first_last.h"

int main(void)
{
	int arr1[] = {5, 3, 7, 3, 9, 3, 2};
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int first, last;

	first_last(arr1, size1, 3, &first, &last);
	printf("Array: {5, 3, 7, 3, 9, 3, 2}\n");
	printf("Target 3 → First: %d, Last: %d\n\n", first, last);
	// Expected: First 1, Last 5

	int arr2[] = {1, 2, 3, 4, 5};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	first_last(arr2, size2, 6, &first, &last);
	printf("Array: {1, 2, 3, 4, 5}\n");
	printf("Target 6 → First: %d, Last: %d\n\n", first, last);
	// Expected: First -1, Last -1 (not found)

	int *arr3 = NULL;
	int size3 = 0;
	first_last(arr3, size3, 10, &first, &last);
	printf("Empty array → First: %d, Last: %d\n", first, last);
	// Expected: First -1, Last -1

	return 0;
}
