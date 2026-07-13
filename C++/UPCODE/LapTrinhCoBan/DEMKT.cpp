#include <iostream>
using namespace std;

void charFrequency(char c[], int numOfCharacters)
{
    int freq[26] = {}; // Index 0 -> 'a', 1 -> 'b', ..., 25 -> 'z'
    // a = 97, b = 98, ... , z = 122

    for (int i = 0; i < numOfCharacters; ++i) {
        if (c[i] >= 'a' && c[i] <= 'z') {
            freq[c[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            cout << static_cast<char>(i + 'a') << ":" << freq[i] << endl;
        }
    }
}

int main()
{
    int numOfCharacters = 0;
    char c[100];

    char character;
    while (cin >> character) {
        if (character >= 'a' && character <= 'z') {
            c[numOfCharacters++] = character;
        }
    }

    charFrequency(c, numOfCharacters);
    return 0;
}

