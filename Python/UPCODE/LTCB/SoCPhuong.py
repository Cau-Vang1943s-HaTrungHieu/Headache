def is_perfect_sqr(num):
    if (num < 0): return False
    sqrNum = num ** 0.5
    return sqrNum * sqrNum == num

num = int(input())
print("yes" if is_perfect_sqr(num) else "no")