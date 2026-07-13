#include <iostream>
#include <fstream>
#include <cmath>

bool is_perfect_sqr(int n)
{
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

int main()
{
    int n;
    std::ifstream fin("FSTREAM.inp");
    if (!fin.is_open())
    {
        std::cout << "Cannot open file." << std::endl;
        return -1;
    }
    std::ofstream fout("FSTREAM.out");
    fin >> n;
    fout << (is_perfect_sqr(n) ? "YES" : "NO");

    fin.close();
    fout.close();
    return 0;
}