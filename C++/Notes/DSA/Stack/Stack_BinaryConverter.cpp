#include <iostream>
#include <stack>

int main()
{
    std::stack<int> stack;
    int n; std::cin >> n;

    while (n != 0)
    {
        int remainder = n % 2;
        stack.push(remainder);
        n /= 2;
    }


    while (!stack.empty())
    {
        std::cout << stack.top();
        stack.pop();
    }
    std::cout << std::endl;

    return 0;
}