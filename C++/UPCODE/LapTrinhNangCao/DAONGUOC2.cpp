#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int reversed_value(std::string& text)
{
    std::string reversed = text;
    std::reverse(reversed.begin(), reversed.end());
    return stoi(reversed);
}

int main()
{
    std::ofstream fout("outDaoNguoc2.txt");
    std::ifstream fin("inDaoNguoc2.txt");

    std::vector<std::string> numbers;
    std::string input;
    while (fin >> input) numbers.push_back(input);

    // Find the greatest reversed
    int max_val = reversed_value(numbers[0]);
    std::string max_num = numbers[0];

    for (size_t i = 1; i < numbers.size(); i++)
    {
        int val = reversed_value(numbers[i]);
        if (val > max_val)
        {
            max_val = val;
            max_num = numbers[i];
        }
    }
    
    // Write the greatest reversed into the output file 
    fout << max_num << "\n";

    // Find any instances of the greatest reversed
    std::vector<int> positions;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (reversed_value(numbers[i]) == max_val) positions.push_back(i);
    }

    if (positions.size() > 1)
    {
        for (size_t i = 0; i < positions.size(); i++)
        {
            fout << positions[i];
            if (i + 1 < positions.size()) fout << " ";
        }
        fout << "\n";
    }

    return 0;
}