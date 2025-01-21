#pragma once

#include "iostream"

template <class T>
int compare(T obj1, T obj2)
{
    if (obj1 == obj2)
    {
        return 0;
    }
	return obj1 > obj2 ? -1 : 1;
}

template <class T>
void bubbleSort(T objArr[], int size)
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (objArr[j] > objArr[j + 1])
            {
                T temp = objArr[j];
                objArr[j] = objArr[j + 1];
                objArr[j + 1] = temp;
            }
        }
    }
}

template <class T>
void printArray(T objArr[], int size)
{
    for (int i = 0; i < size;i++)
    {
        std::cout << objArr[i] << std:: endl;
    }
}