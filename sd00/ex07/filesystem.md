# File System Manager (bonus)

## Problem Description

Develop new features for the file system manager you built previously.

You must:

- Recursively compute the total size of any given folder, which includes all files and nested contents.
- Implement a helper to print the structure in a tree-like format.
- Implement a recursive function to free the entire file system.

## Function Prototypes

```c
int compute_total_size(FSNode *node);
void print_structure(const FSNode *node, int indent);
void free_filesystem(FSNode *node);
```

## Files to Submit

- filesystem_bonus.c  
- filesystem.c  
- filesystem.h  

### Required Functions

```c
FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);
```

## Allowed Functions

- `malloc`  
- `free`  
- `strdup`  
- `printf`  

## Design Reasoning

- Uses a recursive, hierarchical structure (n-ary tree).
- Structs provide clarity for different node types (file/folder).
- Reduces function complexity by encapsulating logic inside well-named helper functions.

## Common Mistakes

| Description | Reason | Severity |
|-------------|--------|----------|
| Using too many parameters in one function | Makes the code unreadable and hard to change | 4 |
| Using a flat list instead of hierarchy | Makes recursion or grouping impraticable | 5 |
| Forgetting to free memory | Causes memory leaks in larger systems | 3 |
| Failing to differentiate file and folder nodes | Breaks the computation logic | 4 |
