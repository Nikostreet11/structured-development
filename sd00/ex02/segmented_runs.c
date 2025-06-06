#include "segmented_runs.h"

// Returns 1 if segment contains an increasing run of length >= 3
int has_increasing_run(const int *segment, int length)
{
	if (length < 3)
		return 0;

	int streak = 1;
	int i = 1;
	while (i < length)
	{
		if (segment[i] > segment[i - 1])
		{
			streak++;
			if (streak >= 3)
				return 1;
		}
		else
		{
			streak = 1;
		}
		i++;
	}
	return 0;
}

// Counts how many segments contain an increasing run of length >= 3
int count_segments(const int *arr, int size)
{
	int count = 0;

	int start = 0; // start index of current segment
	int i = 0;

	while (i <= size)
	{ // loop runs until size to process last segment
		if (i == size || arr[i] == -1)
		{
			int segment_length = i - start;
			if (segment_length > 0)
			{
				if (has_increasing_run(&arr[start], segment_length))
				{
					count++;
				}
			}
			start = i + 1; // next segment starts after -1
		}
		i++;
	}
	return count;
}
