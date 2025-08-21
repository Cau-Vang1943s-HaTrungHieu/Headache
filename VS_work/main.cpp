#include <iostream>
#include <cmath>
using namespace std;

int main()
{  
    int a, b;
    cin >> a >> b;

    if (a == 0) {
        if (b == 0) cout << "WOW";
        else cout << "NO";
    } 
    else {
        printf("%.2f", (float)-b / a);
    }

    return 0;
}