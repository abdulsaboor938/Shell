/*
Abdul Saboor
20L-1113
BDS-5A
*/

// This is the main file for executing shell commands by creating child process ids

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

// vector<string> tokenize(string arg)
// {
//     vector<string> tokens;
//     stringstream check1(line);
//     while (getline(check1, intermediate, ' '))
//     {
//         tokens.push_back(intermediate);
//     }
//     return tokens;
// }

int main()
{
    system("clear"); // to clear exisitng terminal and load custom terminal

    while (true)
    {
        string instr, temp;                             // this is a string to take input from user
        cout << "20L-1113@Assignment1 Shell (base) $ "; // prompt for terminal input
        getline(cin, instr);                            // getting input from command line

        if (instr == "exit") // going to exit if "exit" command given
        {
            goto END;
        }

        // Tokenizing input string based on spaces

        /*
        Further Steps:
        * First major task is to properly tokenize and learn to pass params in a separate program,
            try creating a function that returns an array or vector of tokens
        - create a child process and wait for child to complete
        - call the exec function eith all parameters
        */
        pid_t retVal;
        retVal = fork();
        if (retVal < 0)
        {
            // fork failed
            cout << "Fork Failed" << endl;
        }
        else if (retVal == 0)
        {
            // child process

            cout << "child process" << endl;

            // instr.append("\n");
            // char arr[instr.length()];
            // strcpy(arr, instr.c_str());
            // char *temp = &arr[0];
            // execl("/bin", temp);

            vector<string> tokens;
            stringstream X(instr);
            while (getline(X, temp, ' '))
            {
                tokens.push_back(temp);
            }

            // creating a pointer array and storing
            char *args[tokens.size() + 1];
            for (int i = 0; i < tokens.size(); i++)
            {
                args[i] = new char[tokens[i].length()];
                strcpy(args[i], tokens[i].c_str());
            }
            args[tokens.size()] = NULL;
            // int status = execl("/bin", args[0]);
            // cout << status << endl;
        }
        else
        {
            wait(NULL);
            // parent process
        }
    }
END:;
}

// Perform argumneted operation through text files
// use a binary file to execute given commands directly