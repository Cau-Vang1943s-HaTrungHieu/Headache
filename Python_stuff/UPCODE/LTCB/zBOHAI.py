def sumOfDivisors(num):
    result = 0
    for i in range(1, num + 1):
        if (num % i == 0):
            result += i
    return result

def productOfDigits(num):
    result = 1
    while (num > 0):
        digit = num % 10
        result *= digit
        num //= 10
    return result

n, m = map(int, input().split())
print("YES") if productOfDigits(n) == sumOfDivisors(m) else print("NO")