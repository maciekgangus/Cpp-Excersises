#include <iostream>

template<typename T = float>
struct Type_t
{
    Type_t(){}
    explicit Type_t(T a):value(a){}
    T value;
    
    
};

template<typename T>
std::ostream& operator<<(std::ostream& os,const Type_t<T>& obj)
    {   
        return os<<obj.value;
    }


template<typename T>
struct ptr
{
    using value_type = T;
    explicit ptr(T* a): para(a){}
    ptr(ptr&& other)
    {
        para = other.para;
        other.para = nullptr;
    }

    T& operator*() const
    {
        return *para;
    }

    T* operator->() const
    {
        return para;
    }

    



    T* para;
};




using Float_t = Type_t<>;

int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>;

    Type_t t1{new Type_t::value_type{}}; // ptr<pair>
    // Type_t t2 = t1;
    //Type_t t2; t2 = t1;
    // Type_t t2 = new Type_t::value_type();
    // Powyższe się mają nie kompilować
    (*t1).first = Type_t::value_type::first_type{1.}; // float_t
    t1->second = Type_t::value_type::second_type{2.5};

    Type_t t2 = std::move(t1);

    // t3=std::move(t2); 
    const Type_t t3{new Type_t::value_type{}};                                 
    //(*t3).first= 13;
    // t3->second = 13;
    // Powyższe się mają nie kompilować
    (*t3).first = Type_t::value_type::first_type{1};  
    t3->second = Type_t::value_type::second_type{2.5};

    
    std::cout << (*t3).first.value << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
*/