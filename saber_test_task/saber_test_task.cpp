#include <iostream>
#include "List.h"

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

    std::cout << std::endl;
    return  byteNumber;
}

void RemoveDups(char* str)
{
    int index = 0;
    int skip_symbols = 0;
    while (str[index] != '\0')
    {
        if (str[index] == str[index + 1])
            skip_symbols++;
        else
        {
            if(skip_symbols !=0 )
            {
                int index_copy = index;
                while (str[index_copy] != '\0')
                {
                    str[index_copy - skip_symbols] = str[index_copy];
                    index_copy++;
                }
                str[index_copy-skip_symbols] = '\0';
            }
            index -= skip_symbols;
            skip_symbols = 0;
        }

        index++;
    }
}



int main()
{
    intToByte(-16);

    char data[] = "aaaaaaa ggggggjjjjgg hhh";
    RemoveDups(data);
    std::cout <<data;

    List list;
    /*std::string test[] = { "aaaaaa" ,"bbbbbbbb","ccccccc"};
    
    for (std::string data:test)
    {
        list.add(data);
    }*/

    FILE* file;
    fopen_s(&file,"test.txt", "rb");
    list.Deserialize(file);
    fclose(file);
}