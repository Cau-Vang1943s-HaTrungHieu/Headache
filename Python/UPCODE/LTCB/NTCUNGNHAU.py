def gcd(a, b):
    while (b != 0):
        tmp = b
        b = a % b
        a = tmp
    return a

a, b = map(int, input().split())
print("yes" if gcd(a, b) == 1 else "no")