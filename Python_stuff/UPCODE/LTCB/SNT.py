def is_prime(num):
    if (num == 2): return True
    if (num < 2 or num % 2 == 0): return False
    for i in range(3, int(n ** 0.5) + 1, 2):
        if (num % i == 0): return False
    return True

n = int(input())
print("true") if (is_prime(n)) else print("false")

# Explanation
"""
- n ** 0.5 is a way of calculating the square root of n
- The ** operator means exponentiation, so n ** 0.5 is the same as
square root of n
- Add 1 in order not to let it stop before reaching the square
root of n
"""