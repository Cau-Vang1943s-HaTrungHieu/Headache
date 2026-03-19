#include <bits/stdc++.h>
using namespace std;

// Nhân số lớn với số nguyên nhỏ
string mulBig(string a, int b) {
    reverse(a.begin(), a.end());
    string res;
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int da = a[i]-'0';
        long long prod = 1LL*da*b + carry;
        res.push_back(char(prod%10 + '0'));
        carry = prod/10;
    }
    while (carry) {
        res.push_back(char(carry%10 + '0'));
        carry /= 10;
    }
    while (res.size()>1 && res.back()=='0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int N; cin >> N;
    string fact = "1";
    for (int i = 2; i <= N; i++) {
        fact = mulBig(fact, i);
    }
    cout << fact << "\n";
}
