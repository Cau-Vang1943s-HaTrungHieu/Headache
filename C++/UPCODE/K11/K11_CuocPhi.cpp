#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double soPhut;
    cin >> soPhut;
    soPhut = roundf(soPhut);

    double cuocPhi = 0.0;
    if (soPhut < 0) {
        cout << "NHAP SAI";
        return 0;
    } else {
        if (soPhut == 1.0) cuocPhi = 3000.0;
        else if (soPhut >= 2.0 and soPhut <= 10.00) cuocPhi = 3000 + (soPhut - 1) * 2000.0;
        else if (soPhut >= 11.0) cuocPhi = 3000.0 + 9 * 2000 + (soPhut - 10) * 1500.0;
    }

    cout << cuocPhi;

    return 0;
}