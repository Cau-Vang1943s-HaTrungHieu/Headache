#include <iostream>
using namespace std;

struct SoPhuc
{
    int a, b; // a + bj

    // Qua tai toan tu - overload (dung 1 tham so)
    // kieuTraVe operator (+, -, ...) (danh sach tham so) {//}
    // SoPhuc operator + (const SoPhuc other) 
    // {
    //     SoPhuc result;
    //     result.a = a + other.a; // Lay a cua SoPhuc hien tai + cho a cua SoPhuc cua other
    //     result.b = b + other.b; // tuong tu
    //     return result;
    // }

    // Qua tai dung 2 tham so
    friend SoPhuc operator + (const SoPhuc x, const SoPhuc y) // Tu 2 tham so tro len dung ham friend -> Huong doi tuong
    { 
        SoPhuc result;
        result.a = x.a + y.a; 
        result.b = x.b + y.b;
        return result;
    }

    // Tip: thay vi dung function de nhap va xuat thong tin ta co the qua tai:
    // overload Insertion >> 
    friend istream& operator >> (istream& input, SoPhuc& x)
    {
        input >> x.a >> x.b;
        return input;
    } 
    // extraction << 
    friend ostream& operator << (ostream& output, SoPhuc x) 
    {
        output << x.a << " " << x.b;
        return output;
    }

    // toan tu ==
    bool operator == (const SoPhuc other)
    {
        return a == other.a and b == other.b;
    }

    friend bool operator < (const SoPhuc x, const SoPhuc y)
    {
        return (x.a * x.a + x.b * x.b < y.a * y.a + y.b * y.b); 
    }
};

int main()
{
    // De cong 2 kieu SoPhuc voi nhau ta can qua tai dau +
    cout << "Cong 2 SoPhuc:" << endl;
    SoPhuc a{1, 2}, b{3, 4};
    SoPhuc c = a + b;
    cout << c.a << " " << c.b;
    cout << endl;

    // Nhap xuat, cong 2 so phuc:
    cout << "Nhap xuat, cong 2 so phuc:" << endl;
    SoPhuc d, e;
    cin >> d >> e;
    cout << d + e;
    cout << endl;

    // So sanh 2 SoPhuc (co bang nhau):
    cout << "So sanh 2 SoPhuc (co bang nhau):" << endl;
    cout << (d == e ? "Yes" : "No");
    cout << endl;

    // So sanh 2 SoPhuc (xet nho hon):
    cout << "So sanh 2 SoPhuc (xet nho hon):" << endl;
    cout << (d < e ? "Yes" : "No");
    cout << endl;

    return 0;
}