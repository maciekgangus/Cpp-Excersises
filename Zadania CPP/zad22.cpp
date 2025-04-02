#include <iostream>
#include <vector>
#include <deque>


template <typename T = int, typename StorageType = std::deque<int>> 
struct fifo
{
    
    using storage_type = StorageType;
    StorageType kolejka;
    fifo()
    {
        std::cout<<__PRETTY_FUNCTION__<<"\n";
    }

    void push(T a)
    {
        kolejka.push_back(a);
    }

    T get()
    {
        T a = kolejka.back();
        kolejka.pop_front();
        return a;
    }

    T size()
    {
        return kolejka.size();
    }

    auto begin()
    {
        return kolejka.begin();
    }

    auto end()
    {
        return kolejka.end();
    }


    
};





int main()
{
    fifo<> ft;
    for(int i: {0,1,2,3,4})
   	 ft.push(i);

    fifo<int, std::deque<int>> f = ft;

    std::cout << f.get() << "\n";
    std::cout << f.size() << "\n";

    for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
   	 std::cout << *i << ", ";
}



// fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
// 0
// 4
// 1,2,3,4,

