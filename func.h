#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to create a new file
//  Returns 0 if the file is created successfully
//  Returns -1 if file creation fails
//  Returns 2 if the file already exists
int createFile() {
    printf("\nEnter name for the file: ");
    char filename[100];
    fgets(filename, sizeof(filename), stdin);

    // Remove the newline character from the filename
    filename[strcspn(filename, "\n")] = 0;

    // Check if the file already exists
    if (access(filename, F_OK) != -1) {
        return 2;  // Return 2 if the file already exists
    }

    // Try to create the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return -1;  // Return -1 if file creation fails

    } else {
        fclose(file);
        return 0;  // Return 0 if the file is created successfully
    }
}
