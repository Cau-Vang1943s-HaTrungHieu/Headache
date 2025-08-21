#include <iostream>
using namespace std;

struct LineSegment
{
    int a, b;

    void addsPoints()
    {
        cin >> a >> b;
    }

    bool contains(int point) const
    {
        return point >= a && point <= b;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    LineSegment lseg[n];

    int maxPoint = 0;
    for (int i = 0; i < n; ++i) {
        lseg[i].addsPoints();
        if (lseg[i].b > maxPoint) {
            maxPoint = lseg[i].b;
        }
    }

    int count = 0;
    for (int pt = 1; pt <= maxPoint; ++pt) {
        int segsWithPt = 0;
        for (int i = 0; i < n; ++i) {
            if (lseg[i].contains(pt)) {
                ++segsWithPt;
            }
        }

        if (segsWithPt == k) {
            ++count;
            // Optional: Print the point
            // cout << pt << " ";
        }
    }

    cout << count;
    return 0;
}
