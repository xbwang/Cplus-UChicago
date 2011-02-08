#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//median template using sort as underlying algorithm
template<typename T>
double median_template(vector<T> vector_in)
{
	int m, n;
	if(vector_in.size()%2 != 0){
		n = (vector_in.size()+1)/2;
		m = n;
	}else{
		n = vector_in.size()/2;
		m = n + 1;
	}
	sort(vector_in.begin(),vector_in.end());
	return (double)(vector_in.at(n-1)+vector_in.at(m-1))/2;
}

int main()
{
	//double(even elements) as input
	vector<double> myvector_double;
	double mymedian_double;
	vector<double>::iterator it_double;
	
	myvector_double.push_back(1.6);
	myvector_double.push_back(1.5);
	myvector_double.push_back(1.2);
	myvector_double.push_back(1.1);
	myvector_double.push_back(1.3);
	myvector_double.push_back(1.4);
	
	cout << "original vector: ";
	for(it_double = myvector_double.begin(); it_double != myvector_double.end(); ++it_double)
		cout << *it_double << " ";
	cout << endl;
	
	mymedian_double = median_template(myvector_double);
	cout << "median_template<double> median: " << mymedian_double;
	cout << endl;
	
	//int(even elements) as input
	vector<int> myvector_int;
	double mymedian_int;
	vector<int>::iterator it_int;

	myvector_int.push_back(6);
	myvector_int.push_back(5);
	myvector_int.push_back(2);
	myvector_int.push_back(4);
	myvector_int.push_back(1);
	myvector_int.push_back(3);

	cout << "original vector: ";
	for(it_int = myvector_int.begin(); it_int != myvector_int.end(); ++it_int)
		cout << *it_int << " ";
	cout << endl;

	mymedian_int = median_template(myvector_int);
	cout << "median_template<int> median: " << mymedian_int;
	cout << endl;
	
	//int(odd elements) as input
	vector<int> myvector;
	double mymedian;
	vector<int>::iterator it;

	myvector.push_back(5);
	myvector.push_back(2);
	myvector.push_back(4);
	myvector.push_back(1);
	myvector.push_back(3);

	cout << "original vector: ";
	for(it = myvector.begin(); it != myvector.end(); ++it)
		cout << *it << " ";
	cout << endl;

	mymedian = median_template(myvector);
	cout << "median_template<int> median: " << mymedian;
	cout << endl;
	
	return 0;
}