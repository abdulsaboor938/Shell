// implementing pipe

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <vector>

using namespace std;

// function to remove starting and ending spaces from a string
string trim(string str)
{
    int start = 0;
    int end = str.length() - 1;
    while (str[start] == ' ')
    {
        start++;
    }
    while (str[end] == ' ')
    {
        end--;
    }
    return str.substr(start, end - start + 1);
}

// function to split string into commads based on |
vector<string> split(string command)
{
    vector<string> commands;
    string cmd;
    for (char c : command)
    {
        if (c == '|')
        {
            commands.push_back(trim(cmd));
            cmd = "";
        }
        else
        {
            cmd += c;
        }
    }
    commands.push_back(trim(cmd));
    return commands;
}

// function to split command into arguments into a dynamic char array
char **split_args(string command)
{
    char **args = new char *[command.length()];
    int i = 0;
    string arg;
    for (char c : command)
    {
        if (c == ' ')
        {
            args[i] = new char[arg.length() + 1];
            strcpy(args[i], arg.c_str());
            i++;
            arg = "";
        }
        else
        {
            arg += c;
        }
    }
    args[i] = new char[arg.length() + 1];
    strcpy(args[i], arg.c_str());
    i++;
    args[i] = NULL;
    return args;
}

// recursive function to execute commands in a pipe
void execute_pipe(vector<string> commands, int index, int in, int out)
{
    // if all commands are executed
    if (index == commands.size())
    {
        return;
    }

    // creating pipe
    int fd[2];
    pipe(fd);

    // creating child process
    int pid = fork();
    if (pid == 0)
    {
        // child process
        // if not first command
        if (in != 0)
        {
            // redirecting input
            dup2(in, 0);
            close(in);
        }
        // if not last command
        if (out != 1)
        {
            // redirecting output
            dup2(out, 1);
            close(out);
        }
        // if not last command
        if (index != commands.size() - 1)
        {
            // redirecting output to pipe
            dup2(fd[1], 1);
            close(fd[1]);
        }
        // splitting command into arguments into a dynamic char array
        char **args = split_args(commands[index]);
        // executing command
        execvp(args[0], args);
    }
    else
    {
        // parent process
        // waiting for child process to finish
        wait(NULL);
        // if not last command
        if (index != commands.size() - 1)
        {
            // closing write end of pipe
            close(fd[1]);
            // executing next command
            execute_pipe(commands, index + 1, fd[0], out);
        }
    }
}

// function to execute a command
void execute_command(string command)
{
    // splitting command into commands based on |
    vector<string> commands = split(command);

    // implementing cd command
    if (commands[0].substr(0, 2) == "cd")
    {
        chdir(commands[0].substr(3).c_str());

        // executing remaining commands
        execute_pipe(commands, 1, 0, 1);
    }
    else
    {
        // executing commands in a pipe
        execute_pipe(commands, 0, 0, 1);
    }
}

int main()
{
    // just maintains history, implements some checks and passes the command to execute_command

    system("clear");
    string command;
    while (true)
    {
        // vector to store history of last 10 commands
        static vector<string> history;

        int flag = 0;

        // printing current directory
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        cout << cwd << " $ ";
        getline(cin, command);

        // implementing exit command
        if (strcmp(command.c_str(), "exit") == 0)
        {
            goto END;
        }

        // implementing !!
        if (strcmp(command.c_str(), "!!") == 0)
        {
            flag = 1;
            // print the last command if history is not empty
            if (history.size() > 0)
            {
                command = history[history.size() - 1];
            }
            else
            {
                cout << "No commands in history" << endl;
                continue;
            }
        }

        // implementing !n
        if (command[0] == '!')
        {
            flag = 1;
            int n = stoi(command.substr(1));
            if (n > 0 && n <= history.size())
            {
                command = history[n - 1];
            }
            else
            {
                cout << "No such command in history" << endl;
                continue;
            }
        }

        if (flag == 0)
        {
            // implementing history
            if (history.size() == 10)
            {
                history.erase(history.begin());
            }
            history.push_back(command);
        }

        // executing command
        execute_command(command);
    }
END:;
    return 0;
}