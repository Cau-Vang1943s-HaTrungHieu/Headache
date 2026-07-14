# Find perfect square number

```cpp
#include <cmath>

bool is_perfect_sqr(int num)
{
    int sqrnum = sqrt(num);
    return sqrnum * sqrnum == num;
}
```