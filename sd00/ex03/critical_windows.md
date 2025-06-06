# Critical Windows

## Problem Description

Write a function that takes an array of daily seismic tremor readings and its size, and returns how many **critical windows** occurred.

A **critical window** is any **5-day** period that meets **all** the following conditions:

- At least 3 of the 5 days had readings **≥ 70**.
- No reading exceeded **150**.
- The **average** of the 5 values is **≥ 90**.

The function must analyze each 5-day window in the input (using a **sliding window**) and return how many of them qualify as "critical".

## Function Prototype

```c
int count_critical_windows(const int *readings, int size);
```

## Files to Submit

- `critical_windows.c`
- `critical_windows.h`

## Allowed Functions

None

## Design Reasoning

- Threshold values appear in multiple conditions; they should be clearly defined once, avoiding *magic numbers* in the code.
- Each helper function handles one clear task with local variables only, improving testability and readability.
- Avoids early exits or break/continue to preserve linear flow and maintain axiomatic reasoning.

## Common Mistakes

| Description | Reason | Severity |
|-------------|--------|----------|
| Using hardcoded magic numbers | Poor maintainability if thresholds change | 5 |
| Hardcoding multiple checks in one loop | Decreases readability and testability | 4 |
| Not handling windows correctly | Off-by-one errors, incorrect counting | 3 |
