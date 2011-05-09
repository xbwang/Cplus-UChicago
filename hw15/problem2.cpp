/*********************
* hw15-2
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    tuple<int, float, long> myTuple(1, 1.1, 100);
    cout << "- [1st test]int number: " << get<0>(myTuple) << endl;
    cout << "- [1st test]float number: " << get<1>(myTuple) << endl;
    cout << "- [1st test]long number: " << get<2>(myTuple) << endl;
    
    get<0>(myTuple) = 2;
    get<1>(myTuple) = 2.2;
    get<2>(myTuple) = 200;
    cout << "- [2nd test]int number: " << get<0>(myTuple) << endl;
    cout << "- [2nd test]float number: " << get<1>(myTuple) << endl;
    cout << "- [2nd test]long number: " << get<2>(myTuple) << endl;
    
    tuple<string, double> newTuple("test", 1.11111);
    tuple<int, float, long, string, double>
    catTuple = tuple_cat(myTuple, newTuple);
    cout << "- [3rd test]int number: " << get<0>(catTuple) << endl;
    cout << "- [3rd test]float number: " << get<1>(catTuple) << endl;
    cout << "- [3rd test]long number: " << get<2>(catTuple) << endl;
    cout << "- [3rd test]string number: " << get<3>(catTuple) << endl;
    cout << "- [3rd test]double number: " << get<4>(catTuple) << endl;
    
    return 0;
}