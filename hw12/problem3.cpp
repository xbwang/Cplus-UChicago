/*********************
* hw12-3
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

mutex some_mutex;

void isThread(int n)
{
    for(int i = 0; i < 5; ++i){
        lock_guard<mutex> guard(some_mutex);
        cout << "I'm thread no." << n << "!" << endl;
    }
}

int main()
{
    vector<std::thread> tV;

    for(int i = 1; i <= 9 ; ++i){
        tV.push_back(move(thread(isThread, i)));
        //i tried put the thread directly into the vector like tV.push_back(thread(isThread,i))
        //and it also works.
    }

    for_each(tV.begin(), tV.end(), [&](thread& x){x.join();});
    
    return 0;
}