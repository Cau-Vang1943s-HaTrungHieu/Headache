/*

Nhập n phần tử của mảng một chiều. Nhập các giá trị cho mảng một chiều.Tìm “số hoàn thiện đầu tiên” trong mảng một chiều các số nguyên. Nếu mảng không có số hoàn thiện thì trả về giá trị -1.
Lưu ý: Input: Nhập n trước, sau đó nhập các giá trị của mảng sau.
VD:
Input:
4
5
-1
6
2
Output: 
6
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] <= 1) continue; // Số hoàn thiện phải lớn hơn 1
        int tong = 0;
        for(int j = 1;j < a[i]; j++){
            if(a[i] % j == 0) tong += j;
        }
        if(tong == a[i]){
            cout << a[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}