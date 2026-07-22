#include <iostream>
#include <string>

void generate(std::string& binary, int pos, int n)
{
    if (pos == n)
    {
        std::cout << binary << '\n';
        return;
    }

    binary[pos] = '0';
    generate(binary, pos + 1, n);

    binary[pos] = '1';
    generate(binary, pos + 1, n);
}

int main()
{
    int n; std::cin >> n;
    std::string binary(n, '0');
    generate(binary, 0, n);

    return 0;
}