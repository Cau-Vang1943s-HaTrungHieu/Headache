def binary_convertion(num):
    if num == 0: return "0"

    stack = []
    while (num > 0):
        remainder = num % 2
        stack.append(str(remainder))
        num = num // 2
    
    # Reverse the stack to get the correct binary representation
    binary = ''.join(reversed(stack))
    return binary

num = int(input())
print(binary_convertion(num))