#ifndef MYTYPELIST_H
#define MYTYPELIST_H
#include "Typelist.h"
#include <iostream>
using std::cout;
using std::endl;

namespace cspp51055
{
    template<class T1, class T2 = NullType, class T3 = NullType, class T4 = NullType, class T5 = NullType, class T6 = NullType, class T7 = NullType, class T8 = NullType, class T9 = NullType, class T10 = NullType>
    struct myTypelist
    {
        typedef Typelist<T1,
                    Typelist<T2,
                        Typelist<T3,
                            Typelist<T4,
                                Typelist<T5,
                                    Typelist<T6,
                                        Typelist<T7,
                                            Typelist<T8,
                                                Typelist<T9,
                                                    Typelist<T10, NullType> > > > > > > > > >
            Result;

        inline static void print(){
            cout << "[";
            if(typeid(T1) != typeid(NullType))
                cout << typeid(T1).name();
            if(typeid(T2) != typeid(NullType))
                cout << ", " << typeid(T2).name();
            if(typeid(T3) != typeid(NullType))
                cout << ", " << typeid(T3).name();
            if(typeid(T4) != typeid(NullType))
                cout << ", " << typeid(T4).name();
            if(typeid(T5) != typeid(NullType))
                cout << ", " << typeid(T5).name();
            if(typeid(T6) != typeid(NullType))
                cout << ", " << typeid(T6).name();
            if(typeid(T7) != typeid(NullType))
                cout << ", " << typeid(T7).name();
            if(typeid(T8) != typeid(NullType))
                cout << ", " << typeid(T8).name();
            if(typeid(T9) != typeid(NullType))
                cout << ", " << typeid(T9).name();
            if(typeid(T10) != typeid(NullType))
                cout << ", " << typeid(T10).name();
            cout << "]" << endl;
        }
    private:
        myTypelist();
    };
}
#endif