def isPerfectSqr(number):
    sqrNum = number ** 0.5
    return sqrNum * sqrNum == number

redundantVar = int(input())
my_list = list(map(int, input().split()))
perfectSqrSum = sum(x for x in my_list if isPerfectSqr(x))
print(perfectSqrSum)