//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "func.h"



//main function
int main() {
    char command[50];  // Buffer to store user input
    int flag;          // Flag to store the return value of the functions

    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*    Welcome to the Virtual File System!     *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
    printf("\n");


    while(1){ // Infinite loop to keep the program running until the user exits
        printf("Select a command:\n\n");
        printf("[mkfl] Create a new file\n");               //Implemented
        printf("[rmfl] delete a file\n");                   //Not yet implemented
        printf("[mkdr] Create a new directory\n");          //Not yet implemented
        printf("[rmdr] Delete a directory\n");              //Not yet implemented
        printf("[ls] List files and directories\n");        //Not yet implemented
        printf("[cd] Change directory\n");                  //Not yet implemented
        printf("[pwd] Print current directory\n");          //Not yet implemented
        printf("[help] Display help\n");                    //Not yet implemented
        printf("[exit] Exit the program\n\n");              //Implemented
        printf("Enter a command: ");

        // Read user input and store it in the command buffer
        fgets(command, sizeof(command), stdin);

        // Convert to lowercase 
        for (int i = 0; i < (int)sizeof(command); i++) {  // Cast sizeof result to int
            command[i] = (char)tolower((unsigned char)command[i]); // Explicitly cast to char
        }

        // Check if the entered command is "mkfl"
        if (strcmp(command, "mkfl\n") == 0) {
            flag = createFile();
            if (flag == -1) {
                printf("Error creating file!\n");
            }
            if (flag == 2) {
                printf("Error: File already exists!\n");
            }
            if (flag == 0) {
                printf("File created successfully!\n");
            }
        }

        // Check if the entered command is "exit"
        if (strcmp(command, "exit\n") == 0) {
            printf("\nExiting the program...\n");
            return 0;
        }
    }

    return 0;
}