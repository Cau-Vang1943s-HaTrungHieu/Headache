// Web: HackerRank

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v;

    for (int i = 0; i < n; ++i) {
        int length;
        cin >> length;
        vector<int> arr;
        for (int j = 0; j < length; ++j) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        v.push_back(arr);
    }

    for (int i = 0; i < q; ++i) {
        int a;
        int b;
        cin >> a >> b;
        cout << v[a][b] << endl;
    }
    return 0;
}