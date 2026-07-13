values = list(map(int, input().split()))

total = 0
for i in values:
    total += i

print(str(values[0]) + "+" + str(values[1]) + "=" + str(total))