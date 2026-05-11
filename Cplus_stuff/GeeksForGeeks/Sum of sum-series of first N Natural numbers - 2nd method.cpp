/***********************************************
    Sum of sum-series of first N Natural numbers
    GeeksForGeeks

    Given a natural number n, find the sum of the sum-series of the first N natural number.
    Sum-Series: is sum of first N natural numbers, i.e, sum-series of 5 is 15 ( 1 + 2 + 3 + 4 + 5 ).

    Examples:
        Input: N = 5 
        Output: 35 
        Explanation: 
        Sum of sum-series of {1, 2, 3, 4, 5} i.e. {1 + 3 + 6 + 10 + 15} is 35.

        Input: N = 2 
        Output: 4 
        Explanation: 
        Sum of sum-series of {1, 2} i.e. {1 + 3} is 4. 
 ***********************************************/

 #include <iostream>
 using namespace std;

 static long sumOfSumSeries(int n)
 {
    long sum = 0L;

    for (int i = 1; i <= n; i++) {
        sum = sum + (i * (i + 1)) / 2;
    }
    return sum;
 }

 int main()
 {
    int n = 5;
    cout << sumOfSumSeries(5);
    return 0;
 }