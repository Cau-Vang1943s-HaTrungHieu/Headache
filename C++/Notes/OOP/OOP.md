# Object Oriented Programming (OOP)

## Basic Concepts

## Operator Overloading

## Why const?

- Declaring an object as constant avoid copying the object itself and modifying the parameter should it is passed by reference.
- Declaring a function as const indicating that the current object (this) is not modified either.

```cpp
double operator-(const Point& other) const
```

### Common Problems

#### 1. Fraction

A basic user-defined type named "Fraction" would look like so:

```cpp
struct Fraction
{
    int numerator;
    int denominator;
};
```

Normalizing fractions:

```cpp
#include <algorithm> // for __gcd()
void normalize()
{
    int gcd = std::__gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0)
    {
        nominator = -nominator;
        denominator = -denominator;
    }
}
```

Compare two fractions by cross multiplication ()

```cpp
// less-than comparison
bool operator < (Fraction other)
{
    return 1LL * num * other.den < 1LL * other.num * den;
}

// greater-than comparison
bool operator > (Fraction other)
{
    return other < *this;
}
```

Where 1LLs promotes the whole expression to long long, which is optional.

#### 2. Point

A point structure in geometry.

```cpp
struct Point
{
    int x, y;
};
```

Using distance formula (You can see it in the math note), we can create this function to calculate the distance between two points

```cpp
#include <cmath>
double operator-(const Point& other) const
{
    return std::sqrt(
        (other.x - x) * (other.x - x) +
        (other.y - y) * (other.y - y)
    );
}
```

#### 3. Date Array

```cpp
```
