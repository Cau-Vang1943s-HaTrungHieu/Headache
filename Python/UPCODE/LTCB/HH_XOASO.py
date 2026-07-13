num = input()

maxVal = 0
for i in range(len(num)):
    croppedNum = num[:i] + num[i + 1:]
    if croppedNum:
        val = int(croppedNum)
        if val > maxVal:
            maxVal = val
print(maxVal)