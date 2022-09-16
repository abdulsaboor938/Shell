#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    // Approach 1
    // string str, temp;
    // getline(cin, str);
    // vector<string> tokens;
    // stringstream X(str);
    // while (getline(X, temp, ' '))
    // {
    //     tokens.push_back(temp);
    // }
    // for (int i = 0; i < tokens.size(); i++)
    // {
    //     cout << tokens[i].c_str() << endl;
    // }

    // Approach 2

    // string instr;
    // cout << "Enter string: ";
    // getline(cin, instr);
    // instr.append("\n");
    // char arr[instr.length()];
    // strcpy(arr, instr.c_str());
    // cout << arr << endl;
}