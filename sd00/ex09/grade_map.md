# Grade Mapping (bonus)

## Problem Description

Develop new features for the grade mapping system you built previously.

You must now:

- Compute the distribution of grades (i.e., the count of each grade).
- Print the distribution of grades (must be understandable).
- Free the distribution of grades.

Compute the distribution by inserting each pair grade/count into a data structure of your choice. If a grade never appears in the mapping, it should not appear in the distribution either.

## Function Prototypes

```c
GradeNode *compute_distribution(const char **mapped_grades, int size);
void print_distribution(GradeNode *head);
void free_distribution(GradeNode *head);
```

## Files to Submit

- grade_map_bonus.c  
- grade_map.c  
- grade_map.h  

### Required Function

```c
void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);
```

## Allowed Functions

- `malloc`  
- `free`  
- `strcmp`  
- `strcpy`  
- `strlen`  
- `printf`

## Design Reasoning

- Separating logic into mapping and distribution improves maintainability.
- Linked list is chosen to make insertions flexible and independent of the number of grade types.

## Common Mistakes

| Description | Reason | Severity |
|-------------|--------|----------|
| Using flags or switch for mapping | Breaks modular design | 4 |
| Hardcoding grade labels | Prevents extensibility | 3 |
| Not freeing allocated memory | Memory leak | 5 |
| Using array for distribution | Rigid and not scalable | 4 |
