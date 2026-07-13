height = int(input())
for i in range(height):
    spaces = ' ' * i
    asterisks = '*' * (2 * (height - i) - 1)
    line = spaces + asterisks + spaces
    print(line) if i != height - 1 else print(line, end="")