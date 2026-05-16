#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "--- TEST 1 ---" << std::endl;
    Base* obj1 = generate();
    std::cout << "Pointer ID : "; identify(obj1);
    std::cout << "Reference ID: "; identify(*obj1);
    delete obj1;
    std::cout << std::endl;

    std::cout << "--- TEST 2 ---" << std::endl;
    Base* obj2 = generate();
    std::cout << "Pointer ID : "; identify(obj2);
    std::cout << "Reference ID: "; identify(*obj2);
    delete obj2;
    std::cout << std::endl;

    std::cout << "--- TEST 3 ---" << std::endl;
    Base* obj3 = generate();
    std::cout << "Pointer ID : "; identify(obj3);
    std::cout << "Reference ID: "; identify(*obj3);
    delete obj3;
    std::cout << std::endl;

    return 0;
}