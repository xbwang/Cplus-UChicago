/*********************
* hw17-3
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <boost/utility.hpp>
#include <boost/type_traits.hpp>

typedef char no_tag[1];
typedef char yes_tag[2];

template <typename T, T (T::*)() > struct square_helper {};

template <typename T> no_tag& test(...);
template <typename T> yes_tag& test(square_helper<T, &T::square>* p);

template <typename T>
struct has_square
{
public:
    enum {value = sizeof(test<T>(0)) == sizeof(yes_tag)};
};

template <class T>
typename boost::disable_if<has_square<T>, T>::type square(T t)
{
    return t*t;
}

template <class T>
typename boost::enable_if<has_square<T>, T>::type square(T t)
{
    t.square();
}

//testing
struct A
{
    A square() { std::cout << "A's square" << std::endl; return A(); }
};

int main()
{
    A a;
    square(a);
    std::cout << square(7) << std::endl;
    std::cout << square(1.1) << std::endl;
    return 0;
}