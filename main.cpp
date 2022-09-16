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
        string instr;                                   // this is a string to take input from user
        cout << "(base) 20L-1113@Assignment1 Shell % "; // prompt for terminal input
        getline(cin, instr);                            // getting input from command line

        if (instr == "exit") // going to exit if "exit" command given
        {
            goto END;
        }

        // Tokenizing input string based on spaces
        cout << "You entered: " << instr << endl;

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
            // using a vector to store the params and then converting to char
            execl("/bin", instr);
        }
        else
        {
            wait(NULL);
            // parent process
        }
    }
END:;
}