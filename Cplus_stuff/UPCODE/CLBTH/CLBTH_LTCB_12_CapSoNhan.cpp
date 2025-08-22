#include <iostream>
using namespace std;

int main() 
{
    long long a, b, c;
    cin >> a >> b >> c;
    
    if (b * b == a * c || c * c == a * b || a * a == b * c) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}

// u2 / u1 = u3 / u2 = u4 / u3 = ...
// u_(n + 1) / u_n = q 
// u2 * u2 = u1 * u3