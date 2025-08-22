/*
Tính S(n) = 1/2 + 3/4 + ... + (2n + 1) / (2n + 2).
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    float tong=0;
    for (long i=0; i<=n;i++){
        tong+=float((2*i+1))/(2*i+2);
    }
    cout<<tong;
}