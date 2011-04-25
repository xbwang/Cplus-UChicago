/*********************
* hw13-1
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <boost/type_traits.hpp>
using boost::is_signed;
using namespace std;
using namespace boost;

template<class T>
int f(T t)
{
    /*
    if(is_signed<T>::value)
        return -1;
    else
        return 0;
    */
    return is_signed<T>::value ? -1 : 0;
}

int main()
{
    cout << f(7) << endl;
    cout << f(7U) << endl;
    return 0;
}