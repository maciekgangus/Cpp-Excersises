#include <iostream>
#include <list>
#include <functional>


bool f1(int elem)
{
    return 1;
}


bool f2(int elem)
{
    if(!(elem%2))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

template<typename T>
void print_to_if(std::ostream& os, T begin, T end, std::function<bool(int)> func)
{
    for(auto it = begin; it!=end; it++)
    {
        if(func(*it))
        {
            os<<(*it)<<" ";
        }
    }

    os<<"\n";
}

struct f3
{
    f3(int a): add_value(a){}

    void operator()(int& elem)
    {
        elem += add_value;
    }

    int add_value;
};

template<typename T>
void change(T begin, T end, f3 other)
{
    for(auto it = begin; it!=end; it++)
    {
        other(*it);
    }
}

int main(){
    const auto cl = {1,2,3,4,5,6,7};

    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f1);
    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f2);

    int add_value{-1};
    std::list<int> cl2 = {7,6,5,4,3,2,1};
    change(begin(cl2), end(cl2), f3{add_value});
    print_to_if(std::cout << "All: ", begin(cl2), end(cl2), f1);
}
/*
All: 1 2 3 4 5 6 7 
All: 2 4 6 
All  6 5 4 3 2 1 0 
*/