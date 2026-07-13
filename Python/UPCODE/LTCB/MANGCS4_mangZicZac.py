n, m = map(int, input().split())
mang = []
for _ in range(n):
    mang.extend(map(int, input().split()))
mang.sort()
matrix = []
for i in range(n):
    row = mang[i*m:(i+1)*m]
    if (i % 2 == 1):
        row = row[::-1]
    print(*row)