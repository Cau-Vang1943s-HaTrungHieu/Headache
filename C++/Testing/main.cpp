#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool compare(const std::string& a, const std::string& b)
{
    return a + b > b + a;
}

int main()
{
    std::ifstream fin("CONNECT.INP");
    std::ofstream fout("CONNECT.OUT");
    int capacity; fin >> capacity;
    std::string connectors[100];

    for (int i = 0; i < capacity; i++)
    {
        fin >> connectors[i];
    }

    std::sort(connectors, connectors + capacity, compare);

    std::string result = "";

    for (int i = 0; i < capacity; i++)
    {
        result += connectors[i];
    }

    fout << result;

    return 0;
}