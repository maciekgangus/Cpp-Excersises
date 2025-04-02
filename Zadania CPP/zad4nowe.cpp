#include <iostream>

struct A
{
    

    A():i(1){}
    int i;
};


template<typename T>
struct ptr
{
    ptr()
    {
        object = nullptr;
    }
    explicit ptr(T* objp): object(objp){}

    ptr(ptr& object) = delete; 


    T& operator*() const
    {
        return *object;
    }

    T* operator->() const
    {
        return object;
    }

    bool operator==(const ptr& other) const
    {
       return object == other.object;
    }

    bool operator!=(const ptr& other) const
    {
        return object != other.object;
    }

    ptr& operator=(ptr& object) = delete;

    T* object;
};


int main ()
{
    const ptr<A>  a ( new A );
    const ptr<A> b;
    ptr<A> c ( new A );

    //ptr<A>  _b_error = new A;      // Odkomentowanie powoduje błąd kompilacji 
    //a = a; 			             // Odkomentowanie powoduje błąd kompilacji 
    //const ptr<A> _c_error = a;     // Odkomentowanie powoduje błąd kompilacji 

    std::cout << ( ( *a ).i , a->i ) << " " << ++c->i << " ";
    std::cout << ( a == ptr<A> () ) << " " << ( a != b ) << "\n";
}
/* output/wyjście:
1 2 0 1
*/