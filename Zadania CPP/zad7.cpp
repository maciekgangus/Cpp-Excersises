#include <iostream>

template<typename T>
class B
{
    public:
    using value_type = T;
    B(T a)
    {
        value = a;
    }
    B(B<T>& other)
    {
        value = other.value;
    }

    T get()
    {
        return value;
    }
    T value;
    

};
template<typename T>
class B<T*>
{
    public:
    using value_type = T;

    B(T* a)
    {
        value = a;
    }

    T get()
    {
        return *value;
    }

    B(const B<T*>& other) = delete;

    B<T*> operator=(B<T*>& other) = delete;
    T* value;
};


int main()
{
    typedef B<int> int_b;
    typedef B<int*> int_p_b;        //jednak typedef

    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
    //int_p_b e = b; //error
     //b=b; //error
    
    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
    std::cout <<" b=" << b.get()+1 << std::endl;
}
/*
a=1
a_copy=2
 b=3
 */