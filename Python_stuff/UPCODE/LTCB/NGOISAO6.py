h = int(input())
for i in range(h):
    line = ""
    for j in range(2 * h - 1):
        if i == h - 1:
            line += "*"
        else:
            if j == h - i - 1 or j == h + i - 1:
                line += "*"
            else:
                line += " "
    print(line, end="" if i == h - 1 else "\n")