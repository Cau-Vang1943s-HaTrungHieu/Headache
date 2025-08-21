/*
Tìm ước số lẻ lớn nhất của số nguyên dương n. Ví dụ n = 100 ước lẻ lớn nhất của 100 là 25. 
 Yêu cầu bài toán: nhập vào một số nguyên n và tìm ước LẺ lớn nhất của n.



Ví dụ:

Input
120
Output
15
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n <= 0) cout << -1;
    else {
        for(int i = n/2; i >= 1 ; i--){
            if(n % i == 0 && i % 2 != 0){
                cout << i;
                return 0;
            }
        }
    }
}