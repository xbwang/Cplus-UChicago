/*********************
* hw11-2.1
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <boost/function.hpp>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
using namespace boost;

double square(double i)
{
    return pow(i, 2);
}

int main()
{
    vector<double> v;
    v.push_back(7);
    v.push_back(24);
    vector<double> w;
    transform(v.begin(), v.end(), back_inserter(w), square);
    cout << sqrt(accumulate(w.begin(), w.end(), 0.0)) << endl;
    return 0;
}