index = int(input())
num = int(input())

digits = [int(digit) for digit in str(num)]

if (0 <= index <= len(digits) - 1):
    print(digits[index])
else:
    print(-1)