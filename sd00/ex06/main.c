#include <stdio.h>
#include <stdlib.h>
#include "grade_map.h"

void print_grades(int *scores, const char **mapped, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d → %s\n", scores[i], mapped[i]);
	}
}

/* Test main */
int main(void)
{
	int scores[] = {91, 82, 67, 90, 58, 73, 88, 91, 100, 54};
	int n = sizeof(scores) / sizeof(scores[0]);
	const char **mapped = malloc(sizeof(char *) * n);

	GradeMapper st_mapper = standard_mapper;
	GradeMapper pm_mapper = plusminus_mapper;
	GradeMapper pf_mapper = passfail_mapper;

	map_scores(scores, n, st_mapper, mapped);
	printf("\nMapped grades:\n");
	print_grades(scores, mapped, n);

	map_scores(scores, n, pm_mapper, mapped);
	printf("\nMapped grades:\n");
	print_grades(scores, mapped, n);

	map_scores(scores, n, pf_mapper, mapped);
	printf("\nMapped grades:\n");
	print_grades(scores, mapped, n);

	free(mapped);
	return 0;
}