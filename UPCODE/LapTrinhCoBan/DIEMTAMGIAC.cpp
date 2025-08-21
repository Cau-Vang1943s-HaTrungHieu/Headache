#include <iostream>
#include <cmath>
using namespace std;

struct Coordinate
{
    int x, y;

    double to(Coordinate other)
    {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    bool coincidesWith(Coordinate other)
    {
        return x == other.x and y == other.y;
    }

    friend istream& operator >> (istream& input, Coordinate& coord)
    {
        input >> coord.x >> coord.y;
        return input;
    }

    friend ostream& operator << (ostream& output, Coordinate coord) 
    {
        output << "(" << coord.x << "," << coord.y << ")";
        return output;
    }
};

struct Triangle
{
    Coordinate A, B, C;

    double perimeter()
    {
        double AB = A.to(B);
        double BC = B.to(C);
        double CA = C.to(A);
        return AB + BC + CA;
    }

    double acreage()
    {
        return 0.5 * (abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)));
    }

    friend istream& operator >> (istream& input, Triangle& tri)
    {
        input >> tri.A >> tri.B >> tri.C;
        return input;
    }

    friend ostream& operator << (ostream& output, Triangle tri)
    {
        output << tri.A << tri.B << tri.C;
        return output;
    }
    
    bool coincidesWith(Triangle other)
    {
        return // 3! = 6 cases
        (A.coincidesWith(other.A) and B.coincidesWith(other.B) and C.coincidesWith(other.C)) or
        (A.coincidesWith(other.B) and B.coincidesWith(other.A) and C.coincidesWith(other.C)) or
        (A.coincidesWith(other.C) and B.coincidesWith(other.B) and C.coincidesWith(other.A)) or
        (A.coincidesWith(other.A) and B.coincidesWith(other.C) and C.coincidesWith(other.B)) or
        (A.coincidesWith(other.B) and B.coincidesWith(other.C) and C.coincidesWith(other.A)) or
        (A.coincidesWith(other.C) and B.coincidesWith(other.A) and C.coincidesWith(other.B));
    }
};

int main()
{
    Triangle abc, def;
    cin >> abc >> def;

    cout << abc << endl << def << endl;
    cout << (abc.perimeter() < def.perimeter() ? "TRUE" : "FALSE") << endl;
    cout << (abc.coincidesWith(def) ? "TRUE" : "FALSE");

    return 0;
}


