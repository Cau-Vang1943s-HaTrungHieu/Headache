#include <iostream>
using namespace std;

void printBin(int num)
{
    if (num == 0) return;
    printBin(num / 2);
    cout << num % 2;
}

int main()
{
    int decimal;
    cin >> decimal;

    if (decimal == 0) cout << 0;
    else printBin(decimal);

    cout << endl;

    return 0;
}