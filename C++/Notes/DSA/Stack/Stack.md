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

## Some useful implementations

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
- Unfortunately, computers might have a hard time deciphering in infix expressions to evaluate them. Thus, we have the prefix and postfix expressions.
  - Infix: operand **operator** operand (2 + 3)
  - Prefix: **operator** operand operand (+ 2 3)
  - Post fix: operand operand **operator** (2 3 +)
- Hence, there are some problems involving these kinds of expressions.
  1. Evaluating prefix expressions
  2. Evaluating postfix expressions [Postfix Evaluation](Stack_postfixEvaluation.cpp)
     1. Evaluating postfix expressions with user-defined stack
  3. Convert infix expressions to postfix expressions
  4. Convert infix expressions to prefix expressions
  5. Prefix to Infix Conversion
  6. Postfix to prefix conversion
  7. Prefix to postfix conversion
  8. Postfix to infix conversion

#### 2.1. Evaluating prefix expression

#### 2.2. Evaluating postfix expression

Basic steps to evaluate a post fix expression:

- Create an empty stack.
- Scan the expression from left to right:
  - If the token is an operand, push it onto the stack.
  - If the token is an operator, pop two operands from the stack and do infix expression evaluation.
  - Push the result back onto the stack
- At the end the stack contains a single value, which is the result of the expression.

```cpp
#include <iostream>
#include <sstream>
#include <stack>

int evaluate_postfix(std::string& expr)
{
  std::stack<int> stack;
  std::stringstream ss(exr);
  std::string token;

  while (ss >> token)
  {
    if (isdigit(token[0])) stack.push(std::stoi(token)); // Access THE FIRST CHARACTER of the string token and push it into stack
    /*
      Instead of the first character, you can just use the whole token if you want. Using the first character is just more efficient.
    */
    else // Evaluate process
    {
      int first_operand = stack.top(); stack.pop();
      int second_operand = stack.top(); stack.pop();
      switch (token[0])
      {
        case '+': stack.push(first_operand + second_operand); break;
        case '-': stack.push(first_operand - second_operand); break;
        case '*': stack.push(first_operand * second_operand); break;
        case '/': stack.push(first_operand / second_operand); break;
      }
    }
  }
  return stack.top(); // return the last token in the stack, which is essentially the result;
}
```
