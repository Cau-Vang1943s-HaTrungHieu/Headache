a, b = map(int, input().split())
operat0r = input()

if (operat0r == '+'): print(str(a) + '+' + str(b) + '=' + str(a + b))
elif (operat0r == '-'): print(str(a) + '-' + str(b) + '=' + str(a - b))
elif (operat0r == '*'): print(str(a) + '*' + str(b) + '=' + str(a * b))
elif (operat0r == '%'): print(str(a) + '%' + str(b) + '=' + str(a % b))
