import sys

sumOfDigits = 0
count = 0
for line in sys.stdin:
    line = line.strip()
    if (int(line) == -1):
        break
    if line.isdigit():
        sumOfDigits += int(line)
        count += 1

avg = sumOfDigits / count
if (avg >= 8.5):
    print("A")
elif (avg >= 7.0):
    print("B")
elif (avg >= 5.5):
    print("C")
elif (avg >= 4):
    print("D")
else:
    print("F")