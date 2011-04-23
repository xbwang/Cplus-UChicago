/*********************
* hw11-2.5
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <iostream>
using namespace std;
using namespace boost::lambda;

int main()
{
    vector<double> v;
    v.push_back(7);
    v.push_back(24);
    cout << sqrt(accumulate(v.begin(), v.end(), 0.0, boost::lambda::_1+boost::lambda::_2*boost::lambda::_2)) << endl;
    return 0;
}

//c++0x's lambda is better since you can't use boost::lambda with the preset functions in c++
