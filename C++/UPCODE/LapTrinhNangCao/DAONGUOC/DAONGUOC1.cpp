#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int reversed_value(std::string& s)
{
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    return stoi(reversed);
    /*
        reverse(begin_iterator, end_iterator);
        - begin_iterator: the starting position of the range
        - end_iterator: the position just past the last element of the range.
        - Works on containers (array, vector, string)

        stoi --> string to integer
        stoll --> string to long long
        ...
    */
}

int main()
{
    std::vector<std::string> numbers;
    std::string input;
    
    // Read till eof
    while (std::cin >> input) numbers.push_back(input);

    // Find the reversed number that has greatest value
    std::string max_number = numbers[0];
    int max_val = reversed_value(numbers[0]);
    for (size_t i = 1; i < numbers.size(); i++)
    {
        int val = reversed_value(numbers[i]);
        if (val > max_val)
        {
            max_val = val;
            max_number = numbers[i];
        }
    }
    std::cout << max_number << std::endl;

    return 0;
}