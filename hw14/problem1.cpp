/*********************
* hw14-1
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
using namespace std;

template<int i>
class Fib
{
public:
    static const unsigned int value = Fib<i-1>::value + Fib<i-2>::value;
};

template<>
class Fib<0>
{
public:
    static const unsigned int value = 0;
};
template<>
class Fib<1>
{
public:
    static const unsigned int value = 1;
};

int main()
{
    cout << Fib<6>::value << endl;
    
    return 0;
}