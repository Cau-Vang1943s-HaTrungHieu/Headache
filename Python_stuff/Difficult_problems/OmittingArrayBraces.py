index, value = map(int, input().split())
my_list = list(map(int, input().split()))
my_list.insert(index, value)

# string val only!
print(' '.join(map(str, my_list)))

# For loop
for i in my_list:
    print(i, end = ' ')
print()

# Unpacking method using unpacking operator *
print(*my_list)

# List Comprehension
[print(i, end = ' ') for i in my_list]
