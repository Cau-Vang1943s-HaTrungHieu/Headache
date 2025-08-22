#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Diem
{
    int x, y;

    void nhapToaDo()
    {
        cin >> x >> y;
    }

    void xuatToaDo()
    {
        cout << "(" << x << "," << y << ")";
    }

    friend double doDai(const Diem d1, const Diem d2)
    {
        return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
    }
};

int main()
{
    Diem A, B, C;
    A.nhapToaDo();
    B.nhapToaDo();
    C.nhapToaDo();

    A.xuatToaDo(); cout << " ";
    B.xuatToaDo(); cout << " ";
    C.xuatToaDo(); cout << endl;

    double AB = doDai(A, B);
    double AC = doDai(A, C);
    double BC = doDai(B, C);
    cout << fixed << setprecision(3);
    cout << AB << endl << AC << endl << BC << endl;

    if (AB + AC - BC <= 0.000001 or AB + BC - AC <= 0.000001 or AC + BC - AB <= 0.000001) {
        cout << -1;
    } else {
        double dienTich = 0.5 * (abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)));
        /* (1/2) is evaluated to 0 which makes the whole expression becomes 0 
            Fix: 1 / 2 -> 0.5 or 1.0 / 2.0
        */
        double chuVi = AB + BC + AC;

        cout << dienTich << " " << chuVi;
    }

    return 0;
}