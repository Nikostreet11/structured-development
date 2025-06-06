#include <stdio.h>
#include "password_validator.h"

int main(void)
{
	PasswordHistory history = {.head = 0, .count = 0};

	const char *tests[] = {
		"Weak1!",        // too short / missing criteria → INVALID_WEAK
		"Strong1@Pass",  // VALID
		"Strong1@Pass",  // same as last → INVALID_SIMILAR
		"Str0ng!Pass",   // edit distance 2 from "Strong1@Pass" → VALID
		"Another$Pass2", // VALID
		"Strong1@Pass!", // edit distance 1 from "Strong1@Pass" → INVALID_SIMILAR
		"Good#Pass123",  // VALID
		"Strong1@Pass"   // same as the first one entered, but system forgot → VALID
	};
	int n = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < n; i++)
	{
		PwStatus status = validate_password(tests[i], &history);
		printf("Test \"%s\": ", tests[i]);
		if (status == VALID)
		{
			printf("VALID\n");
		}
		else if (status == INVALID_WEAK)
		{
			printf("INVALID_WEAK\n");
		}
		else if (status == INVALID_SIMILAR)
		{
			printf("INVALID_SIMILAR\n");
		}
	}
	return 0;
}
