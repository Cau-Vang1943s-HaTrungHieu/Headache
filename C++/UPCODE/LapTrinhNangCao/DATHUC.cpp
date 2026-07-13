#include <iostream>

struct BacNhat
{
    int a, b;
    
    friend std::istream& operator >> (std::istream& input, BacNhat& poly)
    {
        input >> poly.a >> poly.b;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const BacNhat& poly)
    {
        output << poly.a << "x+" << poly.b;
        return output;
    }

    int evaluation(int x)
    {
        return a * x + b;
    }

    BacNhat operator + (BacNhat other)
    {
        BacNhat result;
        result.a = a + other.a;
        result.b = b + other.b;
        return result;
    }

    bool operator == (BacNhat other)
    {
        return (a + b == other.a + other.b);
    }
};

int main()
{
    BacNhat F1, F2;
    int x;
    std::cin >> F1 >> F2 >> x;

    std::cout << F1 << std::endl;
    std::cout << F2 << std::endl;
    std::cout << F1 << "+" << F2 << "=" << F1 + F2 << std::endl;
    std::cout << F1.evaluation(x) << std::endl;
    std::cout << F2.evaluation(x) << std::endl;
    std::cout << (F1 == F2 ? "TRUE" : "FALSE") << std::endl;

    return 0;
}