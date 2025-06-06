#include <stdio.h>
#include "filesystem.h"

int main(void) {
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

    // Compute sizes
    printf("Total size of 'root' folder: %d KB\n", compute_size(root)); // Expected: 1492
    printf("Total size of 'docs' folder: %d KB\n", compute_size(docs)); // Expected: 150
    printf("Total size of 'images' folder: %d KB\n", compute_size(images)); // Expected: 1300

    // Free the system
    free_filesystem(root);

    return 0;
}
