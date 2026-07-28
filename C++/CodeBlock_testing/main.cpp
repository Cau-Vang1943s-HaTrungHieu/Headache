#include <iostream>

struct Complex
{
    int real;
    int img;

    friend std::istream& operator>>(std::istream& input, Complex& cmplx)
    {
        input >> cmplx.real >> cmplx.img;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Complex cmplx)
    {
        if (cmplx.real != 0) output << cmplx.real;

        if (cmplx.img != 0)
        {
            if (cmplx.img > 0 and cmplx.real != 0) output << "+";
            if (cmplx.img < 0) output << "-";
            output << std::abs(cmplx.img) << "*i";
        }

        return output;
    }

    Complex operator+(const Complex& other) const
    {
        Complex result;
        result.real = real + other.real;
        result.img = img + other.img;
        return result;
    }

    Complex operator-(const Complex& other) const
    {
        Complex result;
        result.real = real - other.real;
        result.img = img - other.img;
        return result;
    }

    Complex operator*(const Complex& other) const
    {
        Complex result;
        result.real = real * other.real - img * other.img;
        result.img = real * other.img + img * other.real;
        return result;
    }

    bool operator<(const Complex& other) const
    {
        if (real != other.real) return real < other.real;
        return img < other.img;
    }
};

int main()
{
    int n; std::cin >> n;
    Complex cmplx_arr[100];

    for (int i = 0; i < n; i++)
    {
        std::cin >> cmplx_arr[i];
    }

    Complex max_cmplx = cmplx_arr[0], min_cmplx = cmplx_arr[0];
    Complex sum = cmplx_arr[0], product = cmplx_arr[0];

    for (int i = 1; i < n; i++)
    {
        if (max_cmplx < cmplx_arr[i]) max_cmplx = cmplx_arr[i];
        if (cmplx_arr[i] < min_cmplx) min_cmplx = cmplx_arr[i];
        sum = sum + cmplx_arr[i];
        product = product * cmplx_arr[i];
    }

    std::cout << max_cmplx << std::endl;
    std::cout << sum << std::endl;
    std::cout << product << std::endl;
    std::cout << max_cmplx - min_cmplx << std::endl;

    return 0;
}
