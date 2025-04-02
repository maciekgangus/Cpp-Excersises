#include <type_traits> // Dla std::is_pod i std::integral_constant 
#include <iostream>
#include <deque>
#include <vector>


template <typename T, typename U>
void my_copy(T begin, T end, U destination){
    if(std::is_pod<typename T::value_type>::value){
        std::cout << "Copying POD objects\n"; 
    }else {
        std::cout << "Copying non-POD objects\n";
    }
}

struct A 
{

};


struct A_ 
{ 
    virtual ~A_ () {}; 
};




int main ()
{
    //prosze wykorzystac te informacje
    std::integral_constant<bool, true> tA = std::is_pod<A>::type ();
    std::integral_constant<bool, false> tA_ = std::is_pod<A_>::type ();

    //Iterator dla każdego kontenera ma zdefiniowany 
    //typ value_type określający typ obiektu na który wskazuje

    std::deque<A> vA1;
    std::vector<A> vA2;
    my_copy ( vA1.begin (), vA1.end (), vA2.begin () );

    std::vector <A_> vA_1;
    std::deque<A_> vA_2;
    my_copy ( vA_1.begin (), vA_1.end (), vA_2.begin () );
}


/* output/wyjscie
Copying POD objects
Copying non-POD objects
*/
