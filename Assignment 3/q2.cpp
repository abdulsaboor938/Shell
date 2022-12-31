// this program uses multithreading to print all prime numbers less than or equal to a number given by the user

#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;

// global variables
int num;
int prime;

// function prototypes
void *prime_func(void *arg);

// main function gets input from command line and creates threads
int main(int argc, char *argv[])
{
    // get input from command line
    num = atoi(argv[1]);

    // create threads
    pthread_t prime_thread;

    // create attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // create threads
    pthread_create(&prime_thread, &attr, prime_func, NULL);

    cout << "The prime numbers less than or equal to " << num << " are: ";
    // wait for threads to finish
    pthread_join(prime_thread, NULL);
}

// prime function prints all prime numbers less than or equal to a number given by the user
void *prime_func(void *arg)
{
    // print all prime numbers less than or equal to a number given by the user
    for (int i = 2; i <= num; i++)
    {
        bool isPrime = true;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            prime = i;
            cout << prime << " ";
        }
    }

    // if no prime number is found
    if (prime == 0)
    {
        cout << "Null";
    }
    cout << endl;
}