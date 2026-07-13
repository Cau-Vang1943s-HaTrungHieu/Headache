def gcd(a, b):
    while (b != 0):
        tmp = b
        b = a % b
        a = tmp
    return a

a, b = int(input()), int(input())
print(gcd(a, b))