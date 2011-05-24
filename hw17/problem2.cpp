/*********************
* hw17-2
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <boost/function_output_iterator.hpp>
#include <vector>
#include <iostream>
using namespace std;

template<class T>
struct new_ostream_iterator
{
    new_ostream_iterator(ostream &os_, string delim_) : os(os_), delim(delim_) , first(true) {}
    
    void operator()(T t)
    {
        if(first == true){
            first = false;
        }else{
            os << delim;
        }
        os << t;
    }
private:
    ostream &os;
    string delim;
    bool first;
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    cout << "(";
    copy(v.begin(), v.end(),  boost::make_function_output_iterator(new_ostream_iterator<int>(cout, ",")));
    cout << ")" << endl;
    return 0;
}