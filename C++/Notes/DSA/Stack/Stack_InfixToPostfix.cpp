#include <iostream>
#include <stack>
#include <string>

int precedence(char operat0r)
{
    switch (operat0r)
    {
        case '+': 
        case '-': 
            return 1;
        case '*': 
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default: 
            return 0;
    }
}

bool is_operand(char character)
{
    return std::isalnum(character);
}

std::string infix_to_postfix(std::string& infix)
{
    std::stack<char> operators;
    std::string postfix;

    for (char symbol : infix)
    {
        if (is_operand(symbol)) postfix += symbol; // Operands go directly into postfix
        else if (symbol == '(') operators.push(symbol);
        else if (symbol == ')')
        {
            while (operators.top() != '(') // See '(' isn't included in the stack
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Discard '('
        }
        else // Second popping rule
        {
            while (!operators.empty() 
                    and operators.top() != '('
                    and precedence(operators.top()) >= precedence(symbol))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(symbol);
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main()
{
    std::string infix;
    
    std::cout << "Expression: ";
    std::cin >> infix;
    std::cout << "Postfix: " << infix_to_postfix(infix) << std::endl;

    return 0;
}