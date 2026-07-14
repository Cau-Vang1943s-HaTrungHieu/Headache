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
