#include <iostream>

using namespace std;

struct A
{
    A()
    {
        cout<<__PRETTY_FUNCTION__<<endl;
    }
    ~A()
    {
        cout<<__PRETTY_FUNCTION__;
    }
};

struct B : A
{
    B() : A()
    {
        cout<<__PRETTY_FUNCTION__;
        
    }
    ~B()
    {
        cout<<__PRETTY_FUNCTION__;
    }
};



struct X : A
{
    X() : A()
    {
        cout<<__PRETTY_FUNCTION__;
    }
    ~X()
    {
        cout<<__PRETTY_FUNCTION__;
    }
};

struct Y
{
    Y()
    {
        cout<<__PRETTY_FUNCTION__;
    }
    ~Y()
    {
        cout<<__PRETTY_FUNCTION__;
    }
};

struct Z : Y , X
{
    Z(): Y()
    {
        cout<<__PRETTY_FUNCTION__<<endl;
    }
    ~Z()
    {
        cout<<__PRETTY_FUNCTION__;
    }
};

int main() {Z z;}


//A::A() 
//B::B(); A::A() 
//X::X(); A::A() 
//X::X(); Y::Y(); Z::Z() 
//Z::~Z(); Y::~Y(); X::~X(); A::~A(); X::~X(); A::~A(); B::~B(); A::~A(); %