#include <iostream>
#include <string>
#include "MyArray.h"
#include "ArraySizeException.h"

#define ARRAY_SIZE 12

int main()
{
    cout << "LR#5 VAR 2" << endl << endl;

    try
    {
        cout << "MyArray defined size: " << ARRAY_SIZE << ". Size of creating array: " << 10 << endl;

        MyArray* arr = new MyArray(new double[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, 10);

        delete arr;
    }
    catch (ArraySizeException e)
    {
        cout << "Catched error: " << e.what() << endl;
    }

    cout << endl;

    try
    {
        const int length = 12;

        double* sourceArray = new double[12] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        cout << "Source array: ";

        for (int i = 0; i < length; i++)
        {
            if (i > 0)
            {
                cout << ", ";
            }

            cout << sourceArray[i];
        }

        cout << endl;

        MyArray* arr = new MyArray(sourceArray, length);

        arr->getBetweenMaxMinProduct();

        delete arr;
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

        delete arr;
    }
    catch (...)
    {
        cout << "Catched error" << endl;
    }

    return 0;
}