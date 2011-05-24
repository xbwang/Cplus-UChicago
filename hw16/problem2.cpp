#include <iostream>
#include "Factory.h"
using namespace cspp51045;
using std::cout;
using std::endl;

class Locomotive{};
class FreightCar{};
class Caboose{};

template<class T>
class Model{};
template<>
class Model<Locomotive>
{
    void foo() { cout << "- i'm a MLocomotive" << endl; }
};
template<>
class Model<FreightCar>
{
    void foo() { cout << "- i'm a MFreightCar" << endl; }
};
template<>
class Model<Caboose>
{
    void foo() { cout << "- i'm a MCaboose" << endl; }
};

template<class T>
class Real{};
template<>
class Real<Locomotive>
{
    void foo() { cout << "- i'm a RLocomotive" << endl; }
};
template<>
class Real<FreightCar>
{
    void foo() { cout << "- i'm a RFreightCar" << endl; }
};
template<>
class Real<Caboose>
{
    void foo() { cout << "- i'm a RCaboose" << endl; }
};

typedef AbstractFactory<TYPELIST_3(Locomotive, FreightCar, Caboose)> AbstractTrainFactory;
typedef ParameterizedFactory<AbstractTrainFactory, Model> ModelTrainFactory;
typedef ParameterizedFactory<AbstractTrainFactory, Real> RealTrainFactory;

int main()
{
    return 0;
}