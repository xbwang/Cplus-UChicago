/*********************
* hw11-2.3
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <boost/bind.hpp>
#include <boost/lambda.hpp>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <iostream>
using namespace std;
using namespace boost;

int main()
{
    vector<double> v;
    v.push_back(7);
    v.push_back(24);
    cout << sqrt(accumulate(v.begin(), v.end(), 0.0, _1+pow(_2,2))) << endl;
    return 0;
}

//c++0x's is better since it have explicitly sign that where the lambda is 
//and what the parameters are like a function.