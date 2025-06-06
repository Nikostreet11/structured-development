# Password Validator (bonus)

## Problem Description

Develop new features for the password validation system you built previously.
The system must now enforce the following strength rules for a new password:

1. **Strength rules**:

   - At least 8 characters long
   - At least one uppercase letter
   - At least one lowercase letter
   - At least one digit
   - At least one special character (`!@#$%^&*`)

2. **Similarity rule**:

   - The new password must not have an **edit distance** less or equal than *one* from any of the last three chosen passwords.

Store the last three accepted passwords so that inserting a new valid password overwrites the oldest entry. The validation function returns one of three states:

- `0 = VALID`
- `1 = INVALID_WEAK` (fails strength rules)
- `2 = INVALID_SIMILAR` (too similar to one of the last three **valid** passwords)

## Function Prototype

```c
PwStatus validate_password(const char *new_pw, PasswordHistory *history);
```

## Files to Submit

- `password_validator.c`
- `password_validator_bonus.c`
- `password_validator.h`
- `main.c`

## Allowed Functions

- `strncpy`

## Design Reasoning

- **Circular list**: Stores up to three previous passwords. When a new valid password is accepted, it replaces the oldest entry and advances the head.
- **Modularity**:  
  - Helper functions check length, character classes, and edit distance.  
  - No global variables—state is managed via `PasswordHistory`.  
- **Edit distance**:  
  - Implemented recursively to compare two strings.  
  - `EDIT_DISTANCE_THRESHOLD` is defined once; not hardcoded as “1” in multiple places.  
- **Validation steps**:  

 1. Check strength criteria.  
 2. Compute edit distance against each stored password; if any distance ≤ `EDIT_DISTANCE_THRESHOLD`, reject as `INVALID_SIMILAR`.  
 3. If valid, insert into the circular history.

## Common Mistakes

| Description | Reason | Severity |
|-------------|--------|----------|
| Hardcoding edit-distance threshold in comparisons | Makes updates error-prone; should be a single `#define` or `const`.                        | 5        |
| Using a linear array instead of a circular buffer | Overwriting history requires shifting all elements, reducing performance and readability.  | 4        |
| Not handling recursive base cases correctly       | Leads to infinite recursion or incorrect distance calculations.                           | 5        |
| Failing to null-terminate after `strncpy`         | Produces undefined behavior when reading the string later.                                 | 4        |
| Mixing similarity and strength checks             | Blurs responsibilities and makes logic hard to test and maintain.                          | 3        |
