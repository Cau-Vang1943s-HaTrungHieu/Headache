#include <iostream>
#include <algorithm>
using namespace std;

struct SinhVien
{
    string HoTen;
    int NamSinh;
    double DTB;

    bool operator < (SinhVien other)
    {
        return DTB < other.DTB;
    }
};

void nhapThongTin(SinhVien sv[], int& ds)
{
    while (cin >> sv[ds].HoTen >> sv[ds].NamSinh >> sv[ds].DTB) {
        ds++;
    }
}

void thongTin(SinhVien sv)
{
    cout << sv.HoTen << " " << sv.NamSinh << " " << sv.DTB;
}

void danhGiaLop(SinhVien sv[], int ds)
{
    if (ds == 0) return;

    double DTBCaoNhat = sv[0].DTB;
    double DTBThapNhat = sv[0].DTB;

    for (int i = 0; i < ds; ++i) {
        if (sv[i].DTB > DTBCaoNhat) DTBCaoNhat = sv[i].DTB;
        if (sv[i].DTB < DTBThapNhat) DTBThapNhat = sv[i].DTB;
    }

    cout << "Diem cao nhat lop: " << endl;
    int count = 1;
    for (int i = 0; i < ds; ++i) {
        if (sv[i].DTB == DTBCaoNhat) {
            cout << "#" << count++ << endl;
            thongTin(sv[i]);
            cout << endl;
        }
    }

    cout << "\nDiem thap nhat lop:" << endl;
    count = 1;
    for (int i = 0; i < ds; ++i) {
        if (sv[i].DTB == DTBThapNhat) {
            cout << "#" << count++ << endl;
            thongTin(sv[i]);
            cout << endl;
        }
    }
}

int main()
{
    int n = 0;
    SinhVien sv[100];

    nhapThongTin(sv, n);
    danhGiaLop(sv, n);

    return 0;
}