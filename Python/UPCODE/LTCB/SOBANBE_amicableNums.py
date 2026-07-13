def sumOfDivisors(num):
    result = 0
    for i in range(1, num):
        if (num % i == 0):
            result += i
    return result

def areFriends(a, b):
    return sumOfDivisors(a) == b and sumOfDivisors(b) == (a)

a, b = map(int, input().split())

print("YES") if areFriends(a, b) else print("NO")