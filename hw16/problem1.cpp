#include <iostream>
#include "Factory.h"
using namespace cspp51045;
using std::cout;
using std::endl;

class Locomotive{public: virtual void foo(){}};
class FreightCar{public: virtual void foo(){}};
class Caboose{public: virtual void foo(){}};
//Model cars
class MLocomotive : public Locomotive
{
    void foo() { cout << "- i'm a MLocomotive" << endl; }
};
class MFreightCar : public FreightCar
{
    void foo() { cout << "- i'm a MFreightCar" << endl; }
};
class MCaboose : public Caboose
{
    void foo() { cout << "- i'm a MCaboose" << endl; }
};
//Real cars
class RLocomotive : public Locomotive
{
    void foo() { cout << "- i'm a RLocomotive" << endl; }
};
class RFreightCar : public FreightCar
{
    void foo() { cout << "- i'm a RFreightCar" << endl; }
};
class RCaboose : public Caboose
{
    void foo() { cout << "- i'm a RCaboose" << endl; }
};

typedef AbstractFactory<TYPELIST_3(Locomotive, FreightCar, Caboose)> CarFactory;
typedef ConcreteFactory<CarFactory, TYPELIST_3(MLocomotive, MFreightCar, MCaboose)> ModelTrainFactory;
typedef ConcreteFactory<CarFactory, TYPELIST_3(RLocomotive, RFreightCar, RCaboose)> RealTrainFactory;

int main()
{
    CarFactory *mt = new ModelTrainFactory();
    Locomotive *ml = mt->create<Locomotive>();
    ml->foo();
    
    CarFactory *rt = new RealTrainFactory();
    FreightCar *rf = rt->create<FreightCar>();
    rf->foo();
    
    return 0;
}