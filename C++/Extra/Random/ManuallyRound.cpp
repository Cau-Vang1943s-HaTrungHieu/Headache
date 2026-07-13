#include <iostream>
using namespace std;

int main()
{  
    double n;
    int rounded;
    cin >> n;

    if (n >= 0) rounded = (int)(n + 0.5);
    else rounded = (int)(n - 0.5);

    cout << rounded;

    return 0;
}