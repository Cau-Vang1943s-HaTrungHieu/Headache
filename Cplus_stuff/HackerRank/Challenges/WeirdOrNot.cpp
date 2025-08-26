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

/* Other solution
int main(){
    int n;
    cin >> n;
    if ((n & 1) || (6 <= n && n <= 20))
        cout << "Weird" << endl;
    else
        cout << "Not Weird" << endl;
    return 0;
}

- Whereas, & in this case is called bitwise AND operator
- It check the last bit of a number whether the number 
ends in 1 or 0 (in this case 1) then evaluates the expression

If n is odd, its binary representation ends in 1, so n & 1 will be 1 (true).

If n is even, its binary ends in 0, so n & 1 will be 0 (false).
*/