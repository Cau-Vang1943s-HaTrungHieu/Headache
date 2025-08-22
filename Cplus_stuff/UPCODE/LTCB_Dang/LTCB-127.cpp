/*Viết hàm sắp xếp mảng một chiều các số thực tăng dần.
Input:
Dòng 1 nhập vào n phần tử. 
Dòng 2 nhập vào mảng số thực. 
Output :
In ra mảng sau sắp xếp.
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}