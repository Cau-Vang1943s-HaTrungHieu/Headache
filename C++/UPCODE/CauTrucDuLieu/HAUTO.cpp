#include <iostream>
#include <sstream>
#include <string>

const int MAX = 100;

struct Stack
{
    int data[MAX];
    int top_index;

    // Initialize
    void init()
    {
        top_index = -1;
        /*
            When stack is first initialized, it is empty, and that
            emptiness is the value -1 itself.
        */
    }

    bool empty()
    {
        return top_index == -1; // Again why -1
    }

    bool full()
    {
        return top_index == MAX - 1;
    }

    void push(int x)
    {
        if (!full()) data[++top_index] = x;
    }

    int top()
    {
        return data[top_index];
    }

    void pop()
    {
        if (!empty()) top_index--;
    }
};

int postfix_evaluation(std::string expr)
{
    Stack stack;
    stack.init();

    std::stringstream ss(expr);
    std::string token;

    while (ss >> token)
    {
        if (isdigit(token[0])) stack.push(std::stoi(token));
        else // if character  isn't didgit then it must be operator
        {
            int second_operand = stack.top(); stack.pop();
            int first_operand = stack.top(); stack.pop();
            int result;
            switch (token[0])
            {
                case '+': result = first_operand + second_operand; break;
                case '-': result = first_operand - second_operand; break;
                case '*': result = first_operand * second_operand; break;
            }
            stack.push(result);
        }
    }
    return stack.top();
}

int main()
{
    std::string expr;
    std::getline(std::cin, expr);
    std::cout << postfix_evaluation(expr) << std::endl;

    return 0;
}