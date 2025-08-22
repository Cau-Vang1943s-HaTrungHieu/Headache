#include <iostream>
#include <cmath>
using namespace std;

double squareArea(double edge)
{
    return edge * edge;
}

const double Pi = atan(1) * 4;
double circleArea(double diameter)
{
    double radius = static_cast<double> (diameter) / 2.0; 
    return Pi * (radius * radius);
}

int main()
{
    double n;
    cin >> n;
    cout << squareArea(n) - circleArea(n);
    
    return 0;
}