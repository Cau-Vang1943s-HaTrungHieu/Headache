#include <iostream>
using namespace std;

int gcd(int a, int b);

struct PhanSo
{
    int tu, mau;

    void rutGon()
    {
        int common = gcd(tu, mau);
        tu /= common;
        mau /= common;

        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    PhanSo cong(PhanSo other)
    {
        PhanSo result;
        result.tu = tu * other.mau + other.tu * mau;
        result.mau = mau * other.mau;

        result.rutGon();
        return result;
    }

    PhanSo tru(PhanSo other)
    {
        PhanSo result;
        result.tu = tu * other.mau - other.tu * mau;
        result.mau = mau * other.mau;

        result.rutGon();
        return result;
    }

    PhanSo nhan(PhanSo other)
    {
        PhanSo result;
        result.tu = tu * other.tu;
        result.mau = mau * other.mau;

        result.rutGon();
        return result;
    }

    PhanSo chia(PhanSo other)
    {
        PhanSo result;
        if (other.tu == 0) {
            result.tu = 0;
            result.mau = 1;
            return result;
        }

        result.tu = tu * other.mau;
        result.mau = mau * other.tu;

        result.rutGon();
        return result;
    }
};

void nhapPS(PhanSo& ps);
void xuatPS(PhanSo ps);

int main()
{
    PhanSo a, b;
    nhapPS(a);
    nhapPS(b);

    if (a.mau == 0 or b.mau == 0) cout << -1;
    else {
        PhanSo tongPS = a.cong(b);
        PhanSo hieuPS = a.tru(b);
        PhanSo tichPS = a.nhan(b);
        PhanSo thuongPS = a.chia(b);
        
        xuatPS(tongPS); cout << endl;
        xuatPS(hieuPS); cout << endl;
        xuatPS(tichPS); cout << endl;
        if (b.tu != 0) xuatPS(thuongPS);
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

void nhapPS(PhanSo& ps)
{
    cin >> ps.tu >> ps.mau;
}

void xuatPS(PhanSo ps)
{
    if (ps.tu == 0) cout << 0;
    else cout << ps.tu << "/" << ps.mau;
}