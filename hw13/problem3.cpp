/*********************
* hw13-3 test
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "is_base_of.h"
#include <iostream>
using namespace mybase;
using namespace std;

class B
{
    int b;
    int g() { return 1; }
};

class D : public B
{
    int d;
    int g() { return 2; }
};

int main()
{
    cout << "B is " << (m_is_base_of<B,D>::value ? "" : "not ") << "base of D" << endl;
    cout << "D is " << (m_is_base_of<D,B>::value ? "" : "not ") << "base of B" << endl;
    cout << "void is " << (m_is_base_of<void,D>::value ? "" : "not ") << "base of D" << endl;
    cout << "B is " << (m_is_base_of<B,void>::value ? "" : "not ") << "base of void" << endl;

    return 0;
}