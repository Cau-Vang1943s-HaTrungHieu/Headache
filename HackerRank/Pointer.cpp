#include <iostream>
using namespace std;

void update(int *a, int *b)
{
    int temp = *a;  // copy value of a to temporary variable
    *a = *a + *b;
    *b = abs(temp - *b);
}

int main()
{   
    int a, b;
    int *p_a = &a, *p_b = &b;
    
    scanf("%d %d", &a, &b);
    update(p_a, p_b);
    cout << a << endl << b;

    return 0;
}