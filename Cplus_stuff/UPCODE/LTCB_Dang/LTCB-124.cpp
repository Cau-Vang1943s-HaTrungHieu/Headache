/*
Viết hàm kiểm tra trong mảng các số nguyên có tồn tại giá trị chẵn nhỏ hơn 2004 hay không?
Nếu có thì in ra màn hình "Yes"
Nếu không thì in ra màn hình "No"
VD:
input: 
4
2 3 5 7
output: Yes
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
    bool ktra = false;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0 && a[i] < 2004){
            ktra = true;
            break;
        }
    }
    if(ktra == true) cout << "Yes";
    else cout << "No";
    return 0; 
}