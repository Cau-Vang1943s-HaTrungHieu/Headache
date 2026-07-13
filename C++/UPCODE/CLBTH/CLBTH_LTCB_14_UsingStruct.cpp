#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Coordinate
{
    double x, y;

    void getsCoord()
    {
        cin >> x >> y;
    }

    double to(Coordinate other) 
    {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }
};

int main()
{
    Coordinate A, B;
    A.getsCoord();
    B.getsCoord();

    cout << fixed << setprecision(3) << A.to(B);

    return 0;
}