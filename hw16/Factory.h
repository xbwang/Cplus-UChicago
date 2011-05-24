#ifndef FACTORY_H
#  define FACTORY_H
#include "Typelist.h"

namespace cspp51045 {

template<typename T>
struct AbstractCreator {
    virtual T *doCreate(Type2Type<T>) = 0;
};

template<typename T, class Accumulator>
struct AbstractFactoryBinop : public AbstractCreator<T>, public Accumulator {
};

struct AbstractFactoryBase {
    void *doCreate() {} // To keep using statement from failing
};

template<class TList>
struct AbstractFactory
    : public Accumulate<TList, EmptyType, AbstractFactoryBinop>::Result
{
    typedef TList AbstractProducts;
    typedef TList UnimplementedProducts;
    template<class T> T *create() {
        // Since template methods can't be virtual, use the template
        // argument to uniquely identify a virtual non-template method
        // We will need to cast up because the different doCreate<>
        // methods hide each other ("method hiding")
        AbstractCreator<T> &creator = *this;
        return creator.doCreate(Type2Type<T>());
    }
};

template<typename T, class Accum>
struct ConcreteFactoryBinop : public Accum {
    typedef typename Accum::UnimplementedProducts::Tail UnimplementedProducts;
    // The product we are implementing
    typedef typename Accum::UnimplementedProducts::Head AbstractProduct;
    virtual T *doCreate(Type2Type<AbstractProduct>) {
        return new T;
    }
};

template<class Abstract, class TList>
class ConcreteFactory
    : public 
        Accumulate
          <typename Reverse<TList>::Result, Abstract, ConcreteFactoryBinop>
            ::Result
{
    typedef TList ConcreteProducts;
};

template<class Abstract, template<class T> class Model>
class ParameterizedFactory
{
    
};

}
#endif
