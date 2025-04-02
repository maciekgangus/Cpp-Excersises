#include <iostream>
#include <memory>
#include <string>

void my_print_el(std::string napis)
{
    std::cout<<napis;
}


void my_print(std::array<std::unique_ptr<int>,2>& tablica, std::string napis = ";", std::string strzala = "\n")
{
    std::cout<<"["<<*tablica[0]<<napis<<*tablica[1]<<napis<<"]"<<strzala;
}

template<typename T>
void my_swap(T& a, T& b)
{
    
    
    std::swap(a,b);
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