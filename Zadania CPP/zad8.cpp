#include <iostream>

template<typename T = float>
struct Type_t
{
    Type_t(T a):value(a){};
    Type_t():value(){};
    T value;
    friend std::ostream& operator<<(std::ostream& os, Type_t object)
    {
        os<<object.value;
        return os;
    }
};

template<typename T>
class ptr
{
    public:
    using value_type = T;
    T* value = nullptr;
    ptr(T* other)
    {
        value = other;
    }
    ptr(ptr&& other)
    {
        value = other.value;
        other.value = nullptr;
    }

    T& operator*() const
    {
        return *value;
    }

    T* operator->() const
    {
        return value;
    }

    ptr(const ptr<T>& other) = delete;
    ptr(ptr<T>& other) = delete;

    ptr& operator=(ptr<T>& other) = delete;
    
    
    
    

   

};

using Float_t = Type_t<>;


int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>;

    Type_t t1{new Type_t::value_type{}};
    // Type_t t2 = t1;
    //Type_t t2; t2 = t1;
    // Type_t t2 = new Type_t::value_type();
    // Powyższe się mają nie kompilować
    (*t1).first = Type_t::value_type::first_type{1.};
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