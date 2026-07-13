num = int(input())

total = 1
for i in range(num + 1):
    multiplication = 1
    for j in range(i + 1):
        multiplication *= (2*(j+1)) / (2*j + 3)
    total += multiplication

print(round(total, 2))