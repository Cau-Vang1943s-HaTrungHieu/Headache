/*
Viết chương trình nhập vào tháng của một năm. Cho biết tháng thuộc quý mấy trong năm.
Biết rằng cứ 3 tháng là 1 quý.
Ví dụ: tháng 1 thuộc quý 1, tháng 8 thuộc quý 3.
*/
#include <iostream>
using namespace std;
int main(){
    int m;
    cin >> m;
    switch(m){
        case1: case 2: case 3:
            cout << "Quy 1";
            break;
        case 4: case 5: case 6:
            cout << "Quy 2";
            break;
        case 7: case 8: case 9:
            cout << "Quy 3";
            break;
        case 10: case 11: case 12:
            cout << "Quy 4";
            break;
        default:
            cout << "Invalid month";
            break;
    }
    return 0;
}
// Cách 2: Sử dụng if-else
/*
if(m >= 1 && m <= 3) cout << 1;
else if(m >= 4 && m <= 6) cout << 2;
else if(m >= 7 && m <= 9) cout << 3;
else if(m >= 10 && m <= 12) cout << 4;
else cout << "Invalid month";
*/  