/*Hãy tìm chữ số đảo ngược của số nguyên dương n. 
Yêu cầu bài toán: Hãy tìm chữ số đảo ngược của số nguyên dương n. 
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    //Cách 1
    int n; cin >> n;
    while(n > 0){
        int cs = n % 10;
        cout << cs;
        n /= 10;
    }
    // Cách 2
    /*string n; cin >> n;
    reverse(n.begin(), n.end());
    cout << n;
    */
    return 0;
}