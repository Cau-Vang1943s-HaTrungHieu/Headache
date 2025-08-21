/*
Liệt kê tất cả ước số của số nguyên dương n
Vi du:
Input: 10
Output: 
1
2
5
10
*/
#include <iostream>
using namespace std;

int US(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cout << i << endl;
    }
}
int main(){
    int n;
    cin >> n;
    if(n <= 0) {
        cout << -1; 
        return 0;
    }
    
    US(n); 
    return 0;
}