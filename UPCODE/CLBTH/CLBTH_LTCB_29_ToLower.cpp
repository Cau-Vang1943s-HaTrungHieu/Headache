#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string decapitalise(const string& input)
{
    string result = input;
    for (int i = 0; i <= input.size(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

int main()
{
    string s; 
    getline(cin, s);
    cout << decapitalise(s);

    return 0;
}