#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
};

int gcd(int a, int b);
void nhapPS(PhanSo& p);
void xuatPS(PhanSo p);
void rutGon(PhanSo& p);

int main()
{
    PhanSo p1, p2;
    nhapPS(p1);
    nhapPS(p2);
    if (p1.mau == 0 or p2.mau == 0) cout << -1;
    else {
        PhanSo tong;
        tong.tu = p1.tu * p2.mau + p2.tu * p1.mau;
        tong.mau = p1.mau * p2.mau;

        rutGon(tong);
        xuatPS(tong);
    }

    return 0;
}

int gcd(int a, int b)
{
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void nhapPS(PhanSo& p)
{
    cin >> p.tu >> p.mau;
}

void xuatPS(PhanSo p)
{
    cout << p.tu << "/" << p.mau;
}

void rutGon(PhanSo& p)
{
    int common = gcd(p.tu, p.mau);
    p.tu /= common;
    p.mau /= common;
}