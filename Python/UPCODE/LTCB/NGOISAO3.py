width, length = map(int, input().split())

for w in range(width):
    if (0 < w < width - 1):
        print('*' + " "*(length - 2) + '*')
    else: 
        print("*" * length, end = "\n" if w < width - 1 else "")