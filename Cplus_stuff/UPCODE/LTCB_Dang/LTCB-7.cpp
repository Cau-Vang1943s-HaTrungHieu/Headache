/*
S(n)= 1/2 + 2/3 + 3/4 + ... + n/(n+1)
Input: 3
Output: 1.917
Chú ý: Làm tròn đến số thập phân thứ 3
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    long long n;
    cin >> n;
    float tong = 0;
    for (long long i=1; i<=n; i++){
        tong+=float(i)/(i+1);
    }
    cout<<fixed<<setprecision(3) << tong;
    return 0;
}