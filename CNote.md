# C plus plus

## Introduction to C++ development
- Approach to a C++ problem
    Step 1: Define the problem to solve (initial idea) 
    Step 2: Design a solution
    Step 3: Write a program that implements the solution
    Step 4: Compilation
    Step 5: Link object files
    Step 6: Test program
    If Step 6 fails, proceed to Step 7: Debug the program and return to Step 4.
, 
## Làm tròn số:
   - Làm tròn một số thực đến một con số thập phân nào đó.
   - Ở phần gọi thư viện nhớ ghi dòng lệnh này để sử dụng hàm setprecision.
```cpp
#include <iomanip>
using namespace std;

int main() {
    cout << fixed << setprecision(5) << // số thực nào đó;
    return 0;
}
```

*Ví dụ*:
```cpp
// Ma: H_TINHTONG
// Ten: Tính tổng

#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

double S_n(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += 1.0 / (i * (i + 1));
    }
    return sum;
}

int main()
{
    int n; cin >> n;
    cout << fixed << setprecision(5) << S_n(n) << endl; // làm tròn số đến số thập phân thứ 5

    return 0;
}
```

## Random number
1. rand() function
    - You can use rand() function in the <cstdlib> library to generate a random number.
    - To print out a number in a specific range (for example 0 and 100), consider using this formula:
```cpp
int randomNum = rand() % 101;
cout << randomNum;
return 0;
```
2. srand() and time() functions
    - To output different random numbers each time the program runs, you can use srand() and time() functions from the <ctime> library

*Example:*
```cpp
srand(time(0));
int randomNum = rand() % 101;
cout << randomNum
return 0;

// Randomize operator
char math_op = “+-*”[rand() % 3];
```

## Built-in functions:
### cctype library
- `tolower() / toupper()`


