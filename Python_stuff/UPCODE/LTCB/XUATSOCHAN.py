values = list(map(str, input().split()))

for i in values:
    if (i.isdigit() and int(i) % 2 == 0):
        print(i, end=" ")