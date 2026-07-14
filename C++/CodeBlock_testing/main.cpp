#include <iostream>
#include <vector>
#include <stack>

int largest_rectangle_area(std::vector<int>& heights)
{
    std::stack<int> stack;
    int max_area = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++)
    {
        int h = (i == n ? 0 : heights[i]);
        while (!stack.empty() and h < heights[stack.top()])
        {
            int height = heights[stack.top()];
            stack.pop();
            int width = stack.empty() ? i: i - stack.top() - 1;
            max_area = std::max(max_area, height * width);
        }
        stack.push(i);
    }
    return max_area;
}

int main()
{
    int tmp;
    std::vector<int> heights;
    while (std::cin >> tmp) heights.push_back(tmp);
    std::cout << largest_rectangle_area(heights) << std::endl;
    return 0;
}
