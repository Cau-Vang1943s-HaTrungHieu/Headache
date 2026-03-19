#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int freq[1001] = {0};  // Assuming input values are between 0 and 1000

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++freq[a[i]];
    }

    int dupCount = 0;
    for (int i = 0; i <= 1000; ++i) {
        if (freq[i] > 1) ++dupCount;
    }

    cout << dupCount;
    return 0;
}
