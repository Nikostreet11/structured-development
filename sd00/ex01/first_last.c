#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last) {
	int i = 0;
	*first = -1;
	*last  = -1;

	/* Single pass, no break/continue/goto */
	while (i < size) {
		if (arr[i] == target) {
			if (*first == -1) {
				/* record first occurrence */
				*first = i;
			}
			/* always update last occurrence */
			*last = i;
		}
		i++;
	}
}
