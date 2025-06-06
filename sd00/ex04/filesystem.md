# File System Manager

## Problem Description

Implement a basic file system manager that simulates the hierarchical structure of folders and files.

Each **folder** can contain:

- Files (each with a name and size).
- Other folders (size set to zero).

You must implement the following functions to create files and folders, insert them into parent folders, and retrieve children or a sibling.

## Function Prototypes

```c
FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);
```

## Files to Submit

- filesystem.c  
- filesystem.h  

## Allowed Functions

- `malloc`  
- `strdup`  

## Design Reasoning

- Uses a recursive, hierarchical structure (n-ary tree).
- Structs provide clarity for different node types (file/folder).
- Reduces function complexity by encapsulating logic inside well-named helper functions.

A novice might try to write all parameters directly into one function, or use flat lists with conditionals to handle different node types, leading to hard-to-read, fragile code.
Instead, a hierarchical structure (e.g., n-ary tree with linked siblings) keeps the logic readable and extendable.

## Common Mistakes

| Description | Reason | Severity |
|-------------|--------|----------|
| Using too many parameters in one function | Makes the code unreadable and hard to change | 4 |
| Using a flat list instead of hierarchy | Makes recursion or grouping impraticable | 5 |
| Failing to differentiate file and folder nodes | Breaks the computation logic | 4 |
