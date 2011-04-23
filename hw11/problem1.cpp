/*********************
* hw11-1
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <vector>
#include <cmath>
#include <boost/function.hpp>
using namespace std;
using namespace boost;

double
StandardDeviation(vector<double> v)
{
    double mean = 0;
    double sumSquares = 0;

    for_each(v.begin(), v.end(), [&mean](int x){
        mean += x;
        });
    mean /= v.size();

    for_each(v.begin(), v.end(), [=,&sumSquares](int x){
        sumSquares += pow(x-mean,2);
        });
    return sqrt(sumSquares/v.size());
}

int main()
{
    vector<double> v;
    v.push_back(7);
    v.push_back(24);
    cout << StandardDeviation(v) << endl;
    return 0;
}
