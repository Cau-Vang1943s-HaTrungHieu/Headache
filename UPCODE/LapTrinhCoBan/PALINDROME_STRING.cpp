#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
    stack<char> st;
    string cleaned = "";

    // Buoc 1: lam sach chuoi (chi lay ky tu hoac so, va chuyen ve chu thuong)
    for (char c : s) {
        if (isalnum(c)) { // isalnum = alphanumeric (a - z 0 - 9)
            cleaned += tolower(c);
        }
    }

    int len = cleaned.length();

    //Buoc 2: Dua nua dau vao stack
    for (int i = 0; i < len / 2; ++i) {
        st.push(cleaned[i]);
    }

    // Buoc 3: So sanh nua sau voi stack
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;
    // If length of string is even then divide length by 2, otherwise divide by 2 then add 1
    for (int i = start; i < len; ++i) {
        if (st.top() != cleaned[i]) {
            return false;
        }
        st.pop();
    }
    
    return true;
}

int main()
{
    string s;
    getline(cin, s);

    cout << (isPalindrome(s) ? "YES" : "NO");
    
    return 0;
}