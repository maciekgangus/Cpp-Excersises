#include<iostream>
#include<array>
#include<string>


void my_print_el(std::string a)
{
    std::cout<<a;
}

void my_print(std::array<std::unique_ptr<int>,2>& a, std::string b = ";", std::string c = "\n")
{
    std::cout<<'['<<*a[0]<<b<<*a[1]<<']'<<c;
}

void my_swap(std::unique_ptr<int> &a, std::unique_ptr<int> &b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void my_swap(int &a, int &b)
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