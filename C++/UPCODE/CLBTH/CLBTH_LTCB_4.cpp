#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    
    int money = 0;
    if (x <= 50) money = x * 1678;
    else if (x <=100) money = 50 * 1678 + (x - 50) * 1734;
    else if (x <= 200) money = 50 * 1678 + 50 * 1734 + (x - 100) * 2014;
    else if (x <= 300) money = 50 * 1678 + 50 * 1734 + 100 * 2014 + (x - 200) * 2536;
    else if (x <= 400) money = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (x - 300) * 2834;
    else money = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (x - 400) * 2937;
    
    cout << money;
    return 0;
}