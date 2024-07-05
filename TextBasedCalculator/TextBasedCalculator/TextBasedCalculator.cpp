// TextBasedCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class Calculator
{
public:
    int Calculate(std::string input)
    {
        return 69;
    }
};

int main()
{
    std::string input = "input";
    Calculator calcualtor;
    std::cout << "Type in your equation:\n";
    std::cin >> input;
    std::cout << "Your equation equals: " << calcualtor.Calculate(input);
    return 0;
}