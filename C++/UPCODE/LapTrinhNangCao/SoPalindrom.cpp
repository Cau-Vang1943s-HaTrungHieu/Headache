#include <iostream>

bool is_palindrome(int num)
{
    int original = num;
    int reversed = 0;

    while (num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main()
{
    int n; std::cin >> n;
    
    while (n--)
    {
        int x;
        std::cin >> x;
        
        if (is_palindrome(x)) std::cout << x << ' ';
    }

    return 0;
}