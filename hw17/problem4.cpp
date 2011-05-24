/*********************
* hw17-4
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <boost/utility.hpp>
#include <boost/type_traits.hpp>

typedef char no_tag[1];
typedef char yes_tag[2];

template <typename T, int (T::*) > struct id_helper {};

template <typename T> no_tag& test(...);
template <typename T> yes_tag& test(id_helper<T, &T::id>* p);

template <typename T>
struct has_id
{   
public:
    enum {value = sizeof(test<T>(0)) == sizeof(yes_tag)};
};

template <class T>
int get_id(T t, typename boost::disable_if<has_id<T> >::type* dummy = 0)
{
    return -1;
}

template <class T>
int get_id(T t, typename boost::enable_if<has_id<T> >::type* dummy = 0)
{
    return t.id;
}


struct A
{
    A() : id(111){}
    int id;
};

int main()
{
    std::cout << get_id(7) << std::endl;
    std::cout << get_id(A()) << std::endl;
    
    return 0;
}