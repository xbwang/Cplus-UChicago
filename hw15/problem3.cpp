/*********************
* hw15-3
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "Tuple3.h"
#include <string>
#include <iostream>
using namespace cspp51055;
using namespace std;

int main()
{
    Tuple3<TYPELIST_3(int, float, string)> t;
    t.at<0>() = 1;
    t.at<1>() = 1.1;
    t.at<2>() = "test";
    
    cout << "- now integer index works:" << endl;
    cout << "- int: " << t.at<0>() << endl;
    cout << "- float: " << t.at<1>() << endl;
    cout << "- string: " << t.at<2>() << endl;
    
    return 0;
}