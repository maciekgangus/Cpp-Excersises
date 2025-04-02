#include <iostream>
#include <typeinfo>

template<typename T>
void test()
{
    
    
    
    
    int a;
    if((a = std::is_pod<T>::value))
    {
        std::cout<<typeid(typename T::value_type).name()<<"is_pod ="<<a<<" POD type"<<std::endl;
    }
    else
    {
        std::cout<<typeid(typename T::value_type).name()<<"is_pod ="<<a<<" nonPOD type"<<std::endl;
     }
    
}

struct A
{
    using value_type = A;
};

struct B
{
    ~B(){}
    using value_type = B;
    
};


int main() 
{

    test<A>();
    test<B>();
    test<std::array<A,10>>();
    test<std::vector<A>>();
    return 0;
}

// A is_pod = 1, Copying POD type.
// B is_pod = 0, Copying non-POD type.
// std::array<A,10> is_pod = 1, Copying POD type.
// std::vector<A> is_pod = 0, Copying non-POD type.