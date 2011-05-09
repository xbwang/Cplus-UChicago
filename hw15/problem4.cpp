/*********************
* hw15-4
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "Tuple4.h"
//#include "Typelist.h"
#include <iostream>
using namespace cspp51055;
using namespace std;

int main()
{
	Tuple4<TYPELIST_3(float, int, double)> t;
	
	t.at<0>() = 1.1;
	t.at<1>() = 2;
	t.at<2>() = 3.0;
	
	//cout << t.at<float>() << endl;
	//typedef TYPELIST_3(int, int, float) t;
	//cout << IndexOf<t, int>::value << endl; 
	
	return 0;
}