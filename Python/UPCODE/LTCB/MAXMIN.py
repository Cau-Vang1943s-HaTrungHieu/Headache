num = int(input())

digits = [int(digit) for digit in str(num)]
print(min(digits) + max(digits))
