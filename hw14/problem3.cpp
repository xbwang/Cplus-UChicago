/*********************
* hw14-3
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "Typelist.h"
#include <iostream>
using namespace cspp51055;
using namespace std;

//problem3 code
namespace cspp51055
{
    template<class T, class U>
    struct Replace<NullType, T, U>
    {
        typedef NullType Result;
    };

    template<class Tail, class T, class U>
    struct Replace<Typelist<T, Tail>, T, U>
    {
        typedef Typelist<U, typename Replace<Tail, T, U>::Result> Result;
    };

    template<class Head, class Tail, class T, class U>
    struct Replace<Typelist<Head, Tail>, T, U>
    {
        typedef Typelist<Head, typename Replace<Tail, T, U>::Result> Result;
    };
}

//testing part
#define TYPELIST_4(T1, T2, T3, T4) Typelist<T1, TYPELIST_3(T2, T3, T4)>
#define TYPELIST_5(T1, T2, T3, T4, T5) Typelist<T1, TYPELIST_4(T2, T3, T4, T5)>
int main()
{
    
    typedef TYPELIST_5(int, char, int, int, char) types;
    cout << "Original types: ";
    types::print(cout) << endl;
    cout << "After replacing int to double: ";
    Replace<types, int, double>::Result::print(cout) << endl;
    return 0;
}