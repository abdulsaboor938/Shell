#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string str, temp;
    getline(cin, str);
    vector<string> tokens;
    stringstream X(str);
    while (getline(X, temp, ' '))
    {
        tokens.push_back(temp);
    }
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i].c_str() << endl;
    }
}