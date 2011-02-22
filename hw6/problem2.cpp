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

mutex some_mutex;
class A
{
public:
    A() : a(0) {} 
    void bump(int i){
        std::lock_guard<std::mutex> guard(m);
		cout << "Updates a to be " << (a+=i) << "." << endl;
    }
    int a;
    mutex m;
};

A a;
void test(int n)
{
	for(int i = 0; i < 20; i++){
		a.bump(1);
	}
}

int main()
{
	std::thread threadOne(test, 1);
	std::thread threadTwo(test, 2);
	std::thread threadThree(test, 3);
	
	threadOne.join();
	threadTwo.join();
	threadThree.join();
	return 0;
}