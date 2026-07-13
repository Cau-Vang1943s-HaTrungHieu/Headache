a, b = map(int, input().split())
my_list = [[0] * b for _ in range(a)]
num = 1
for i in range(a):
    if (i % 2 == 0):
        for j in range(b):
            my_list[i][j] = num
            num += 1
    else:
        for j in range(b - 1, -1, -1):
            my_list[i][j] = num
            num += 1
for row in my_list:
    print(*row)