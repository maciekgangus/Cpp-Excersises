#include <cstdlib>
#include <iostream>

namespace std{
  class vector{};
  class list{};
  class deque{};
  class set{};
  class map{};
}

namespace oop
{
    template<typename T>
    struct Array
    {
        using value_type = T;
        
        Array(T size)
        {
            data = new T[size];
        }

        Array& insert(T symbol)
        {
            data[iter++] = symbol;
            return *this;
        }

        Array& operator+(T symbol)
        {
            return insert(symbol);
        }

        T operator~()
        {
            return iter;
        }

        const T& operator[](size_t position) const
        {
            return data[position];
        }

        size_t iter = 0;
        T* data = nullptr;
    };
}

int main(){

    typedef oop::Array<char> type;
    type a( rand() % 10 + 6 );

    a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3 );

    for(unsigned i = 0; i!= ~a; ++i)
      std::cout<< a[i] << (i+1 != ~a ? "" : "\n"  );
    


    
}

/*
  #C++03
*/