def isPrime(num):
    if (num == 2): return True
    if (num < 2 or num % 2 == 0): return False
    for i in range(3, int(num ** 0.5) + 1, 2):
        if (num % i == 0): return False
    return True

k = int(input())
intVals = list(map(int, input().split()))
maxPrimeNum = -1
found = False
for i in intVals:
    if (isPrime(i) and i > maxPrimeNum and i <= k):
        maxPrimeNum 