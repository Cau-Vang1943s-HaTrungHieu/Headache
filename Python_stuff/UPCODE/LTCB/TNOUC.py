n = int(input())
if n <= 16:
    total = n * 7000
elif n <= 50:
    total = 16 * 7000 + (n - 16) * 8500
else:
    total = 16 * 7000 + (50 - 16) * 8500 + (n - 50) * 100000

print(total)