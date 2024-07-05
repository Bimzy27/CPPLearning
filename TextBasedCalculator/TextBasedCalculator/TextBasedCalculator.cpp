// TextBasedCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>
#include <set>

class Calculator
{
public:
    int Calculate(std::string input)
    {
        std::set<char> operands = {'+', '-', '*', '/'};
        std::queue<std::string> equation;

        //Create equation from string
        std::string curNum = "";
        while (input.length() > 0)
        {
            char c = input[0];
            input.erase(input.begin());

            if (isdigit(c))
            {
                curNum += c;
            }
            else if (operands.find(c) != operands.end())
            {
                equation.push(curNum);
                std::string str(1, c);
                equation.push(str);
                curNum = "";
            }
        }

        float result = 0;
        char op = '+';

        //Calculate equation
        while (!equation.empty())
        {
            if (operands.find(equation.front()[0]) != operands.end()) // is operator character
            {
                op = equation.front()[0];
            }
            else
            {
                float f = std::stof(equation.front());
                if (op == '+')
                {
                    result += f;
                }
                else if (op == '-')
                {
                    result -= f;
                }
                else if (op == '*')
                {
                    result *= f;
                }
                else if (op == '/')
                {
                    result /= f;
                }

                std::cout << "result: " << result << " op: " << op << "\n";
            }

            equation.pop();
        }

        return result;
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