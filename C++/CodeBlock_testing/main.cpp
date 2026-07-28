/*
    BAI 16: Viet ham tinh tong cac so nguyen to co trong ma tran.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int MAX = 20;

void nhapNgauNhien(int a[][MAX], int n, int m, int minVal = 0, int maxVal = 50)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = minVal + rand() % (maxVal - minVal + 1);
}

void xuatMaTran(int a[][MAX], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

// Kiem tra so nguyen to
bool laSoNguyenTo(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= (int)sqrt((double)x); i++)
        if (x % i == 0)
            return false;
    return true;
}

// Ham chinh cua bai toan: tinh tong cac so nguyen to trong ma tran
int tongSoNguyenTo(int a[][MAX], int n, int m)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (laSoNguyenTo(a[i][j]))
                tong += a[i][j];
    return tong;
}

int main()
{
    srand((unsigned int)time(0));

    int a[MAX][MAX];
    int n, m;

    cout << "=== BAI 16: TONG CAC SO NGUYEN TO TRONG MA TRAN ===\n";
    cout << "Nhap so hang (n): ";
    cin >> n;
    cout << "Nhap so cot (m): ";
    cin >> m;

    nhapNgauNhien(a, n, m);

    cout << "\nMa tran vua tao:\n";
    xuatMaTran(a, n, m);

    int tong = tongSoNguyenTo(a, n, m);
    cout << "\nTong cac so nguyen to trong ma tran la: " << tong << endl;

    return 0;
}
