/*Tìm giá trị lớn nhất trong mảng 1 chiều các số thực

VD:
input : 
4
1 2 3 4
output: 4
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    double max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max) max = a[i];
    }
    cout << max;
    return 0;
}