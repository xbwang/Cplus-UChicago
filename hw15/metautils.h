#ifndef META_UTILS_H
#  define META_UTILS_H

namespace cspp51055 {
template<bool flag, typename T, typename U> struct SelectBool;

template<typename T, typename U>
struct SelectBool<true, T, U>
{
    typedef T Result;
};

template<typename T, typename U>
struct SelectBool<false, T, U>
{
    typedef U Result;
};

template<typename flag, typename T, typename U>
struct Select
{
    typedef typename SelectBool<flag::value, T, U>::Result Result;
};

template<int v>
struct Int2Type
{
    enum { value = v };
};

template<typename T>
struct Type2Type
{
    typedef T OriginalType;
};
}

#endif