#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

float op_square(float i)
{
	return i*i;
}

int main()
{
	vector<float> source;
	vector<float> result;
	vector<float>::iterator it;
	
	source.push_back(1.1);
	source.push_back(1.2);
	source.push_back(1.3);
	source.push_back(1.4);
	source.push_back(1.5);
	
	cout << "original vector: ";
	for(it = source.begin(); it != source.end(); ++it)
		cout << *it << " ";
	cout << endl;
	
	result.resize(source.size());
	transform(source.begin(), source.end(), result.begin(), op_square);
	
	cout << "result vector: ";
	for(it = result.begin(); it != result.end(); ++it)
		cout << *it << " ";
	cout << endl;
	
	return 0;
}