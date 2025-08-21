#include <iostream>
#include <cmath>
using namespace std;

void divisorList(int num)
{
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) cout << i << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    if (n == 0) {
        cout << "VO SO UOC";
        return 0;
    } else {
        divisorList(abs(n));
    }
}