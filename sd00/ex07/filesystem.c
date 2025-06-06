#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

// Create a new file
FSNode *create_file(const char *name, int size)
{
	FSNode *node = malloc(sizeof(FSNode));
	node->type = FILE_NODE;
	node->name = strdup(name);
	node->size = size;
	node->children = NULL;
	node->sibling = NULL;
	return node;
}

// Create a new folder
FSNode *create_folder(const char *name)
{
	FSNode *node = malloc(sizeof(FSNode));
	node->type = FOLDER_NODE;
	node->name = strdup(name);
	node->size = 0;
	node->children = NULL;
	node->sibling = NULL;
	return node;
}

// Add child to folder (maintaining insertion order)
void add_child(FSNode *parent, FSNode *child)
{
	if (!parent || parent->type != FOLDER_NODE)
		return;
	if (!parent->children)
	{
		parent->children = child;
	}
	else
	{
		FSNode *curr = parent->children;
		while (curr->sibling)
			curr = curr->sibling;
		curr->sibling = child;
	}
}

FSNode *get_children(const FSNode *parent)
{
	if (!parent || parent->type != FOLDER_NODE)
		return NULL;
	return parent->children;
}

FSNode *get_sibling(const FSNode *node)
{
	if (!node)
		return NULL;
	return node->sibling;
}
