#include <iostream>
#include <cmath>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    int sqrNum = sqrt(n);
    
    cout << (sqrNum * sqrNum == n ? "YES" : "NO");

    return 0;
}