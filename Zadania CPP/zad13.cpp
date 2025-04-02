#include <iostream>
#include <string>


struct A
{
    A(){}
    A(std::string a)
    {
        value = a;
    }
    virtual void Print(std::ostream& os) const
    {
        os<<value;
    }
    
    
    

    std::string value;
    
};

struct B: A
{
    B(int a)
    {
        nr = a;
    }
    void Print(std::ostream& os) const override
    {
        os<<nr;
    }
    int nr;
    
};


std::ostream& operator<<(std::ostream& os ,const A& object)
{
    object.Print(os);
    return os;
}

std::ostream& operator<<(std::ostream& os ,const B& object)
{
    object.Print(os);
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

/*
a:      Tekst; b:       123
a_r:    Tekst; b_r:     123
*/