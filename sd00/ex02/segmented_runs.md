# Count Increasing Runs in Segmented Data

## Problem Description

You have an array of integers divided into multiple segments. The boundaries of each segment are marked by a special sentinel value `-1` (which is **not** part of any segment).

Example:  
`[2, 3, 4, -1, 5, 6, -1, 1, 2, 3, 4]`  
contains 3 segments:

- Segment 1: `[2, 3, 4]`
- Segment 2: `[5, 6]`
- Segment 3: `[1, 2, 3, 4]`

Your task is to write a function that:

- Counts how many segments contain **at least one increasing sequence of length 3 or more** (strictly increasing consecutive numbers).
- Returns this count.

**Important:**

- The input array may contain zero or more segments, separated by `-1`.
- Segments can be empty (two consecutive `-1`s).

## Function Prototype

```c
int count_segments(const int *arr, int size);
```

## Files to Submit

- segmented_runs.c  
- segmented_runs.h

## Allowed Functions

None

## Design Reasoning

- The problem naturally splits into subproblems: analyzing individual segments vs analyzing the whole array.
- Local variables in each function track different levels of state cleanly.
- Avoids the temptation to use global variables for counters or flags.
- Improves code clarity and maintainability by function separation.

This exercise enforces proper variable scoping, modular design, and maintainable code.

## Common Mistakes

| Description | Reason | Severity |
|---|---|---|
| Using global variables to track counts or flags | Breaks modularity and testability | 5 |
| Processing the entire array without splitting by segment | Complex, hard to maintain code | 4 |
| Not handling empty segments correctly | Incorrect counts | 4 |
| Off-by-one errors in segment length | Misses valid runs | 3 |
| Forgetting strict increase condition | False positives | 4 |
