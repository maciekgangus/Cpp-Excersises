#include <iostream>

struct Int_t
{
    Int_t(int a): nr(a){}
    int nr;
};



std::ostream& operator<<(std::ostream& os, const Int_t& obj)
{
    return os<<obj.nr;
}

struct ptr
{
    ptr(Int_t* obj): value(obj)
    {
        std::cout<<"K_"<<*value<<";";
    }
    ~ptr()
    {
        std::cout<<"D_"<<*value<<";";
    }
    Int_t* value;
};



int main()
{
    { ptr p {new Int_t{1}}; }
      ptr p {new Int_t{2}};
}


/*
output:

K_1;D_1;K_2;D_2

*/