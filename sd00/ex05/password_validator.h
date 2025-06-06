#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#define MAX_PW_LEN 50

typedef enum
{
	VALID = 0,
	INVALID = 1,
} PwStatus;

PwStatus validate_password(const char *new_pw, const char *curr_pw);

#endif // PASSWORD_VALIDATOR_H
