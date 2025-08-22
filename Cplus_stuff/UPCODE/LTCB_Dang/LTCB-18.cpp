/*
Tính S(n) = 1 + x^2 / 2! +  ... + x^2n / (2n)!.
Ví dụ:

Input

Output

Input mẫu

1

1

Output mẫu

1.50


*/
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int giaiThua(int n)
{
    if (n == 1)
        return 1;
    return n * giaiThua(n - 1);
}
int main(){
    float x,n,s,a;
    cin>>x>>n;
    s=1;
    for(int i=1;i<=n;i++){a=pow(x,2*i)/giaiThua(2*i);
    s=s+a;
    }
    cout << fixed << setprecision(2) <<s;
}