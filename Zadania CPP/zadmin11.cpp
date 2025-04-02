#include <iostream>
#include <typeinfo>



struct Obj
{
    public:
        
        virtual void Draw() const = 0;

};

template<typename T>
struct Box : public Obj
{
    public:
        explicit Box(T value) : Value(value){}

        void Draw() const override
        {
            std::cout << Value << std::endl;
        }
        
        void printValue(std::ostream& str) const
        {
            str << Value;
        }

        operator T()
        {
            return Value;
        }

        template <typename U>
        friend std::ostream& operator<<(std::ostream& str, const Box<U>& obj);

    private:
        T Value;
};

template <typename T>
std::ostream& operator <<(std::ostream& str, const Box<T>& obj)
{
    obj.printValue(str);
    return str;
}



int main()
{
    Box<int> b_i {3};        
    Obj& r_1 = b_i; 
    r_1.Draw(); 
    int i = b_i;
    Box<double> b_d {3.4} ;
    Obj& r_2 = b_d;
    r_2.Draw(); 
    double d = b_d;
    Box<Box<int>> bb_i {3} ;
    const Obj& r_3 = bb_i;
    r_3.Draw(); 
    Box<int> br_i = bb_i;
    Box<Box<double>> bb_d {3.4} ; 
    const Obj& r_4 = bb_d;
    r_4.Draw();
    Box<double> b_a = bb_d;

 Box<int> _ = 3; //Odkomentowanie powoduje b��d kompilacji

}
// struct Box<int>::Draw() --> 3
// struct Box<double>::Draw() --> 3.4
// struct Box<Box<int>>::Draw() --> 3
// struct Box<Box<double>>::Draw() --> 3.4