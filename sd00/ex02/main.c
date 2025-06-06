// main.c
#include <stdio.h>
#include "segmented_runs.h"

int main(void)
{
	int arr1[] = {2, 3, 4, -1, 5, 6, -1, 1, 2, 3, 4};
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("Test 1: %d segments with run (expected 2)\n", count_segments(arr1, size1));

	int arr2[] = {1, 1, 2, 2, -1, -1, 5, 7, 9, -1, 2, 2, 2};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	printf("Test 2: %d segments with run (expected 1)\n", count_segments(arr2, size2));

	int arr3[] = {-1, -1, -1}; // three empty segments
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	printf("Test 3: %d segments with run (expected 0)\n", count_segments(arr3, size3));

	int arr4[] = {1, 2, 3, 4, 5}; // single segment, full increasing run
	int size4 = sizeof(arr4) / sizeof(arr4[0]);
	printf("Test 4: %d segments with run (expected 1)\n", count_segments(arr4, size4));

	int arr5[] = {5, 4, 3, 2, 1, -1, 2, 2, 2}; // no increasing runs in any segment
	int size5 = sizeof(arr5) / sizeof(arr5[0]);
	printf("Test 5: %d segments with run (expected 0)\n", count_segments(arr5, size5));

	return 0;
}
