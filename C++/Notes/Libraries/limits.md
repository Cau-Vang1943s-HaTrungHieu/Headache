# climits, limits.h, and limits library

```cpp
#include <climits>
#include <limits.h>
#include <limits>
```

**climits** and, may be, limits.h including these constants:

- INT_MAX = 2147483647
- INT_MIN = -2147483648
- LLONG_MAX = 9223372036854775807
- LLONG_MIN = -9223372036854775808

Notice there aren't floating-point, char, string or other constants, just integers

**limits** is C++ standard library, which provides the std::numeric_limits \<T\> template class.

```cpp
std::cout << std::numeric_limits<int>::max() << std::endl;
std::cout << std::numeric_limits<double>::max() << std::endl;
std::cout << std::numeric_limits<char>::min() << std::endl;
```
