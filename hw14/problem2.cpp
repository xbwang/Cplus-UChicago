/*********************
* hw14-2
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "Typelist.h"
#include <iostream>
using namespace std;
using namespace cspp51055;

namespace cspp51055
{
    //problem2 part1: create TYPELIST_4&TYPELIST_5
    #define TYPELIST_4(T1, T2, T3, T4) Typelist<T1, TYPELIST_3(T2, T3, T4)>
    #define TYPELIST_5(T1, T2, T3, T4, T5) Typelist<T1, TYPELIST_4(T2, T3, T4, T5)>
    //problem4 part2: create Typelist with 7 elements
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    struct Typelist_7
    {
        typedef typename Append<typename Append<typename Append<typename Append<typename Append<typename Append<typename Append<NullType, T1>::Result, T2>::Result, T3>::Result, T4>::Result, T5>::Result, T6>::Result, T7>::Result Result;
        inline static void print(){
            cout << "[";
            cout << typeid(T1).name() << ", ";
            cout << typeid(T2).name() << ", ";
            cout << typeid(T3).name() << ", ";
            cout << typeid(T4).name() << ", ";
            cout << typeid(T5).name() << ", ";
            cout << typeid(T6).name() << ", ";
            cout << typeid(T7).name();
            cout << "]" << endl;
        }
    private:
        Typelist_7();
    };
}

//testing part
class A { public: static void foo() { cout << "In A" << endl; } };
class B { public: static void foo() { cout << "In B" << endl; } };
class C { public: static void foo() { cout << "In C" << endl; } };
class D { public: static void foo() { cout << "In D" << endl; } };
class E { public: static void foo() { cout << "In E" << endl; } };
int main()
{
    typedef TYPELIST_4(A, B, C, D) types_4;
    typedef TYPELIST_5(B, C, A, E, D) types_5;
    cout << "4 types Typelist: ";
    types_4::print(cout) << endl;
    cout << "type at 2 in types_4: ";
    TypeAt<types_4, 2>::Result::foo();
    cout << "5 types Typelist: ";
    types_5::print(cout) << endl;
    cout << "type at 4 in types_5: ";
    TypeAt<types_5, 4>::Result::foo();
    
    Typelist_7<A,B,C,D,E,A,B>::print(); 
    return 0;
}