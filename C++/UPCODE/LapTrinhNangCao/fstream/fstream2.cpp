#include <iostream>
#include <fstream>

int main()
{
    int a, b;
    std::ofstream fout("output.txt");
    std::ifstream fin("input.txt");

    fin >> a >> b;
    fout << a + b;

    fout.close(); fin.close();

    return 0;
}