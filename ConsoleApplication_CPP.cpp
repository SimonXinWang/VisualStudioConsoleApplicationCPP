// ConsoleApplication_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool simulate(bool input1, bool input2, bool input3, bool input4)
{
    bool interm_result = false;
    interm_result = input2 && input3;
    interm_result = interm_result || input4;
    interm_result = interm_result && input1;

    return interm_result;
}

int main()
{
    std::cout << "1:" << simulate(true, false,  false, true) << std::endl;
    std::cout << "2:" << simulate(true, false, false, false) << std::endl;
    std::cout << "3:" << simulate(false, false, false, false) << std::endl;
}
