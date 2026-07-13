num = int(input())
hundreds = int(num / 100)
tens = int(num / 10 % 10)
ones = int(num % 10)

print(ones)
print(hundreds)
print(tens, end = '')