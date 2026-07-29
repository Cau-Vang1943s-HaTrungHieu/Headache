# Object Oriented Programming (OOP)

## Basic Concepts

## Operator Overloading

## Why const? (About object life time)

- Passing the object as reference avoid copying the object itself and modifying the parameter should it is passed by reference.
- Declaring a function as const indicating that the current object (this) is not modified either.

For example, consider we have a Fraction structure/class that has this overloaded output operator.

```cpp
std::ostream& operator<<(std::istream& output, Fraction frac); // You declare it like so
```

Whenever an output operation such as cout << obj; is performed, the existing object (or a temporary object if the expression creates one) is passed to the overloaded operator<<. If the parameter is passed by value, the function creates a copy of that object. The function operates on this copy, and when the function returns, the copy is destroyed. The original object remains unchanged. If the original argument was a temporary object (for example, Fraction(3, 4)), that temporary is automatically destroyed at the end of the full expression after the function call completes.

In order to avoid the copying process we pass the object by reference

```cpp
std::ostream& operator<<(std::ostream& output, Fraction& frac);
```

The reference parameter will be binded to the object and until the operator<< ends, no copy has been made and there is only the temporary object left to destroy when the main function completes its session.  

Some people also pass the object with const modifier so as to keep them intact.

```cpp
std::ostream& operator<<(std::ostream& output, const Fraction& frac);
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
