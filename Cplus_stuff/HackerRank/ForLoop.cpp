// Web: HackerRank

#include <iostream>
using namespace std;

int main()
{
    string numbers[] = {"null", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int a, b;
    scanf("%d %d", &a, &b);

    for (int n = a; n <= b; ++n) {
        if (n >= 1 and n <= 9) {
            cout << numbers[n];
        } else {
            if (n % 2 == 0) printf("even");
            else printf("odd");
        }
        cout << endl;
    }

    return 0;
}