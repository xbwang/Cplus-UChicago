/*********************
* hw14-5
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "Typelist.h"
#include <iostream>
#include <boost/type_traits.hpp>
using namespace cspp51055;

namespace cspp51055
{
    template <class TL> struct ApplyRemoveConst;
    template<>
    struct ApplyRemoveConst<NullType>{
        typedef NullType Result;
    };
    
    template<class Head, class Tail>
    struct ApplyRemoveConst<Typelist<Head, Tail> >{
        //typedef typename ApplyTypeTrait<boost::remove_const, Typelist<Head, Tail> >::Result Result;
        typedef Typelist<typename boost::remove_const<Head>::type, typename ApplyRemoveConst<Tail>::Result> Result;
    };
    
}

int main()
{
    typedef TYPELIST_3(int, const char, double) types_3;
    typedef ApplyRemoveConst<types_3>::Result RemovedConstTypelist;
    RemovedConstTypelist::print(std::cout) << std::endl;
    return 0;
}