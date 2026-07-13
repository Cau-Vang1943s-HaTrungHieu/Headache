def converted_base(num, choice = 0):
	match choice:
		case 0: base = 2
		case 1: base = 8
		case 2: base = 16
		case _: base = 2
	
	digits = "0123456789ABCDEF"
	result = ""
	while (num > 0):
		result = digits[num % base] + result
		num //= base
	return result

n, choice = map(int, input().split())
print(converted_base(n, choice))