#include <iostream>
#include <algorithm>
using namespace std;

struct SinhVien
{
    string msv, ten;
    double gpa;

    // Qua tai toan tu < de sap xep tang dan
    bool operator < (const SinhVien other) 
    {
        return gpa < other.gpa;
    }
};

int main()
{
    int n; 
    cin >> n;
    SinhVien ds[n];

    for (int i = 0; i < n; ++i) {
        cin >> ds[i].msv;
        cin.ignore(); getline(cin, ds[i].ten);
        cin >> ds[i].gpa;
    }
    // Sap xep theo gpa.
    sort(ds, ds + n);

    for (SinhVien x : ds) {
        cout << x.msv << " " << x.ten << " " << x.gpa << endl;
    }

    return 0;
}