/*Hãy đếm số lượng chữ số lẻ của số nguyên dương n. 
  Yêu cầu bài toán: Nhập vào số nguyên dương n. Xuất ra màn hình số lượng chữ số lẻ của số nguyên dương ấy.
Ví dụ:

Input
1234
Output
2
*/
#include <iostream>
using namespace std;
int demcsl(int n){
    int dem = 0;
    while(n > 0){
        int cs = n % 10;
        if(cs % 2 != 0) dem++;
        n /= 10;
    }
    return dem;
}
int main(){
    int n; cin >> n;
    cout << demcsl(n);
    return 0;
}