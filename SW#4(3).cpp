#include <iostream>
#include <initializer_list>

int retOne()
{
    return 1;
}

template<typename T>
T retElem(T value) {
    return value;
}

template<typename T, typename... Args>
T retElem(T first, Args... args) {
    return first * retElem(args...);
}

template<typename q>
bool test(q func, double eq)
{
    return (eq == func) ?  true : false;
}

int main()
{
    /*std::cout << test(retOne(), 1) << " expected 1" << std::endl;
    std::cout << test(retOne(), 2) << " expected 0" << std::endl;
    std::cout << test(retElem(12), 12) << " expected 1" << std::endl;
    std::cout << test(retElem(131, 2, 1, 12), 262) << " expected 0" << std::endl;*/
    std::cout << retElem(2, 3, 5);
}
