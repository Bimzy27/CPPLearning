// TextBasedCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

class Calculator
{
public:
    float Calculate(string input)
    {
        set<char> operands = {'+', '-', '*', '/'};
        queue<string> equation;

        //Create equation from string
        std::string curNum = "";
        while (input.length() > 0)
        {
            char c = input[0];
            input.erase(input.begin());

            if (isdigit(c) || c == '.')
            {
                curNum += c;
            }
            else if (operands.find(c) != operands.end())
            {
                equation.push(curNum);
                string str(1, c);
                equation.push(str);
                curNum = "";
            }
        }
        if (curNum != "")
        {
            equation.push(curNum);
        }

        float result = 0.0f;
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
                float f = stof(equation.front());
                if (op == '+')
                {
                    result = result + f;
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
            }

            equation.pop();
        }

        return result;
    }
};

int main()
{
    string input = "input";
    Calculator calcualtor;
    while (true)
    {
        cout << "Type in your equation:\n";
        cin >> input;
        cout << "Your equation equals: " << calcualtor.Calculate(input) << "\n";
    }
    
    return 0;
}