/*******************
hw6 Final Submission
Xiangbo Wang
2/21/2011
********************/
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

std::mutex some_mutex;
unsigned workUnits = 0;
//extracredit is just done by synronize the access that only one thread can access the workUnits at any time.
void doWork(int m, int n)
{
    for(int i = 0; i < n; i++){
        std::lock_guard<std::mutex> guard(some_mutex);
        cout << "Thread no." << m << " has done the no." << ++workUnits << " unit." << endl;
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



