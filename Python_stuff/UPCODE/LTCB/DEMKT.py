chars = input().split()
char_count = {}

for char in chars:
    if char in char_count:
        char_count[char] += 1
    else:
        char_count[char] = 1

for char in sorted(char_count.keys()):
    print(f"{char}:{char_count[char]}")