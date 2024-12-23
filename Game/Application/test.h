// Log.h
#ifndef LOG_H // Include guard
#define LOG_H

#include <iostream>
#include <string>

namespace Test
{
    // Base case for print function (single argument)
    template<typename T>
    void print(T t)
    {
        std::cout << t;
    }

    // Recursive case for print function (multiple arguments)
    template<typename T, typename... Args>
    void print(T t, Args... args)
    {
        std::cout << t; // Print the first argument
        print(args...); // Recursively print the remaining arguments
    }

    template<typename... Args>
    void error(const std::string& error, Args... args) // ERROR PRINT
    {
        std::cout << "\033[31m[ERROR] " << error; // Print the error message
        print(args...); // Call the print function with the unpacked arguments
        std::cout << "\033[0m" << std::endl; // Reset color
    }
}

#endif // LOG_H