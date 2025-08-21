#include <iostream>
using namespace std;

struct Slot
{
    string maSo;
    string sdt;
    string nhaMang;

    void layThongTin()
    {
        cin >> maSo >> sdt >> nhaMang;
    }

    void xuatThongTin()
    {
        cout << maSo << " " << sdt << " " << nhaMang;
    }
};

void timKiem(Slot sim[], int soLuongSim, string sdtCanTim)
{
    string baSoDauCanTim = sdtCanTim.substr(0, 3);

    for (int i = 0; i < soLuongSim; ++i) {
        string baSoDau = sim[i].sdt.substr(0, 3);
        if (baSoDauCanTim == baSoDau) {
            cout << sim[i].maSo << ":" << sim[i].sdt << ":" << sim[i].nhaMang << endl;
        }
    }
}

int main()
{
    int n; 
    Slot sim[100];
    cin >> n;

    for (int i = 0; i < n; ++i) {
        sim[i].layThongTin();
    }

    string sdt;
    cin >> sdt;
    timKiem(sim, n, sdt);

    return 0;
}