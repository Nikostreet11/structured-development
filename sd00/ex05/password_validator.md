# Password Validator

## Problem Description

Implement a password validation system that enforces the following strength rules for a new password:

- At least 8 characters long
- At least one uppercase letter
- At least one lowercase letter
- At least one digit
- At least one special character (`!@#$%^&*`)
- Must differ from current password

The validation function returns one of two states:

- `0 = VALID`
- `1 = INVALID` (fails any of the rules above)

## Function Prototype

```c
PwStatus validate_password(const char *new_pw, const char *curr_pw);
```

## Files to Submit

- `password_validator.c`
- `password_validator.h`

## Allowed Functions

None

## Design Reasoning

- **Modularity**:  
  - Different helper functions check length, character classes, and password equality.
  - The password validation process follows a logic structure.

## Common Mistakes

| Description | Reason | Severity |
|-------------|--------|----------|
| Hardcoding different checks in a single function | Worsen readability and extendability | 5 |
| Mixing similarity and strength checks | Blurs responsibilities and makes logic hard to test and maintain. | 3 |
