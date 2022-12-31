// this program gets input from user and use multithreading to calculate the following:
// 1. the average of the numbers
// 2. the maximum of the numbers
// 3. the minimum of the numbers

#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

// global variables
int num;
vector<int> numbers;
int average;
int maximum;
int minimum;

// function prototypes
void *average_func(void *arg);
void *maximum_func(void *arg);
void *minimum_func(void *arg);

// main function gets input from command line and creates threads
int main(int argc, char *argv[])
{
    // create a vector corresponding to number of arguments
    // convert the arguments to integers and store them in the vector
    for (int i = 1; i < argc; i++)
    {
        num = atoi(argv[i]);
        numbers.push_back(num);
    }

    // create threads
    pthread_t average_thread;
    pthread_t maximum_thread;
    pthread_t minimum_thread;

    // create attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // create threads
    pthread_create(&average_thread, &attr, average_func, NULL);
    pthread_create(&maximum_thread, &attr, maximum_func, NULL);
    pthread_create(&minimum_thread, &attr, minimum_func, NULL);

    // wait for threads to finish
    pthread_join(average_thread, NULL);
    pthread_join(maximum_thread, NULL);
    pthread_join(minimum_thread, NULL);

    // print results
    cout << "The average is: " << average << endl;
    cout << "The maximum is: " << maximum << endl;
    cout << "The minimum is: " << minimum << endl;

    return 0;
}

void *average_func(void *arg)
{
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += numbers[i];
    }
    average = sum / num;
    pthread_exit(0);
}

void *maximum_func(void *arg)
{
    maximum = numbers[0];
    for (int i = 1; i < num; i++)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }
    pthread_exit(0);
}

void *minimum_func(void *arg)
{
    minimum = numbers[0];
    for (int i = 1; i < num; i++)
    {
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
    }
    pthread_exit(0);
}