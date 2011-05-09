/*********************
* hw15-5
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "myTypelist.h"
#include <string>
#include <iostream>
using namespace cspp51055;

int main()
{
    //10 input types
    typedef myTypelist<int, double, float, string, long, char, char*, unsigned char, unsigned int, unsigned long> t10;
    t10::print();
    //1 input type
    typedef myTypelist<int> t1;
    t1::print();
    //3 input types
    typedef myTypelist<double, char*, string> t3;
    t3::print();
    
    return 0;
}