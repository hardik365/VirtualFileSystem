#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "func.h"

// Function to display the command menu
void displayMenu() {
    printf("\nSelect a command:\n\n");
    printf("[mkfl] Create a new file\n");
    printf("[rmfl] Delete a file\n");
    printf("[rnfl] Rename a file\n");
    printf("[mkdr] Create a new directory\n");
    printf("[rmdr] Delete a directory\n");
    printf("[rndr] Rename a directory\n");
    printf("[ls] List files and directories\n");
    printf("[cd] Change directory\n");
    printf("[pwd] Print current directory\n");
    printf("[help] Display help\n");
    printf("[x] Exit the program\n\n");
}

int main() {
    char command[50]; // Buffer to store user input
    int flag;         // Flag to store the return value of the functions

    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*    Welcome to the Virtual File System!     *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
    printf("\n");

    // Display the menu once at the beginning
    displayMenu();

    while (1) { // Infinite loop to keep the program running until the user exits
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
            displayMenu();
        } else if (strcmp(command, "meta") == 0) {
            flag = fileMetadata();
            if (flag == -1) {
                printf("Problem retrieving metadata\n");
            } else {
                printf("File meta successful\n");
            }
            displayMenu();
        } else if (strcmp(command, "rmfl") == 0) {
            flag = deleteFile();
            if (flag == -1) {
                printf("Error deleting file!\n");
            } else {
                printf("File deleted successfully!\n");
            }
            displayMenu();
        } else if (strcmp(command, "rnfl") == 0) {
            flag = renameFile();
            if (flag == -1) {
                printf("Error renaming file!\n");
            } else {
                printf("File renamed successfully!\n");
            }
            displayMenu();
        } else if (strcmp(command, "ls") == 0) {
            flag = listFilesAndDirectories();
            displayMenu();
        } else if (strcmp(command, "mkdr") == 0) {
            flag = createDirectory();
            displayMenu();
        } else if (strcmp(command, "rmdr") == 0) {
            flag = deleteDirectory();
            displayMenu();
        } else if (strcmp(command, "rndr") == 0) {
            flag = renameDirectory();
            displayMenu();
        } else if (strcmp(command, "cd") == 0) {
            flag = changeDirectory();
            displayMenu();
        } else if (strcmp(command, "pwd") == 0) {
            flag = printCurrentDirectory();
            displayMenu();
        } else if (strcmp(command, "help") == 0) {
            displayHelp(); // Re-display menu for help
        } else if (strcmp(command, "x") == 0) {
            printf("\nExiting the program...\n");
            break; // Exit the loop
        }
    }

    return 0;
}
