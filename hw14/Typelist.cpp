#include "Typelist.h"
#include <iostream>
#include <boost/type_traits.hpp>

using namespace std;
using namespace cspp51055;
using namespace boost;

class A {
public:
    template<int i> int at() { return i; }
    template<class T> int at() { return 0; }
    static void foo() { cout << "In A" << endl; }
};

class B : public A {
public:
    static void foo() { cout << "In B" << endl; }
};

class C : public B {
public:
    static void foo() { cout << "In C" << endl; }
};

class D {
public:
    static void foo() { cout << "In D" << endl; }
};


int
main()
{
    typedef TYPELIST_2(A, B) AB;

    int i = Length<TYPELIST_3(char,unsigned char, signed char)>::value;
    cout << endl << i << endl;
    TypeAt<AB,1>::Result::foo();
    int j = IndexOf<AB, int>::value;
    cout << "The Index of int in AB is " << j << endl;
    typedef Append<AB, int>::Result ABint;
    int k = IndexOf<ABint, int>::value;
    cout << "The Index of int in ABint is " << k << endl;

    AB::print(cout) << endl;
    typedef TYPELIST_3(A, const char *, int *) TL;
    typedef TYPELIST_3(int, float, int) Dups;
    typedef ApplyTypeTrait<boost::remove_pointer, TL>::Result TL3;
    typedef Last<TL3> Last3;
    cout << "Removing pointers from ";
    TL::print(cout) << " gives ";
    TL3::print(cout) << endl;

    cout << endl << "Removing int from ";
    Dups::print(cout) << " gives ";
    Erase<Dups, int>::Result::print(cout) << endl;

    cout << endl << "Removing all ints from ";
    Dups::print(cout) << " gives ";
    EraseAll<Dups, int>::Result::print(cout) << endl;

    cout << endl << "Removing duplicates from ";
    Dups::print(cout) << " gives ";
    NoDuplicates<Dups>::Result::print(cout) << endl;

    // Once you define Replace in the homework, you can uncomment the following
    cout << endl << "Replacing int with double in ";
    Dups::print(cout) << " gives ";
    Replace<Dups, int, double>::Result::print(cout) << endl;

    typedef TYPELIST_3(D, B, C) DBC;
    cout << endl << "Most Derived from D in ";
    DBC::print(cout);
    cout << " is " << typeid(MostDerived<DBC, D>::Result).name() << endl;

    cout << endl << "Most Derived from B in ";
    DBC::print(cout);
    cout << " is " << typeid(MostDerived<DBC, B>::Result).name() << endl;

    cout << endl << "Topologically sort ";
    DBC::print(cout);
    cout << " by derivation is ";
    DerivedToFront<DBC>::Result::print(cout) << "." << endl;

    return 0;
}