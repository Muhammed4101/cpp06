#include "Serializer.hpp"
#include <iostream>

int main()
{

    Data myData;
    myData.id = 42;
    myData.name = "Arthur Dent";


    std::cout << "--- ORIGINAL STATE ---" << std::endl;
    std::cout << "Data address : " << &myData << std::endl;
    std::cout << "Data ID      : " << myData.id << std::endl;
    std::cout << "Data Name    : " << myData.name << std::endl;
    std::cout << std::endl;


    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "--- SERIALIZE ---" << std::endl;
    std::cout << "Raw integer value (uintptr_t): " << raw << std::endl;
    std::cout << std::endl;


    Data* ptr = Serializer::deserialize(raw);
    std::cout << "--- DESERIALIZE ---" << std::endl;
    std::cout << "New pointer address          : " << ptr << std::endl;
    std::cout << std::endl;


    std::cout << "--- VERIFICATION TEST ---" << std::endl;
    if (ptr == &myData) {
        std::cout << "[SUCCESS] Original address and new pointer address match perfectly!" << std::endl;
        std::cout << "Accessed Values -> ID: " << ptr->id << ", Name: " << ptr->name << std::endl;
    } else {
        std::cout << "[ERROR] Addresses do not match!" << std::endl;
    }

    return 0;
}