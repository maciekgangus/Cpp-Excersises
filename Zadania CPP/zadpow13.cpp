#include <iostream>
#include <string>


struct is_printable
{
    is_printable(){}
    virtual void Print(std::ostream& os) const
    {
        
    }
};

struct A : is_printable
{
    A(){}
    A(std::string a): napis(a){}
    virtual void Print(std::ostream& os) const
    {
        os<<napis;
    }

    std::string napis;
};

struct B : is_printable
{
    B(int a): value(a){}
    virtual void Print(std::ostream& os) const
    {
        os<<value;
    }


    int value;
};

std::ostream& operator<<(std::ostream& os, const is_printable& other)
{
    other.Print(os);
    return os;
}






int main()
{
  A a ("Tekst"); 
  B b {123};
  std::cout<< "a:\t"<<a<<"; b:\t"<<b<<"\n";
  const is_printable & a_r = a; 
  const is_printable & b_r = b;
   std::cout<< "a_r:\t"<<a_r<<"; b_r:\t"<<b_r<<"\n";
}

/*
a:      Tekst; b:       123
a_r:    Tekst; b_r:     123
*/