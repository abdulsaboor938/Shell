#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex m;
condition_variable cv;
int bowler = 0;
int batsman = 0;

void bowler_thread(int id)
{
    unique_lock<mutex> lk(m);
    while (true)
    {
        bowler++;
        cout << "Bowler " << id << " arrived" << endl;
        cv.notify_all();
        while (batsman == 0)
        {
            cv.wait(lk);
        }
        cout << "Bowler " << id << " is bowling" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Bowler " << id << " finished bowling" << endl;
        bowler--;
        batsman--;
        cv.notify_all();
    }
}

void batsman_thread(int id)
{
    unique_lock<mutex> lk(m);
    while (true)
    {
        batsman++;
        cout << "Batsman " << id << " arrived" << endl;
        cv.notify_all();
        while (bowler == 0)
        {
            cv.wait(lk);
        }
        cout << "Batsman " << id << " is batting" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Batsman " << id << " finished batting" << endl;
        batsman--;
        bowler--;
        cv.notify_all();
    }
}

int main()
{
    thread bowler1(bowler_thread, 1);
    thread bowler2(bowler_thread, 2);
    thread batsman1(batsman_thread, 1);
    thread batsman2(batsman_thread, 2);
    bowler1.join();
    bowler2.join();
    batsman1.join();
    batsman2.join();
    return 0;
}