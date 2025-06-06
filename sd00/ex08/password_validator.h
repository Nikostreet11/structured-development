#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#define MAX_PW_LEN 50
#define HISTORY_SIZE 3
#define EDIT_DISTANCE_THRESHOLD 1

typedef enum
{
	VALID = 0,
	INVALID_WEAK = 1,
	INVALID_SIMILAR = 2
} PwStatus;

typedef struct
{
	char passwords[HISTORY_SIZE][MAX_PW_LEN];
	int head;  // points to the oldest password
	int count; // number of stored passwords (≤ HISTORY_SIZE)
} PasswordHistory;

int my_strlen(const char *s);
int is_strong_password(const char *pw);
PwStatus validate_password(const char *new_pw, PasswordHistory *history);

#endif // PASSWORD_VALIDATOR_H
