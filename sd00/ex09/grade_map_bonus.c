#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade_map.h"

/* Helper to print the distribution list */
void print_distribution(GradeNode *head)
{
	while (head != NULL)
	{
		printf("%s: %d\n", head->grade, head->count);
		head = head->next;
	}
}

/* Helper to free the distribution list */
void free_distribution(GradeNode *head)
{
	while (head != NULL)
	{
		GradeNode *tmp = head;
		head = head->next;
		free(tmp->grade);
		free(tmp);
	}
}

/* Step 2: Compute distribution using linked list */
GradeNode *add_or_increment(GradeNode *head, const char *grade)
{
	GradeNode *current = head;
	GradeNode *prev = NULL;
	while (current != NULL)
	{
		if (strcmp(current->grade, grade) == 0)
		{
			current->count++;
			return head;
		}
		prev = current;
		current = current->next;
	}

	GradeNode *new_node = malloc(sizeof(GradeNode));
	new_node->grade = malloc(strlen(grade) + 1);
	strcpy(new_node->grade, grade);
	new_node->count = 1;
	new_node->next = NULL;

	if (prev == NULL)
	{
		return new_node;
	}
	else
	{
		prev->next = new_node;
		return head;
	}
}

GradeNode *compute_distribution(const char **mapped_grades, int size)
{
	GradeNode *head = NULL;
	for (int i = 0; i < size; i++)
	{
		head = add_or_increment(head, mapped_grades[i]);
	}
	return head;
}
