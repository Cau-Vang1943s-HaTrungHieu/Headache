height = int(input())

for i in range(height):
    spaces = ' ' * (height - i - 1)
    asterisks = '*' * (2 * i + 1)
    line = spaces + asterisks + spaces
    print(line) if i != height - 1 else print(line, end="")