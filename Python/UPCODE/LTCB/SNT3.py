def isPrime(num):
    if (num == 2): return True
    if (num < 2 or num % 2 == 0): return False
    for i in range(3, int(num ** 0.5) + 1, 2):
        if (num % i == 0): return False
    return True

begin, end = map(int, input().split())

for i in range(begin, end + 1):
    if (isPrime(i)): print(i)