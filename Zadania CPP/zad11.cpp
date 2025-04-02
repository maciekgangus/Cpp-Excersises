/*

1. słowo kluczowa mutable + podać przykład kodu
2. klasa abstrakcyjna
3. STL - uzupełnij kod

*/
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>




struct A
{
    void operator()(int& a)
    {
        a = it;
        it--;
    }
    int it = -1;
};




int main() {
	std::list<int> coll(11);
	std::for_each( std::begin(coll), std::end(coll), A());
	std::copy( coll.begin(), coll.end(), std::ostream_iterator<int>(std::cout,"; "));
	return 0;
}
//to ma się wyświetlić:
// -1; -2; -3; -4; -5; -6; -7; -8; -9; -10; -11;