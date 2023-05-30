#include <iostream>
#include <string>
#include "MyArray.h"
#include "ArraySizeException.h"

int main()
{
    cout << "LR#5 VAR 2" << endl << endl;

    try
    {
        MyArray* arr = new MyArray(new double[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, 10);
    }
    catch (ArraySizeException e)
    {
        cout << "Catched error: " << e.what() << endl;
    }

    try
    {
        MyArray* arr = new MyArray(new double[12] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 12);

        arr->getBetweenMaxMinProduct();
    }
    catch (std::string e)
    {
        cout << "Catched error: " << e << endl;
    }
    
    cout << endl;

    try
    {
        MyArray* arr = new MyArray(new double[12] {1, 2, 3, 4, 12, 5, 0.5, 6, 11, -23.5, 9, 10}, 12);

        cout << "Array: " << arr->getArrayStr() << endl;
        cout << "Positive elements sum: " << arr->getPositiveElementsSum() << endl;
        cout << "Product of elements situated between absolute max and min: " << arr->getBetweenMaxMinProduct() << endl;
    }
    catch (...)
    {
        cout << "Catched error" << endl;
    }

    return 0;
}