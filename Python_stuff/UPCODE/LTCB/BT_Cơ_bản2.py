def gcd(a, b):
    while (b != 0):
        tmp = b
        b = a % b
        a = tmp
    return a

a, b = map(int, input().split())
lcm = (a * b) / gcd(a, b)
print(f"{int(gcd(a, b))} {int(lcm)}")
