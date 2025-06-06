#include <stdio.h>
#include "filesystem.h"

// Helper to print the node hierarchy
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

int main(void)
{
	// Create root folder
	FSNode *root = create_folder("root");

	// Add files to root
	add_child(root, create_file("readme.txt", 12));
	add_child(root, create_file("log.txt", 30));

	// Create subfolder and add files
	FSNode *docs = create_folder("docs");
	add_child(docs, create_file("resume.pdf", 60));
	add_child(docs, create_file("paper.docx", 90));
	add_child(root, docs);

	// Create subfolder and add files
	FSNode *images = create_folder("images");
	add_child(images, create_file("photo1.jpg", 500));
	add_child(images, create_file("photo2.jpg", 800));
	add_child(root, images);

	// Visualize the structure
	print_structure(root, 2);

	return 0;
}
