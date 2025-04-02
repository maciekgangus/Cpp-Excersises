#include <iostream>
#include <vector>


void add2(int& elem)
{
    elem += 2;
}

struct liftToVector
{
    liftToVector(std::function<void(int&)> fun): function(fun){}

    std::vector<int> operator()(std::vector<int>& vec)
    {
        for(auto &elemm: vec)
        {
            function(elemm);
        }
        return vec;
    }

    std::function<void(int&)> function;
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