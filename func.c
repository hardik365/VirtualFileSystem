#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>

#define PATH_MAX 4096

// Create a new directory
int createDirectory() {
    char dirname[50];
    printf("Enter the name of the directory to create: ");
    scanf("%49s", dirname);

    // Use mkdir system call
    if (mkdir(dirname, 0755) == -1) {
        perror("Error creating directory");
        return -1;
    }

    printf("Directory created successfully!\n");
    return 0;
}

// Delete a directory
int deleteDirectory() {
    char dirname[50];
    printf("Enter the name of the directory to delete: ");
    scanf("%49s", dirname);

    // Use rmdir system call (directory must be empty)
    if (rmdir(dirname) == -1) {
        perror("Error deleting directory");
        return -1;
    }

    printf("Directory deleted successfully!\n");
    return 0;
}

// Rename a directory
int renameDirectory() {
    char oldname[50], newname[50];
    printf("Enter the current name of the directory: ");
    scanf("%49s", oldname);
    printf("Enter the new name for the directory: ");
    scanf("%49s", newname);

    // Use rename system call
    if (rename(oldname, newname) == -1) {
        perror("Error renaming directory");
        return -1;
    }

    printf("Directory renamed successfully!\n");
    return 0;
}

// Change current working directory
int changeDirectory() {
    char path[100];
    printf("Enter the path to change to: ");
    scanf("%99s", path);

    // Use chdir system call
    if (chdir(path) == -1) {
        perror("Error changing directory");
        return -1;
    }

    printf("Changed directory to %s successfully!\n", path);
    return 0;
}

// Print the current working directory
int printCurrentDirectory() {
    char cwd[PATH_MAX];

    // Use getcwd system call
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("Error getting current directory");
        return -1;
    }

    printf("Current directory: %s\n", cwd);
    return 0;
}

// Display help for commands
void displayHelp() {
    FILE *file = fopen("help.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}




