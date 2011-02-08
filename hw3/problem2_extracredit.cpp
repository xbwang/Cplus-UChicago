#include <iostream>
using namespace std;

class Parent;
void fail(Parent*);

class Parent
{
public:
    virtual void pure_virtual() = 0; //pure virtual function
    Parent() { fail(this); }
    virtual ~Parent();  
};

void fail(Parent* p)
{
    p->pure_virtual();
};

class Child : public Parent
{
    Child(){}
    ~Child(){}
};

int main()
{
    Child* test = new Child(); //constructor fails b/c calling pure virtual fucntion
    delete test;
}