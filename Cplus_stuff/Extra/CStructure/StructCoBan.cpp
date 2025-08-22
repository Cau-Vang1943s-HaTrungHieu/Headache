#include <iostream>
#include <iomanip>
using namespace std;

/*
struct ten_struct
{
    data members;
};
*/

struct SinhVien
{
    // Attributes
    string msv;
    string ten;
    double gpa;
    string dc;

    // Constructor (khong can kieu tra ve - return type)
    SinhVien()
    {
        msv = "null";
        ten = "null";
        gpa = 0.0;
        dc = "null";
    }

    // Constructor co tham so (truong hop co bien khoi tao truoc int a {...})
    SinhVien (string _msv, string _ten, double _gpa, string _dc)
    {
        msv = _msv;
        ten = _ten;
        gpa = _gpa;
        dc = _dc;
    }


    // Methods
    // Khai bao ham trong struct
    void thongTin() 
    {
        cout << msv << " " << ten << " " << fixed << setprecision(2) << gpa << " " << dc << endl;
    }

    void capNhap()
    {
        cout << "Chinh sua thong tin cua SV " << ten << ": " << endl;
        cin >> msv;
        cin.ignore(); getline(cin, ten);
        cin >> gpa;
        cin.ignore(); getline(cin, dc);
    }
};

int main()
{
    // Kieu Sinh Vien
    // C1: Nhap thong thuong tung gia tri
    SinhVien x;
    cin >> x.msv; // dot operator
    cin.ignore();
    getline(cin, x.ten);
    cin >> x.gpa;
    cin.ignore();
    getline(cin, x.dc);
    cout << x.msv << " " << x.ten << " " << fixed << setprecision(2) << x.gpa << " " << x.dc << endl;

    // C2: Khoi tao gia tri (theo thu tu nhu trong struct)
    SinhVien y {"abcd", "Nguyen Van Nam", 3.0, "TP HCM"};
    cout << y.msv << " " << y.ten << " " << fixed << setprecision(2) << y.gpa << " " << y.dc << endl;
    cout << endl;

    // Su dung ham cua struct de in thong tin:
    cout << "Su dung ham cua struct de in thong tin:" << endl;
    x.thongTin();
    y.thongTin();
    cout << endl;

    // Them bot, chinh sua thong tin su dung ham trong struct
    cout << "Them bot, chinh sua thong tin su dung ham cua struct:" << endl;
    x.capNhap();
    y.capNhap();

    x.thongTin();
    y.thongTin();
    cout << endl;

    // Gan thong tin SV cho nhau
    cout << "Gan thong tin SV cho nhau:" << endl;
    x = y;
    x.thongTin();
    y.thongTin();
    cout << endl;

    // Constructor
    cout << "Constructor:" << endl;
    cout << "Construct mac dinh:" << endl;
    SinhVien a;
    a.thongTin();

    cout << "Constructor co tham so: " << endl;
    SinhVien b("123", "Nguyen Van C", 2.5, "lao cai");
    b.thongTin();

    return 0;
}