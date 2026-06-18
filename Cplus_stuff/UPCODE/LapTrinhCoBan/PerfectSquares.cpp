#include <iostream>
#include <cmath>
using namespace std;

/*
    PERFECT SQUARE
    - Perfect square is an integer that is a product of an integer
    by itself or as the second exponent of an integer.
*/

bool is_perfect_sqr(int num)
{
    int sqr_num = sqrt(num);
    return sqr_num * sqr_num == num;
}

int main()
{  
    int n;
    cin >> n;
    int sqrNum = sqrt(n);
    
    cout << (is_perfect_sqr(n) ? "YES" : "NO") << endl;

    return 0;
}