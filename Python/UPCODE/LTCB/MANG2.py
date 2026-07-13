listSize = int(input())
values = list(map(int, input().split()))
evenSum = 0
for value in values:
    if (value % 2 == 0):
        evenSum += value
print(evenSum)