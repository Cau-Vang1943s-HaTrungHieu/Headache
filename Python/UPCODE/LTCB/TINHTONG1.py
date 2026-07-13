num = int(input())

total = 0
for i in range(1, num + 1):
    total += 1 / i ** 3

print(round(total, 3))