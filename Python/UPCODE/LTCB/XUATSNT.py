def isPrime(num):
    if (num == 2): return True
    if (num < 2 or num % 2 == 0): return False
    for i in range(3, int(num ** 0.5) + 1, 2):
        if (num % i == 0): return False
    return True

n = int(input())
found = False
for i in range(n + 1):
    if (isPrime(i)):
        found = True
        print(i, end=" ")

if (not found):
    print(-1)