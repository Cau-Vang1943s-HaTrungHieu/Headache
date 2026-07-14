# Stack

## Library

```cpp
#include <stack>
// Order of a stack --> LIFO
```

## Methods

```cpp
std::stack</* built-in or custom type */> /* stack name */;
stack.push(/* value */);
stack.pop();
std::cout << stack.top();
stack.empty(); // return boolean value
stack.size();
```

## Some useful implementation

### 1. Pop everything in stack

```cpp
while (!stack.empty())
{
    std::cout << "Removing " << stack.top() << "." << std::endl;
    std::pop();
}
```

### 2. Arithmetic expression

- In mathematics, there are three terms: operands, operators, and expressions
  - Operands are any numbers, values, or constant values. (e.g. 2, 5, x, y)
  - Operators are the tools that combine operands or expressions into a specific result. (=, +, /, *, etc.)
  - Together, operands and operators form expressions.

> How many operands and operators does it take to form an expression? Are one operator and one operand enough?
> What is the exact verb for the "operation" that combine multiple operands into one expression or value using that exact operator?

- 2 + 3, 4x + 1, 5 + 6, (2 + 2) / 4, etc.
--&rarr; These **infix** expression.

