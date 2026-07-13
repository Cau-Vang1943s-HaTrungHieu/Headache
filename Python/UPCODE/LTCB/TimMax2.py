n, m = map(int, input().split())
array = [list(map(int, input().split())) for _ in range(n)]
maxVal = array[0][0]
for i in range(n):
    for j in range(m):
        if (array[i][j] > maxVal):
            maxVal = array[i][j]
print(maxVal)