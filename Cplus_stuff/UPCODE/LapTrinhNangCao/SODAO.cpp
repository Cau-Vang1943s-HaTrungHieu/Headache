#include <iostream>

struct SoDao
{
    int num;

    friend std::istream& operator >> (std::istream& input, SoDao& sd)
    {
        input >> sd.num;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const SoDao sd)
    {
        output << "[SoDao] " << sd.num;
        return output;
    }

    int reversed_num()
    {
        int result = 0;
        int temp = num;
        while (temp != 0)
        {
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        return result;
    }

    bool operator > (SoDao other)
    {
        return reversed_num() > other.reversed_num();
    }

    int operator + (int n)
    {
        return reversed_num() + n;
    }
};

int main()
{
    SoDao sd1, sd2;
    std::cin >> sd1 >> sd2;

    std::cout << sd1 << std::endl;
    std::cout << sd2 << std::endl;
    std::cout << (sd1 > sd2 ? "YES" : "NO") << std::endl;
    std::cout << sd1 + sd2.reversed_num() << std::endl;

    return 0;
}