#include <sstream>
#include <limits>
#include "MyArray.h"
#include "ArraySizeException.h"

#define ARRAY_SIZE 12

MyArray::MyArray(double* const source, int sourceSize)
{
	this->arraySize = ARRAY_SIZE;
	this->arr = new double[this->arraySize];

	if (sourceSize != this->arraySize)
	{
		throw ArraySizeException();
	}

	for (int i = 0; i < this->arraySize; i++)
	{
		this->arr[i] = source[i];
	}
}

MyArray::~MyArray()
{
	delete[] this->arr;
}

std::string MyArray::getArrayStr() const
{
	std::stringstream ss;

	for (int i = 0; i < this->arraySize; i++)
	{
		if (i != 0)
		{
			ss << " ";
		}

		ss << this->arr[i];
	}

	ss << std::endl;

	return ss.str();
}

double MyArray::getPositiveElementsSum() const
{
	double sum = 0;

	for (int i = 0; i < this->arraySize; i++)
	{
		if (this->arr[i] > 0)
		{
			sum += this->arr[i];
		}
	}

	return sum;
}

double MyArray::getBetweenMaxMinProduct() const
{
	int maxIdx = -1;
	int minIdx = -1;

	double max = std::numeric_limits<double>::min();
	double min = std::numeric_limits<double>::max();

	for (int i = 0; i < this->arraySize; i++)
	{
		if (abs(this->arr[i]) > max)
		{
			max = abs(this->arr[i]);

			maxIdx = i;
		}

		if (abs(this->arr[i]) < min)
		{
			min = abs(this->arr[i]);

			minIdx = i;
		}
	}

	if (maxIdx == minIdx)
	{
		throw std::string("Absolute max/min not found");
	}

	int direction = maxIdx > minIdx ? 1 : -1;

	double product = 1;

	for (int i = minIdx + direction; i != maxIdx; i += direction)
	{
		product *= this->arr[i];
	}
	
	return product;
}
