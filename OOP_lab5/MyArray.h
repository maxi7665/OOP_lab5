#include <string>

#pragma once
class MyArray
{
private:

	double* arr;
	int arraySize;

public:
	MyArray(double* const source, int sourceSize);
	~MyArray();

	std::string getArrayStr() const;

	double getPositiveElementsSum() const;
	double getBetweenMaxMinProduct() const;
};

