#include "Array.hpp"

int main()
{
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); ++i)
        intArray[i] = i * 10;

    for (unsigned int i = 0; i < intArray.size(); ++i)
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

    try
    {
        std::cout << "intArray[10] = " << intArray[10] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";

    for (unsigned int i = 0; i < strArray.size(); ++i)
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;

    return (0);
}