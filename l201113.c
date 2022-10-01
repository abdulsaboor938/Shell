/*
Abdul Saboor
20L-1113
BDS-5A
Assignment 1
*/

// c program to implement a working terminal

// includeing libraries to use
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// main function
int main()
{
    system("clear"); // to clear the screen before working

    // loop to take input till exit
    while (1)
    {
        char instr[500];                                 // character array to take input
        printf("(base) 20L-1113@Assignment-1 Shell $ "); // shell prompt
        fgets(instr, sizeof(instr), stdin);              // capturing input string

        if (strcmp(instr, "exit") == 10) // if input is exit command
        {
            break; // exit from loop
        }

        // tokenizing string and creating an array
        char *tokens[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
                          "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""}; // array for storing tokens

        int i = 0; // counter for array
        *(tokens + i) = strtok(instr, " ");

        while (1)
        {
            *(tokens + ++i) = strtok(NULL, " ");
            if (*(tokens + i) == NULL) // if end of command occurs
            {
                i--;
                *(tokens + i) = strtok(*(tokens + i), "\n"); // removing \n from last argument before NULL
                break;                                       // exiting from while loop
            }
        }

        int pid = fork(); // creating child process to execute
        if (pid == 0)
        {
            // in child process
            if (execvp(tokens[0], tokens) == -1) // executing command from tokenized array
                printf("zsh: command not found: %s \n", tokens[0]);
            exit(0); // exiting properly
        }
        if (pid > 1)
        {
            // parent process
            wait(NULL); // waiting for child to complete execution
        }
    }
    return 0;
}