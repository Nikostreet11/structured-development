#include "password_validator.h"

/* Helper: compute length */
int my_strlen(const char *s)
{
	int len = 0;
	while (s[len] != '\0')
		len++;
	return len;
}

/* Helper: check uppercase */
static int has_uppercase(const char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			return 1;
		i++;
	}
	return 0;
}

/* Helper: check lowercase */
static int has_lowercase(const char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			return 1;
		i++;
	}
	return 0;
}

/* Helper: check digit */
static int has_digit(const char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			return 1;
		i++;
	}
	return 0;
}

/* Helper: check special character */
static int has_special(const char *s)
{
	const char *specials = "!@#$%^&*";
	int i = 0;
	while (s[i])
	{
		int j = 0;
		while (specials[j])
		{
			if (s[i] == specials[j])
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

/* Check strength rules */
int is_strong_password(const char *pw)
{
	int len = my_strlen(pw);
	if (len < 8)
		return 0;
	if (!has_uppercase(pw))
		return 0;
	if (!has_lowercase(pw))
		return 0;
	if (!has_digit(pw))
		return 0;
	if (!has_special(pw))
		return 0;
	return 1;
}

/* Returns 1 the two strings are equal, 0 otherwise */
static int is_equal(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return 0;

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return 0;
		s1++;
		s2++;
	}

	return (*s1 == '\0' && *s2 == '\0');
}
