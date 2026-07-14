#include <iostream>
#include <stack>
#include <string>

bool is_balanced(std::string& expr)
{
    std::stack<char> stack;
    for (char character : expr)
    {
        if (character == '(') stack.push(character);
        else if (character == ')')
        {
            if (stack.empty()) return false; // too many braces
            stack.pop();
        }
    }
    return stack.empty();
}

int main()
{
    std::string expr;
    std::getline(std::cin, expr);

    if (is_balanced(expr)) std::cout << "Balanced\n";
    else std::cout << "Not balanced\n";

    return 0;
}