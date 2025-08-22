/*

Nhập n phần tử của mảng một chiều. Nhập các giá trị của mảng. Tìm giá trị âm đầu tiên trong mảng một chiều các số thực. Nếu mảng không có giá trị âm thì trả về giá trị 1.
Lưu ý: Nhập n trước. Sau đó nhập các giá trị của mảng sau.
VD:
Input: 
5
1
-5
3
-4
4
Output: 
-5

*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            cout << a[i];
            return 0;
        }
    }
    cout << 1;
    return 0;
}