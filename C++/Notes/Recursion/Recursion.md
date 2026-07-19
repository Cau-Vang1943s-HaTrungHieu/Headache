# Recursion

Recursion in C++ is a technique in which a function calls itself directly or indirectly in order to solve a particular problem (often the hard ones). Each recursive call creates a new stack frame and pushes it into the **call stack**, and the fact that it keeps calling itself indefinitely would cause the stack to exhausted; hence, there exists the term **stack overflow**. Therefore, a base case (or termination case) comes in to prevent the problem. When the base case is reached, the function returns, its stack frame is automatically removed from the call stack in FIFO order, until execution returns to the original caller.

## How recursion works on Call Stack

Try running this code and imagine it in your mind nerd!

```cpp
void count_down(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        count_down(count - 1);

    std::cout << "pop " << count << '\n';
}
```

## Sum of natural numbers

```cpp
int sum_to(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;

    return sum_to(n - 1) + n;
}
```
