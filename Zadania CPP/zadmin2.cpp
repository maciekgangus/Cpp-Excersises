#include <iostream>
#include <deque>




template<typename T = int, typename U = std::deque<T>>
struct fifo
{
    
    using storage_type = U;

    fifo()
    {
      std::cout<<__PRETTY_FUNCTION__<<std::endl;
    };
    fifo(const fifo& other) : kolejka(other.kolejka){}

    void push(T a)
    {
      kolejka.push_back(a);
    }

    T get()
    {
      T tmp = *kolejka.begin(); //kolejka[0];
      kolejka.pop_front();
      return tmp;
    }

    unsigned size()
    {
      return kolejka.size();
    }

    typename U::const_iterator begin()
    {
      return kolejka.begin();
    }

    typename U::const_iterator end()
    {
      return kolejka.end();
    }

    U kolejka;
};


int main(){
    fifo<> ft;
    for(int i: {0,1,2,3,4})
        ft.push(i);

    fifo<int, std::deque<int>> f = ft;

    std::cout << f.get() << std::endl;
    std::cout << f.size() << std::endl;

    for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
        std::cout << *i << ",";
}
/*
  Wynik:
  fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
  0
  4
  1,2,3,4,
*/