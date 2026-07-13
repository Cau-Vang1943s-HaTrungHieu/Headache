#include <iostream>
#include <fstream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    std::ofstream fout("out.txt");
    fout << a + b;
    
    fout.close();
    return 0;
}