#ifndef IS_BASE_OF_H
#  define IS_BASE_OF_H
#include <boost/type_traits.hpp>
using boost::true_type;
using boost::false_type;
#include "metautils.h"
using cspp51055::SelectBool;

namespace cspp51045 {
template<class T, class U>
class Conversion {
    typedef char Small;
    class Big { char dummy[2]; };

    static Small Test(U);
    static Big Test(...);
    static T MakeT();
public:
    enum { exists = sizeof(Test(MakeT())) == sizeof(Small) };
};

template<bool b> class IsConvertibleHelper;
template<>
class IsConvertibleHelper<true> : public true_type {
};
template<>
class IsConvertibleHelper<false> : public false_type {
};

template<class T, class U>
class is_convertible_to 
  : public IsConvertibleHelper<Conversion<T, U>::exists> {
};

// Alternate (probably better) solution
template<class T, class U>
class is_convertible_alternate
  : public SelectBool<Conversion<T,U>::exists, 
                      true_type,
                      false_type>::Result {
};

}

#endif