/*********************
* hw14-4
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "Typelist.h"
#include <iostream>
#include <boost/type_traits.hpp>
using namespace cspp51055;

namespace cspp51055
{
    template<class TL, template<class> class T> struct Filter;
    
    template<template<class> class T>
    struct Filter<NullType, T>{
        typedef NullType Result;
    };
    
    template<class Head, class Tail, template<class> class T>
    struct Filter<Typelist<Head, Tail>, T>
    {
        //when want to do the if-else selection in template, have anther template approach it.
        typedef typename Select<T<Head>, 
            Typelist<Head, typename Filter<Tail, T>::Result>, 
            typename Filter<Tail, T>::Result>::Result Result;
    };
}

int main()
{   
    typedef TYPELIST_3(int, double, char*) types_3;
    types_3::print(std::cout) << std::endl;
    typedef Filter<types_3, boost::is_pointer>::Result FilteredTypes;
    FilteredTypes::print(std::cout) << std::endl;
    return 0;
}