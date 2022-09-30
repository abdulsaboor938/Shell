// c program to implement a working terminal

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    system("clear");
    while (1)
    {
        char instr[500];
        printf("(base) 20L-1113@Assignment1 ~ ");
        fgets(instr, sizeof(instr), stdin);

        if (strcmp(instr, "exit") == 10)
            goto END;

        // tokenizing string and creating an array
        char *tokens[] = {};
        int i = 0;
        *(tokens + i) = strtok(instr, " ");
        printf("%s\t%i\n", *(tokens + i), i);

        while (1)
        {
            char *temp;
            i++;
            temp = strtok(NULL, " ");
            *(tokens + i) = temp;
            printf("%s\t%i\n", temp, i);
            if (temp == NULL)
                break;
        }

        // for (int j = 0; j <= i; j++)
        // {
        //     printf("%s\n", *(tokens + j));
        // }

        // int pid = fork(); // creating child process to execute
        // if (pid == 0)
        // {
        //     // in child process
        //     execvp(tokens[0], tokens);
        // }
        // if (pid > 1)
        // {
        //     // parent process
        //     wait(NULL);
        // }
    }
END:;
    return 0;
}