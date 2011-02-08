#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//median template using sort as underlying algorithm
template<typename T>
T median_template(vector<T> vector_in)
{
	int n;
	n = (vector_in.size()+1)/2;
	sort(vector_in.begin(),vector_in.end());
	return vector_in.at(n-1);
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
	
	//int as input
	vector<int> myvector_int;
	int mymedian_int;
	vector<int>::iterator itt;
	
	myvector_int.push_back(5);
	myvector_int.push_back(2);
	myvector_int.push_back(4);
	myvector_int.push_back(1);
	myvector_int.push_back(3);

	cout << "original vector: ";
	for(itt = myvector_int.begin(); itt != myvector_int.end(); ++itt)
		cout << *itt << " ";
	cout << endl;

	mymedian_int = median_template(myvector_int);
	cout << "median_template<int> median: " << mymedian_int;
	cout << endl;
	
	return 0;
}