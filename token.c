#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
    char *temp[] = {"echo", "hello"};
    char *temp1 = {"world"};
    *(temp + 2) = temp1;
    *(temp + 3) = NULL;
    execvp(temp[0], temp);
    return 0;
}