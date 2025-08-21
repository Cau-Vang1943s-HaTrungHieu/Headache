/*
Hãy tìm “giá trị dương nhỏ nhất” trong mảng các số thực (duongnhonhat).
Nếu mảng không có giá trị dương thì trả về giá trị
không dương là – 1.
Input: 
Dòng đầu nhập n.
Dòng hai nhập mảng.
*/
#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    double min_duong = 1e9;
    bool co_duong = false;
    
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            if(a[i] < min_duong){
                min_duong = a[i];
                co_duong = true;
            }
        }
    }
    
    if(co_duong) cout << min_duong;
    else cout << -1;
    return 0;
}