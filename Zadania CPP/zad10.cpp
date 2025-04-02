#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

void add2(int &a)
{
    a+=2;
}

template<typename T>
struct liftToVector
{
    liftToVector(T a)
    {
        func = a;
    }
    std::vector<int> operator()(std::vector<int> &a)
    {
        for(auto &it: a)
        {
            func(it);
        }
        return a;
    }
    T func;
};



int main()
{
    auto vadd2 = liftToVector(add2);
    std::vector<int> x = {0,9,4};
    auto v = vadd2(x);

    std::for_each(v.begin(), v.end(), [](const int n) {std::cout<< n << ' ';});

    return 0;
}

// 2 11 6