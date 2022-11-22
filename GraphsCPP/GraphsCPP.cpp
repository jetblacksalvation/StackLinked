// GraphsCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//linked list stack type.
#include <iostream>

#include "StackList.hpp"


int main()
{
    StackList<int> bruh({10,1,5});
    bruh.PrintStack();
    bruh[3] = 25;
    std::cout<<bruh[3];
    std::cout << "Hello World!\n";
}
