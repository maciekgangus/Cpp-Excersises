

#include <iostream>


struct Obj
{
    virtual void Draw() const = 0;
};

template<typename T>
struct Box: Obj
{
    explicit Box(const T& a): value(a){}
    
    void Draw() const 
    {
        std::cout<< __PRETTY_FUNCTION__ << value << std::endl;
    }

    operator T()
    {
        return value;
    }

    
    

    T value;
};





template<typename T>
struct Box<Box<T>>: Obj
{
    Box(const T& a): value(a){}
    

    void Draw() const 
    {
        std::cout<< __PRETTY_FUNCTION__ << value.value << std::endl;
    }

    operator Box<T>()
    {
        return value;
    }


    Box<T> value;
};

int main(){

    Box<int> b_i{3};        
    Obj& r1 = b_i;  
    r1.Draw(); 
    int i = b_i; //int i = 3
    Box<double> b_d{3.4};        
    Obj& r2 = b_d;  r2.Draw(); 
    double d = b_d;
    Box<Box<int>> bb_i{3}; 
    const Obj& r3 = bb_i; r3.Draw(); 
    b_i = bb_i; //b_i = 3
    Box<Box<double>> bb_d{3.4}; 
    const Obj& r4 = bb_d; 
    r4.Draw(); 
    b_d = bb_d;

    //Box<int> _ = 3; // Odkomentowanie powoduje b��d kompilacji
}
/* standardowe wyj�cie:
struct Box<int>::Draw() --> 3
struct Box<double>::Draw() --> 3.4
struct Box<Box<int>>::Draw() --> 3
struct Box<Box<double>>::Draw() --> 3.4 */