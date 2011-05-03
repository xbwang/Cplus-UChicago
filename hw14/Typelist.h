#ifndef TYPELIST_H
#  define TYPELIST_H
#include <iostream>
#include <string>
#include <typeinfo>
#include <boost/type_traits.hpp>
#include "metautils.h"
using std::string;
using std::ostream;
using boost::is_base_of;

namespace cspp51055 {
class NullType{
public:
    // NullType ends a typelist (just like NULL ends a C string)
    inline static ostream &printInternal(ostream &os, string delimiter) {
        return os << "]";
    }
};
template<class T, class U>
struct Typelist
{
    typedef T Head;
    typedef U Tail;
    // Lets us a print a typelist
    inline static ostream &print(ostream &os) {
        return printInternal(os, "[");
    }
    inline static ostream &printInternal(ostream &os, string delimiter) {
        os << delimiter << typeid(Head).name();
        return Tail::printInternal(os, ", ");
    }
private:
    Typelist(); // Cannot create!
};

#define TYPELIST_1(T1)  Typelist<T1, NullType>
#define TYPELIST_2(T1, T2) Typelist<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) Typelist<T1, TYPELIST_2(T2, T3)>

// Recursively calculate the length of a Typelist
// Use of this, and all other templates in this file,
// is shown in Typelist.cpp
template<class TList> struct Length;

template<>
struct Length<NullType>
{
    enum { value = 0};
};

template<class T, class U>
struct Length<Typelist<T, U> >
{
    enum { value = 1 + Length<U>::value };
};

// Find the ith element of the Typelist
template<class Head, int i> struct TypeAt;

template<class Head, class Tail>
struct TypeAt<Typelist<Head, Tail>, 0>
{
    typedef Head Result;
};

template<class Head, class Tail, int i>
struct TypeAt<Typelist<Head, Tail>, i>
{
    typedef typename TypeAt<Tail, i - 1>::Result Result;
};

// Which number element in the Typelist is Target?
template<class List, class Target> struct IndexOf;

// If it's not in Typelist, return -1
template<class Target>
struct IndexOf<NullType, Target>
{
    enum { value = -1 };
};

template<class Tail, class Target>
struct IndexOf<Typelist<Target, Tail>, Target>
{
    enum { value = 0 };
};

template<class Head, class Tail, class Target>
struct IndexOf<Typelist<Head, Tail>, Target>
{
private: // Using a Compile-time temporary int
    enum { temp = IndexOf<Tail, Target>::value };
public:
    enum { value = temp == -1 ? -1 : 1 + temp };
};

// Append a type or a Typelist to a Typelist
template<class First, class Second> struct Append;

template<class First>
struct Append<First, NullType>
{
    typedef First Result;
};

template<class Second>
struct Append<NullType, Second>
{
    typedef TYPELIST_1(Second) Result;
};

template<class Head, class Tail>
struct Append<NullType, Typelist<Head, Tail> >
{
    typedef Typelist<Head, Tail> Result;
};

template <class Head, class Tail, class Second>
struct Append<Typelist<Head, Tail>, Second>
{
    typedef Typelist<Head, typename Append<Tail, Second>::Result> Result;
};

// Apply a boost::type_trait like remove_pointer that transforms
// one type to another to each element of a Typelist.
// ApplyTypeTrait is the compile-time equivalent of std::transform
template <template<class> class T, class List> struct ApplyTypeTrait;

template <template<class> class T>
struct ApplyTypeTrait<T, NullType> {
  typedef NullType Result;
};

template <template<class> class T, class Head, class Tail>
struct ApplyTypeTrait<T, Typelist<Head, Tail> > {
typedef Typelist<typename T<Head>::type, typename ApplyTypeTrait<T, Tail>::Result> Result;
};

// Return the last type in a Typelist
template <class List> struct Last;

template<>
struct Last<NullType>
{
  typedef NullType Result;
};

template<class Head>
struct Last<Typelist<Head, NullType> > {
  typedef Head Result;
};

template<class Head, class Tail>
struct Last<Typelist<Head, Tail> > 
{
typedef typename Last<Tail>::Result Result;
};

// Erase the first occurrence of a given type from a Typelist
template<class TList, class T> struct Erase;

template<class T>
struct Erase<NullType, T>
{
    typedef NullType Result;
};

template<class T, class Tail>
struct Erase<Typelist<T, Tail>, T>
{
    typedef Tail Result;
};

template<class Head, class Tail, class T>
struct Erase<Typelist<Head, Tail>, T>
{
    typedef Typelist<Head, typename Erase<Tail, T>::Result> Result;
};

// Erase all occurrences of a given type from a typelist
template<class TList, class T> struct EraseAll;

template<class T>
struct EraseAll<NullType, T>
{
    typedef NullType Result;
};

template<class T, class Tail>
struct EraseAll<Typelist<T, Tail>, T>
{
    // Keep erasing
    typedef typename EraseAll<Tail, T>::Result Result;
};

template<class Head, class Tail, class T>
struct EraseAll<Typelist<Head, Tail>, T>
{
    typedef Typelist<Head, typename EraseAll<Tail, T>::Result> Result;
};

// Remove duplicates from a typelist
template<class TList> struct NoDuplicates;

template<>
struct NoDuplicates<NullType>
{
    typedef NullType Result;
};

template<class Head, class Tail>
struct NoDuplicates<Typelist<Head, Tail> >
{
private:
    // Using two compile time temporaries makes the logic easier to follow
    typedef typename NoDuplicates<Tail>::Result L1;
    typedef typename Erase<L1, Head>::Result L2;
public:
    typedef Typelist<Head, L2> Result;
};

// Replace the first occurrence of T in a typelist with U
template<class TList, class T, class U> struct Replace;
// Your homework is to define this
/******problem3 codes Xiangbo_Wang******/
/*
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
*/
// Find a member of TList that is most derived from T.
template<class TList, class T> struct MostDerived;

// If no class in TList inherits from T, just return T.
template<class T>
struct MostDerived<NullType, T>
{
    typedef T Result;
};

template<class Head, class Tail, class T>
struct MostDerived<Typelist<Head, Tail>, T>
{
private:
    typedef typename MostDerived<Tail, T>::Result Candidate;
public:
    typedef 
      typename Select<is_base_of<Candidate, Head>, Head, Candidate>::Result
      Result;
};

// Does a topological sort of a typelist, moving the most derived
// class first. What this means is that if D inherits from B and
// TL is a Typelist containing both D and B, then D is guaranteed
// to appear before B in DerivedToFront<TL>.
template<class T> struct DerivedToFront;

template<>
struct DerivedToFront<NullType>
{
    typedef NullType Result;
};

template<class Head, class Tail>
struct DerivedToFront<Typelist<Head, Tail> >
{
private:
    // Check if something is most derived from the Head
    typedef typename MostDerived<Tail, Head>::Result TheMostDerived;
    // If so, we will swap this with the current head. If not,
    // we will just be swapping it with itself, so no harm done.

    // Firstly, lets move the current head to where the most derived is
    // This ensures that the Tail will contain all the elements except
    // the most derived
    typedef typename Replace<Tail, TheMostDerived, Head>::Result Temp;
    // Now, sort the tail
    typedef typename DerivedToFront<Temp>::Result L;
public:
    // Finally, we return a typelist with the most derived in the
    // head and the remaining elements recursively sorted.
    typedef Typelist<TheMostDerived, L> Result;
};

// In order to use typelists to build classes, we will create
// a compile-time equivalent to std::accumulate. 
//
// Now, as we iterate through the types in the Typelist, we can
// accumulate new fields and methods in the type we are building.
//
// Note how the signature corresponds to std::accumulate
template<class TList, class Initial, template<class, class> class Binop>
struct Accumulate;

template<class Initial, template<class, class> class Binop>
struct Accumulate<NullType, Initial, Binop>
{
    typedef Initial Result;
};

template<class Head, class Tail, class Initial, template<class, class> class Binop>
struct Accumulate<Typelist<Head, Tail>, Initial, Binop>
{
    typedef Binop<Head, typename Accumulate<Tail, Initial, Binop>::Result > Result;
};

// We will illustrate the use of std::accumulate to build a
// (rather bad) tuple class. 
struct TupleBase {
};

template<class T, class Accumulator>
struct TupleOp : public Accumulator {
    T value;
};

template<class TList>
class Tuple : public Accumulate<TList, TupleBase, TupleOp>::Result {
};
}
#endif