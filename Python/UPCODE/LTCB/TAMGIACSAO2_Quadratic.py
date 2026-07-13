"""
Suppose we have a triangle with height 4, we have:
*
**
***
****
1 + 2 + 3 + 4 = 10 asterisks
So, for a triangle of height h, the total number of asterisks needed
is the sum of the first h natural numbers:
Total = (h * (h + 1) / 2)

But in this case, we're only given the number of asterisks
"""
import math
def is_triangular(n):
    # Solve h(h+1)/2 = n → h^2 + h - 2n = 0
    # Use quadratic formula: h = (-1 + sqrt(1 + 8n)) / 2
    discriminant = 1 + 8 * n
    root = (-1 + math.sqrt(discriminant)) / 2
    return root.is_integer()

asterisks = int(input())
if (is_triangular(asterisks)):
    print("YES")
else: print("NO")