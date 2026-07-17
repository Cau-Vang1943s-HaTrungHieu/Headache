# Math functions

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
