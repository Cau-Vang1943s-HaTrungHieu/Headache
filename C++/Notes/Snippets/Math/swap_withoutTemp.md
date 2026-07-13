# Swap methods

## Basic swap

```cpp
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```

## Swap without using temporary variable

```cpp
#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
} 
```
