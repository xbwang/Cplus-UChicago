/************************************
* Final Version
* Xiangbo Wang / xbwang@uchicago.edu
* Problem3
************************************/
#include <iostream>
#include <math.h>
using namespace std;

class Nth_Power
{
private:
    int power;
public:
    Nth_Power(int n){ power = n; }
    int operator ()(int base) const;    
};

int Nth_Power::operator ()(int base) const
{
    return pow(base, power);
}

int main()
{
    Nth_Power cube(3);
	//the 4.3 asks us to print the first 10 cubes
	//however the original code just has a loop of 9
    for(int i = 1; i < 11; i++){
        cout << cube(i) << endl;
    }
    
    return 0;
}