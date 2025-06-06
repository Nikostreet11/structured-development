#include <string.h>
#include "password_validator.h"

static int min3(int a, int b, int c)
{
	int m = (a < b) ? a : b;
	return (m < c) ? m : c;
}

/* Recursive edit distance (Levenshtein) */
static int edit_distance(const char *s1, const char *s2)
{
	if (*s1 == '\0')
	{
		return my_strlen(s2);
	}
	if (*s2 == '\0')
	{
		return my_strlen(s1);
	}
	if (*s1 == *s2)
	{
		return edit_distance(s1 + 1, s2 + 1);
	}
	int insert_cost = 1 + edit_distance(s1, s2 + 1);
	int delete_cost = 1 + edit_distance(s1 + 1, s2);
	int substitute_cost = 1 + edit_distance(s1 + 1, s2 + 1);
	return min3(insert_cost, delete_cost, substitute_cost);
}

/* Returns 1 if edit distance ≤ EDIT_DISTANCE_THRESHOLD */
static int is_similar(const char *s1, const char *s2)
{
	int dist = edit_distance(s1, s2);
	return (dist <= EDIT_DISTANCE_THRESHOLD);
}

/* Helper to save a new password in the history */
void store_password(const char *new_pw, PasswordHistory *history)
{
	int idx;
	if (history->count < HISTORY_SIZE)
	{
		idx = (history->head + history->count) % HISTORY_SIZE;
		history->count++;
	}
	else
	{
		idx = history->head;
		history->head = (history->head + 1) % HISTORY_SIZE;
	}
	strncpy(history->passwords[idx], new_pw, MAX_PW_LEN - 1);
	history->passwords[idx][MAX_PW_LEN - 1] = '\0';
}

/*
 * Validate a new password against strength and similarity rules.
 * On VALID, the password is inserted into history (overwriting oldest).
 */
PwStatus validate_password(const char *new_pw, PasswordHistory *history)
{
	if (!is_strong_password(new_pw))
	{
		return INVALID_WEAK;
	}
	// Check similarity against last passwords
	int i, idx;
	for (i = 0; i < history->count; i++)
	{
		idx = (history->head + i) % HISTORY_SIZE;
		if (is_similar(new_pw, history->passwords[idx]))
		{
			return INVALID_SIMILAR;
		}
	}
	// Insert new password into circular history
	store_password(new_pw, history);
	return VALID;
}