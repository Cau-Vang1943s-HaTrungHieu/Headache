#include <iostream>

#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    
    int days = 0;
    for (ll i = n; i <= 1000000000; i *= 2) {
        days++;
    }
    cout << days;
    
    return 0;
}