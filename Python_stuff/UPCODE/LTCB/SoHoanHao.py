def is_perfect(num):
    if num < 2: return False
    divisor_sum = 1
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            divisor_sum += i
    return divisor_sum == num

n = int(input())
print("Yes") if (is_perfect(n)) else print("No")