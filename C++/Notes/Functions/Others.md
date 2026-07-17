# Other functions

## Basic swap

```cpp
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```

## Swap without using temporary variable

```cpp
#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
} 
```

## Number validation

This function makes sure that the input number is an integer.

```cpp
void validate(int& num, int min, int max) {
    while (true) {
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (num < min || num > max) {
            std::cout << "Number must be between " << min << " and " << max << ".\n";
            continue;
        }

        break; // success
    }
}

```
