#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int total = 0;
    for (int i = 0; i < s.size(); ++i) {
        int count = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[i] == s[j]) count++;
        }
        if (count == 1) total++;
    }

    cout << total << endl;

    return 0;
}      

/*
#include <iostream>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    
    int times = 0; 
    for (int i = 0; i < s.length(); ++i) {
        bool isDuplicate = false;

        for (int j = 0; j < s.length(); ++j) {
            if (i != j and s[j] == s[i]) {
                isDuplicate = true;
                break; 
            }
        }
        
        if (!isDuplicate) ++times;
    }

    cout << times;

    
    return 0;
}
*/ 