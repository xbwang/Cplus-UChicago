/*********************
* hw13-2 test
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include "is_const.h"
using namespace myconst;
using namespace std;

int main()
{
    if(m_is_const<const char[]>::value)
        cout << "- <const char[]> is a const" << endl;
    else
        cout << "- <const char[]> is not a const" << endl;
    
    if(m_is_const<int*>::value)
        cout << "- <int*> is a const" << endl;
    else
        cout << "- <int*> is not a const" << endl;
    
    if(m_is_const<int* const >::value)
        cout << "- <const int*> is a const" << endl;
    else
        cout << "- <const int*> is not a const" << endl;
    
    return 0;
}