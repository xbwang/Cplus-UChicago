/*********************
* hw12-4
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
using namespace std;

mutex some_mutex;
void g(int i)
{
    lock_guard<mutex> guard(some_mutex);
    cout << "- i'm " << i << "." << endl;
}

int main()
{
    vector<thread> threads;
    thread t(g, 1);
    threads.push_back(move(t));
    //for testing
    for_each(threads.begin(), threads.end(), [&](thread& x){ x.join(); });
    
    return 0;
}