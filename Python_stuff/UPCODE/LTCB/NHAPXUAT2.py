a, b = map(int, input().split())

temp = a
a = b
b = temp
print(str(a) + " " + str(b))