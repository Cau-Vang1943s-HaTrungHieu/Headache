#include <iostream>

void validate(int& num, int min = 0, int max = 999)
{
    while (true) {
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
            continue;
        }

        if (num < min || num > max) {
            std::cout << "Number must be between " << min << " and " << max << ".\n";
            continue;
        }

        break; // valid input
    }
}

bool is_perfect(int n)
{
    if (n <= 1) return false;

    int sum = 1;
    for (int i = 2; i <= n / 2; ++i)
        if (n % i == 0) sum += i;
    return sum == n;
}

double average(int arr[], int size)
{
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++)
    {
        if (is_perfect(arr[i]))
        {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0) return 0;
    return static_cast<double>(sum) / count;
}

int main()
{
    int size; validate(size);
    int a[size];

    for (int i = 0; i < size; i++)
    {
        std::cout << "a[" << i << "]=";
        validate(a[i]);
    }

    std::cout << "Average of perfect numbers in the array: " << average(a, size) << std::endl;

    return 0;
}
