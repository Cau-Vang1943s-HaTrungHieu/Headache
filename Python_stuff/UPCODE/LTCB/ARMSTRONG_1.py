import sys

def isArmstrong(num):
    numOfDigits = len(str(num))
    return sum(int(digit) ** numOfDigits for digit in str(num)) == num

for line in sys.stdin:
    n = int(line.strip())
    print("YES") if (isArmstrong(int(line))) else print("NO")
