import sys

def is_prime(num):
    if num == 2: return True
    if num < 2 or num % 2 == 0: return False
    for i in range(3, int(num ** 0.5) + 1, 2):
        if (num % i == 0): return False
    return True
        
for line in sys.stdin:
    line = line.strip()
    if line.isdigit():
        sum_of_primes = 0
        num = int(line)
        while num > 0:
            digit = num % 10
            if is_prime(digit):
                sum_of_primes += digit
            num //= 10
        print(sum_of_primes)