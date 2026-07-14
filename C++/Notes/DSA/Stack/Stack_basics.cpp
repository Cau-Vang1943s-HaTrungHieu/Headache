#include <iostream>
#include <stack> // Remember to include stack library

int main()
{
    std::stack<int> stack; // Stack is also a part of standard library
    stack.push(5);
    stack.push(2);
    stack.push(3);
    std::cout << stack.top() << std::endl;
    stack.pop();
    std::cout << stack.top() << std::endl;
    
    while (!stack.empty()) stack.pop();

    if (stack.empty()) std::cout << "Stack is empty!" << std::endl;

    return 0;
}