#include <stdio.h>   // For printf, fgets, feof, ferror
#include <string.h>  // For strlen, strcmp
#include <ctype.h>   // For toupper
#include <stdlib.h>  // For system, exit

#define MAX_COMMAND_LENGTH 1024 

void to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH]; 

    while (1) {
        printf(">> ");
        // Flush stdout to ensure the prompt is displayed immediately
        fflush(stdout);

        // fgets reads up to MAX_COMMAND_LENGTH-1 characters or until a newline is found.
        // It includes the newline character if found.
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            if (feof(stdin)) {
                printf("\nExiting uppershell. Goodbye!\n");
                break; // Exit loop on EOF
            } else if (ferror(stdin)) {
                perror("Error reading input");
                break; 
            }
        }

        // Remove the trailing newline character if it exists
        // fgets includes the newline, but system() doesn't want it.
        command[strcspn(command, "\n")] = 0;

        to_uppercase(command);

        int status = system(command);
    }

    return 0; 
}
