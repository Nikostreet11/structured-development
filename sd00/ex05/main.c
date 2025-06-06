#include <stdio.h>
#include "password_validator.h"

int main(void)
{
	const char *tests[] = {
		"Weak1!",		 // too short / missing criteria → INVALID
		"Strong1@Pass",	 // VALID
		"Strong1@Pass",	 // same as last → INVALID
		"Str0ng!Pass",	 // VALID
		"Another$Pass2", // VALID
		"Strong1@Pass!", // VALID
		"Good#Pass123",	 // VALID
		"Strong1@Pass"	 // same as the first one entered, but system forgot → VALID
	};
	int n = sizeof(tests) / sizeof(tests[0]);
	const char *curr_pw = NULL;
	for (int i = 0; i < n; i++)
	{
		PwStatus status = validate_password(tests[i], curr_pw);
		printf("Test \"%s\": ", tests[i]);
		if (status == VALID)
		{
			printf("VALID\n");
			curr_pw = tests[i];
		}
		else if (status == INVALID)
		{
			printf("INVALID\n");
		}
	}
	return 0;
}
