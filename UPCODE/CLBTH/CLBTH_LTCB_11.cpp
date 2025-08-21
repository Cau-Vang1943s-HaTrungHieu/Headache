#include <iostream>
using namespace std;

void inputArray(int a[][205], int rows, int columns)
{
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            cin >> a[r][c];
        }
    }
}

void findMaxSum(int a[][205], int rows, int columns)
{
    int maxSumOfRow = a[0][0];
    int maxSumOfCol = a[0][0];
    for (int r = 0; r < rows; ++r) {
        int sumOfRow = 0;
        for (int c = 0; c < columns; ++c) {
            sumOfRow += a[r][c]; 
        }
        if (sumOfRow > maxSumOfRow) maxSumOfRow = sumOfRow;
    }
    
    for (int c = 0; c < columns; ++c) {
        int sumOfCol = 0;
        for (int r = 0; r < rows; ++r) {
            sumOfCol += a[r][c];
        }
        if (sumOfCol > maxSumOfCol) maxSumOfCol = sumOfCol;
    }
    
    cout << maxSumOfRow << endl << maxSumOfCol;
}

int main()
{
    int n, m;
    int a[205][205];
    cin >> n >> m;
    
    inputArray(a, n, m);
    findMaxSum(a, n, m);
    
    return 0;
}