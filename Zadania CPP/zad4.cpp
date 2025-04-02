#include <iostream>
#include <cstdlib>
#include <vector>

namespace OOP
{
    template<typename T>
    class Array
    {
        public:
        using value_type = T;
        Array(T t){};

        Array<T>& insert(T element)
        {
            content.push_back(element);
            return *this;
        }

        Array<T>& operator%(T elem)
        {
            return insert(elem);
        }

        size_t operator~()
        {
            return content.size();
        }

        T& operator[](int index)
        {
            return content.at(index);
        }



        std::vector<T> content;
    };
};



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