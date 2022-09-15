/*
Abdul Saboor
20L-1113
BDS-5A
*/

// This is the main file for executing shell commands by creating child process ids

#include <iostream>
#include <string.h>
using namespace std;

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
        * First major task is to properly tokenize and learn to pass params in a separate program
        - create a child process and wait for child to complete
        - call the exec function eith all parameters
        */
    }
END:;
}