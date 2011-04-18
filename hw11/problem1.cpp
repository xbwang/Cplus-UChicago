/*********************
* hw11-1
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double
StandardDeviation(vector<double> v)
{
    double mean = 0;
    double sumSquares = 0;

    for_each(v.begin(), v.end(), [&mean](int x){
        mean += x;
        });
    mean /= v.length();

    for_each(v.begin(), v.end(), [=,&sumSquares](int x){
        sumSquares += pow(x-mean,2);
        });
    return sqrt(sumSquares/v.size());
}

int main()
{
    return 0;
}