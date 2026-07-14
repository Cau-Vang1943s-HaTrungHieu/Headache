#include <iostream>
using namespace std;

struct Time
{
    int gio, phut, giay;
};

struct Ticket
{
    string tenVe;
    Time time;
};

int main()
{
    Ticket a;
    getline(cin, a.tenVe);
    cin >> a.time.gio >> a.time.phut >> a.time.giay;
    

    return 0;
}
