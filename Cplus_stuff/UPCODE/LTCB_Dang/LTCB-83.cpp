/*Viết chương trình nhập vào hai số thực a, b. Kiểm tra xem chúng có cùng dấu hay không. 
Nếu cùng dấu, xuất "YES". Không thì xuất "NO". Nếu a=0 hoặc b=0 thì xuất "0".
*/
#include <iostream>
using namespace std;
int main(){
    double a, b;
    cin >> a >> b;
    if(a > 0 && b > 0 || a < 0 && b < 0){
        cout << "YES";
    } 
    else if(a == 0 || b == 0){
        cout << 0;
    }
    else cout << "NO";
    return 0;
}