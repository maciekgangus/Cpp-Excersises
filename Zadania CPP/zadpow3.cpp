#include <iostream>

namespace OOP
{
    template<typename T>
    struct Array
    {
        
        using value_type = T;
        Array(T size): iter(0)
        {
            tablica = new T[size];
        }
        
        T* tablica; //nie mozna []
        

        Array& insert(T elem)
        {
            tablica[iter] = elem;
            iter++;
            return *this;
        }

        Array& operator%(T elem)
        {
            return this->insert(elem);
        }

        T& operator[](T index)
        {
            return tablica[index];
        } 

        unsigned operator~()
        {
            return iter;
        }

        ~Array()
        {
            delete tablica;
        }
        T iter;
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