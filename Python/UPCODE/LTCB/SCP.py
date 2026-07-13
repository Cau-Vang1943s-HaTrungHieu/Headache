import math

def is_perfect_sqr(num):
    sqrNum = math.isqrt(num)
    return sqrNum * sqrNum == num

num = int(input())
print("yes") if (is_perfect_sqr(num)) else print("no")