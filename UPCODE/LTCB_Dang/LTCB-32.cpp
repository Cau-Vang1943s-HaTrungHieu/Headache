/*Kiểm tra số Chính phương
Nếu có thì in ra màn hình "YES"
Nếu không thì in ra màn hình "NO"
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n; cin >> n;
    int x = sqrt(n);
    if(x*x == n) cout << "YES";
    else cout << "NO";
    return 0;
}