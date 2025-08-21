/*Viết chương trình in ra tam giác cân có độ cao h
Ví dụ: 
input : 4
output:
    *
   ***
  *****
*/
#include <iostream>
using namespace std;
int main(){
    int h;
    cin >> h;
    for(int i = 1; i <= h; i++){
        // In khoảng trắng trái
        for(int j = 1; j <= h - i; j++){
            cout << " ";
        }
        // In dấu sao
        for(int j = 1; j <= 2 * i - 1; j++){
            cout << "*";
        }
        // In khoảng trắng phải
        for(int j = 1; j <= h - i; j++){
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}