#include <iostream>

struct Polynomial
{
    int a, b;

    friend std::istream& operator >> (std::istream& input, Polynomial& expression)
    {
        input >> expression.a >> expression.b;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Polynomial expression)
    {
        output << expression.a << "x+" << expression.b;
        return output;
    }

    int evaluation(int x)
    {
        return a*x + b;
    }

    Polynomial operator + (Polynomial& other)
    {
        Polynomial result;
        result.a = a + other.a;
        result.b = b + other.b;
        return result;
    }

    bool operator == (Polynomial& other)
    {
        return (a + b) == (other.a + other.b);
    }
};

int main()
{
    Polynomial f1, f2; std::cin >> f1 >> f2;
    int x; std::cin >> x;
    
    std::cout << f1 << std::endl << f2 << std::endl;
    std::cout << f1 << "+" << f2 << "=" << f1 + f2 << std::endl;
    std::cout << f1.evaluation(x) << std::endl;
    std::cout << f2.evaluation(x) << std::endl;
    std::cout << (f1 == f2 ? "TRUE" : "FALSE") << std::endl;
    return 0;
}