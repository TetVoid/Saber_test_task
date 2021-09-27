
#include <iostream>

int* intToByte(int number)
{
    bool negativeFlag = false;
    if (number < 0)
    {
        number *= -1;
        negativeFlag = true;
    }
    number++;
    int countOfBit = ceil(log2(number))+1;
    number--;


    int* byteNumber = new int[countOfBit];

    if (negativeFlag)
        byteNumber[0] = 1;
    else
        byteNumber[0] = 0;

    for (int i = countOfBit-1; i > 0; i--)
    {
        byteNumber[i] = number % 2;
        number /= 2;
    }

    for (int i = 0; i < countOfBit; i++)
        std::cout << byteNumber[i];

    return  byteNumber;
}

int main()
{
    intToByte(999);
}