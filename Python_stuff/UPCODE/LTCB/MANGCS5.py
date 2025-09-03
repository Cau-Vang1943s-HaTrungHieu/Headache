def is_perfect_sqr(num):
    sqrNum = num ** 0.5
    return sqrNum * sqrNum == num

values = list(map(int, input().split()))

print(sum(value for value in values if (is_perfect_sqr(value))))        