/*
Tính S(n) = x + x^2 / 1 + 2 + x^3 / 1 + 2 + 3 + ... + x^n / 1 + 2 + ... + n.
*/

#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    float s=0;
    int n,x;
    cin>>x;
    cin>>n;
    
    
    for(int i=1;i<=n;i++)
    {
        s=s+(float)(2*pow(x,i)/(pow(i,2)+i));
    }
    cout<<s;
    return 0;
}