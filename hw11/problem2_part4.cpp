/*********************
* hw11-2.4
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <boost/bind.hpp>
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
    cout << sqrt(accumulate(v.begin(), v.end(), 0.0, bind(std::plus<double>(), _1, bind(std::multiplies<double>(), _2, _2)))) << endl;
    return 0;
}
