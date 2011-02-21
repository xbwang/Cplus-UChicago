/*******************
hw6 Final Submission
Xiangbo Wang
2/21/2011
********************/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//The problem is that there might be such situation that more than one threads intend to call the bump(int i = 1),
//and do the a+=i concurrently.
//This will make them get wrong result.
//For example, two threads try to call bump at the same time and updated a==3 by a+=1.
//However, the proper way is that one of the threads should wait for the other finishing updating
//then both of them will get the right results.
class A
{
public:
    A() : a(0) {} 
    void bump(int i = 1){
        std::lock_guard<std::mutex> guard(m);
        a += i;
    }
    int a;
    mutex m;
};