#include <iostream>
#include <cmath>
#include <iomanip>

struct Complex
{
    double a, b;

    friend std::istream& operator>>(std::istream& input, Complex& cmplx)
    {
        input >> cmplx.a >> cmplx.b;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Complex cmplx)
    {
        output << "{";
        if (cmplx.a != 0) output << cmplx.a;

        if (cmplx.b != 0)
        {
            if (cmplx.b > 0 and cmplx.a != 0) output << "+";
            if (cmplx.b < 0) output << "-";
            if (std::abs(cmplx.b) != 1) output << std::abs(cmplx.b);
            output << "i";
        }
        output << "}";
        return output;
    }

    Complex operator+(const Complex& other) const
    {
        Complex result;
        result.a = a + other.a;
        result.b = b + other.b;
        return result;
    }

    Complex operator-(const Complex& other) const
    {
        Complex result;
        result.a = a - other.a;
        result.b = b - other.b;
        return result;
    }

    double cmplx_modulus() const
    {
        return std::sqrt(a * a + b * b);
    }
};

struct ComplexArray
{
    int size = 0;
    Complex* values;

    friend std::istream& operator>>(std::istream& input, ComplexArray& arr)
    {
        arr.values = new Complex[100];
        while (input >> arr.values[arr.size]) arr.size++;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, ComplexArray arr)
    {
        for (int i = 0; i < arr.size; i++)
        {
            output << arr.values[i] << " ";
        }
        return output;
    }

    Complex sum()
    {
        Complex result{0, 0};
        for (int i = 0; i < size; i++)
        {
            result = result + values[i];
        }
        return result;
    }

    Complex difference()
    {
        Complex result{0, 0};
        for (int i = 0; i < size; i++)
        {
            result = result - values[i];
        }
        return result;
    }
};

int main()
{
    ComplexArray arr;
    std::cin >> arr;

    std::cout << arr << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < arr.size; i++)
    {
        std::cout << arr.values[i].cmplx_modulus() << " ";
    }
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(0);

    std::cout << arr.sum() << std::endl;

    return 0;
}
