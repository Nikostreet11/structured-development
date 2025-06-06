#ifndef FILESYSTEM_H
#define FILESYSTEM_H

typedef enum {
    FILE_NODE,
    FOLDER_NODE
} NodeType;

typedef struct FSNode {
    NodeType type;
    char *name;
    int size; // In KB

    struct FSNode *children;   // Head of linked list (only for folders)
    struct FSNode *sibling;    // Next node in same folder
} FSNode;

FSNode* create_file(const char *name, int size);
FSNode* create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);
int compute_size(FSNode *node);
void print_structure(const FSNode *node, int indent);
void free_filesystem(FSNode *node);

#endif // FILESYSTEM_H
