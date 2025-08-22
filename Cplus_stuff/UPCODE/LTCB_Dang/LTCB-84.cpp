/*Giải phương trình và biện luận phương trình ax + b = 0.

Nhập: 2 số thực a, b. 
Xuất:
- "1" nếu vô số nghiệm.
- "0" nếu vô nghiệm.
- xuất ra nghiệm nếu pt có nghiệm.
*/
#include <iostream>
using namespace std;
int main(){
    double a, b;
    cin >> a >> b;
    if(a == 0 && b == 0) cout << "1";
    else if(a == 0 && b != 0) cout << "0";
    else cout << -b / a;
    return 0;
}