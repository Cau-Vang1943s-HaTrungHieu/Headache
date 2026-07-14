#include <iostream>
#include <stack>
#include <string>

bool is_balanced(std::string& expr)
{
    std::stack<char> stack;
    for (char character : expr)
    {
        if (character == '(' or character == '[' or character == '{')
        {
            stack.push(character);
        }
        else if (character == ')' or character == ']' or character == '}')
        {
            if (stack.empty()) return false;
            char top_item = stack.top();
            if ((character == ')' and top_item != '(') or
                (character == ']' and top_item != '[') or
                (character == '}' and top_item != '{'))
                return false;
            stack.pop();
        }
    }
    return stack.empty();
}

int main()
{
    std::stack<char> stack;
    std::string s;
    std::getline(std::cin, s);
    std::cout << (is_balanced(s) ? "Balanced" : "Not Balanced") << std::endl;
}