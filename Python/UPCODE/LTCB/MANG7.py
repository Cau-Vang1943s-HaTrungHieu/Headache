n = int(input())
array = []
for i in range(n):
    row = list(map(int, input().split()))
    array. append(row)
for i in range(n):
    print(array[i][i], end=' ')