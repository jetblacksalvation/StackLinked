// GraphsCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//linked list stack type.
#include <iostream>

#include "StackList.hpp"


int main()
{
    StackList<int> bruh({10,1,5});
    bruh.PrintStack();
    //std::cout<<bruh[3];
    bruh.PushEnd(11);
    std::cout << "-----------\n";

    bruh.RemoveElem(2);
    std::cout << "-----------\n";

    bruh.PrintStack();
    // std::cout << "Hello World!\n";
}
