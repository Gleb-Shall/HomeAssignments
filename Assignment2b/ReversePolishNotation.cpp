/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 2b
*/


#include "ReversePolishNotation.h"


float MathematicalOperation(const float &number1, const float &number2, const std::string &oper)
{
    // determines which operation sign was entered and returns the result of this operation on the two numbers from the top of the stack
    if (oper == "+")
    {
        return number1 + number2;
    }
    if (oper == "-")
    {
        return number1 - number2;
    }
    if (oper == "*")
    {
        return number1 * number2;
    }
    if (oper == "/")
    {
        return number1 / number2;
    }
    return 0;
}


void ReversePolishNotation()
{
    float *stack = new float[100];	// stack declaration (length fixed)
    float *top = stack; 		// pointer to the top of the stack
    std::string temp = " ";
    std::string operations = "+-*/";
    std::cout << "Enter a valid reverse polish notation expression. To get the result, enter '='" << "\n";

    std::cin >> temp;			// I save the first number manually, the rest are processed inside the loop
    *top = stoi(temp);			// changing the value by working with the pointer

    while (true)
    {
        std::cin >> temp;
        if (temp == "=")
        {
            break;
        }
        if (operations.find(temp) == std::string::npos)	// if the line "+-*/" does NOT contain the inclusion of the entered line
        {
            top++;
            *top = stoi(temp);		// keep the number on the top of the stack
        }
        else
        {
            float operand2 = *top;	//  otherwise we read the top two values ​​from the stack
            float operand1 = *(top - 1);
            *(top-1) = MathematicalOperation(operand1, operand2, temp);	// and apply the resulting operation to them. now the received value is the top of the stack
            top--;
        }
    }
    std::cout << *top << '\n';		// the value remaining on the top of the stack after all operations is the result
    delete [] stack;
}
