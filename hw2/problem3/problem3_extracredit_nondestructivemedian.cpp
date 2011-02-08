#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//median template using sort as underlying algorithm
template<typename T>
T median_template(vector<T> vector_in)
{
	int n;
	vector<T> temp;
	temp.resize(vector_in.size());
	copy(vector_in.begin(), vector_in.end(), temp.begin());
	n = (temp.size()+1)/2;
	sort(temp.begin(),temp.end());
	return temp.at(n-1);
}

int main()
{
	//double as input
	vector<double> myvector_double;
	double mymedian_double;
	vector<double>::iterator it;
	
	myvector_double.push_back(1.2);
	myvector_double.push_back(1.5);
	myvector_double.push_back(1.1);
	myvector_double.push_back(1.3);
	myvector_double.push_back(1.4);
	
	cout << "original vector: ";
	for(it = myvector_double.begin(); it != myvector_double.end(); ++it)
		cout << *it << " ";
	cout << endl;
	
	mymedian_double = median_template(myvector_double);
	cout << "median_template<double> median: " << mymedian_double;
	cout << endl;
	
	cout << "original vector after median operation: ";
	for(it = myvector_double.begin(); it != myvector_double.end(); ++it)
		cout << *it << " ";
	cout << endl;

	
	return 0;
}