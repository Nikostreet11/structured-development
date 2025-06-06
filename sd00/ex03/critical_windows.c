#include "critical_windows.h"

// Check if a single reading is valid (not over max threshold)
int is_valid_reading(int value)
{
	return value <= MAX_OPERATING_THRESHOLD;
}

// Check if a reading qualifies as a dangerous day
int is_dangerous_day(int value)
{
	return value >= DANGER_THRESHOLD;
}

// Check if a window of 5 readings is a critical window
int is_critical_window(const int *window)
{
	int danger_days = 0;
	int sum = 0;
	int i = 0;

	while (i < WINDOW_SIZE)
	{
		if (!is_valid_reading(window[i]))
		{
			return 0;
		}
		if (is_dangerous_day(window[i]))
		{
			danger_days++;
		}
		sum += window[i];
		i++;
	}

	if (danger_days < MIN_DANGER_DAYS)
	{
		return 0;
	}

	float average = (float)sum / WINDOW_SIZE;
	return average >= AVG_DANGER_THRESHOLD;
}

// Count how many 5-day windows are critical
int count_critical_windows(const int *readings, int size)
{
	int count = 0;
	int i = 0;

	while (i <= size - WINDOW_SIZE)
	{
		if (is_critical_window(&readings[i]))
		{
			count++;
		}
		i++;
	}

	return count;
}
