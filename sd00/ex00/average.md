# Average

## Problem Description

Write a function that takes an array of integers and its size, and returns the average as a float. The elements must be:

- Validated (must be in range 0-100 inclusive).
- Ignored if invalid (must not stop the loop).

## Function Prototype

```c
float average(const int *arr, int size);
```

## Files to Submit

- average.c
- average.h

## Allowed Functions

None

## Design Reasoning

- No break, goto, or early exit.
- Clear, maintainable logic—validating and processing in separate steps.
- Handles all edge cases.

Goto, break, and continue invalid axiomatic reasoning, reducing readability and making debugging more difficult.
The function can handle an empty array and invalid values robustly.

## Common Mistakes

| Description | Reason | Severity |
|---|---|---|
| Using unnecessary early return | Reduces readability | 3 |
| Forgetting to check grade bounds | Logical error, incorrect results | 4 |
| Dividing by total size instead of valid_count | Wrong average | 5 |
