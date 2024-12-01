// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "func.h"

// main function
int main()
{
    char command[50]; // Buffer to store user input
    int flag;         // Flag to store the return value of the functions

    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*    Welcome to the Virtual File System!     *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
    printf("\n");

    while (1) { // Infinite loop to keep the program running until the user exits
        printf("Select a command:\n\n");
        printf("[mkfl] Create a new file\n"); // Implemented
        printf("[rmfl] Delete a file\n");     // Implemented
        printf("[rnfl] Rename a file\n");     // Implemented
        printf("[mkdr] Create a new directory\n"); // Implemented
        printf("[rmdr] Delete a directory\n");     // Implemented
        printf("[rndr] Rename a directory\n");     // Implemented
        printf("[ls] List files and directories\n"); // Implemented
        printf("[cd] Change directory\n");           // Implemented
        printf("[pwd] Print current directory\n");   // Implemented
        printf("[help] Display help\n");    // Implemented
        printf("[x] Exit the program\n\n"); // Implemented

        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);

        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        // Convert to lowercase
        size_t len = strlen(command);
        for (size_t i = 0; i < len; i++) {
            command[i] = (char)tolower((unsigned char)command[i]);
        }

        // Command handlers
        if (strcmp(command, "mkfl") == 0) {
            flag = createFile();
            if (flag == -1) {
                printf("Error creating file!\n");
            } else if (flag == 2) {
                printf("Error: File already exists!\n");
            } else {
                printf("File created successfully!\n");
            }
        } else if (strcmp(command, "rmfl") == 0) {
            flag = deleteFile();
            if (flag == -1) {
                printf("Error deleting file!\n");
            } else {
                printf("File deleted successfully!\n");
            }
        } else if (strcmp(command, "rnfl") == 0) {
            flag = renameFile();
            if (flag == -1) {
                printf("Error renaming file!\n");
            } else {
                printf("File renamed successfully!\n");
            }
        } else if (strcmp(command, "ls") == 0) {
            flag = listFilesAndDirectories();
        } else if (strcmp(command, "mkdr") == 0) {
            flag = createDirectory();
        } else if (strcmp(command, "rmdr") == 0) {
            flag = deleteDirectory();
        } else if (strcmp(command, "rndr") == 0) {
            flag = renameDirectory();
        } else if (strcmp(command, "cd") == 0) {
            flag = changeDirectory();
        } else if (strcmp(command, "pwd") == 0) {
            flag = printCurrentDirectory();
        } else if (strcmp(command, "help") == 0) {
            displayHelp();
        } else if (strcmp(command, "x") == 0) {
            printf("\nExiting the program...\n");
            return 0;
        } else {
            printf("Invalid command! Type 'help' for a list of commands.\n");
        }
    }


    return 0;
}