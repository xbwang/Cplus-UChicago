#ifndef TUPLE4_H
#define TUPLE4_H
#include "Typelist.h"

namespace cspp51055 {
template<class T>
struct Holder {
    T value;
};

template<class T, class Accumulator>
struct Tuple4Op : Holder<T>, public Accumulator {
    typedef Accumulator Base;
    typedef T type;
};

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
struct Tuple4 : public Accumulate<TList, EmptyType, Tuple4Op>::Result {
    template<typename T>
    T &at() {
        Holder<T> *holder = this;
        return holder->value;
    }
    template<int i>
    typename At<i, Tuple4<TList> >::Result::type &at() {
        Holder<typename At<i, Tuple4<TList> >::Result::type> *holder = this;
        return holder->value;
    }
	
	template<typename T, int i>
	T &myat(){
	
	}
};

}
#endif