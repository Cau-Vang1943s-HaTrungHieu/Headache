/*Hãy tính tích các chữ số của số nguyên dương n*/
#include <iostream>
using namespace std;
int main() {
    int n, tich = 1;
    cin >> n;
    while(n > 0){
        int cs = n % 10; 
        tich *= cs;
        n /= 10; 
    }
    cout << tich;
    return 0;
}