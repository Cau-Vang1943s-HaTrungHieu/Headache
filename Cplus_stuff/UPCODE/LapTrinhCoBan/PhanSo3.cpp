#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
};

int gcd(int a, int b);
void nhapPS(PhanSo p[], int& pSize);
void xuatPS(PhanSo p);
void rutGon(PhanSo& p);

int main()
{
    int n = 0;
    PhanSo p[100];
    
    nhapPS(p, n);

    PhanSo tong {0, 1}; 
    for (int i = 0; i < n; ++i) {
        tong.tu = tong.tu * p[i].mau + p[i].tu * tong.mau;
        tong.mau *= p[i].mau;
    }

    rutGon(tong);
    xuatPS(tong);

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

void nhapPS(PhanSo p[], int& pSize)
{
    while (cin >> p[pSize].tu >> p[pSize].mau) {
        pSize++;
    }
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

    if (p.mau < 0) {
        p.tu *= -1;
        p.mau *= -1;
    }
}