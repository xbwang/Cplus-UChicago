#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double median_partial_sort(vector<double> vector_in)
{
	int n;
	n = (vector_in.size()+1)/2;
	partial_sort(vector_in.begin(), vector_in.begin()+n,vector_in.end());
	return vector_in.at(n-1);
}

int main()
{
	vector<double> myvector;
	double mymedian;
	vector<double>::iterator it;
	//initialize the vector
	myvector.push_back(1.1);
	myvector.push_back(1.2);
	myvector.push_back(1.3);
	myvector.push_back(1.4);
	myvector.push_back(1.5);
	random_shuffle(myvector.begin(), myvector.end());
	cout << "original vector: ";
	for(it = myvector.begin(); it != myvector.end(); ++it)
		cout << *it << " ";
	cout << endl;
	//take the median
	mymedian = median_partial_sort(myvector);
	cout << "partial_sort median: " << mymedian;
	cout << endl;
	
	return 0;
}