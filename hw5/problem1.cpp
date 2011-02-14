#include <iostream>
#include <string>
using namespace std;

class B
{
public:
    B(){ cout << "I'm B" << endl; }
    ~B(){}
    virtual void foo(){} 
};

class D : public B
{
public:
    D(){ cout << "I'm D" << endl; }
    ~D(){}
    void foo(){ cout << "foo() in D" << endl; }
};

class C
{
public:
    C(){ cout << "I'm C" << endl; }
    ~C(){}
};

int main()
{
    B *b;
    C *c;
    
    dynamic_cast<D*>(b);
    //dynamic_cast<D*>(c);  //this will not be compiled
    reinterpret_cast<D*>(b);
    reinterpret_cast<D*>(c); //this will work since the reinterpret doesn't do check
    
    return 0;
}

//Dynamic_cast is better since it just allow casting Base* to Derived*
//only when the target object relly is a Derived*, which prevent from
//casting between two non related objects.
//However, reinterpret_cast doesn't have such protection,
//where it allows any pointer type to any other pointer type.