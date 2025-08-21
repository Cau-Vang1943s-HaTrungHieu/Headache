/*
Viết chương trình nhập n và tính tổng S = 1 + 2 + 3 + ... + n.
Ví dụ:

Input

utput

Input mẫu

5

Output mẫu

15

Ví dụ:

Input

Output

Input mẫu

-100

Output mẫu

-1
*/
#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    if(n < 0) cout << -1;
    else {
        long long S = 0;
        for(long long i = 1; i <= n; i++) S += i;
        cout << S;
    }
    return 0;
}