/*********************
* hw13-2
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#ifndef IS_CONST_H
#   define IS_CONST_H
#include <boost/type_traits.hpp>

namespace myconst
{
    using boost::type_traits::yes_type;
    using boost::type_traits::no_type;
    
    yes_type is_const_tester(const void*);
    no_type is_const_tester(void*);
    
    template<class T>
    class Checker{
    public:
        static T *t;
        enum { value = sizeof(yes_type) == sizeof(is_const_tester(t)) };
    };
    //remove reference
    template<class T>
    struct remove_reference{
        typedef T type;
    };
    template<class T>
    struct remove_reference<T &>{
        typedef T type;
    };
    template<class T>
    struct remove_reference<T &&>{
        typedef T type;
    };
    
    template<bool b> class is_const_helper;
    template<>
    class is_const_helper<true> : public boost::true_type {};
    template<>
    class is_const_helper<false> : public boost::false_type {};
    
    template<class T>
    class m_is_const : public is_const_helper<Checker<T>::value> {};
}
#endif