#include <iostream>
#include <string>

void generate(std::string current, int n)
{
    if (current.length() == n)
    {
        std::cout << current << '\n';
        return;
    }

    generate(current + "0", n);
    generate(current + "1", n);
}

int main()
{
    int n; std::cin >> n;

    generate("", n);

    return 0;
}