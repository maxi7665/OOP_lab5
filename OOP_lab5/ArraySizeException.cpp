#include "ArraySizeException.h"

const char* ArraySizeException::what()
{
    return "Wrong array size!";
}
