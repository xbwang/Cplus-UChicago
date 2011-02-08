#include "optimized_copy.h"
#include <boost/type_traits.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> sourceVector;
	vector<int> resultVector;
	vector<int>::iterator it;
	for(int i = 1; i < 10; i++)
		sourceVector.push_back(i);
	cout << "source vector: ";
	for(it = sourceVector.begin(); it != sourceVector.end(); it++)
		cout << *it << " ";
	cout << endl;
	
	resultVector.resize(sourceVector.size());
	optimized_copy(sourceVector.begin(), sourceVector.end(), resultVector.begin());
	cout << "result vector: ";
	for(it = resultVector.begin(); it != resultVector.end(); it++)
		cout << *it << " ";
	cout << endl;
	
	return 0;
}