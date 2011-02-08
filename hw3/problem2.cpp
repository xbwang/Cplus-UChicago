#include <iostream>
using namespace std;

class Parent
{
public:
    virtual void fail() = 0; //pure virtual function
};

class Child : public Parent
{
public:
    void succeed(){cout<<"calling succeed() in Child.\n";}
};

int main()
{
    Child *testChild;
    testChild->succeed();   //this will not fail
    testChild->fail();  //this will fail b/c pure virtual function called
    
    return 0;
}