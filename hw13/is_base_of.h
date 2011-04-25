/*********************
* hw13-3
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "is_convertible.h"
#include <boost/type_traits.hpp>
using cspp51045::is_convertible_to;

namespace mybase
{
    template<class B, class D>
    class Checker{
    public:
        //enum { value = (boost::is_void<B>::value || boost::is_void<D>::value) ? false : is_convertible_to<D*, B*>::value };
        enum { value = is_convertible_to<D*, B*>::value };
    };
    //i found that if i don't put the 'public' before the classes when inheriating
    //it won't let me compile because of inaccessiblility
    //i did some research on it but i still don't get the idea
    
    template<bool b> class is_base_of_helper;
    template<>
    class is_base_of_helper<true> : public boost::true_type {};
    template<>
    class is_base_of_helper<false> : public boost::false_type {};
    
    template<class B, class D>
    class m_is_base_of : public is_base_of_helper<Checker<B,D>::value> {};
    template<class D>
    class m_is_base_of<void, D> : public is_base_of_helper<false> {};
}