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
    class Array
    {
        public:
        using value_type = T;
        Array(int a)
        {
            size = a;
            tab = new T[size];
            
        }
        ~Array()
        {
            delete tab;
        }

        T* tab = nullptr;
        int size;
        int iter = 0;

        Array& insert(T a)
        {
            tab[iter] = a;
            iter++;
            return *this;
        }

        Array& operator+(T a)
        {
            return this->insert(a);
        }
        int operator~()
        {
            return this->size;
        }
        T& operator[](int index)
        {
            return tab[index];
        }

    };
};


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