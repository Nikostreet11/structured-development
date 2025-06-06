# First and Last Occurrences

## Problem Description

Write a function that receives:

- an array of integers (`arr[]`)
- its size (`size`)
- a target integer (`target`)

and computes:

1. The index of the **first** occurrence of `target` in `arr`, or `-1` if it doesn’t appear.
2. The index of the **last** occurrence of `target` in `arr`, or `-1` if it doesn’t appear.

## Function Prototype

```c
void first_last(int arr[], int size, int target, int *first, int *last);
```

## Files to Submit

- first_last.c  
- main.c  
- first_last.h

## Allowed Functions

None

## Design Reasoning

- A novice might be tempted to use `break` to capture the first match, which breaks axiomatic reasoning.
- Instead, using a clean `while` loop allows both `first` and `last` to be tracked in one pass.
- The solution avoids duplication of logic and is robust to edge cases like empty arrays or absence of the target.

## Common Mistakes

| Description | Reason | Severity |
|---|---|---|
| Using `break` after first match | Prevents axiomatic reasoning | 4 |
| Initializing `*first`/`*last` to 0 | Cannot distinguish “not found” from index 0 | 5 |
| Not updating `*last` on later matches | Last occurrence stays untracked | 5 |
| Writing two separate loops | Unnecessary code duplication | 2 |
