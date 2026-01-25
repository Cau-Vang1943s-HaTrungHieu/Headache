// Ma: H_TINHTONG
// Ten: Tính tổng

#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

double S_n(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (i * (i + 1));
    }
    return sum;
}

int main()
{
    int n; cin >> n;
    cout << fixed << setprecision(5) << S_n(n) << endl;

    return 0;
}