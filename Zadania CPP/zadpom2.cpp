#include <iostream>

struct A
{
    ~A(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
};

template<typename T>
struct B
{
    B(){}
    B(T elem): object(elem){}

    

    T object;
};


int main()
{
    typedef B<A> B_A;
    using TypeName = B<B_A>; //B<B<A>>
    TypeName a = TypeName(TypeName());
    TypeName b(a);
}