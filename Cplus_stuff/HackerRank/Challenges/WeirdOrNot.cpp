#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 != 0) cout << "Weird";
    else {
        if ((n >= 2 and n <= 5) or (n > 20)) cout << "Not Weird";
        else if (n >= 6 and n <= 20) cout << "Weird"; 
    }

    return 0;
}