#include <stdio.h>
#include "critical_windows.h"

int main(void)
{
	int readings1[] = {80, 95, 120, 88, 100, 60, 75, 85, 130, 140};
	int size1 = sizeof(readings1) / sizeof(readings1[0]);
	printf("Test 1: %d critical windows (expected 4)\n",
		   count_critical_windows(readings1, size1));

	int readings2[] = {70, 71, 72, 73, 74, 75, 76, 77, 78};
	int size2 = sizeof(readings2) / sizeof(readings2[0]);
	printf("Test 2: %d critical windows (expected 0)\n",
		   count_critical_windows(readings2, size2));

	int readings3[] = {50, 60, 65, 70, 69, 80, 55, 60, 45};
	int size3 = sizeof(readings3) / sizeof(readings3[0]);
	printf("Test 3: %d critical windows (expected 0)\n",
		   count_critical_windows(readings3, size3));

	int readings4[] = {90, 95, 92, 93, 91, 92, 93, 94};
	int size4 = sizeof(readings4) / sizeof(readings4[0]);
	printf("Test 4: %d critical windows (expected 4)\n",
		   count_critical_windows(readings4, size4));

	int readings5[] = {200, 80, 85, 90, 95, 100, 105};
	int size5 = sizeof(readings5) / sizeof(readings5[0]);
	printf("Test 5: %d critical windows (expected 2)\n",
		   count_critical_windows(readings5, size5));

	return 0;
}
