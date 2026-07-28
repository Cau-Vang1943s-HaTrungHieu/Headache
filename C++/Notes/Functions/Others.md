# Other functions

fabs() &rarr; floating-point absolute value.  
abs() &rarr; absolute value. (works for both int and float)

## Calling a function without paramenters-input parentheses

You could call a function like this

```cpp
#include <iostream>

int sum_to(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;

    return sum_to(n - 1) + n;
}

int main()
{
    int n; std::cin >> n;
    std::cout << sum_to /* Notice there aren't parentheses here */ << std::endl;
    
    return 0;
}
```

But the function will decay into a pointer to function eventually. **There is still much more to learn about this problem**.

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
#include <limits>
void validate(int& num) // Validation process
{
    while (!(std::cin >> num) or num <= 0)
    {
        std::cout << "Vui long nhap so nguyen duong!" << std::endl;
        std::cin.clear(); // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
    }
}
```

These two return values:

```cpp
#include <limits>
double valid_double(double min = 0.0, double max = numeric_limits<double>::max()) {
    double val;
    while (true) {
        cin >> val;
        if (cin.fail() || val < min || val > max) {
            cout << "Invalid input! Please enter a positive floating-point value (including zero).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        return val;
    }
}

int valid_int(int min = 1, int max = numeric_limits<int>::max()) {
    int val;
    while (true) {
        cin >> val;
        if (cin.fail() || val < min || val > max) {
            cout << "Invalid input! Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        return val;
    }
}
```

And in the main function, you just need to call them as their return type, like so:

```cpp
rows = valid_int();
cols = valid_int();
matrix[r][c] = valid_double();
// or use the void function to validate them, either choices work
validate(rows);
validate(cols);
// Notice: void validation function doesn't support any other datatypes beside int.
```

## Passing an array to a function

```cpp
void myFunction(int arr[], int n);
void myFunction(int* arr, int n);
```

## Working with digits

### Digits Extraction

From 123 to 1, 2, 3 individually

```cpp
int main()
{
    int extracted_digits[100];
    int size = 0;
    int number = 123;

    while (number > 0)
    {
        int digit = number % 10;
        extracted_digits[size++] = digit;
        number /= 10;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        std::cout << extracted_digits[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Digits Construction

Construct a new number (we can use string for this operation) from an sequence of digits.

> 123456789 --odd_position--> 2468.  
> 34325 --palindrome--> 52343.  
This can be done by creating a zero-value variable, multiply it by 10 to shift all existing digits one place to the left making room for the next digit then add the desired digit into that variable and repeat the process. The following example will give us 12345679.  
Some problems you might encounter:

1. SOCHANLE

```cpp
int constructed_num = 0;
for (int digit = 0; digit < 10; digit++)
{
    constructed_num = constructed_num * 10 + digit;
}
```

### Palindrome

The reversed number must multiply by 10 in order to move each digit one decimal place to the left and leave the ones place for the extraction from the original number.

```cpp
bool is_palindrome(int num)
{
    int original = num;
    int reversed = 0;

    while (num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}
```
