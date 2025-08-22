/*Viết chương trình nhập 3 cạnh của một tam giác (có thể là số thực). Hãy cho biết đó là tam giác gì?
- Tam giác đều (xuất: deu)
- Tam giác vuông (xuất: vuong)
- Tam giác cân (xuất: can)
- Tam giác bình thường (xuất: tam giac binh thuong)
Nếu không phải 3 cạnh của tam giác thì xuất -1.
VD: input: 3 4 5        output: vuong
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    if(a + b <= c || a + c <= b || b + c <= a){
        cout << -1;
    }
    else if(a == b && b == c){
        cout << "deu";
    }
    else if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a){
        cout << "vuong";
    }
    else if(a == b || a == c || b == c){
        cout << "can";
    }
    else{
        cout << "tam giac binh thuong";
    }
}