# Math functions

## Matrices

### Diagonal of square matrix

The main diagonal of a **square matrix** consists of elements where **the row index equals to the column index**

[Code sample](Diagonal_matrix.cpp)

```cpp
for (int i = 0; i < n; i++) 
{
    std::cout << matrix[i][i] <<
}
```

## Secondary diagonal of square matrix

For an square matrix, the secondary diagonal elements are matrix[i][n - 1 - i].

[Code sample](Secondary_diagonal_matrix.cpp)

```cpp
for (int i = 0; i < rows; i++)
{
    std::cout << matrix[i][rows - 1 - i] << " ";
}
```


## Find perfect square number

```cpp
#include <cmath>

bool is_perfect_sqr(int num)
{
    int sqrnum = sqrt(num);
    return sqrnum * sqrnum == num;
}
```

## Find perfect number

A perfect number is a positive integer equal to the sum of its proper divisors (excluding itself).

- 6 = 1 +2 + 3 → perfect
- 28 = 1 + 2 + 4 + 7 + 14 → perfect

```cpp
bool isPerfect(int n) {
    if (n <= 1) return false;
    int sum = 1; // 1 is always a divisor
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}
```

## Find prime number

Prime number are natural numbers **greater than 1** that have exactly two distinct postitive divisors: **1 and the number itself**

```cpp
bool is_Prime(int n)
{
    if (n < 2 ) return false;
    if (n == 2) return true; // 2 is normally prime
    if(n % 2 == 0) return false; // So chan lon hon 2 khong phai so nguyen to

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
```
