/*******************
hw6 Final Submission
Xiangbo Wang
2/21/2011
********************/
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
/***If the case is that we are expected to count all workUnits done by all threads using one global count.***/
//The problem is that if we don't synchronize access to the global count,
//there might be situations such that more than one threads want to update the count concurrently
//and the updated result would not be accurent.
//For example, two threads(thread1 and thread2) want to increase the count by one at the some point.
//Both of them obtain the current count as 200 and update it to 201.
//However, the actual result should be 202 after these two updates.

//There is another issue raised if we synchronize the access.
//Every time any thread need to update the count, other thread which attempts to update it
//will have to wait until the count is released, which might lower the performance.

/***If the case is that we are expected to count the total workUnits done by each thread using one global count.***/
//One global count still can't obatin what we want.
//Since each thread wants to increase the global count and no one can get an accurate result.

//thread_local variable can help since it make an instance of the global variable for each thread.
//So the varible in the thread is seen as a local one then it will get the right result.
std::mutex some_mutex;
unsigned __thread workUnits = 0;

void doWork(int m, int n)
{
    for(int i = 0; i < n; i++){
        workUnits += 1;
        std::lock_guard<std::mutex> guard(some_mutex);
        cout << workUnits << " units are done by Thread no." << m << "."<< endl;
    }
}

int main()
{
    std::thread thread1(doWork, 1, 20);
    std::thread thread2(doWork, 2, 10);
    std::thread thread3(doWork, 3, 30);

    thread1.join();
    thread2.join();
    thread3.join();
    
    return 0;
}

/*
use a global array to store the thread_local results!
*/



