#ifndef TUPLE3_H
#define TUPLE3_H
#include "Typelist.h"

namespace cspp51055 {
template<class T>
struct Holder {
    T value;
};

template<class T, class Accumulator>
struct Tuple3Op : Holder<T>, public Accumulator {
    typedef Accumulator Base;
    typedef T type;
};

//integer index works
template<int i, class T>
struct At
{
    typedef typename At<i - 1, typename T::Base>::Result Result;
};

template<class T>
struct At<0, T>
{
    typedef T Result;
};

template<class TList>
struct Tuple3 : public Accumulate<TList, EmptyType, Tuple3Op>::Result {
    template<typename T>
    T &at() {
        Holder<T> *holder = this;
        return holder->value;
    }
    template<int i>
    typename At<i, Tuple3<TList> >::Result::type &at() {
        Holder<typename At<i, Tuple3<TList> >::Result::type> *holder = this;
        return holder->value;
    }

        
};

}
#endif