// this program uses multithreading to print fibonacci numbers less than or equal to a number given by the user

#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;

// global variables
int num;
int fib;

// function prototypes
void *fib_func(void *arg);

// main function gets input from command line and creates threads
int main(int argc, char *argv[])
{
    // get input from command line
    num = atoi(argv[1]);

    // create threads
    pthread_t fib_thread;

    // create attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // create threads
    pthread_create(&fib_thread, &attr, fib_func, NULL);

    cout << "The fibonacci numbers less than or equal to " << num << " are: ";
    // wait for threads to finish
    pthread_join(fib_thread, NULL);
}

// fib function prints all fibonacci numbers less than or equal to a number given by the user
void *fib_func(void *arg)
{
    // print all fibonacci numbers less than or equal to a number given by the user
    int first = 0;
    int second = 1;
    int next = 0;
    while (next <= num)
    {
        if (next <= num)
        {
            fib = next;
            cout << fib << " ";
        }
        first = second;
        second = next;
        next = first + second;
    }

    // if no fibonacci number is found
    if (fib == 0)
        cout << "No fibonacci number found" << endl;
    cout << endl;
}