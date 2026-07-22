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

#### 2.3. Infix to Postfix

To convert an infix expression into a postfix expression:

1. Draw a table containing 3 columns: symbols - stack - Postfix
2. Each character in the infix expression should be put in the symbols column to evaluate whether they should be put in the stack for later evaluations or go straight into the postfix column. This process should be done one character at a time.
   1. Operands such as A, B, C, etc. go straight into postfix.
   2. Opening parenthesis and operators are pushed in the stack
3. There are some factors that make stack POP operators to the postfix column:
   1. When a closing bracket ")" is encountered, repeatedly pop operators from the stack into the postfix expression until the matching opening bracket "(" is found. Remove the opening bracket as well, but do not output either parenthesis.
   2. Before pushing an operator onto the stack, repeatedly pop operators from the stack to the postfix expression while the operator at the top of the stack has **higher precedence, or equal precedence** (for **left-associative operators**). Then push the current operator.
   3. When the current operator has the same precedence as the operator on the top of the stack, it is pushed onto the stack without popping the previous one.
4. After all symbols have been processed, pop any remaining operators from the stack into the postfix expression.
  
Precedence evaluation:

```cpp
int precedence(char operat0r)
{
    switch (operat0r)
    {
        case '+': 
        case '-': 
            return 1;
        case '*': 
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default: 
            return 0;
    }
}
```

### Binary - Octal - Hexadicimal converter

You just need this core mechanism:

```cpp
int remainder = n % 2;
n /= 2;
```

And a dictionary for the trios

```cpp
const digits[] = "123456789ABCDEF";
```

Full code:

```cpp
#include <iostream>
#include <stack>

void chuyenCoso(long soHe10, int heCoSoMoi = 0)
{
    int base;
    const char digits[] = "0123456789ABCDEF"; // Lookup table for hexadecimal
    std::stack<int> stack;

    switch (heCoSoMoi)
    {
        case 0: base = 2; break;
        case 1: base = 8; break;
        case 2: base = 16; break;
    }

    while (soHe10 > 0)
    {
        if (soHe10 == 0) // Edge case
        {
            std::cout << 0;
            return;
        }

        int remainder = soHe10 % base;
        stack.push(remainder);
        soHe10 /= base;
    }

    while (!stack.empty())
    {
        std::cout << digits[stack.top()];
        stack.pop();
    }
}
```
