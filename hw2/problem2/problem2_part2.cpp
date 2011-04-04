#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

float op_square(float i)
{
	return i*i;  
}

int main()
{
	//part1 codes
	vector<float> source;
	vector<float> resSqu;
	vector<float>::iterator it;
	float init = 0.0;
	float resRoot = 0.0;
	source.push_back(1.1);
	source.push_back(1.2);
	source.push_back(1.3);
	source.push_back(1.4);
	source.push_back(1.5);
	cout << "original vector: ";
	for(it = source.begin(); it != source.end(); ++it)
		cout << *it << " ";
	cout << endl;
	
	resSqu.resize(source.size());
	transform(source.begin(), source.end(), resSqu.begin(), op_square);
	cout << "square result vector: ";
	for(it = resSqu.begin(); it != resSqu.end(); ++it)
		cout << *it << " ";
	cout << endl;

	//part2 codes
	cout << "accumulate result: " << accumulate(resSqu.begin(), resSqu.end(), init);
	cout << endl;
	
	cout << "result root: " << sqrt(accumulate(resSqu.begin(), resSqu.end(), init));
	cout << endl;
	
	return 0;
}