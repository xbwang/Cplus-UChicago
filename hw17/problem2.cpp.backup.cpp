/*********************
* hw17-2.backup
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <boost/function_output_iterator.hpp>
#include <vector>
#include <iostream>
using namespace std;

template <class T, class charT=char, class traits=char_traits<charT> >
struct new_ostream_iterator : public iterator<output_iterator_tag, void, void, void, void>
{	
	basic_ostream<charT, traits>* out_stream;
	const charT* delim;
	
	typedef charT char_type;
	typedef traits traits_type;
	typedef basic_ostream<charT, traits> ostream_type;
	
	new_ostream_iterator(ostream_type& s) : out_stream(&s), delim(0) {}
	new_ostream_iterator(ostream_type& s, const charT* delimiter) : out_stream(&s), delim(delimiter) {}
	new_ostream_iterator(const new_ostream_iterator<T, charT, traits>& x) : out_stream(x.out_stream), delim(x.delim){}
	
	new_ostream_iterator<T, charT, traits>& operator = (T& value){
		*out_stream << value;
		if(delim != 0)
			*out_stream << delim;
		return *this;
	}
	new_ostream_iterator<T,charT,traits>& operator*() { return *this; }
	new_ostream_iterator<T,charT,traits>& operator++() { return *this; }

	
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	cout << "(";
	copy(v.begin(), v.end(), new_ostream_iterator<int>(cout, ","));
	cout << ")" << endl;
}