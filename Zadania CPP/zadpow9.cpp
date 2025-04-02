#include <iostream>

struct A
{
    A():A(0,0)
    {
        std::cout<<__PRETTY_FUNCTION__<<": _a="<<_a<<" _b="<<_b<<std::endl;
    }
    explicit A(int a):A(a,0)
    {
        std::cout<<__PRETTY_FUNCTION__<<": _a="<<_a<<" _b="<<_b<<std::endl;
    }

    A(int a, int b): _a(a), _b(b)
    {
        std::cout<<__PRETTY_FUNCTION__<<": _a="<<_a<<" _b="<<_b<<std::endl;
    }

    A(A&& other)
    {
        _a=other._a;
        _b=other._b;
        other._a = 0;
        other._b = 0;
        std::cout<<__PRETTY_FUNCTION__<<": _a="<<_a<<" _b="<<_b<<std::endl;
    }
    
   

    int _a;
    int _b;
};

int main()
{
    std::cout << "a->"; A a;
    std::cout << "b->"; A b(1);
    std::cout << "c->"; A c(1,2);

    std::cout << "d->"; A d = std::move(c);

    //A e = c;
    //A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[std::move]: _a=1,_b=2
*/