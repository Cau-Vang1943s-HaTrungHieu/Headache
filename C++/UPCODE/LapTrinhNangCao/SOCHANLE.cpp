#include <iostream>
#include <string>

struct Number
{
    int value;

    friend std::istream& operator>>(std::istream& input, Number& n)
    {
        input >> n.value;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Number n)
    {
        output << n.even_position();
        return output;
    }

    int odd_position()
    {
        std::string s_value = std::to_string(value);
        int result = 0;

        for (int i = 1; i < s_value.length(); i += 2)
        {
            result = result * 10 + (s_value[i] - '0'); 
        }
        return result;
        /*
            Wanna see something interesting?
            Because the ASCII codes for digits are consecutive
            '0' 48
            '1' 49
            '2' 50
            '3' 51
            '4' 52
            '5' 53
            '6' 54
            '7' 55
            '8' 56
            '9' 57
            Substracting the 0 character shifts the whole range down to
            0
            1
            2
            3
            4
            5
            6
            7
            8
            9
        */
    }

    int even_position()
    {
        std::string s_val = std::to_string(value);
        int result = 0;
        
        for (int i = 0; i < s_val.length(); i += 2)
        {
            result = result * 10 + (s_val[i] - '0');
        }
        return result;
    }

    bool operator<(Number other)
    {
        return even_position() < other.even_position();
    }

    int components_sum(int choice = 0)
    {
        int components;
        if (choice == 0) components = even_position();
        if (choice == 1) components = odd_position();
        int result = 0;
        while (components > 0)
        {
            int digit = components % 10;
            result += digit;
            components /= 10;
        }
        return result;
    }
};

int main()
{
    Number a, b;
    int choice;
    std::cin >> a >> b >> choice;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << (a < b ? "true" : "false") << std::endl;
    std::cout << a.components_sum(choice) << std::endl;
    std::cout << b.components_sum(choice) << std::endl;

    return 0;
}