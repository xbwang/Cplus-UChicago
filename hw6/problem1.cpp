/*******************
hw6 Final Submission
Xiangbo Wang
2/21/2011
********************/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex some_mutex;

void counting(int n)
{
    for(int i = 1; i < 101; i++){
        //if the lock is not included, the three threads would try to access the std::cout
        //concurrently, which may cause the output not in the proper form
        std::lock_guard<std::mutex> guard(some_mutex);
        cout << "Thread " << n << " has been called " << i << " times" << endl;
    }
}

int main()
{
    std::thread threadOne(counting, 1);
    std::thread threadTwo(counting, 2);
    std::thread threadThree(counting, 3);
    
    threadOne.join();
    threadTwo.join();
    threadThree.join();
    
    return 0;
}

