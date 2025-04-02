#include <iostream>
#include <list>


template<typename T>
void print_to_if(std::ostream& os, T begin, T end, std::function<int(int)> fun)
{
    for(auto it = begin; it!=end; it++)
    {
        os<<fun(*it);
    }
    std::cout<<"\n";
}

int f1(int item)
{
    return item;
}

int f2(int item)
{
    if(item % 2)
    {
        return item;
    }
}

struct f3
{
    int add;
    f3(int value) : add(value){}
    void operator()(int& value)
    {
        value += add;
    }
};


template<typename T>
void change(T begin, T end, f3 object)
{
    for(auto it = begin; it!=end; it++)
    {
        object(*it);
    }
    
}



int main(){
    const auto cl = {1,2,3,4,5,6,7};

    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f1);
    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f2);

    int add_value{-1};
    std::list<int> cl2 = {7,6,5,4,3,2,1};
    change(begin(cl2), end(cl2), f3{add_value});
    print_to_if(std::cout << "All:  ", begin(cl2), end(cl2), f1);
}
/*
All: 1 2 3 4 5 6 7 
All: 2 4 6 
All  6 5 4 3 2 1 0 
*/