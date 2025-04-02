#include <iostream>
#include <vector>

struct Derived1;
struct Derived2;
struct Derived3;

struct Base
{
    Base(){}
    virtual std::ostream& print(std::ostream& os) const{};
};


struct Derived1 : Base
{
    
    Derived1(){}
    Derived1(Derived3& other) = delete;
    virtual std::ostream& print(std::ostream& os) const
    {
        os << __PRETTY_FUNCTION__<<"\n";
        return os;
    }
};

struct Derived2 : Base
{   
    Derived2(Derived3& other){}
    virtual std::ostream& print(std::ostream& os) const
    {
        return os<< __PRETTY_FUNCTION__<<"\n";
    }
};

struct Derived3 : Base
{
    virtual std::ostream& print(std::ostream& os) const
    {
        return os<< __PRETTY_FUNCTION__<<"\n";
    }
};

std::ostream& operator<<(std::ostream& os, Base* obj)
{
    return obj->print(os);
}

std::ostream& operator<<(std::ostream& os, std::vector<Base*>& obj)
{
    for(auto &it: obj)
    {
        (*it).print(os);
    }
    return os;
}


int main(){
    Derived1 d1;
    Derived3 d3;
    Derived2 d2 = d3;
    // Derived1 d1_make_err = d2;

    // std::vector<Base> v_make_err = {d1, d2, d3};
    std::vector<Base*> v = {&d1, &d2, &d3};

    std::cout <<v.front()<<std::endl;
    std::cout << v;
}
/*Wynik:
virtual std::ostream& Derived1::print(std::ostream&) const
[
virtual std::ostream& Derived1::print(std::ostream&) const,
virtual std::ostream& Derived2::print(std::ostream&) const,
virtual std::ostream& Derived3::print(std::ostream&) const
]
*/