# Grade Mapping

## Problem Description

Write a program that converts an array of integer scores into an array of grade strings using a dynamic mapping strategy.

The grade mapping function must support the following mapping strategies:

- `standard_mapper` (A - F scale)

  | score | grade |
  |:-----:|:-----:|
  | 90 - 100 | A |
  | 80 - 89 | B |
  | 70 - 79 | C |
  | 60 - 69 | D |
  | 0 - 59 | F |

- `plusminus_mapper` (A+ / A / A- / B+ ... F scale)

  | score | grade |
  |:-----:|:-----:|
  | 97 - 100 | A+ |
  | 93 - 96 | A |
  | 90 - 92 | A- |
  | 87 - 89 | B+ |
  | 83 - 86 | B |
  | 80 - 82 | B- |
  | 77 - 79 | C+ |
  | 73 - 76 | C |
  | 70 - 72 | C- |
  | 67 - 69 | D+ |
  | 63 - 66 | D |
  | 60 - 62 | D- |
  | 0 - 59 | F |

- `passfail_mapper`: (Pass / Fail)

  | score | grade |
  |:-----:|:-----:|
  | 60 - 100 | P |
  | 0 - 59 | F |

## Function Prototype

```c
void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);
```

## Files to Submit

- grade_map.c  
- grade_map.h

## Allowed Functions

None

## Design Reasoning

- This exercise discourages bad practices like function flags and promotes function pointers for flexibility.

Flags can lead to several `switch` statements to manage different strategies, while function pointers facilitate the development of new features without the need to modify existing code.

## Common Mistakes

| Description | Reason | Severity |
|-------------|--------|----------|
| Using flags or switch for mapping | Breaks modular design | 4 |
| Hardcoding grade labels | Prevents extensibility | 3 |
| Not freeing allocated memory | Memory leak | 5 |
