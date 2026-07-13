#include <iostream>
#include <cmath>
using namespace std;

bool isRightTriangle(double a, double b, double c)
{
    return  
    fabs(a * a + b * b - c * c) < 1e-6 or   
    fabs(a * a + c * c - b * b) < 1e-6 or  
    fabs(b * b + c * c - a * a) < 1e-6;
}

int main()
{
    float a, b, c;
    cin >> a >> b >> c;

    if (a + b <= c or a + c <= b or b + c <= a) cout << -1;
    else if (a == b and b == c) cout << "deu";
    else if (isRightTriangle(a, b, c)) cout << "vuong";
    else if (a == b or b == c or a == c) cout << "can";
    else cout << "tam giac binh thuong";

    return 0;
}