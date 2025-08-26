width, length = map(int, input().split())

for w in range(width):
    print("*" * length, end = "\n" if w < width - 1 else "")