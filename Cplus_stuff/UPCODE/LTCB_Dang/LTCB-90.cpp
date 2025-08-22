/*
Viết chương trình tìm số nguyên dương m lớn nhất sao cho 1 + 2 + 3 + ... + m < N
*/
#include <iostream>
using namespace std;
int main(){
    unsigned int n;
    cin>>n;
    long tong=0;
    int kq;
    for (long i=1; i<n ; i++){
        tong+=i;
        if (tong>n){
            break;
        }
        kq=i;
    }
    cout<<kq;
}