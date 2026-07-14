#include <iostream>
#include <stack>
#include <vector>

std::vector<int> next_greater_element(std::vector<int>& arr)
{
    std::stack<int> stack;
    std::vector<int> result(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stack.empty() and stack.top() <= arr[i]) stack.pop();
        result[i] = stack.empty() ? -1 : stack.top();
        stack.push(arr[i]);
    }
    return result;
}

int main()
{
    std::stack<int> stack;
    std::vector<int> arr;
    int tmp;
    while (std::cin >> tmp) arr.push_back(tmp);

    auto result = next_greater_element(arr);

    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;


    return 0;
}