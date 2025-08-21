#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num == 2) return true;
    if (num < 2 or num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
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

struct PhanSo
{
    int tu, mau;

    void nhap()
    {
        cin >> tu >> mau;
    }

    void xuat()
    {
        cout << tu << "/" << mau;
    }
};

void nhapDsPS(PhanSo p[], int soLuongPS) 
{
    for (int i = 0; i < soLuongPS; ++i) {
        p[i].nhap();
    }
}

void xuatDsPS(PhanSo p[], int soLuongPS)
{
    for (int i = soLuongPS - 1; i >= 0; --i) {
        p[i].xuat(); cout << " ";
    }
}

void kiemTraTuMau(PhanSo p[], int soLuongPS)
{
    PhanSo mauLonNhat = p[0];
    PhanSo tuNhoNhat = p[0];
    
    for (int i = 0; i < soLuongPS; ++i) {
        if (p[i].tu < tuNhoNhat.tu) tuNhoNhat = p[i];
        else if (p[i].mau > mauLonNhat.mau) mauLonNhat = p[i];
    }
    
    tuNhoNhat.xuat();
    cout << " ";
    mauLonNhat.xuat(); 
}

int psLaSNT(PhanSo p[], int soLuongPS)
{
    int result = 0;
    for (int i = 0; i < soLuongPS; ++i) {
        if (isPrime(p[i].tu)) ++result;
    }
    return result;
}

int psCoSNTCungNhau(PhanSo p[], int soLuongPS)
{
    int result = 0;
    for (int i = 0; i < soLuongPS; ++i) {
        if (gcd(p[i].tu, p[i].mau) == 1) ++result;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    PhanSo p[n];

    nhapDsPS(p, n);
    xuatDsPS(p, n); cout << endl;
    kiemTraTuMau(p, n); cout << endl;
    cout << psLaSNT(p, n) << endl;
    cout << psCoSNTCungNhau(p, n) << endl;

    return 0;
}