#include <iostream>
using namespace std;

#pragma once
class ArraySizeException : public std::exception
{
public:
    const char* what();
    
};