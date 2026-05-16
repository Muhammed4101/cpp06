#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base::~Base() {}

Base* generate(void)
{
    int random = std::rand() % 3;

    if (random == 0)
    {
        std::cout << "[Generator] Instantiated: A" << std::endl;
        return new A();
    }
    else if (random == 1) {
        std::cout << "[Generator] Instantiated: B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "[Generator] Instantiated: C" << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) 
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) 
        std::cout << "C" << std::endl;
    else 
        std::cout << "Unknown type" << std::endl;

}

void identify(Base& p)
{    
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception& e) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception& e) {}
    
    std::cout << "Unknown type" << std::endl;
}