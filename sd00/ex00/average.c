#include "average.h"

float average(const int *arr, int size)
{
	int i = 0;
	int valid_count = 0;
	int sum = 0;

	while (i < size)
	{
		int grade = arr[i];
		if (grade >= 0 && grade <= 100)
		{
			sum += grade;
			valid_count++;
		}
		i++;
	}

	if (valid_count == 0)
	{
		return 0.0f;
	}
	return (float)sum / valid_count;
}
