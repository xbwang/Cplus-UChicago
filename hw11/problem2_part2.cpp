/*********************
* hw11-2.2
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
using namespace boost;

int main()
{
    vector<double> v;
    v.push_back(7);
    v.push_back(24);
    vector<double> w;
    transform(v.begin(), v.end(), back_inserter(w), bind(std::multiplies<double>, _1, _1));
    cout << sqrt(accumulate(w.begin(), w.end(), 0.0)) << endl;
    return 0;
}