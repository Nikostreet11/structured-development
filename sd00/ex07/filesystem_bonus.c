#include <stdio.h>
#include <stdlib.h>
#include "filesystem.h"

// Recursively compute folder size
int compute_size(FSNode *node) {
    if (!node) return 0;

    if (node->type == FILE_NODE) {
        return node->size;
    }

    int total = 0;
    FSNode *child = node->children;
    while (child) {
        total += compute_size(child);
        child = child->sibling;
    }
    return total;
}

// Print the node hierarchy
void print_structure(const FSNode *node, int indent)
{
	if (!node)
		return;

	for (int i = 0; i < indent; i++)
		printf("  ");

	if (node->type == FOLDER_NODE)
	{
		printf("[FOLDER] %s\n", node->name);
		FSNode *child = get_children(node);
		while (child)
		{
			print_structure(child, indent + 1);
			child = get_sibling(child);
		}
	}
	else
	{
		printf("[FILE]   %s (%d KB)\n", node->name, node->size);
	}
}

// Free the filesystem
void free_filesystem(FSNode *node)
{
    if (!node) return;

    // Recursively free children
    FSNode *child = get_children(node);
    while (child) {
        FSNode *next = get_sibling(child);
        free_filesystem(child);
        child = next;
    }

    // Free current node
    free(node->name);
    free(node);
}