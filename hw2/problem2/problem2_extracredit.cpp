#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

float op_accumulate_square(float i, float j)
{
	return i + j*j;  
}

int main()
{
	//part1 codes
	vector<float> source;
	vector<float>::iterator it;
	float init = 0.0;
	source.push_back(1.1);
	source.push_back(1.2);
	source.push_back(1.3);
	source.push_back(1.4);
	source.push_back(1.5);
	cout << "original vector: ";
	for(it = source.begin(); it != source.end(); ++it)
		cout << *it << " ";
	cout << endl;
	
	//extra-credit codes
	cout << "accumulate-square result: " << accumulate(source.begin(), source.end(), init, op_accumulate_square);
	cout << endl;
	
	cout << "root result: " << sqrt(accumulate(source.begin(), source.end(), init, op_accumulate_square));
	cout << endl;
	
	return 0;
}