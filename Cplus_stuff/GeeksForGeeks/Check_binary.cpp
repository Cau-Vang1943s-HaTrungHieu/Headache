/***********************************************
    Given a number N, the task is to check first whether the 
    given number is binary or not and its value should be greater 
    than 1. print true if N is the binary representation else 
    print false.

    Examples:
        Input: N = 1010 
        Output: true 
        Explanation: 
        Given number is greater than 1 and none of its digits is greater than 1. Thus, it is a binary number greater than 1.

        Input: N = 1234 
        Output: false 
        Explanation: 
        Given number is greater than 1 but some of its digits { 2, 3, 4} are greater than 1. Thus, it is not a binary number. 
***********************************************/

#include <iostream>
using namespace std;

bool isBin(string s)
{
    if (s == "0" || s == "1") return false;
    
    for (char c : s) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

int main()
{
    string number;
    cin >> number;

    cout << (isBin(number) ? "True" : "False") << endl;
    return 0;
}