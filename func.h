#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#ifndef FUNC_H
#define FUNC_H

int createDirectory();
int deleteDirectory();
int renameDirectory();
int changeDirectory();
int printCurrentDirectory();
void displayHelp();

#endif

// Function to create a new file
//  Returns 0 if the file is created successfully
//  Returns -1 if file creation fails
//  Returns 2 if the file already exists
int createFile()
{
    printf("\nEnter name for the file: ");
    char filename[100];
    fgets(filename, sizeof(filename), stdin);

    // Remove the newline character from the filename
    filename[strcspn(filename, "\n")] = 0;

    // Check if the file already exists
    if (access(filename, F_OK) != -1)
    {
        return 2; // Return 2 if the file already exists
    }

    // Try to create the file
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        return -1; // Return -1 if file creation fails
    }
    else
    {
        fclose(file);
        return 0; // Return 0 if the file is created successfully
    }
}

int deleteFile()
{
    char filename[100];
    printf("\nEnter name of file to delete: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Attempt to delete the file
    if (remove(filename) == 0)
    {
        return 0; // Successful deletion
    }
    else
    {
        return -1; // Deletion failed
    }
}

int renameFile()
{
    char oldname[100], newname[100];

    printf("\nEnter current filename: ");
    fgets(oldname, sizeof(oldname), stdin);
    oldname[strcspn(oldname, "\n")] = 0;

    printf("Enter new filename: ");
    fgets(newname, sizeof(newname), stdin);
    newname[strcspn(newname, "\n")] = 0;

    // Attempt to rename the file
    if (rename(oldname, newname) == 0)
    {
        return 0; // Successful rename
    }
    else
    {
        return -1; // Rename failed
    }
}

int listFilesAndDirectories()
{
    DIR *dir;
    struct dirent *entry;

    // Open the current directory
    dir = opendir(".");
    if (dir == NULL)
    {
        printf("Error opening directory!\n");
        return -1;
    }

    printf("\nFiles and Directories:\n");
    printf("--------------------\n");

    // Read and print directory contents
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            // Determine type of entry
            if (entry->d_type == DT_DIR)
            {
                printf("[DIR]  %s\n", entry->d_name);
            }
            else
            {
                printf("[FILE] %s\n", entry->d_name);
            }
        }
    }

    // Close the directory
    closedir(dir);
    return 0;
}