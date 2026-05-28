#include <iostream>

struct PhanSo
{
    int tu;
    int mau;

    void RutGon();

    PhanSo operator + (PhanSo ps)
    {
        PhanSo tong;
        tong.tu = tu * ps.mau + ps.tu * mau;
        tong.mau = mau * ps.mau;

        tong.RutGon();
        return tong;
    }
};

int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

std::istream& operator >> (std::istream& input, PhanSo& ps)
{
    input >> ps.tu >> ps.mau;
    return input;
}

std::ostream& operator << (std::ostream& output, const PhanSo& ps)
{
    output << ps.tu << "/" << ps.mau;
    return output;
}

bool operator == (PhanSo a, PhanSo b)
{
    a.RutGon();
    b.RutGon();
    return (a.tu == b.tu and a.mau == b.mau);
}

bool operator != (PhanSo a, PhanSo b)
{
    return !(a == b);
}

int main()
{
    PhanSo ps1, ps2;
    std::cin >> ps1 >> ps2;

    std::cout << ps1 + ps2 << std::endl;

    return 0;
}

void PhanSo::RutGon()
{
    int ucln = UCLN(tu, mau);

    tu /= ucln;
    mau /= ucln;

    if (mau < 0)
    {
        tu = -tu;
        mau = -mau;
    }
}