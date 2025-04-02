#include<iostream>
#include<array>
#include<string>


void my_print_el(std::string a)
{
    std::cout<<a;
}

template<typename T>
void my_print(T& array, std::string a=";", std::string b= "\n")
{
    std::cout<<"[";
    for(auto it = std::begin(array); it != std::end(array); it++)
    {
        std::cout<<**it<<a;
    }
    std::cout<<"] "<<b;
}






template<typename T>
void my_swap(T& a, T& b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    
}

template<>
void my_swap<int>(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}




int main()
{
  std::array<std::unique_ptr<int>,2> a = {
      std::unique_ptr<int>(new int {1}),
      std::unique_ptr<int>(new int {2})
      };

  my_print_el("----------------\n");
  my_print(a,";"," -> ");
  my_swap(a[0],a[1]);
  my_print(a,";"," -> ");
  my_swap(*a[0],*a[1]);
  my_print(a);
  my_print_el("----------------");
}
//[1;2;] -> [2;1;] -> [1;2;]