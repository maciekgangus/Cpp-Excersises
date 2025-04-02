#include <iostream> 
#include <cstdlib>
#include <vector>


namespace OOP
{
    template<typename T>
    struct Array
    {
        using value_type = T;
        
        Array(T a) {vec.reserve(a);}

        Array& insert(T item)
        {
            vec.push_back(item);
            return *this;
        }

        Array& operator%(T item)
        {
            return insert(item);
        }

        T operator~()
        {
            return vec.size();
        }

        T& operator[](size_t position)
        {
            return vec.at(position);
        }



        std::vector<T> vec;
    };
}



int main()
{
    typedef ::OOP::Array<int> type;
    type a(rand() % 100 + 10); // nie trzeba seedować żeby program się wykonał

    a.insert('#' - 1).insert('P') % type::value_type('O') % ('-') % ('E') % ('G') % ('Z') % ('1');
    
     ++a[0];
    for (unsigned i = 0; i != ~a; i++){
        std::cout << static_cast<char>(a[i]) << (i + 1 != ~a ? '_' : '\n');
    }
}
//#_P_O_-_E_G_Z