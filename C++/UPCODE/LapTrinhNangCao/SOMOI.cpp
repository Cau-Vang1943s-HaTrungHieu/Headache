#include <iostream>

struct SoMoi
{
    int A;

    friend std::istream& operator >> (std::istream& input, SoMoi& somoi)
    {
        input >> somoi.A;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, SoMoi somoi)
    {
        output << "[SoMoi] " << somoi.A;
        return output;
    }

    int digitSum()
    {
        int result = 0, temp = A;
        while (temp > 0)
        {
            result += temp % 10;
            temp /= 10;
        }
        return result;
    }

    bool operator > (SoMoi& other)
    {
        return digitSum() > other.digitSum();
    }

    SoMoi operator + (SoMoi& other)
    {
        SoMoi result;
        result.A = digitSum() + other.digitSum();
        return result;
    }
};

int main()
{
    SoMoi so1, so2;
    std::cin >> so1 >> so2;
    std::cout << so1 << std::endl << so2 << std::endl;
    std::cout << (so1 > so2 ? "true" : "false") << std::endl;
    std::cout << so1 + so2 << std::endl;

    return 0;
}
