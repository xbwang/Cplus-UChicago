/************************************
* Final Version
* Xiangbo Wang / xbwang@uchicago.edu
* Problem1, extra credit
************************************/
#include <iostream>
using namespace std;

struct ForceInit
{
    ForceInit(){ ios_base::Init(); cout << "Hello"; }
};

class A
{
public:
    A(){ cout << "World"; }
};

class B
{
public:
    B();
};

class Print
{
public:
    B b;
    Print(){
        cout << "!" <<endl;
    }
    A c;
};

B::B()
{
     cout << " ";
}

static ForceInit a;
Print d;

int main(){
    return 0;
}