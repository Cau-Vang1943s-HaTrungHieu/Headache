#include <iostream>
#include <sstream>
#include <stack>

int evaluate_postfix(std::string& expr)
{
    std::stack<int> stack;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token)
    {
        if (isdigit(token[0])) stack.push(std::stoi(token));
        else
        {
            int first_operand = stack.top(); stack.pop();
            int second_operand = stack.top(); stack.pop();
            switch (token[0])
            {
                case '+': stack.push(first_operand + second_operand); break;
                case '-': stack.push(first_operand - second_operand); break;
                case '*': stack.push(first_operand * second_operand); break;
                case '/': stack.push(first_operand / second_operand); break;
            }
        }
    }
    return stack.top();
}

int main()
{
    std::string expr;
    std::getline(std::cin, expr);

    std::cout << evaluate_postfix(expr) << std::endl;

    return 0;
}