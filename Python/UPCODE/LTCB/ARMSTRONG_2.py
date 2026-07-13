import sys

def isArmstrong(num):
    numOfDigits = len(str(num))
    return sum(int(digit) ** numOfDigits for digit in str(num)) == num

a, b = map(int, input().split())
found = False

for i in range(a, b + 1):
    if isArmstrong(i): 
        print(i, end=" ")
        found = True

if (not found): print(-1)
