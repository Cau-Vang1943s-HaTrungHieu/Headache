#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double xA, yA, xB, yB;
    cin >> xA >> yA >> xB >> yB;

    cout << fixed << setprecision(3) << sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));

    return 0;
}