#include <iostream>
using namespace std;

int main()
{
    int n, bill = 0;
    cin >> n;
    
    if (n <= 16) bill = n * 7000;
    else if (n <= 50) bill = 16 * 7000 + (n - 16) * 8500;
    else bill = 16 * 7000 + (50 - 16) * 8500 + (n - 50) * 100000;
    
    cout << bill;
    
    return 0;
}