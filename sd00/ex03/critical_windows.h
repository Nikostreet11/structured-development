#ifndef CRITICAL_WINDOWS_H
#define CRITICAL_WINDOWS_H

#define WINDOW_SIZE 5
#define MIN_DANGER_DAYS 3
#define DANGER_THRESHOLD 70
#define MAX_OPERATING_THRESHOLD 150
#define AVG_DANGER_THRESHOLD 90

int count_critical_windows(const int *readings, int size);

#endif // CRITICAL_WINDOWS_H
