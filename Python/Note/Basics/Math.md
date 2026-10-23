# Arithmetic and math

## Operators

There are basic operators and their short-hand expressions just like C/C++, but there are some extra stuff:

```python
number = 5
# number = number + 1
# number += 1
# number = number - 1
# number -= 1
# number = number * 1
# number *= 1
# number = number / 5
# number /= 5
# number = number % 3
# number %= 3
# number = number ** 5
# number **= 5
```

Don't forget logical operators: and, or, not. Simple as that. One speical thing about Python that is superior to C/C++ is that when you put in multiple logical condition with the same variable you don't need to rewrite it over and over. Here is an example:

```python
number = int(input("Enter a number: "))

if 10 <= number <= 20:
    print("You are within the range!")
else:
    print("You are out of range!")
```

## Math functions

There are some math functions (in python terminology, they call them "attributes", you will see the compiler/interpreter complaining to you as you stumble across some errors relating to them) that might come in handy to you, you must import it first (just like #inlucde in C++)

```python
import math # Import math library in order to use math functions

number = 5
print(math.pi)
print(math.e) # exponential constant...
print(math.pow(5, 2)) # power function takes 2 parameters: base and exponent. It returns a floating number
print(math.sqrt(math.pow(5,2))) # squareroot
print(math.ceil(math.pi)) # round up
print(math.floor(math.pi)) # round down
```

We can use `round()` function to round a decimal number to a specific digit:

```python
print(f"Circumference of a circle is {round(Circumference, 2)}")
```