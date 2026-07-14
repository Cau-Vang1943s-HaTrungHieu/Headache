#include <iostream>
#include <stack>
#include <sstream>

int main()
{
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    std::string token;
    std::stack<std::string> stack;
    while (ss >> token) stack.push(token);

    while (!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}