#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>

int main()
{
    char t_path[PATH_MAX];
    getcwd(t_path, sizeof(t_path));
    printf("%s\n", t_path);

    chdir("..");
    getcwd(t_path, sizeof(t_path));
    printf("%s\n", t_path);

    chdir(getenv("HOME"));
    getcwd(t_path, sizeof(t_path));
    printf("%s\n", t_path);
    return 0;
}