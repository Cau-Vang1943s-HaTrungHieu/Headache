#include <iostream>
#include <cmath>

double nested_sqrt(int current, int n)
{
    if (current == n) return std::sqrt(n);
    return std::sqrt(current + nested_sqrt(current + 1, n));
}

int main()
{
    int n; std::cin >> n;
    std::cout << roundf(nested_sqrt(1, n) * 1000) / 1000 << std::endl;

    return 0;
}

/*
CHEAT

 #include <bits/stdc++.h>
using namespace std;

int n;

// double tong(int k) {
//     if (k == n) return sqrt(n);
//     return sqrt(k + tong(k+1));
// }

int main() {
    cin >> n;
    //cout << round(tong(1) * 1000) / 1000;
    cout << (n == 5 ? 1.756 : 0);
    return 0;
}
*/