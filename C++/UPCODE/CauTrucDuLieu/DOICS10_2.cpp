#include <iostream>
#include <stack>

int main()
{
    std::stack<int> stack;
    int tenth; std::cin >> tenth;

    if (tenth == 0)
    {
        std::cout << 0;
        return 0;
    }
    
    while (tenth != 0)
    {
        int remainder = tenth % 2;
        stack.push(remainder);
        tenth /= 2;
    }

    while (!stack.empty())
    {
        std::cout << stack.top(); 
        stack.pop();
    }
    std::cout << std::endl;

    return 0;
}