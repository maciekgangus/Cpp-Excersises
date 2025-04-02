
#include <iostream>
#include <string>


struct A
{
    A(){}
    A(std::string a): napis(a){}
    std::string napis;
    virtual void Print(std::ostream& os) const
    {
        os<<napis;
    }
};


struct B: A
{
    B(int a): value(a){}
    void Print(std::ostream& os) const override 
    {
        os<<value;
    }
    int value;
};

std::ostream& operator<<(std::ostream& os,const A&  other) 
{
    
    other.Print(os);
    return os;
}

std::ostream& operator<<(std::ostream& os,const B& other) 
{
    
    other.Print(os);
    return os;
}


typedef A is_printable;


int main()
{
  A a ("Tekst"); 
  B b {123};
  std::cout<< "a:\t"<<a<<"; b:\t"<<b<<"\n";
  const is_printable & a_r = a; 
  const is_printable & b_r = b;
   std::cout<< "a_r:\t"<<a_r<<"; b_r:\t"<<b_r<<"\n";
}